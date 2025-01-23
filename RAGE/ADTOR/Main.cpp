#include "UI/QtCustom/QTriangleWindow.h"

#include "Managers/ConfigManager.h"
#include "MainWindow.h"

void applyStyleSheet(QWidget* widget, const QString& filePath) {
    QFile file(filePath);
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        QString styleSheet = QLatin1String(file.readAll());
        widget->setStyleSheet(styleSheet);
        file.close();
    }
    else {
        qDebug() << "Failed to load stylesheet from" << filePath;
    }
}

int main(int argc, char* argv[]) 
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString& locale : uiLanguages) {
        const QString baseName = "RAGE_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    ConfigManager& configManager = ConfigManager::getInstance();

    MainWindow w(nullptr, configManager.isValid());
    applyStyleSheet(&w, "res/Styles/darkTheme.qss");
    w.show();

    return a.exec();
}
