#ifndef QSEARCHBAR_H
#define QSEARCHBAR_H

#include <QtWidgets/QWidget>

class QSearchBar : public QWidget
{
    Q_OBJECT

public:
    QSearchBar(QWidget* parent = nullptr);

    ~QSearchBar();

    bool eventFilter(QObject* watched, QEvent* event) override;
    void showScrollBar();
    void hideScrollBar();

private:
    class QLineEdit* searchBar = nullptr;
    class QListView* dropdownList = nullptr;
    class QVBoxLayout* layout = nullptr;

    void setupUI();
    void setupConnections();

private slots:
    void onSearchBarFocused();
    void onSearchTextChanged(const QString& text);
};

#endif // QSEARCHBAR_H
