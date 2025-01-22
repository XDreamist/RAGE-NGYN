#pragma once

#include <QtWidgets/QWidget>

class QSearchBar : public QWidget
{
    Q_OBJECT

public:
    explicit QSearchBar(QWidget * parent = nullptr);

    ~QSearchBar();

public:
    class QPushButton* searchButton = nullptr;
    class QLineEdit* searchLine = nullptr;
    class QSearchList* searchList = nullptr;
    class QAbstractItemView* searchPopup = nullptr;

    int maxVisibleItems = 10;

protected:
    class QVBoxLayout* sbLayout = nullptr;

    bool searchActivated = false;
    QString searchText = "Editor";
    QStringList searchOptions;

    void setupUI();
    void setupConnections();

    void activateSearch(bool activate);
    void setSearchText(const QString& text = "");

    bool eventFilter(QObject* watched, QEvent* event) override;

private slots:
    void onButtonClicked();
};
