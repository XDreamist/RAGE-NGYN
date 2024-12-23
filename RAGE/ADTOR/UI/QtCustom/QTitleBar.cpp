/****************************************************************************
** Meta object code from reading C++ file 'QTitleBar.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "QTitleBar.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QTitleBar.h' doesn't include <QObject>."
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
    struct qt_meta_stringdata_CLASSQTitleBarENDCLASS_t {};
    constexpr auto qt_meta_stringdata_CLASSQTitleBarENDCLASS = QtMocHelpers::stringData(
        "QTitleBar"
    );
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQTitleBarENDCLASS[] = {

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

Q_CONSTINIT const QMetaObject QTitleBar::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSQTitleBarENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQTitleBarENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQTitleBarENDCLASS_t,
    // Q_OBJECT / Q_GADGET
    QtPrivate::TypeAndForceComplete<QTitleBar, std::true_type>
>,
nullptr
} };

void QTitleBar::qt_static_metacall(QObject* _o, QMetaObject::Call _c, int _id, void** _a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject* QTitleBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void* QTitleBar::qt_metacast(const char* _clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQTitleBarENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QTitleBar::qt_metacall(QMetaObject::Call _c, int _id, void** _a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP


#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtGui/QMouseEvent>
#include "QSearchBar.h"

QTitleBar::QTitleBar(QWidget* parent) : QWidget(parent)
{
    QVariant icon_data = parent->property("RageLogo");
    if (icon_data.isValid()) RageIcon = icon_data.value<QIcon>();

    QVariant icon_data1 = parent->property("MinusIcon");
    if (icon_data1.isValid()) MinusIcon = icon_data1.value<QIcon>();

    QVariant icon_data2 = parent->property("MaximIcon");
    if (icon_data2.isValid()) MaximIcon = icon_data2.value<QIcon>();

    QVariant icon_data3 = parent->property("MinimIcon");
    if (icon_data3.isValid()) MinimIcon = icon_data3.value<QIcon>();

    QVariant icon_data4 = parent->property("CloseIcon");
    if (icon_data4.isValid()) CloseIcon = icon_data4.value<QIcon>();

    setupUI();
}

QTitleBar::~QTitleBar() = default;

void QTitleBar::setupUI()
{
    TitleLayout = new QHBoxLayout(this);
    TitleLayout->setSpacing(0);
    TitleLayout->setObjectName("TitleLayout");
    TitleLayout->setContentsMargins(0, 0, 0, 0);

    RAGE_Logo = new QPushButton(this);
    RAGE_Logo->setObjectName("RAGE_Logo");
    RAGE_Logo->setStyleSheet(QString::fromUtf8("QPushButton {\n"
        "	border: none;\n"
        "	margin-left: 5px;\n"
        "}"));
    RAGE_Logo->setIcon(RageIcon);
    RAGE_Logo->setIconSize(QSize(20, 20));

    HRSpacer1 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);
    SearchBar = new QSearchBar(this);
    HRSpacer2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

    ControlContainer = new QWidget(this);
    ControlContainer->setStyleSheet(QString::fromUtf8("QPushButton {\n"
        "   /*background-color: #FC7703;*/\n"
        "   border: none;\n"
        "   padding: 3px 7px;\n"
        "}"));
    ControlLayout = new QHBoxLayout(ControlContainer);
    ControlLayout->setContentsMargins(0, 0, 0, 0);
    ControlLayout->setSpacing(0);

    MinimizeButton = new QPushButton(ControlContainer);
    MinimizeButton->setIcon(MinusIcon);
    MinimizeButton->setIconSize(QSize(28, 28));

    MaximizeButton = new QPushButton(ControlContainer);
    MaximizeButton->setIcon(MaximIcon);
    MaximizeButton->setIconSize(QSize(28, 28));

    CloseButton = new QPushButton(ControlContainer);
    CloseButton->setIcon(CloseIcon);
    CloseButton->setIconSize(QSize(28, 28));
    CloseButton->setStyleSheet("QPushButton:hover { background-color: #EA3416; }");

    ControlLayout->addWidget(MinimizeButton);
    ControlLayout->addWidget(MaximizeButton);
    ControlLayout->addWidget(CloseButton);

    TitleLayout->addWidget(RAGE_Logo);
    TitleLayout->addItem(HRSpacer1);
    TitleLayout->addWidget(SearchBar);
    TitleLayout->addItem(HRSpacer2);
    TitleLayout->addWidget(ControlContainer);

    setupConnections();
}

void QTitleBar::setupConnections()
{
    connect(MinimizeButton, &QPushButton::clicked, this, [this] {
        if (parentWidget() && parentWidget()->window())
            parentWidget()->window()->showMinimized();
    });

    connect(MaximizeButton, &QPushButton::clicked, this, [this] {
        if (parentWidget() && parentWidget()->window()) {
            if (parentWidget()->window()->isMaximized()) {
                parentWidget()->window()->showNormal();
                MaximizeButton->setIcon(MaximIcon);
            }
            else
            {
                parentWidget()->window()->showMaximized();
                MaximizeButton->setIcon(MinimIcon);
            }
        }
    });

    connect(CloseButton, &QPushButton::clicked, this, [this] {
        if (parentWidget() && parentWidget()->window())
            parentWidget()->window()->close();
    });
}

void QTitleBar::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        isDragging = true;
        dragStartPosition = event->globalPosition().toPoint() - parentWidget()->frameGeometry().topLeft();
        event->accept();
    }
}

void QTitleBar::mouseMoveEvent(QMouseEvent* event) {
    if (isDragging && (event->buttons() & Qt::LeftButton)) {
        parentWidget()->move(event->globalPosition().toPoint() - dragStartPosition);
        event->accept();
    }
}

void QTitleBar::mouseReleaseEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        isDragging = false;
        event->accept();
    }
}