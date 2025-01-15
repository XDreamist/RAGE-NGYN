#pragma once

#include <QtWidgets/QMainWindow>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr, bool open_rage = false);

    ~MainWindow();

protected:
    bool openRage = false;
    class Ui_RAGE* ui_Rage = nullptr;
    class Ui_ProjectSelector* ui_ProjectSelect = nullptr;

    const char* app_name = "Rage";
    const char* setting_name = "windowSetting";

    void saveWindow();
    void restoreWindow();
    void resetWindow();

    void adjustButtonSize(const QSize& screenSize);
};