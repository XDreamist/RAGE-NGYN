#pragma once

#include <QtWidgets/QWidget>

class QSearchBar : public QWidget
{
    Q_OBJECT

public:
    explicit QSearchBar(QWidget * parent = nullptr);

    ~QSearchBar();

public:
    class QPushButton* SearchButton = nullptr;
    class QLineEdit* SearchLine = nullptr;
    class QSearchList* SearchList = nullptr;
    class QAbstractItemView* SearchPopup = nullptr;

    int MaxVisibleItems = 10;

protected:
    class QVBoxLayout* SBLayout = nullptr;

    bool SearchActivated = false;
    QString SearchText = "Editor";
    QStringList SearchOptions;

    void setupUI();
    void setupConnections();

    void activateSearch(bool activate);
    void setSearchText(const QString& text = "");

    bool eventFilter(QObject* watched, QEvent* event) override;

private slots:
    void onButtonClicked();
};
