/****************************************************************************
** Meta object code from reading C++ file 'edititem.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/View/edititem.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'edititem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSEditItemENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSEditItemENDCLASS = QtMocHelpers::stringData(
    "EditItem",
    "refresh",
    "",
    "AbstractSensor*",
    "string",
    "oldName",
    "checkSensor",
    "nameNotChanged",
    "onOkClicked",
    "onCancelClicked",
    "onEditAvailable"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSEditItemENDCLASS_t {
    uint offsetsAndSizes[22];
    char stringdata0[9];
    char stringdata1[8];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[7];
    char stringdata5[8];
    char stringdata6[12];
    char stringdata7[15];
    char stringdata8[12];
    char stringdata9[16];
    char stringdata10[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSEditItemENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSEditItemENDCLASS_t qt_meta_stringdata_CLASSEditItemENDCLASS = {
    {
        QT_MOC_LITERAL(0, 8),  // "EditItem"
        QT_MOC_LITERAL(9, 7),  // "refresh"
        QT_MOC_LITERAL(17, 0),  // ""
        QT_MOC_LITERAL(18, 15),  // "AbstractSensor*"
        QT_MOC_LITERAL(34, 6),  // "string"
        QT_MOC_LITERAL(41, 7),  // "oldName"
        QT_MOC_LITERAL(49, 11),  // "checkSensor"
        QT_MOC_LITERAL(61, 14),  // "nameNotChanged"
        QT_MOC_LITERAL(76, 11),  // "onOkClicked"
        QT_MOC_LITERAL(88, 15),  // "onCancelClicked"
        QT_MOC_LITERAL(104, 15)   // "onEditAvailable"
    },
    "EditItem",
    "refresh",
    "",
    "AbstractSensor*",
    "string",
    "oldName",
    "checkSensor",
    "nameNotChanged",
    "onOkClicked",
    "onCancelClicked",
    "onEditAvailable"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSEditItemENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   50,    2, 0x06,    1 /* Public */,
       6,    0,   55,    2, 0x06,    4 /* Public */,
       7,    0,   56,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,   57,    2, 0x08,    6 /* Private */,
       9,    0,   58,    2, 0x08,    7 /* Private */,
      10,    0,   59,    2, 0x0a,    8 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    5,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject EditItem::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSEditItemENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSEditItemENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSEditItemENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<EditItem, std::true_type>,
        // method 'refresh'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<AbstractSensor *, std::false_type>,
        QtPrivate::TypeAndForceComplete<string, std::false_type>,
        // method 'checkSensor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'nameNotChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onOkClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onCancelClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onEditAvailable'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void EditItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EditItem *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->refresh((*reinterpret_cast< std::add_pointer_t<AbstractSensor*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<string>>(_a[2]))); break;
        case 1: _t->checkSensor(); break;
        case 2: _t->nameNotChanged(); break;
        case 3: _t->onOkClicked(); break;
        case 4: _t->onCancelClicked(); break;
        case 5: _t->onEditAvailable(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (EditItem::*)(AbstractSensor * , string );
            if (_t _q_method = &EditItem::refresh; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (EditItem::*)();
            if (_t _q_method = &EditItem::checkSensor; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (EditItem::*)();
            if (_t _q_method = &EditItem::nameNotChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *EditItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EditItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSEditItemENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int EditItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void EditItem::refresh(AbstractSensor * _t1, string _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void EditItem::checkSensor()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void EditItem::nameNotChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
