#pragma once

#include <QtWidgets/QDockWidget>

class QDockWindow : public QDockWidget {
    Q_OBJECT

public:
    explicit QDockWindow(QWidget* parent = nullptr);

    ~QDockWindow();

protected:
    class QDockTitle* dockTitle = nullptr;
    class QGraphicsDropShadowEffect* shadowEffect = nullptr;

    void setupUI();
    void setupConnections();

    void addDropShadow();
    void removeDropShadow();

private slots:
    void onFloatingChanged(bool floating);
};