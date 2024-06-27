/****************************************************************************
** Meta object code from reading C++ file 'searchaddwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/View/searchaddwidget.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'searchaddwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
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
struct qt_meta_stringdata_CLASSSearchAddWidgetENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSSearchAddWidgetENDCLASS = QtMocHelpers::stringData(
    "SearchAddWidget",
    "nameTransfer",
    "",
    "AbstractSensor*",
    "requestAdd",
    "deleteAllSignal",
    "sensorDeleted",
    "focusChanged",
    "addClicked",
    "searchButton",
    "target",
    "deleteClicked",
    "deleteAllClicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSearchAddWidgetENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   68,    2, 0x06,    1 /* Public */,
       4,    0,   71,    2, 0x06,    3 /* Public */,
       5,    0,   72,    2, 0x06,    4 /* Public */,
       6,    0,   73,    2, 0x06,    5 /* Public */,
       7,    0,   74,    2, 0x06,    6 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,   75,    2, 0x08,    7 /* Private */,
       9,    1,   76,    2, 0x08,    8 /* Private */,
      11,    0,   79,    2, 0x08,   10 /* Private */,
      12,    0,   80,    2, 0x0a,   11 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject SearchAddWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSSearchAddWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSearchAddWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSearchAddWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SearchAddWidget, std::true_type>,
        // method 'nameTransfer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<AbstractSensor *, std::false_type>,
        // method 'requestAdd'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deleteAllSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sensorDeleted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'focusChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'searchButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'deleteClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deleteAllClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void SearchAddWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SearchAddWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->nameTransfer((*reinterpret_cast< std::add_pointer_t<AbstractSensor*>>(_a[1]))); break;
        case 1: _t->requestAdd(); break;
        case 2: _t->deleteAllSignal(); break;
        case 3: _t->sensorDeleted(); break;
        case 4: _t->focusChanged(); break;
        case 5: _t->addClicked(); break;
        case 6: _t->searchButton((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->deleteClicked(); break;
        case 8: _t->deleteAllClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SearchAddWidget::*)(AbstractSensor * );
            if (_t _q_method = &SearchAddWidget::nameTransfer; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SearchAddWidget::*)();
            if (_t _q_method = &SearchAddWidget::requestAdd; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SearchAddWidget::*)();
            if (_t _q_method = &SearchAddWidget::deleteAllSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SearchAddWidget::*)();
            if (_t _q_method = &SearchAddWidget::sensorDeleted; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SearchAddWidget::*)();
            if (_t _q_method = &SearchAddWidget::focusChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject *SearchAddWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SearchAddWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSearchAddWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SearchAddWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void SearchAddWidget::nameTransfer(AbstractSensor * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SearchAddWidget::requestAdd()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SearchAddWidget::deleteAllSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void SearchAddWidget::sensorDeleted()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void SearchAddWidget::focusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
