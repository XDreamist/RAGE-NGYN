#pragma once

#include <QtWidgets/QWidget>

class QTitleBar : public QWidget {
    Q_OBJECT

public:
    explicit QTitleBar(QWidget* parent = nullptr);

    ~QTitleBar();

    class QPushButton* RAGE_Logo = nullptr;
    class QSearchBar* SearchBar = nullptr;
    class QWidget* ControlContainer = nullptr;
    class QPushButton* MinimizeButton = nullptr;
    class QPushButton* MaximizeButton = nullptr;
    class QPushButton* CloseButton = nullptr;

protected:
    class QHBoxLayout* TitleLayout = nullptr;
    class QSpacerItem* HRSpacer1 = nullptr;
    class QSpacerItem* HRSpacer2 = nullptr;
    class QHBoxLayout* ControlLayout = nullptr;

    bool isDragging;
    QPoint dragStartPosition;
    QIcon RageIcon;
    QIcon MinusIcon;
    QIcon MaximIcon;
    QIcon MinimIcon;
    QIcon CloseIcon;

    void setupUI();
    void setupConnections();

    void mousePressEvent(class QMouseEvent* event) override;
    void mouseMoveEvent(class QMouseEvent* event) override;
    void mouseReleaseEvent(class QMouseEvent* event) override;
};