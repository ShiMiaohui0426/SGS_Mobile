#include "motionctrl.h"
#include "ui_motionctrl.h"
#define _WheelRadius 50.8//mm

MotionCtrl::MotionCtrl(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MotionCtrl)
{
    ui->setupUi(this);
cantimer=new QThread();
    dirverInit();

    SetVelocity(TARVelocity);

    override=ui->lineEdit_override->text().toDouble();

    Planner=new VelocityPlanner();
    connect(Planner,SIGNAL(SendVelocity(omniVelocity)),this,SLOT(SetVelocity(omniVelocity)),Qt::DirectConnection);
    ui->stackedWidget_planner->addWidget(Planner);
    ui->stackedWidget_planner->setCurrentWidget(Planner);


    pluginInit();
    restore();

}

void MotionCtrl::dirverInit()
{
    double MaxWheelVelocity=60*MaxLinearVelocity*1000/(2*3.14159*_WheelRadius);
    for(int i=0;i<4;i++){
        Driver[i]=new EPOS4CAN();
        QListWidgetItem* pListWidgetItem = new QListWidgetItem;
        pListWidgetItem->setSizeHint(QSize(200,150));
        ui->listWidget->addItem(pListWidgetItem);
        ui->listWidget->setItemWidget(pListWidgetItem,Driver[i]);
        Driver[i]->SetNodeID(i+1);
        Driver[i]->SetReduceRate(26);
        Driver[i]->SetMaxVelocity(MaxWheelVelocity);
        Driver[i]->SetThread(cantimer);
    };
    Driver[2]->SetNodeID(4);
    Driver[3]->SetNodeID(3);
    Driver[0]->OpenDevice();
    Driver[0]->EnableDriver();

    for(int i=1;i<4;i++){

        Driver[i]->SetKeyHandle(Driver[0]->GetKeyHandle());
        Driver[i]->EnableDriver();
    };
    cantimer->start();
}

void MotionCtrl::pluginInit()
{
    //    Test of stackWidget


    QDir dir(QDir::currentPath()+"/lib");
    QStringList filters;
    filters<<QString("*.so");
    dir.setFilter(QDir::Files | QDir::NoSymLinks); //设置类型过滤器，只为文件格式
    dir.setNameFilters(filters);  //设置文件名称过滤器，只为filters格式
    int dir_count = dir.count();
    //    qDebug()<<dir_count;
    //存储文件名称
    QStringList string_list;
    for(int i=0; i<dir_count; i++)
    {
        QString file_name = dir[i];  //文件名称
        QString fullPath=dir.absolutePath()+"/"+file_name;
        qDebug()<<fullPath;
        loadPlugin(fullPath);
    };
    auto *myAPI=myAPIList.at(0);
    ui->stackedWidget_controller->setCurrentWidget(myAPI->get_widget());

    for (auto var : myAPIList) {
        QJsonObject obj= var->GetINFO();
        QString myAPIname=obj["name"].toString();
        if(myAPIname=="manual_keyboard"){
            this->setFocusProxy(var->get_widget());
            ui->tab->setFocusProxy(var->get_widget());
            ui->listWidget->setFocusProxy(var->get_widget());
            for(int i=1;i<4;i++){
                Driver[i]->setFocusProxy(var->get_widget());
            };
            myAPI->get_widget()->setFocus();
            ui->stackedWidget_controller->setCurrentWidget(var->get_widget());
        };
    };
    //    QString fullPath="libKeyboardLib.so";

    //controlAPI* myAPI=loadPlugin(fullPath);




    //    fullPath="libudpLib.so";
    //    myAPI=loadPlugin(fullPath);
    //    myAPIList.append(myAPI);
};

