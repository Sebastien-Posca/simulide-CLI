/****************************************************************************
** Meta object code from reading C++ file 'mosfet.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/gui/circuitwidget/components/mosfet.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mosfet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Mosfet_t {
    QByteArrayData data[7];
    char stringdata0[51];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Mosfet_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Mosfet_t qt_meta_stringdata_Mosfet = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Mosfet"
QT_MOC_LITERAL(1, 7, 6), // "remove"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 5), // "RDSon"
QT_MOC_LITERAL(4, 21, 9), // "Threshold"
QT_MOC_LITERAL(5, 31, 9), // "P_Channel"
QT_MOC_LITERAL(6, 41, 9) // "Depletion"

    },
    "Mosfet\0remove\0\0RDSon\0Threshold\0P_Channel\0"
    "Depletion"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Mosfet[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       4,   20, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,

 // properties: name, type, flags
       3, QMetaType::Double, 0x00195103,
       4, QMetaType::Double, 0x00195103,
       5, QMetaType::Bool, 0x00195003,
       6, QMetaType::Bool, 0x00195103,

       0        // eod
};

void Mosfet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Mosfet *_t = static_cast<Mosfet *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->remove(); break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Mosfet *_t = static_cast<Mosfet *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< double*>(_v) = _t->RDSon(); break;
        case 1: *reinterpret_cast< double*>(_v) = _t->threshold(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->pChannel(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->depletion(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        Mosfet *_t = static_cast<Mosfet *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setRDSon(*reinterpret_cast< double*>(_v)); break;
        case 1: _t->setThreshold(*reinterpret_cast< double*>(_v)); break;
        case 2: _t->setPchannel(*reinterpret_cast< bool*>(_v)); break;
        case 3: _t->setDepletion(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

const QMetaObject Mosfet::staticMetaObject = {
    { &Component::staticMetaObject, qt_meta_stringdata_Mosfet.data,
      qt_meta_data_Mosfet,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Mosfet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Mosfet::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Mosfet.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "eMosfet"))
        return static_cast< eMosfet*>(this);
    return Component::qt_metacast(_clname);
}

int Mosfet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Component::qt_metacall(_c, _id, _a);
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
