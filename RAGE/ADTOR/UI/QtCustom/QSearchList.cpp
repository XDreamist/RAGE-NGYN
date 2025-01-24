/****************************************************************************
** Meta object code from reading C++ file 'QSearchList.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "QSearchList.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QSearchList.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSQSearchListENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSQSearchListENDCLASS = QtMocHelpers::stringData(
    "QSearchList"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQSearchListENDCLASS[] = {

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

Q_CONSTINIT const QMetaObject QSearchList::staticMetaObject = { {
    QMetaObject::SuperData::link<QCompleter::staticMetaObject>(),
    qt_meta_stringdata_CLASSQSearchListENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQSearchListENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQSearchListENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QSearchList, std::true_type>
    >,
    nullptr
} };

void QSearchList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *QSearchList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSearchList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQSearchListENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QCompleter::qt_metacast(_clname);
}

int QSearchList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QCompleter::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP


#include <QtWidgets/QAbstractItemView>
#include <QtCore/QStringListModel>
#include <QtCore/QPropertyAnimation>

QSearchList::QSearchList(const QStringList& options, QObject* parent)
    : QCompleter(parent),
    searchOptions(options),
    searchModel(new QStringListModel(options, this)),
    searchListAnim(nullptr)
{
    setModel(searchModel);
    setCaseSensitivity(Qt::CaseInsensitive);
    setCompletionMode(QCompleter::PopupCompletion);
    setFilterMode(Qt::MatchContains);

    setupUI();
    setupConnections();
}

QSearchList::~QSearchList() = default;

void QSearchList::setupUI()
{
    QAbstractItemView* searchPopup = popup();
    searchPopup->setObjectName("searchPopup");
    searchPopup->setStyleSheet(R"(
        QAbstractItemView {
            color: #D3D3D3;
            background-color: #2E2E2E;
            border: 1px solid #FC7703;
            border-top-left-radius: 0;
            border-top-right-radius: 0;
            border-bottom-left-radius: 5px;
            border-bottom-right-radius: 5px;
            border-top: 1px solid #151515;
        }
        QAbstractItemView::item {
            padding: 4px 14px;
        }
        QAbstractItemView::item:hover {
            background-color: #222222;
            padding: 4px 8px;
        }
        QAbstractItemView::item:selected {
            background-color: #000000;
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

    searchListAnim = new QPropertyAnimation(this, "geometry");
    searchListAnim->setDuration(200);
    searchListAnim->setEasingCurve(QEasingCurve::OutQuad);
}

void QSearchList::setupConnections()
{
}
