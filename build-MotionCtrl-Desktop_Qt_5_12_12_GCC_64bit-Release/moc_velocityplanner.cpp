/****************************************************************************
** Meta object code from reading C++ file 'velocityplanner.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MotionCtrl/VelocityPlanner/velocityplanner.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'velocityplanner.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Vsender_t {
    QByteArrayData data[11];
    char stringdata0[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Vsender_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Vsender_t qt_meta_stringdata_Vsender = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Vsender"
QT_MOC_LITERAL(1, 8, 12), // "SendVelocity"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 13), // "omniVelocity*"
QT_MOC_LITERAL(4, 36, 1), // "v"
QT_MOC_LITERAL(5, 38, 9), // "inputData"
QT_MOC_LITERAL(6, 48, 5), // "myDoc"
QT_MOC_LITERAL(7, 54, 7), // "refresh"
QT_MOC_LITERAL(8, 62, 7), // "setList"
QT_MOC_LITERAL(9, 70, 20), // "QList<omniVelocity>*"
QT_MOC_LITERAL(10, 91, 4) // "list"

    },
    "Vsender\0SendVelocity\0\0omniVelocity*\0"
    "v\0inputData\0myDoc\0refresh\0setList\0"
    "QList<omniVelocity>*\0list"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Vsender[] = {

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
       5,    1,   37,    2, 0x0a /* Public */,
       7,    0,   40,    2, 0x0a /* Public */,
       8,    1,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QJsonObject,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void Vsender::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Vsender *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendVelocity((*reinterpret_cast< omniVelocity*(*)>(_a[1]))); break;
        case 1: _t->inputData((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 2: _t->refresh(); break;
        case 3: _t->setList((*reinterpret_cast< QList<omniVelocity>*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Vsender::*)(omniVelocity * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Vsender::SendVelocity)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Vsender::staticMetaObject = { {
    &QPLCDriver::staticMetaObject,
    qt_meta_stringdata_Vsender.data,
    qt_meta_data_Vsender,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Vsender::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Vsender::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Vsender.stringdata0))
        return static_cast<void*>(this);
    return QPLCDriver::qt_metacast(_clname);
}

int Vsender::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPLCDriver::qt_metacall(_c, _id, _a);
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
void Vsender::SendVelocity(omniVelocity * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_VelocityPlanner_t {
    QByteArrayData data[11];
    char stringdata0[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VelocityPlanner_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VelocityPlanner_t qt_meta_stringdata_VelocityPlanner = {
    {
QT_MOC_LITERAL(0, 0, 15), // "VelocityPlanner"
QT_MOC_LITERAL(1, 16, 12), // "SendVelocity"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 12), // "omniVelocity"
QT_MOC_LITERAL(4, 43, 3), // "Tar"
QT_MOC_LITERAL(5, 47, 16), // "SendVelocitylist"
QT_MOC_LITERAL(6, 64, 20), // "QList<omniVelocity>*"
QT_MOC_LITERAL(7, 85, 4), // "list"
QT_MOC_LITERAL(8, 90, 8), // "SendTarV"
QT_MOC_LITERAL(9, 99, 13), // "omniVelocity*"
QT_MOC_LITERAL(10, 113, 12) // "PlanVelocity"

    },
    "VelocityPlanner\0SendVelocity\0\0"
    "omniVelocity\0Tar\0SendVelocitylist\0"
    "QList<omniVelocity>*\0list\0SendTarV\0"
    "omniVelocity*\0PlanVelocity"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VelocityPlanner[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       5,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   40,    2, 0x0a /* Public */,
      10,    1,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void VelocityPlanner::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VelocityPlanner *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendVelocity((*reinterpret_cast< omniVelocity(*)>(_a[1]))); break;
        case 1: _t->SendVelocitylist((*reinterpret_cast< QList<omniVelocity>*(*)>(_a[1]))); break;
        case 2: _t->SendTarV((*reinterpret_cast< omniVelocity*(*)>(_a[1]))); break;
        case 3: _t->PlanVelocity((*reinterpret_cast< omniVelocity(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VelocityPlanner::*)(omniVelocity );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VelocityPlanner::SendVelocity)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (VelocityPlanner::*)(QList<omniVelocity> * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VelocityPlanner::SendVelocitylist)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject VelocityPlanner::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_VelocityPlanner.data,
    qt_meta_data_VelocityPlanner,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VelocityPlanner::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VelocityPlanner::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VelocityPlanner.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int VelocityPlanner::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void VelocityPlanner::SendVelocity(omniVelocity _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void VelocityPlanner::SendVelocitylist(QList<omniVelocity> * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
