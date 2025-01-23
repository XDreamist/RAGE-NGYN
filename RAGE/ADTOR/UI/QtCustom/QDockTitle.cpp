/****************************************************************************
** Meta object code from reading C++ file 'QDockTitle.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "QDockTitle.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QDockTitle.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSQDockTitleENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSQDockTitleENDCLASS = QtMocHelpers::stringData(
    "QDockTitle"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQDockTitleENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

Q_CONSTINIT const QMetaObject QDockTitle::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSQDockTitleENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQDockTitleENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQDockTitleENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QDockTitle, std::true_type>
    >,
    nullptr
} };

void QDockTitle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *QDockTitle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QDockTitle::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQDockTitleENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QDockTitle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP


#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QStyle>

QDockTitle::QDockTitle(QDockWidget* dock, QWidget* parent)
    : dockWidget(dock),
    QWidget(parent)
{
    setupUI();
    setupConnections();
}

QDockTitle::~QDockTitle() = default;

void QDockTitle::setupUI()
{
    titleLabel = new QLabel("", this);
    titleLabel->setStyleSheet(QString::fromUtf8(
        "   background-color: #222222;\n"
        "   color: #D3D3D3;\n"
        "   padding: 4px 8px;\n"
        "   border-top-left-radius: 5px;\n"
        "   border-top-right-radius: 5px;\n"
        "   border-bottom-left-radius: 0;\n"
        "   border-bottom-right-radius: 0;\n"));

    stretchWidget = new QWidget(this);
    stretchWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    stretchWidget->setStyleSheet("background: none; border-top-right-radius: 5px;");

    closeButton = new QPushButton(stretchWidget);
    closeButton->setIcon(style()->standardIcon(QStyle::SP_TitleBarCloseButton));
    closeButton->setFixedSize(9, 9);
    closeButton->setStyleSheet(QString::fromUtf8(
        "   color: #D3D3D3;\n"
        "   border: none;\n"));
    closeButton->hide();

    stretchLayout = new QHBoxLayout(stretchWidget);
    stretchLayout->addStretch();
    stretchLayout->addWidget(closeButton);

    titleLayout = new QHBoxLayout(this);
    titleLayout->setContentsMargins(0, 0, 0, 0);
    titleLayout->setSpacing(0);
    titleLayout->addWidget(titleLabel);
    titleLayout->addWidget(stretchWidget);
}

void QDockTitle::expandTitle(bool expand)
{
    if (expand) {
        titleLabel->setStyleSheet(QString::fromUtf8(
            "   background-color: #222222;\n"
            "   color: #D3D3D3;\n"
            "   padding: 4px 8px;\n"
            "   border-top-left-radius: 5px;\n"
            "   border-top-right-radius: 0px;\n"
            "   border-bottom-left-radius: 0;\n"
            "   border-bottom-right-radius: 0;\n"));
        stretchWidget->setStyleSheet("background: #222222; border-top-right-radius: 5px;");
        closeButton->show();
    }
    else {
        titleLabel->setStyleSheet(QString::fromUtf8(
            "   background-color: #222222;\n"
            "   color: #D3D3D3;\n"
            "   padding: 4px 8px;\n"
            "   border-top-left-radius: 5px;\n"
            "   border-top-right-radius: 5px;\n"
            "   border-bottom-left-radius: 0;\n"
            "   border-bottom-right-radius: 0;\n"));
        stretchWidget->setStyleSheet("background: none; border-top-right-radius: 5px;");
        closeButton->hide();
    }
}

void QDockTitle::setupConnections()
{
    connect(dockWidget, &QDockWidget::windowTitleChanged, titleLabel, &QLabel::setText);

    connect(closeButton, &QPushButton::clicked, dockWidget, &QDockWidget::close);
}