#pragma once

#ifndef QSEARCHBAR_H
#define QSEARCHBAR_H

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

protected:
    class QVBoxLayout* SBLayout = nullptr;

    bool SearchActivated = false;
    QString SearchText = "Editor";
    QStringList SearchOptions;

    void setupUI();
    void setupConnections();

    void setSearchText(const QString& text = "");
    void activateSearch(bool activate);

    void resizeEvent(QResizeEvent* event);
    bool eventFilter(QObject* watched, QEvent* event) override;

private slots:
    void onButtonClicked();
};

#endif // QSEARCHBAR_H
