/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MainWindow.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

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

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
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
    return _id;
}
QT_WARNING_POP


#include <QtGui/QGuiApplication>
#include <QtGui/QScreen>
#include <QtCore/QSettings>
#include "Managers/LibManager.h"

#include "UI/Editor.h"
#include "UI/ProjectSelection.h"

#include <QtWidgets/QPushButton>
#include <QtWidgets/QFileSystemModel.h>
#include <QtCore/QDir>

MainWindow::MainWindow(QWidget* parent, bool open_rage) : QMainWindow(parent), openRage(open_rage)
{
    this->setWindowFlag(Qt::Window);
    //this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    setupUI();
    setupConnections();
    setupTheme();
}

MainWindow::~MainWindow()
{
    if (shouldSaveState) saveWindow();

    delete ui_Rage;
    delete ui_ProjectSelect;
}

void MainWindow::setupUI()
{
    if (openRage) {
        ui_Rage = new Ui_RAGE;
        ui_Rage->setupUi(this);

        LibManager facade("BRIDGE.dll");
        if (facade.load()) std::cout << "The dll is loaded successfully!\n";
        try {
            int result = facade.createEntity();
            qDebug() << "Created entity's id:" << result;
        }
        catch (const std::runtime_error& e) {
            qDebug() << "Error:" << e.what();
        }
        this->setMenuWidget(ui_Rage->titleBar);
        connect(ui_Rage->titleBar->rageButton, &QPushButton::clicked, this, &MainWindow::resetWindow);
        ui_Rage->listWidget->addItem("Cube");
        QFileSystemModel* model = new QFileSystemModel;
        model->setRootPath(QDir::currentPath());
        ui_Rage->listView->setModel(model);
        ui_Rage->listView->setRootIndex(model->index(QDir::currentPath()));
        //adjustButtonSize(QGuiApplication::primaryScreen()->size());

        restoreWindow();
    }
    else {
        ui_ProjectSelect = new Ui_ProjectSelector;
        ui_ProjectSelect->setupUi(this);
    }
}

void MainWindow::setupConnections()
{
}

void MainWindow::setupTheme()
{
    QFile file(theme_path);
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        QString styleSheet = QLatin1String(file.readAll());
        this->setStyleSheet(styleSheet);
        file.close();
    }
    else {
        qDebug() << "Failed to load stylesheet from : " << theme_path << "\n";
    }
}

void MainWindow::saveWindow()
{
    QSettings settings(app_name, setting_name);

    // Save geometry and state
    settings.setValue("geometry", saveGeometry());
    settings.setValue("windowState", saveState());
}

void MainWindow::restoreWindow()
{
    QSettings settings(app_name, setting_name);

    // Restore geometry and state
    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("windowState").toByteArray());
}

void MainWindow::resetWindow()
{
    QSettings settings(app_name, setting_name);

    // Reset window dock and state
    settings.clear();
    setWindowState(Qt::WindowNoState);

    shouldSaveState = false;
}

void MainWindow::adjustButtonSize(const QSize& screenSize)
{
    qreal dpiScale = QGuiApplication::primaryScreen()->devicePixelRatio();
    int buttonSize = qMax(20, screenSize.width() / 100);
    //buttonSize *= dpiScale; // Scale based on DPI

    setStyleSheet(QString(
        "QPushButton { "
        "   font-size: %2px; "
        "   width: %1px; "
        "   height: %1px; "
        "}"
    ).arg(buttonSize / 2).arg(buttonSize));
}
