#pragma once

#include <QtWidgets/QCompleter>

class QSearchList : public QCompleter {
    Q_OBJECT

public:
    explicit QSearchList(const QStringList& options, QObject* parent = nullptr);

    ~QSearchList();

protected:
    class QStringListModel* searchModel = nullptr;
    class QPropertyAnimation* searchListAnim = nullptr;

    QStringList searchOptions;

    void setupUI();
    void setupConnections();
};