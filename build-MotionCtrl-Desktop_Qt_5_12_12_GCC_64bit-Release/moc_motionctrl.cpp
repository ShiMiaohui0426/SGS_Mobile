/****************************************************************************
** Meta object code from reading C++ file 'motionctrl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MotionCtrl/motionctrl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'motionctrl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MotionCtrl_t {
    QByteArrayData data[10];
    char stringdata0[158];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MotionCtrl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MotionCtrl_t qt_meta_stringdata_MotionCtrl = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MotionCtrl"
QT_MOC_LITERAL(1, 11, 11), // "SetVelocity"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 12), // "omniVelocity"
QT_MOC_LITERAL(4, 37, 11), // "TARVelocity"
QT_MOC_LITERAL(5, 49, 32), // "on_lineEdit_override_textChanged"
QT_MOC_LITERAL(6, 82, 4), // "arg1"
QT_MOC_LITERAL(7, 87, 31), // "on_comboBox_currentIndexChanged"
QT_MOC_LITERAL(8, 119, 5), // "index"
QT_MOC_LITERAL(9, 125, 32) // "on_checkBox_Enabled_stateChanged"

    },
    "MotionCtrl\0SetVelocity\0\0omniVelocity\0"
    "TARVelocity\0on_lineEdit_override_textChanged\0"
    "arg1\0on_comboBox_currentIndexChanged\0"
    "index\0on_checkBox_Enabled_stateChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MotionCtrl[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       5,    1,   37,    2, 0x08 /* Private */,
       7,    1,   40,    2, 0x08 /* Private */,
       9,    1,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void MotionCtrl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MotionCtrl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SetVelocity((*reinterpret_cast< omniVelocity(*)>(_a[1]))); break;
        case 1: _t->on_lineEdit_override_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_checkBox_Enabled_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MotionCtrl::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_MotionCtrl.data,
    qt_meta_data_MotionCtrl,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MotionCtrl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MotionCtrl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MotionCtrl.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MotionCtrl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
