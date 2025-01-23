#pragma once

#include <QtWidgets/QWidget>

class QDockTitle : public QWidget {
    Q_OBJECT

public:
    explicit QDockTitle(class QDockWidget* dock = nullptr, QWidget* parent = nullptr);

    ~QDockTitle();

    void expandTitle(bool expand);

protected:
    class QDockWidget* dockWidget = nullptr;
    class QLabel* titleLabel = nullptr;
    class QWidget* stretchWidget = nullptr;
    class QPushButton* closeButton = nullptr;
    class QHBoxLayout* stretchLayout = nullptr;
    class QHBoxLayout* titleLayout = nullptr;

    void setupUI();
    void setupConnections();
};