MotionCtrl::~MotionCtrl()
{
    save();
    delete ui;
}
#include <QTime>
QTime t,p;
void MotionCtrl::SetVelocity(omniVelocity pTARVelocity)
{
    double DriverVelocity[4];
    omniVelocity TARVelocity=pTARVelocity;
    double speed=sqrt(TARVelocity.vy*TARVelocity.vy+TARVelocity.vx*TARVelocity.vx);
    if(speed>MaxLinearVelocity){
        TARVelocity.vx *=(MaxLinearVelocity)/speed;
        TARVelocity.omega *=(MaxLinearVelocity)/speed;
        TARVelocity.vy *=(MaxLinearVelocity)/speed;
    };


    for (int i =0;i<4 ;i++ ) {
        double alpha=(-90*i+135)*3.14159/180;
        DriverVelocity[i]=-sin(alpha)*TARVelocity.vx+cos(alpha)*TARVelocity.vy+0.2*1.414*3.1415*TARVelocity.omega/180;
        DriverVelocity[i]=DriverVelocity[i]*1000*60/(2*3.14159*_WheelRadius);
        //        qDebug()<<DriverVelocity[i]*override/100;

        Driver[i]->SetVelocity(DriverVelocity[i]*override/100);
        //        qDebug()<<t.elapsed()<<"ms used for motor"<<i;
        //        t.start();
    };
    qDebug()<<p.elapsed()<<"ms used for 4 motors";

    p.start();
}






void MotionCtrl::on_lineEdit_override_textChanged(const QString &arg1)
{
    override=arg1.toDouble();
}

controlAPI *MotionCtrl::loadPlugin(QString plugin_path)
{
    QPluginLoader *pluginLoader = new QPluginLoader(plugin_path);
    QObject *plugin = pluginLoader->instance();
    //    qDebug()<<pluginLoader->errorString()<<plugin ;
    if (plugin) {
        controlAPI* interface = qobject_cast<controlAPI*>(plugin);
        connect(interface,SIGNAL(SetVel(omniVelocity)),Planner,SLOT(PlanVelocity(omniVelocity)));
        ui->comboBox->addItem(interface->GetINFO()["name"].toString());
        ui->stackedWidget_controller->addWidget(interface->get_widget());
        myAPIList.append(interface);
        return interface;
    }
    else {
        delete pluginLoader;
        return nullptr;
    };
}

void MotionCtrl::save()
{
    QJsonDocument mydoc;
    QJsonObject obj;
    for (auto var : myAPIList) {
        QJsonObject info= var->GetINFO();
        obj[info["name"].toString()]=var->save();
    };
    obj["LastController"]=myAPIList[ui->comboBox->currentIndex()]->GetINFO()["name"];
    obj["override"]=override;
    mydoc.setObject(obj);
    QFile file(QDir::currentPath()+"/SGSMobileAutoSave.json");
    file.open(QIODevice::WriteOnly);
    // 将json以文本形式写入文件并关闭文件。
    file.write(mydoc.toJson());
    file.close();

}

void MotionCtrl::restore()
{
    QFile file(QDir::currentPath()+"/SGSMobileAutoSave.json");
    file.open(QIODevice::ReadOnly);
    QJsonParseError jsonError;
    QJsonDocument jsonDoc(QJsonDocument::fromJson(file.readAll(), &jsonError));
    QJsonObject m_para=jsonDoc.object();
    QJsonObject obj=m_para;
    for (auto var : myAPIList) {
        QJsonObject info= var->GetINFO();
        QJsonObject tmp=obj[info["name"].toString()].toObject();
        var->restore(tmp);
    };
    QString LastController=obj["LastController"].toString();
    for (int i=0;i<myAPIList.size();i++) {
        auto var=myAPIList[i];

        if(var->GetINFO()["name"].toString()==LastController){
            ui->comboBox->setCurrentIndex(i);
            ui->checkBox_Enabled->setChecked(var->isEnable());
        };
    };
    override=obj["override"].toDouble();
    ui->lineEdit_override->setText(QString::number(override));
};


void MotionCtrl::on_comboBox_currentIndexChanged(int index)
{
    if(!myAPIList.isEmpty()) {
        ui->stackedWidget_controller->setCurrentWidget(myAPIList[index]->get_widget() );
        ui->checkBox_Enabled->setChecked(myAPIList[index]->isEnable());
    };

};


void MotionCtrl::on_checkBox_Enabled_stateChanged(int arg1)
{
    if(!myAPIList.isEmpty()) {
        myAPIList[ui->comboBox->currentIndex()]->SetEnable(arg1);
    };
}

