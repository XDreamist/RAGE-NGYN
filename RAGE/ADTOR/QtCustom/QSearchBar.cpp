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
        "onSearchTextChanged",
        "",
        "text"
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
                1,    1,   20,    2, 0x08,    1 /* Private */,

                // slots: parameters
                   QMetaType::Void, QMetaType::QString,    3,

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
    // method 'onSearchTextChanged'
    QtPrivate::TypeAndForceComplete<void, std::false_type>,
    QtPrivate::TypeAndForceComplete<const QString&, std::false_type>
>,
nullptr
} };

void QSearchBar::qt_static_metacall(QObject* _o, QMetaObject::Call _c, int _id, void** _a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto* _t = static_cast<QSearchBar*>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onSearchTextChanged((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        default:;
        }
    }
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


#include <QtWidgets/QLabel>
#include <QtCore/QEvent>
#include <QtWidgets/QlistView>
#include <QtCore/QStringListModel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QApplication>
#include <QtCore/QPropertyAnimation>
#include <QtWidgets/QScrollBar>
#include "QSearchList.h"

QSearchBar::QSearchBar(QWidget* parent)
    : QWidget(parent)
{
    setupUI();
    setupConnections();
}

QSearchBar::~QSearchBar() = default;

void QSearchBar::setupUI()
{
    // Initialize search bar
    SearchLine = new QLineEdit(this);
    SearchLine->setObjectName("SearchBar");
    setSearchText("Editor");
    SearchLine->setPlaceholderText("Type to search...");
    SearchLine->setStyleSheet(R"(
        #SearchBar {
            background-color: #2E2E2E;
            color: #D3D3D3;
            padding: 6px 10px;
            border: 1px solid #3E3E3E;
            border-radius: 5px;
        }
        #SearchBar:focus {
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
    SearchLine->setAlignment(Qt::AlignCenter);

    // Initialize SearchList
    QStringList options = { "Editor", "File", "View", "Option 1", "Option 2", "Option 3" };

    SearchList = new CustomCompleter(options, this);
    SearchList->setCaseSensitivity(Qt::CaseInsensitive);
    SearchList->setCompletionMode(QCompleter::PopupCompletion);
    SearchList->setFilterMode(Qt::MatchContains);
    SearchLine->setCompleter(SearchList);

    SearchPopup = SearchList->popup();
    SearchPopup->setObjectName("SearchList");
    SearchPopup->setStyleSheet(R"(
        #SearchList {
            color: #F0F0F0;
            background-color: #2E2E2E;
            border: 1px solid #FC7703;
            border-top-left-radius: 0;
            border-top-right-radius: 0;
            border-bottom-left-radius: 5px;
            border-bottom-right-radius: 5px;
            border-top: 1px solid #151515;
        }
        #SearchList::item {
            padding: 4px 14px;
        }
        #SearchList::item:hover {
            background-color: #222222;
            padding: 4px 8px;
        }
        QScrollBar:vertical {
            border: none;
            background-color: #333333;
            width: 4px;
            margin: 0px 0px 0px 0px;
        }
        QScrollBar::handle:vertical {
            background-color: #555555;
            min-height: 10px;
            border-radius: 2px;
        }
        QScrollBar::handle:vertical:hover {
            background-color: #777777;
        }
        QScrollBar::sub-line:vertical, QScrollBar::add-line:vertical {
            border: none;
            background: none;
            height: 0px;
        }
        QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {
            background: none;
        }
    )");

    SearchListAnim = new QPropertyAnimation(SearchList, "geometry");
    SearchListAnim->setDuration(200);
    SearchListAnim->setEasingCurve(QEasingCurve::OutQuad);

    // Set up layout
    SBLayout = new QVBoxLayout(this);
    SBLayout->setContentsMargins(0, 5, 0, 0);
    SBLayout->setSpacing(0);
    SBLayout->addWidget(SearchLine);
    setLayout(SBLayout);

    // Connect signals and events
    SearchLine->installEventFilter(this);
    SearchPopup->installEventFilter(this);
}

void QSearchBar::setupConnections()
{
    connect(SearchLine, &QLineEdit::textChanged, this, &QSearchBar::onSearchTextChanged);
    
    connect(SearchList, QOverload<const QString&>::of(&QCompleter::highlighted),
        this, [this](const QString& text) {
            setSearchText(text);
            resetSearchLine();
        });

    //connect(SearchList, QOverload<const QModelIndex&>::of(&QCompleter::activated),
    //    this, [this](const QModelIndex& index) {
    //        qDebug() << "Completer activated index:" << index.row();
    //    });
}

void QSearchBar::setSearchText(const QString& text)
{
    if (!text.isEmpty()) SearchText = text;
    if (SearchLine) SearchLine->setText(SearchText);
}

void QSearchBar::showSearchList()
{
    if (SearchList) {
        SearchLine->blockSignals(true);
        SearchLine->clear();
        SearchLine->setAlignment(Qt::AlignLeft);
        SearchLine->blockSignals(false);

        //SearchListAnim->setStartValue(startRect);
        //SearchListAnim->setEndValue(endRect);

        SearchList->complete();
        //SearchListAnim->start();
    }
}

void QSearchBar::resetSearchLine()
{
    if (SearchLine) {
        SearchLine->blockSignals(true);
        SearchLine->setReadOnly(true);
        SearchLine->setCursor(Qt::ArrowCursor);
        SearchLine->setAlignment(Qt::AlignCenter);
        SearchLine->clearFocus();
        SearchLine->setReadOnly(false);
        SearchLine->blockSignals(false);
    }
}

void QSearchBar::onSearchTextChanged(const QString& text)
{
    if (SearchLine && text != SearchText) {
        TypedText = text;
        qDebug() << "You typed : " << text;
    }
}

bool QSearchBar::eventFilter(QObject* object, QEvent* event)
{
    qDebug() << object << " : " << event->type();

    if (object == SearchPopup && event->type() == QEvent::Show) {
        SearchActivated = true;
    }

    if (object == SearchLine && event->type() == QEvent::FocusIn) {
        showSearchList();
    }
    else if (object == SearchLine && event->type() == QEvent::FocusOut) {
        if (!SearchActivated) {
            setSearchText();
            resetSearchLine();
        }
    }
    else if (SearchPopup && event->type() == QEvent::Hide) {
        SearchActivated = false;
        if (!TypedText.isEmpty()) {
            SearchLine->setText(TypedText);
            SearchLine->setFocus();
        }
        else {
            setSearchText();
            resetSearchLine();
        }
    }
    return QWidget::eventFilter(object, event);
}