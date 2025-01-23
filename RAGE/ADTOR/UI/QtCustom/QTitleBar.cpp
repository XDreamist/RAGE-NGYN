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

QTitleBar::QTitleBar(QWidget* parent)
    : QWidget(parent),
    isDragging(false)
{
    auto loadIcon = [parent](const QString& propertyName) -> QIcon {
        QVariant iconData = parent->property(propertyName.toUtf8());
        return iconData.isValid() ? iconData.value<QIcon>() : QIcon();
        };

    rageIcon = loadIcon("RageLogo");
    minusIcon = loadIcon("MinusIcon");
    maximIcon = loadIcon("MaximIcon");
    minimIcon = loadIcon("MinimIcon");
    closeIcon = loadIcon("CloseIcon");

    setupUI();
    setupConnections();
}

QTitleBar::~QTitleBar() = default;

void QTitleBar::setupUI()
{
    titleLayout = new QHBoxLayout(this);
    titleLayout->setSpacing(0);
    titleLayout->setContentsMargins(0, 0, 0, 0);

    rageButton = new QPushButton(this);
    rageButton->setObjectName("rageButton");
    rageButton->setIcon(rageIcon);
    rageButton->setIconSize(QSize(20, 20));

    hrSpacer1 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);
    searchBar = new QSearchBar(this);
    hrSpacer2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

    controlContainer = new QWidget(this);
    controlContainer->setObjectName("controlContainer");
    controlLayout = new QHBoxLayout(controlContainer);
    controlLayout->setContentsMargins(0, 0, 0, 0);
    controlLayout->setSpacing(0);

    minimizeButton = new QPushButton(controlContainer);
    minimizeButton->setObjectName("minimizeButton");
    minimizeButton->setIcon(minusIcon);
    minimizeButton->setIconSize(QSize(28, 28));

    maximizeButton = new QPushButton(controlContainer);
    maximizeButton->setObjectName("maximizeButton");
    maximizeButton->setIcon(maximIcon);
    maximizeButton->setIconSize(QSize(28, 28));

    closeButton = new QPushButton(controlContainer);
    closeButton->setObjectName("closeButton");
    closeButton->setIcon(closeIcon);
    closeButton->setIconSize(QSize(28, 28));

    controlLayout->addWidget(minimizeButton);
    controlLayout->addWidget(maximizeButton);
    controlLayout->addWidget(closeButton);

    titleLayout->addWidget(rageButton);
    titleLayout->addItem(hrSpacer1);
    titleLayout->addWidget(searchBar);
    titleLayout->addItem(hrSpacer2);
    titleLayout->addWidget(controlContainer);
}

void QTitleBar::setupConnections()
{
    auto parentWindow = [this]() { return parentWidget() ? parentWidget()->window() : nullptr; };

    connect(minimizeButton, &QPushButton::clicked, this, [parentWindow] {
        if (auto window = parentWindow()) window->showMinimized();
        });

    connect(maximizeButton, &QPushButton::clicked, this, [this, parentWindow] {
        if (auto window = parentWindow()) {
            if (window->isMaximized()) {
                window->showNormal();
                maximizeButton->setIcon(maximIcon);
            }
            else {
                window->showMaximized();
                maximizeButton->setIcon(minimIcon);
            }
        }
        });

    connect(closeButton, &QPushButton::clicked, this, [parentWindow] {
        if (auto window = parentWindow()) window->close();
        });
}

void QTitleBar::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        isDragging = true;
        initialDragPosition = event->globalPosition().toPoint() - parentWidget()->frameGeometry().topLeft();
        event->accept();
    }
}

void QTitleBar::mouseMoveEvent(QMouseEvent* event) {
    if (isDragging && (event->buttons() & Qt::LeftButton)) {
        if (auto parent = parentWidget()) {
            parent->move(event->globalPosition().toPoint() - initialDragPosition);
        }
        event->accept();
    }
}

void QTitleBar::mouseReleaseEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        isDragging = false;
        event->accept();
    }
}