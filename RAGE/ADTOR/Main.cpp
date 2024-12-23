#include "UI/QtCustom/QTriangleWindow.h"

#include "Managers/ConfigManager.h"
#include "MainWindow.h"

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
    w.show();

    return a.exec();
}
