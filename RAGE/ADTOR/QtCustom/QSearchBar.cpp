/****************************************************************************
** Meta object code from reading C++ file 'QSearchBar.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "QSearchBar.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QSearchBar.h' doesn't include <QObject>."
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
    struct qt_meta_stringdata_CLASSQSearchBarENDCLASS_t {};
    constexpr auto qt_meta_stringdata_CLASSQSearchBarENDCLASS = QtMocHelpers::stringData(
        "QSearchBar",
        "onButtonClicked",
        ""
    );
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQSearchBarENDCLASS[] = {

    // content:
         12,       // revision
          0,       // classname
          0,    0, // classinfo
          1,   14, // methods
          0,    0, // properties
          0,    0, // enums/sets
          0,    0, // constructors
          0,       // flags
          0,       // signalCount

          // slots: name, argc, parameters, tag, flags, initial metatype offsets
                1,    0,   20,    2, 0x08,    1 /* Private */,

                // slots: parameters
                   QMetaType::Void,

                      0        // eod
};

Q_CONSTINIT const QMetaObject QSearchBar::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSQSearchBarENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQSearchBarENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQSearchBarENDCLASS_t,
    // Q_OBJECT / Q_GADGET
    QtPrivate::TypeAndForceComplete<QSearchBar, std::true_type>,
    // method 'onButtonClicked'
    QtPrivate::TypeAndForceComplete<void, std::false_type>
>,
nullptr
} };

void QSearchBar::qt_static_metacall(QObject* _o, QMetaObject::Call _c, int _id, void** _a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto* _t = static_cast<QSearchBar*>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onButtonClicked(); break;
        default:;
        }
    }
    (void)_a;
}

const QMetaObject* QSearchBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void* QSearchBar::qt_metacast(const char* _clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQSearchBarENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QSearchBar::qt_metacall(QMetaObject::Call _c, int _id, void** _a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType*>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP


#include <QtCore/QEvent>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QApplication>
#include "QSearchList.h"

QSearchBar::QSearchBar(QWidget* parent)
    : QWidget(parent)
{
    setupUI();
}

QSearchBar::~QSearchBar() = default;

void QSearchBar::setupUI()
{
    // Initialize search bar
    SearchButton = new QPushButton("Editor", this);
    SearchButton->setObjectName("SearchButton");
    QSizePolicy sizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(SearchButton->sizePolicy().hasHeightForWidth());
    SearchButton->setSizePolicy(sizePolicy);
    SearchButton->setStyleSheet(R"(
        QPushButton {
            background-color: #2E2E2E;
            color: #D3D3D3;
            padding: 6px 10px;
            border: 1px solid #3E3E3E;
            border-radius: 5px;
            margin: 1px 0px;
        }
    )");
    SearchButton->setCursor(Qt::IBeamCursor);

    SearchLine = new QLineEdit(this);
    SearchLine->setObjectName("SearchBar");
    SearchLine->setPlaceholderText("Type to search...");
    SearchLine->setStyleSheet(R"(
        QLineEdit {
            background-color: #2E2E2E;
            color: #D3D3D3;
            padding: 6px 10px;
            border: 1px solid #3E3E3E;
            border-radius: 5px;
        }
        QLineEdit:focus {
            padding: 6px 10px;
            border: 1px solid #FC7703;
            border-top-left-radius: 5px;
            border-top-right-radius: 5px;
            border-bottom-left-radius: 0;
            border-bottom-right-radius: 0;
            border-bottom: none;
            outline: none;
        }
    )");

    // Initialize SearchList
    SearchOptions = { "File", "Edit", "View", "Build", "Test", "Tools", "Window", "Help"};

    SearchList = new QSearchList(SearchOptions, this);
    SearchList->setMaxVisibleItems(MaxVisibleItems);

    SearchLine->setCompleter(SearchList);
    SearchPopup = SearchList->popup();

    // Set up layout
    SBLayout = new QVBoxLayout(this);
    SBLayout->setContentsMargins(0, 5, 0, 0);
    SBLayout->setSpacing(0);
    SBLayout->addWidget(SearchButton);
    SBLayout->addWidget(SearchLine);

    // Connect signals and events
    SearchLine->installEventFilter(this);
    SearchPopup->installEventFilter(this);

    setupConnections();
}

void QSearchBar::setupConnections()
{
    connect(SearchButton, &QPushButton::clicked, this, &QSearchBar::onButtonClicked);
    
    connect(SearchList, QOverload<const QString&>::of(&QCompleter::highlighted),
        this, [this](const QString& text) {
            setSearchText(text);
            activateSearch(false);
        });

    //connect(SearchList, QOverload<const QModelIndex&>::of(&QCompleter::activated),
    //    this, [this](const QModelIndex& index) {
    //        qDebug() << "Completer activated index:" << index.row();
    //    });
}

void QSearchBar::setSearchText(const QString& text)
{
    if (!text.isEmpty()) SearchText = text;
    if (SearchButton) SearchButton->setText(SearchText);
}

void QSearchBar::activateSearch(bool activate)
{
    if (activate) {
        SearchButton->hide();

        SearchLine->show();
        SearchLine->setFocus();

        //SearchListAnim->setStartValue(startRect);
        //SearchListAnim->setEndValue(endRect);

        SearchList->complete();
        //SearchListAnim->start();
    }
    else {
        SearchLine->clear();

        if (SearchList->completionMode() == QCompleter::UnfilteredPopupCompletion) SearchList->setCompletionMode(QCompleter::PopupCompletion);
        SearchList->setCompletionPrefix("");

        SearchLine->hide();

        SearchButton->show();
    }
}

void QSearchBar::onButtonClicked() {
    activateSearch(true);
}

void QSearchBar::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);

    if (SearchLine) {
        //SearchButton->setFixedWidth(SearchLine->width());
    }
}

bool QSearchBar::eventFilter(QObject* object, QEvent* event)
{
    qDebug() << object << " : " << event->type();

    if (object == SearchLine && event->type() == QEvent::MetaCall) {
        activateSearch(false);
    }

    if (object == SearchPopup && event->type() == QEvent::Hide) {
        if (SearchLine->text().isEmpty()) {
            activateSearch(false);
        }
        else if (SearchList->completionMode() == QCompleter::UnfilteredPopupCompletion
            // !!! FIX THIS !!!
            /*|| SearchList->completionCount() < SearchOptions.length()*/) {
            activateSearch(false);
        }
        else {
            SearchList->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
        }
    }
    return QWidget::eventFilter(object, event);
}