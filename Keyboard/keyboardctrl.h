#ifndef KEYBOARDCTRL_H
#define KEYBOARDCTRL_H

#include <QWidget>
#include <qstring.h>
#include<QKeyEvent>
QT_BEGIN_NAMESPACE
namespace Ui { class KeyboardCtrl; }
QT_END_NAMESPACE
struct omniVelocity{
    double vx=0;
    double vy=0;
    double omega=0;
};
class KeyboardCtrl : public QWidget
{
    Q_OBJECT

public:
    KeyboardCtrl(QWidget *parent = nullptr);
    ~KeyboardCtrl();
signals:
    void SetVelocity(omniVelocity);
protected:
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
private slots:
    void on_WButton_pressed();

    void on_WButton_released();

    void on_SButton_pressed();

    void on_SButton_released();

    void on_AButton_pressed();

    void on_AButton_released();

    void on_DButton_pressed();

    void on_DButton_released();

    void on_JButton_pressed();

    void on_JButton_released();

    void on_KButton_pressed();

    void on_KButton_released();

private:
    Ui::KeyboardCtrl *ui;
    omniVelocity TARVelocity;
};
#endif // KEYBOARDCTRL_H
