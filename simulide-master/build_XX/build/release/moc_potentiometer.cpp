/****************************************************************************
** Meta object code from reading C++ file 'potentiometer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/gui/circuitwidget/components/potentiometer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'potentiometer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Potentiometer_t {
    QByteArrayData data[9];
    char stringdata0[73];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Potentiometer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Potentiometer_t qt_meta_stringdata_Potentiometer = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Potentiometer"
QT_MOC_LITERAL(1, 14, 10), // "resChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 4), // "volt"
QT_MOC_LITERAL(4, 31, 6), // "remove"
QT_MOC_LITERAL(5, 38, 10), // "Resistance"
QT_MOC_LITERAL(6, 49, 4), // "Unit"
QT_MOC_LITERAL(7, 54, 8), // "Show_res"
QT_MOC_LITERAL(8, 63, 9) // "Value_Ohm"

    },
    "Potentiometer\0resChanged\0\0volt\0remove\0"
    "Resistance\0Unit\0Show_res\0Value_Ohm"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Potentiometer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       4,   28, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x0a /* Public */,
       4,    0,   27,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

 // properties: name, type, flags
       5, QMetaType::Double, 0x00195003,
       6, QMetaType::QString, 0x00195103,
       7, QMetaType::Bool, 0x00195003,
       8, QMetaType::Int, 0x00195003,

       0        // eod
};

void Potentiometer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Potentiometer *_t = static_cast<Potentiometer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->resChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->remove(); break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Potentiometer *_t = static_cast<Potentiometer *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< double*>(_v) = _t->res(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->unit(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->showVal(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->val(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        Potentiometer *_t = static_cast<Potentiometer *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setRes(*reinterpret_cast< double*>(_v)); break;
        case 1: _t->setUnit(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setShowVal(*reinterpret_cast< bool*>(_v)); break;
        case 3: _t->setVal(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject Potentiometer::staticMetaObject = {
    { &Component::staticMetaObject, qt_meta_stringdata_Potentiometer.data,
      qt_meta_data_Potentiometer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Potentiometer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Potentiometer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Potentiometer.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "eElement"))
        return static_cast< eElement*>(this);
    return Component::qt_metacast(_clname);
}

int Potentiometer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Component::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
