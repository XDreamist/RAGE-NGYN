#pragma once

#include <QtWidgets/QMainWindow>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent, bool open_rage);

    ~MainWindow();

protected:
    bool openRage = false;
    class Ui_RAGE* ui_Rage = nullptr;
    class Ui_ProjectSelection* ui_ProjectSelect = nullptr;

    void adjustButtonSize(const QSize& screenSize);
};