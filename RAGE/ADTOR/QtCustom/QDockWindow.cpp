﻿/****************************************************************************
** Meta object code from reading C++ file 'QDockWindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "QDockWindow.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QDockWindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSQDockWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSQDockWindowENDCLASS = QtMocHelpers::stringData(
    "QDockWindow",
    "onFloatingChanged",
    "",
    "floating"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQDockWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x08,    1 /* Private */,
       4,    0,   41,    2, 0x08,    3 /* Private */,
       5,    0,   42,    2, 0x08,    4 /* Private */,
       6,    0,   43,    2, 0x08,    5 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject QDockWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDockWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSQDockWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQDockWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQDockWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QDockWindow, std::true_type>,
        // method 'onFloatingChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'onMinimizeClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onMaximizeClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onCloseClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void QDockWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QDockWindow*>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onFloatingChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject * QDockWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void * QDockWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQDockWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDockWidget::qt_metacast(_clname);
}

int QDockWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP


#include "QDockTitle.h"
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QGraphicsDropShadowEffect>

QDockWindow::QDockWindow(QWidget* parent) : QDockWidget(parent), ShadowEffect(nullptr)
{
    setupUI();
}

QDockWindow::~QDockWindow() {
    delete ShadowEffect;
}

void QDockWindow::setupUI()
{
    this->setStyleSheet(QString::fromUtf8(
        "QDockWidget {\n"
        "   background-color: #222222;\n"
        "   border: 5px solid transparent;\n"
        "}\n"
        "QDockWidget > QWidget {\n"
        "   background-color: #222222;\n"
        "   border-radius: 8px;\n"
        "   border-top-left-radius: 0px;\n"
        "}"));

    DockTitle = new QDockTitle(this);

    this->setAttribute(Qt::WA_TranslucentBackground);

    setupConnections();
}

void QDockWindow::setupConnections()
{
    connect(this, &QDockWidget::topLevelChanged, this, &QDockWindow::onFloatingChanged);
}

void QDockWindow::onFloatingChanged(bool floating) {
    if (floating) {
        this->setStyleSheet(QString::fromUtf8(
            "QDockWidget {\n"
            "   background-color: #222222;\n"
            "   border: 5px solid transparent;\n"
            "}\n"
            "QDockWidget > QWidget {\n"
            "   background-color: #222222;\n"
            "   border-radius: 8px;\n"
            "   border-top-left-radius: 0px;\n"
            "   border-top-right-radius: 0px;\n"
            "}"));
        DockTitle->expandTitle(true);
        addDropShadow();
    }
    else {
        this->setStyleSheet(QString::fromUtf8(
            "QDockWidget {\n"
            "   background-color: #222222;\n"
            "   border: 5px solid transparent;\n"
            "}\n"
            "QDockWidget > QWidget {\n"
            "   background-color: #222222;\n"
            "   border-radius: 8px;\n"
            "   border-top-left-radius: 0px;\n"
            "}"));
        removeDropShadow();
        DockTitle->expandTitle(false);
    }
}

void QDockWindow::addDropShadow() {
    if (!ShadowEffect) {
        ShadowEffect = new QGraphicsDropShadowEffect(this->topLevelWidget());
    }
    ShadowEffect->setBlurRadius(30);
    ShadowEffect->setOffset(0, 5);
    ShadowEffect->setColor(QColor(0, 0, 0, 60));
    this->widget()->setGraphicsEffect(ShadowEffect);
}

void QDockWindow::removeDropShadow() {
    delete ShadowEffect;
    ShadowEffect = nullptr;
}