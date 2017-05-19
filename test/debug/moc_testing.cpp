/****************************************************************************
** Meta object code from reading C++ file 'testing.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../testing.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testing.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Testing_t {
    QByteArrayData data[10];
    char stringdata0[185];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Testing_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Testing_t qt_meta_stringdata_Testing = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Testing"
QT_MOC_LITERAL(1, 8, 10), // "create_obj"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 15), // "ParsingTestFull"
QT_MOC_LITERAL(4, 36, 16), // "ParsingTestEmpty"
QT_MOC_LITERAL(5, 53, 26), // "HashMap_parse_correct_full"
QT_MOC_LITERAL(6, 80, 27), // "HashMap_parse_correct_empty"
QT_MOC_LITERAL(7, 108, 34), // "TableWidget_insertion_correct..."
QT_MOC_LITERAL(8, 143, 35), // "TableWidget_insertion_correct..."
QT_MOC_LITERAL(9, 179, 5) // "clean"

    },
    "Testing\0create_obj\0\0ParsingTestFull\0"
    "ParsingTestEmpty\0HashMap_parse_correct_full\0"
    "HashMap_parse_correct_empty\0"
    "TableWidget_insertion_correct_full\0"
    "TableWidget_insertion_correct_empty\0"
    "clean"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Testing[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Testing::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Testing *_t = static_cast<Testing *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->create_obj(); break;
        case 1: _t->ParsingTestFull(); break;
        case 2: _t->ParsingTestEmpty(); break;
        case 3: _t->HashMap_parse_correct_full(); break;
        case 4: _t->HashMap_parse_correct_empty(); break;
        case 5: _t->TableWidget_insertion_correct_full(); break;
        case 6: _t->TableWidget_insertion_correct_empty(); break;
        case 7: _t->clean(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Testing::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Testing.data,
      qt_meta_data_Testing,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Testing::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Testing::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Testing.stringdata0))
        return static_cast<void*>(const_cast< Testing*>(this));
    return QObject::qt_metacast(_clname);
}

int Testing::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
