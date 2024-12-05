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
        "onSearchBarFocused",
        "",
        "onSearchTextChanged",
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
          2,   14, // methods
          0,    0, // properties
          0,    0, // enums/sets
          0,    0, // constructors
          0,       // flags
          0,       // signalCount

          // slots: name, argc, parameters, tag, flags, initial metatype offsets
                1,    0,   26,    2, 0x08,    1 /* Private */,
                3,    1,   27,    2, 0x08,    2 /* Private */,

                // slots: parameters
                   QMetaType::Void,
                   QMetaType::Void, QMetaType::QString,    4,

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
    // method 'onSearchBarFocused'
    QtPrivate::TypeAndForceComplete<void, std::false_type>,
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
        case 0: _t->onSearchBarFocused(); break;
        case 1: _t->onSearchTextChanged((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
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
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType*>(_a[0]) = QMetaType();
        _id -= 2;
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

QSearchBar::QSearchBar(QWidget* parent)
    : QWidget(parent), layout(new QVBoxLayout(this)), dropdownList(new QListView(this))
{
    setupUI();
    setupConnections();
}

QSearchBar::~QSearchBar() = default;

void QSearchBar::onSearchBarFocused()
{
    showScrollBar();
}

void QSearchBar::setupUI()
{
    searchBar = new QLineEdit(this);
    searchBar->setObjectName("SearchBar");
    //searchBar->setPlaceholderText("Search...");
    searchBar->setStyleSheet(QString::fromUtf8("#SearchBar\n"
        "{\n"
        "	background-color: #222222;\n"
        "	color: #D3D3D3;\n"
        "	padding-bottom: 2px;\n"
        "	border-top: none;\n"
        "}\n"
        "\n"
        "#SearchBar::focus\n"
        "{\n"
        "	border: 1px solid #D3D3D3;\n"
        "	border-top: none;\n"
        "	border-radius: 9px;\n"
        "	padding-top: 1px;\n"
        "}"));
    searchBar->setFrame(false);
    searchBar->setAlignment(Qt::AlignCenter);
    searchBar->setDragEnabled(true);
    searchBar->setText(QCoreApplication::translate("RAGE", "Editor", nullptr));

    dropdownList->setObjectName("DropDownList");
    dropdownList->setStyleSheet("background-color: #333333;");
    //dropdownList->setWidgetResizable(true);
    dropdownList->hide();

    layout->addWidget(searchBar);
    layout->addWidget(dropdownList);
    setLayout(layout);

    searchBar->installEventFilter(this);
}

void QSearchBar::setupConnections()
{
    connect(searchBar, &QLineEdit::textChanged, this, &QSearchBar::onSearchTextChanged);

    connect(searchBar, &QLineEdit::cursorPositionChanged, this, &QSearchBar::onSearchBarFocused);
}

// Override eventFilter to capture focus events
bool QSearchBar::eventFilter(QObject* watched, QEvent* event)
{
    // Check if the event is related to the searchBar
    if (watched == searchBar) {
        if (event->type() == QEvent::FocusIn) {
            // Show the dropdown when the search bar gains focus
            showScrollBar();
        }
        else if (event->type() == QEvent::FocusOut) {
            // Hide the dropdown when the search bar loses focus
            hideScrollBar();
        }
    }
    // Pass the event to the base class implementation
    return QWidget::eventFilter(watched, event);
}

void QSearchBar::showScrollBar()
{
    // Example of showing a dropdown (QListView)
    if (dropdownList) {
        dropdownList->setModel(new QStringListModel({ "Option 1", "Option 2", "Option 3"}));
        dropdownList->setGeometry(searchBar->x(),
            searchBar->y() + 2 * searchBar->height(),
            searchBar->width(),
            200);
        dropdownList->show();
    }
}

void QSearchBar::hideScrollBar()
{
    if (dropdownList) {
        dropdownList->hide();
    }
}

void QSearchBar::onSearchTextChanged(const QString& text)
{
    // Filter dropdown suggestions based on the text
    if (dropdownList) {
        QStringList suggestions = { "Option 1", "Option 2", "Option 3" };
        QStringList filteredSuggestions;

        for (const QString& option : suggestions) {
            if (option.contains(text, Qt::CaseInsensitive)) {
                filteredSuggestions.append(option);
            }
        }

        auto* model = static_cast<QStringListModel*>(dropdownList->model());
        model->setStringList(filteredSuggestions);
    }
}