/****************************************************************************
** Meta object code from reading C++ file 'buy.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Appstore/buy.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'buy.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Buy_t {
    QByteArrayData data[9];
    char stringdata0[58];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Buy_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Buy_t qt_meta_stringdata_Buy = {
    {
QT_MOC_LITERAL(0, 0, 3), // "Buy"
QT_MOC_LITERAL(1, 4, 6), // "Buyapp"
QT_MOC_LITERAL(2, 11, 0), // ""
QT_MOC_LITERAL(3, 12, 14), // "Software_Tree*"
QT_MOC_LITERAL(4, 27, 4), // "Head"
QT_MOC_LITERAL(5, 32, 11), // "Ui::Widget*"
QT_MOC_LITERAL(6, 44, 2), // "ui"
QT_MOC_LITERAL(7, 47, 4), // "int&"
QT_MOC_LITERAL(8, 52, 5) // "total"

    },
    "Buy\0Buyapp\0\0Software_Tree*\0Head\0"
    "Ui::Widget*\0ui\0int&\0total"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Buy[] = {

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
       1,    3,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 7,    4,    6,    8,

       0        // eod
};

void Buy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Buy *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Buyapp((*reinterpret_cast< Software_Tree*(*)>(_a[1])),(*reinterpret_cast< Ui::Widget*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Buy::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Buy.data,
    qt_meta_data_Buy,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Buy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Buy::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Buy.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Buy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
