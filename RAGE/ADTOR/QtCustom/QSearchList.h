#pragma once

#include <QtWidgets/QCompleter>
#include <QtCore/QStringListModel>
#include <QtCore/QEvent>
#include <QtWidgets/QAbstractItemView>
#include <QtWidgets/QLineEdit>

class CustomCompleter : public QCompleter {
    Q_OBJECT

public:
    explicit CustomCompleter(const QStringList& options, QObject* parent = nullptr)
        : QCompleter(parent) {
        QStringListModel* model = new QStringListModel(options, this);
        setModel(model);
        setCaseSensitivity(Qt::CaseInsensitive);
        setCompletionMode(QCompleter::PopupCompletion);
        setFilterMode(Qt::MatchContains);

        if (popup()) {
            popup()->installEventFilter(this);
        }
    }

protected:
    bool eventFilter(QObject* watched, QEvent* event) override {
        if (watched == popup() && event->type() == QEvent::Hide) {
            // Ensure the focus stays on the line edit
            if (QWidget* widget = this->widget()) {
                if (QLineEdit* lineEdit = qobject_cast<QLineEdit*>(widget)) {
                    //lineEdit->setFocus();
                }
            }
        }
        return QCompleter::eventFilter(watched, event);
    }
};