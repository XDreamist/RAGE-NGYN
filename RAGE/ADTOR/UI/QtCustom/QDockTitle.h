#pragma once

#include <QtWidgets/QWidget>

class QDockTitle : public QWidget {
    Q_OBJECT

public:
    explicit QDockTitle(class QDockWidget* dock = nullptr, QWidget* parent = nullptr);

    ~QDockTitle();

    void expandTitle(bool expand);

protected:
    class QDockWidget* DockWidget = nullptr;
    class QLabel* TitleLabel = nullptr;
    class QWidget* StretchWidget = nullptr;
    class QPushButton* CloseButton = nullptr;
    class QHBoxLayout* StretchLayout = nullptr;
    class QHBoxLayout* TitleLayout = nullptr;

    void setupUI();
    void setupConnections();
};