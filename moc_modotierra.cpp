/****************************************************************************
** Meta object code from reading C++ file 'modotierra.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "modotierra.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modotierra.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_modotierra_t {
    QByteArrayData data[16];
    char stringdata[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_modotierra_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_modotierra_t qt_meta_stringdata_modotierra = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 9),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 11),
QT_MOC_LITERAL(4, 34, 14),
QT_MOC_LITERAL(5, 49, 16),
QT_MOC_LITERAL(6, 66, 18),
QT_MOC_LITERAL(7, 85, 5),
QT_MOC_LITERAL(8, 91, 5),
QT_MOC_LITERAL(9, 97, 3),
QT_MOC_LITERAL(10, 101, 12),
QT_MOC_LITERAL(11, 114, 3),
QT_MOC_LITERAL(12, 118, 4),
QT_MOC_LITERAL(13, 123, 11),
QT_MOC_LITERAL(14, 135, 7),
QT_MOC_LITERAL(15, 143, 7)
    },
    "modotierra\0vinculado\0\0autenticado\0"
    "entradaChanged\0airedesvinculado\0"
    "on_conecta_clicked\0listo\0envio\0val\0"
    "QHostAddress\0dir\0port\0leerentrada\0"
    "saludar\0entrada\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_modotierra[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       1,   74, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06,
       3,    0,   60,    2, 0x06,
       4,    0,   61,    2, 0x06,
       5,    0,   62,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       6,    0,   63,    2, 0x0a,
       7,    0,   64,    2, 0x0a,
       8,    3,   65,    2, 0x0a,
      13,    0,   72,    2, 0x0a,
      14,    0,   73,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 10, QMetaType::UShort,    9,   11,   12,
    QMetaType::QString,
    QMetaType::Void,

 // properties: name, type, flags
      15, QMetaType::QString, 0x00495001,

 // properties: notify_signal_id
       2,

       0        // eod
};

void modotierra::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        modotierra *_t = static_cast<modotierra *>(_o);
        switch (_id) {
        case 0: _t->vinculado(); break;
        case 1: _t->autenticado(); break;
        case 2: _t->entradaChanged(); break;
        case 3: _t->airedesvinculado(); break;
        case 4: _t->on_conecta_clicked(); break;
        case 5: _t->listo(); break;
        case 6: _t->envio((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< QHostAddress(*)>(_a[2])),(*reinterpret_cast< quint16(*)>(_a[3]))); break;
        case 7: { QString _r = _t->leerentrada();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 8: _t->saludar(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (modotierra::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&modotierra::vinculado)) {
                *result = 0;
            }
        }
        {
            typedef void (modotierra::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&modotierra::autenticado)) {
                *result = 1;
            }
        }
        {
            typedef void (modotierra::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&modotierra::entradaChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (modotierra::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&modotierra::airedesvinculado)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject modotierra::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_modotierra.data,
      qt_meta_data_modotierra,  qt_static_metacall, 0, 0}
};


const QMetaObject *modotierra::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *modotierra::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_modotierra.stringdata))
        return static_cast<void*>(const_cast< modotierra*>(this));
    return QObject::qt_metacast(_clname);
}

int modotierra::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = leerentrada(); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void modotierra::vinculado()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void modotierra::autenticado()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void modotierra::entradaChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void modotierra::airedesvinculado()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
