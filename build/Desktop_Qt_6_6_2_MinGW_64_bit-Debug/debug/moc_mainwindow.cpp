/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/View/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCharts/qlineseries.h>
#include <QtCharts/qabstractbarseries.h>
#include <QtCharts/qvbarmodelmapper.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCharts/qcandlestickseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "editAvailable",
    "",
    "onSetFocus",
    "AbstractSensor*",
    "displayInfo",
    "onRequestAdd",
    "onDeleteAll",
    "onSensorDeleted",
    "onStartSim",
    "onInspectSensor",
    "onDataAvailable",
    "onNewValue",
    "onAddValToSensor",
    "onRequestDeleteVal",
    "onUpdateChart",
    "onEditSensor",
    "onCheckSensor",
    "onRefresh",
    "const AbstractSensor*",
    "std::string",
    "onDeleteAllValues",
    "onSaveSensors",
    "onLoadSensors"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[48];
    char stringdata0[11];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[11];
    char stringdata4[16];
    char stringdata5[12];
    char stringdata6[13];
    char stringdata7[12];
    char stringdata8[16];
    char stringdata9[11];
    char stringdata10[16];
    char stringdata11[16];
    char stringdata12[11];
    char stringdata13[17];
    char stringdata14[19];
    char stringdata15[14];
    char stringdata16[13];
    char stringdata17[14];
    char stringdata18[10];
    char stringdata19[22];
    char stringdata20[12];
    char stringdata21[18];
    char stringdata22[14];
    char stringdata23[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 13),  // "editAvailable"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 10),  // "onSetFocus"
        QT_MOC_LITERAL(37, 15),  // "AbstractSensor*"
        QT_MOC_LITERAL(53, 11),  // "displayInfo"
        QT_MOC_LITERAL(65, 12),  // "onRequestAdd"
        QT_MOC_LITERAL(78, 11),  // "onDeleteAll"
        QT_MOC_LITERAL(90, 15),  // "onSensorDeleted"
        QT_MOC_LITERAL(106, 10),  // "onStartSim"
        QT_MOC_LITERAL(117, 15),  // "onInspectSensor"
        QT_MOC_LITERAL(133, 15),  // "onDataAvailable"
        QT_MOC_LITERAL(149, 10),  // "onNewValue"
        QT_MOC_LITERAL(160, 16),  // "onAddValToSensor"
        QT_MOC_LITERAL(177, 18),  // "onRequestDeleteVal"
        QT_MOC_LITERAL(196, 13),  // "onUpdateChart"
        QT_MOC_LITERAL(210, 12),  // "onEditSensor"
        QT_MOC_LITERAL(223, 13),  // "onCheckSensor"
        QT_MOC_LITERAL(237, 9),  // "onRefresh"
        QT_MOC_LITERAL(247, 21),  // "const AbstractSensor*"
        QT_MOC_LITERAL(269, 11),  // "std::string"
        QT_MOC_LITERAL(281, 17),  // "onDeleteAllValues"
        QT_MOC_LITERAL(299, 13),  // "onSaveSensors"
        QT_MOC_LITERAL(313, 13)   // "onLoadSensors"
    },
    "MainWindow",
    "editAvailable",
    "",
    "onSetFocus",
    "AbstractSensor*",
    "displayInfo",
    "onRequestAdd",
    "onDeleteAll",
    "onSensorDeleted",
    "onStartSim",
    "onInspectSensor",
    "onDataAvailable",
    "onNewValue",
    "onAddValToSensor",
    "onRequestDeleteVal",
    "onUpdateChart",
    "onEditSensor",
    "onCheckSensor",
    "onRefresh",
    "const AbstractSensor*",
    "std::string",
    "onDeleteAllValues",
    "onSaveSensors",
    "onLoadSensors"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  128,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    1,  129,    2, 0x08,    2 /* Private */,
       5,    1,  132,    2, 0x08,    4 /* Private */,
       6,    0,  135,    2, 0x08,    6 /* Private */,
       7,    0,  136,    2, 0x08,    7 /* Private */,
       8,    0,  137,    2, 0x08,    8 /* Private */,
       9,    0,  138,    2, 0x08,    9 /* Private */,
      10,    0,  139,    2, 0x08,   10 /* Private */,
      11,    1,  140,    2, 0x08,   11 /* Private */,
      12,    0,  143,    2, 0x08,   13 /* Private */,
      13,    2,  144,    2, 0x08,   14 /* Private */,
      14,    2,  149,    2, 0x08,   17 /* Private */,
      15,    0,  154,    2, 0x08,   20 /* Private */,
      16,    0,  155,    2, 0x08,   21 /* Private */,
      17,    0,  156,    2, 0x08,   22 /* Private */,
      18,    2,  157,    2, 0x08,   23 /* Private */,
      21,    0,  162,    2, 0x08,   26 /* Private */,
      22,    0,  163,    2, 0x08,   27 /* Private */,
      23,    0,  164,    2, 0x08,   28 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19, 0x80000000 | 20,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'editAvailable'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSetFocus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<AbstractSensor *, std::false_type>,
        // method 'displayInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<AbstractSensor *, std::false_type>,
        // method 'onRequestAdd'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDeleteAll'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSensorDeleted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onStartSim'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onInspectSensor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDataAvailable'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<AbstractSensor *, std::false_type>,
        // method 'onNewValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAddValToSensor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'onRequestDeleteVal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'onUpdateChart'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onEditSensor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onCheckSensor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onRefresh'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const AbstractSensor *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::string &, std::false_type>,
        // method 'onDeleteAllValues'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSaveSensors'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onLoadSensors'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->editAvailable(); break;
        case 1: _t->onSetFocus((*reinterpret_cast< std::add_pointer_t<AbstractSensor*>>(_a[1]))); break;
        case 2: _t->displayInfo((*reinterpret_cast< std::add_pointer_t<AbstractSensor*>>(_a[1]))); break;
        case 3: _t->onRequestAdd(); break;
        case 4: _t->onDeleteAll(); break;
        case 5: _t->onSensorDeleted(); break;
        case 6: _t->onStartSim(); break;
        case 7: _t->onInspectSensor(); break;
        case 8: _t->onDataAvailable((*reinterpret_cast< std::add_pointer_t<AbstractSensor*>>(_a[1]))); break;
        case 9: _t->onNewValue(); break;
        case 10: _t->onAddValToSensor((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 11: _t->onRequestDeleteVal((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 12: _t->onUpdateChart(); break;
        case 13: _t->onEditSensor(); break;
        case 14: _t->onCheckSensor(); break;
        case 15: _t->onRefresh((*reinterpret_cast< std::add_pointer_t<const AbstractSensor*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<std::string>>(_a[2]))); break;
        case 16: _t->onDeleteAllValues(); break;
        case 17: _t->onSaveSensors(); break;
        case 18: _t->onLoadSensors(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::editAvailable; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::editAvailable()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
