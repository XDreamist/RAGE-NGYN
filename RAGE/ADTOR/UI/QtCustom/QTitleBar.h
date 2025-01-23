#pragma once

#include <QtWidgets/QWidget>

class QTitleBar : public QWidget {
    Q_OBJECT

public:
    explicit QTitleBar(QWidget* parent = nullptr);

    ~QTitleBar();

    class QPushButton* rageButton = nullptr;
    class QSearchBar* searchBar = nullptr;
    class QWidget* controlContainer = nullptr;
    class QPushButton* minimizeButton = nullptr;
    class QPushButton* maximizeButton = nullptr;
    class QPushButton* closeButton = nullptr;

protected:
    class QHBoxLayout* titleLayout = nullptr;
    class QSpacerItem* hrSpacer1 = nullptr;
    class QSpacerItem* hrSpacer2 = nullptr;
    class QHBoxLayout* controlLayout = nullptr;

    bool isDragging;
    QPoint initialDragPosition;
    QIcon rageIcon;
    QIcon minusIcon;
    QIcon maximIcon;
    QIcon minimIcon;
    QIcon closeIcon;

    void setupUI();
    void setupConnections();

    void mousePressEvent(class QMouseEvent* event) override;
    void mouseMoveEvent(class QMouseEvent* event) override;
    void mouseReleaseEvent(class QMouseEvent* event) override;
};