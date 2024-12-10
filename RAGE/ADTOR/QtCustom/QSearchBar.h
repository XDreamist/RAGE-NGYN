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

private:
    bool SearchActivated = false;
    QString TypedText = "";
    QString SearchText = "Editor";
    QStringList SearchOptions;

    class QLineEdit* SearchLine = nullptr;
    class QCompleter* SearchList = nullptr;
    class QAbstractItemView* SearchPopup = nullptr;
    class QVBoxLayout* SBLayout = nullptr;

    class QPropertyAnimation* SearchListAnim = nullptr;

    void setupUI();
    void setupConnections();

    void setSearchText(const QString& text = "");
    void showSearchList();
    void resetSearchLine();

    bool eventFilter(QObject* watched, QEvent* event) override;

private slots:
    void onSearchTextChanged(const QString& text);
};

#endif // QSEARCHBAR_H
