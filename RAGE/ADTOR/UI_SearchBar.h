/********************************************************************************
** Form generated from reading UI file 'UI_SearchBar.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHBAR_H
#define UI_SEARCHBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include "lister.h"

QT_BEGIN_NAMESPACE

class Ui_SearchBarBackground
{
public:
    QGridLayout *SBLayout;
    QLineEdit *SearchBar;
    Lister *widget;
    QGridLayout *gridLayout;
    QListView *listView;

    void setupUi(QFrame *SearchBarBackground)
    {
        if (SearchBarBackground->objectName().isEmpty())
            SearchBarBackground->setObjectName("SearchBarBackground");
        SearchBarBackground->resize(402, 215);
        SearchBarBackground->setStyleSheet(QString::fromUtf8("#SearchBarBackground {\n"
"	background-color: #222222;\n"
"}"));
        SearchBarBackground->setFrameShape(QFrame::StyledPanel);
        SearchBarBackground->setFrameShadow(QFrame::Plain);
        SBLayout = new QGridLayout(SearchBarBackground);
        SBLayout->setSpacing(0);
        SBLayout->setObjectName("SBLayout");
        SBLayout->setContentsMargins(6, 2, 6, 2);
        SearchBar = new QLineEdit(SearchBarBackground);
        SearchBar->setObjectName("SearchBar");
        SearchBar->setStyleSheet(QString::fromUtf8("#SearchBar\n"
"{\n"
"	background-color: #222222;\n"
"	color: #D3D3D3;\n"
"	padding-bottom: 2px;\n"
"	border-top: none;\n"
"}\n"
"\n"
"#SearchBar::focus\n"
"{\n"
"	border: 1px solid #D3D3D3;\n"
"	border-top: none;\n"
"	border-radius: 9px;\n"
"	padding-top: 1px;\n"
"}"));
        SearchBar->setAlignment(Qt::AlignCenter);

        SBLayout->addWidget(SearchBar, 0, 0, 1, 1);

        widget = new Lister(SearchBarBackground);
        widget->setObjectName("widget");
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        listView = new QListView(widget);
        listView->setObjectName("listView");
        listView->setStyleSheet(QString::fromUtf8("#listView {\n"
"	color: #D3D3D3;\n"
"	background-color: #222222;\n"
"	border: 1px solid #D3D3D3;\n"
"}"));
        listView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listView->setProperty("isWrapping", QVariant(true));
        listView->setSpacing(1);
        listView->setUniformItemSizes(true);
        listView->setBatchSize(88);
        listView->setWordWrap(true);

        gridLayout->addWidget(listView, 0, 0, 1, 1);


        SBLayout->addWidget(widget, 1, 0, 1, 1);


        retranslateUi(SearchBarBackground);

        QMetaObject::connectSlotsByName(SearchBarBackground);
    } // setupUi

    void retranslateUi(QFrame *SearchBarBackground)
    {
        SearchBarBackground->setWindowTitle(QCoreApplication::translate("SearchBarBackground", "Frame", nullptr));
        SearchBar->setText(QCoreApplication::translate("SearchBarBackground", "Editor", nullptr));
        listView->setProperty("gh", QVariant(QString()));
    } // retranslateUi

};

namespace Ui {
    class SearchBarBackground: public Ui_SearchBarBackground {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHBAR_H
