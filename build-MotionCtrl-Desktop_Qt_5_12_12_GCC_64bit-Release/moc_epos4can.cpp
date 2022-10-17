/****************************************************************************
** Meta object code from reading C++ file 'epos4can.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MotionCtrl/EPOS4CAN_V1.0/epos4can.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'epos4can.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EPOS4CAN_VelocitySetter_t {
    QByteArrayData data[4];
    char stringdata0[39];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EPOS4CAN_VelocitySetter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EPOS4CAN_VelocitySetter_t qt_meta_stringdata_EPOS4CAN_VelocitySetter = {
    {
QT_MOC_LITERAL(0, 0, 23), // "EPOS4CAN_VelocitySetter"
QT_MOC_LITERAL(1, 24, 4), // "setV"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 8) // "Velocity"

    },
    "EPOS4CAN_VelocitySetter\0setV\0\0Velocity"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EPOS4CAN_VelocitySetter[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Long,    3,

       0        // eod
};

void EPOS4CAN_VelocitySetter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EPOS4CAN_VelocitySetter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setV((*reinterpret_cast< long(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject EPOS4CAN_VelocitySetter::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_EPOS4CAN_VelocitySetter.data,
    qt_meta_data_EPOS4CAN_VelocitySetter,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EPOS4CAN_VelocitySetter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EPOS4CAN_VelocitySetter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EPOS4CAN_VelocitySetter.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int EPOS4CAN_VelocitySetter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_EPOS4CAN_t {
    QByteArrayData data[8];
    char stringdata0[106];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EPOS4CAN_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EPOS4CAN_t qt_meta_stringdata_EPOS4CAN = {
    {
QT_MOC_LITERAL(0, 0, 8), // "EPOS4CAN"
QT_MOC_LITERAL(1, 9, 4), // "tarV"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 8), // "Velocity"
QT_MOC_LITERAL(4, 24, 6), // "update"
QT_MOC_LITERAL(5, 31, 35), // "on_spinBox_SetVelocity_valueC..."
QT_MOC_LITERAL(6, 67, 4), // "arg1"
QT_MOC_LITERAL(7, 72, 33) // "on_pushButton_SetVelocity_cli..."

    },
    "EPOS4CAN\0tarV\0\0Velocity\0update\0"
    "on_spinBox_SetVelocity_valueChanged\0"
    "arg1\0on_pushButton_SetVelocity_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EPOS4CAN[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   37,    2, 0x08 /* Private */,
       5,    1,   38,    2, 0x08 /* Private */,
       7,    0,   41,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Long,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,

       0        // eod
};

void EPOS4CAN::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EPOS4CAN *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tarV((*reinterpret_cast< long(*)>(_a[1]))); break;
        case 1: _t->update(); break;
        case 2: _t->on_spinBox_SetVelocity_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_SetVelocity_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (EPOS4CAN::*)(long );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EPOS4CAN::tarV)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject EPOS4CAN::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_EPOS4CAN.data,
    qt_meta_data_EPOS4CAN,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EPOS4CAN::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EPOS4CAN::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EPOS4CAN.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int EPOS4CAN::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void EPOS4CAN::tarV(long _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
