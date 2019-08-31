/****************************************************************************
** Meta object code from reading C++ file 'category.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Server/lib/category.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'category.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Category_t {
    QByteArrayData data[24];
    char stringdata0[225];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Category_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Category_t qt_meta_stringdata_Category = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Category"
QT_MOC_LITERAL(1, 9, 15), // "categoryChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 4), // "what"
QT_MOC_LITERAL(4, 31, 13), // "categorySaved"
QT_MOC_LITERAL(5, 45, 4), // "save"
QT_MOC_LITERAL(6, 50, 4), // "path"
QT_MOC_LITERAL(7, 55, 6), // "gender"
QT_MOC_LITERAL(8, 62, 4), // "mode"
QT_MOC_LITERAL(9, 67, 8), // "yearFrom"
QT_MOC_LITERAL(10, 76, 6), // "yearTo"
QT_MOC_LITERAL(11, 83, 10), // "weightFrom"
QT_MOC_LITERAL(12, 94, 8), // "weightTo"
QT_MOC_LITERAL(13, 103, 13), // "roundStandart"
QT_MOC_LITERAL(14, 117, 10), // "roundFinal"
QT_MOC_LITERAL(15, 128, 4), // "name"
QT_MOC_LITERAL(16, 133, 8), // "beltFrom"
QT_MOC_LITERAL(17, 142, 6), // "beltTo"
QT_MOC_LITERAL(18, 149, 9), // "isDanFrom"
QT_MOC_LITERAL(19, 159, 7), // "isDanTo"
QT_MOC_LITERAL(20, 167, 15), // "timeMinStandart"
QT_MOC_LITERAL(21, 183, 12), // "timeMinFinal"
QT_MOC_LITERAL(22, 196, 15), // "timeSecStandart"
QT_MOC_LITERAL(23, 212, 12) // "timeSecFinal"

    },
    "Category\0categoryChanged\0\0what\0"
    "categorySaved\0save\0path\0gender\0mode\0"
    "yearFrom\0yearTo\0weightFrom\0weightTo\0"
    "roundStandart\0roundFinal\0name\0beltFrom\0"
    "beltTo\0isDanFrom\0isDanTo\0timeMinStandart\0"
    "timeMinFinal\0timeSecStandart\0timeSecFinal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Category[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
      17,   42, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    0,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   38,    2, 0x0a /* Public */,
       5,    0,   41,    2, 0x2a /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,

 // properties: name, type, flags
       7, QMetaType::QString, 0x00495103,
       8, QMetaType::QString, 0x00495103,
       9, QMetaType::QString, 0x00495103,
      10, QMetaType::QString, 0x00495103,
      11, QMetaType::QString, 0x00495103,
      12, QMetaType::QString, 0x00495103,
      13, QMetaType::QString, 0x00495103,
      14, QMetaType::QString, 0x00495103,
      15, QMetaType::QString, 0x00495103,
      16, QMetaType::QString, 0x00495103,
      17, QMetaType::QString, 0x00495103,
      18, QMetaType::Bool, 0x00495103,
      19, QMetaType::Bool, 0x00495103,
      20, QMetaType::QString, 0x00495103,
      21, QMetaType::QString, 0x00495103,
      22, QMetaType::QString, 0x00495103,
      23, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,

       0        // eod
};

void Category::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Category *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->categoryChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->categorySaved(); break;
        case 2: _t->save((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->save(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Category::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Category::categoryChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Category::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Category::categorySaved)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Category *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->gender(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->mode(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->yearFrom(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->yearTo(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->weightFrom(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->weightTo(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->roundStandart(); break;
        case 7: *reinterpret_cast< QString*>(_v) = _t->roundFinal(); break;
        case 8: *reinterpret_cast< QString*>(_v) = _t->name(); break;
        case 9: *reinterpret_cast< QString*>(_v) = _t->beltFrom(); break;
        case 10: *reinterpret_cast< QString*>(_v) = _t->beltTo(); break;
        case 11: *reinterpret_cast< bool*>(_v) = _t->isDanFrom(); break;
        case 12: *reinterpret_cast< bool*>(_v) = _t->isDanTo(); break;
        case 13: *reinterpret_cast< QString*>(_v) = _t->timeMinStandart(); break;
        case 14: *reinterpret_cast< QString*>(_v) = _t->timeMinFinal(); break;
        case 15: *reinterpret_cast< QString*>(_v) = _t->timeSecStandart(); break;
        case 16: *reinterpret_cast< QString*>(_v) = _t->timeSecFinal(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Category *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setGender(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setMode(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setYearFrom(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setYearTo(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setWeightFrom(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setWeightTo(*reinterpret_cast< QString*>(_v)); break;
        case 6: _t->setRoundStandart(*reinterpret_cast< QString*>(_v)); break;
        case 7: _t->setRoundFinal(*reinterpret_cast< QString*>(_v)); break;
        case 8: _t->setName(*reinterpret_cast< QString*>(_v)); break;
        case 9: _t->setBeltFrom(*reinterpret_cast< QString*>(_v)); break;
        case 10: _t->setBeltTo(*reinterpret_cast< QString*>(_v)); break;
        case 11: _t->setIsDanFrom(*reinterpret_cast< bool*>(_v)); break;
        case 12: _t->setIsDanTo(*reinterpret_cast< bool*>(_v)); break;
        case 13: _t->setTimeMinStandart(*reinterpret_cast< QString*>(_v)); break;
        case 14: _t->setTimeMinFinal(*reinterpret_cast< QString*>(_v)); break;
        case 15: _t->setTimeSecStandart(*reinterpret_cast< QString*>(_v)); break;
        case 16: _t->setTimeSecFinal(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Category::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Category.data,
    qt_meta_data_Category,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Category::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Category::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Category.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Category::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 17;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Category::categoryChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Category::categorySaved()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
