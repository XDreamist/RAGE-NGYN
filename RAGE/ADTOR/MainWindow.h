#pragma once

#include <QtWidgets/QMainWindow>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr, bool open_rage = false);

    ~MainWindow();

protected:
    bool OpenRage = false;
    class Ui_RAGE* ui_Rage = nullptr;
    class Ui_ProjectSelector* ui_ProjectSelect = nullptr;

    void adjustButtonSize(const QSize& screenSize);
};