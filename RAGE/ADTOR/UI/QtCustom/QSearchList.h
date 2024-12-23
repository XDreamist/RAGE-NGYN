#pragma once

#include <QtWidgets/QCompleter>

class QSearchList : public QCompleter {
    Q_OBJECT

public:
    explicit QSearchList(const QStringList& options, QObject* parent = nullptr);

    ~QSearchList();

protected:
    class QStringListModel* SearchModel = nullptr;
    class QPropertyAnimation* SearchListAnim = nullptr;

    QStringList SearchOptions;

    void setupUI();
};