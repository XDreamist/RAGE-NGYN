#pragma once

#include <QtWidgets/QDockWidget>

class QDockWindow : public QDockWidget {
    Q_OBJECT

public:
    explicit QDockWindow(QWidget* parent = nullptr);

    ~QDockWindow();

protected:
    class QDockTitle* DockTitle = nullptr;
    class QGraphicsDropShadowEffect* ShadowEffect = nullptr;

    void setupUI();
    void setupConnections();

    void addDropShadow();
    void removeDropShadow();

private slots:
    void onFloatingChanged(bool floating);
};