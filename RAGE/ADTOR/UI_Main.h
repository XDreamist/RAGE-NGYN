/********************************************************************************
** Form generated from reading UI file 'UI_Main.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_H
#define UI_MAIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "QtCustom/QSearchBar.h"

QT_BEGIN_NAMESPACE

class Ui_RAGE
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QWidget *TitleBar;
    QHBoxLayout *horizontalLayout;
    QPushButton *RAGE_Logo;
    QSpacerItem *HRSpacer1;
    QSearchBar *SearchBar;
    QSpacerItem *HRSpacer2;
    QWidget *ContentArea;

    void setupUi(QMainWindow *RAGE)
    {
        if (RAGE->objectName().isEmpty())
            RAGE->setObjectName("RAGE");
        RAGE->resize(787, 582);
        QIcon icon;
        icon.addFile(QString::fromUtf8("res/Logo/RAGE.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        RAGE->setWindowIcon(icon);
        RAGE->setStyleSheet(QString::fromUtf8("#RAGE\n"
"{\n"
"	background-color: #222222;\n"
"	color: #D3D3D3;\n"
"}"));
        centralwidget = new QWidget(RAGE);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        TitleBar = new QWidget(centralwidget);
        TitleBar->setObjectName("TitleBar");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TitleBar->sizePolicy().hasHeightForWidth());
        TitleBar->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(TitleBar);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(2, 0, 0, 0);
        RAGE_Logo = new QPushButton(TitleBar);
        RAGE_Logo->setObjectName("RAGE_Logo");
        RAGE_Logo->setIcon(icon);
        RAGE_Logo->setIconSize(QSize(18, 18));
        RAGE_Logo->setFlat(true);

        horizontalLayout->addWidget(RAGE_Logo);

        HRSpacer1 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(HRSpacer1);

        SearchBar = new QSearchBar(TitleBar);
        SearchBar->setObjectName("SearchBar");

        horizontalLayout->addWidget(SearchBar);

        HRSpacer2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(HRSpacer2);


        gridLayout->addWidget(TitleBar, 2, 0, 1, 1);

        ContentArea = new QWidget(centralwidget);
        ContentArea->setObjectName("ContentArea");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(ContentArea->sizePolicy().hasHeightForWidth());
        ContentArea->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(ContentArea, 3, 0, 1, 1);

        RAGE->setCentralWidget(centralwidget);

        retranslateUi(RAGE);

        QMetaObject::connectSlotsByName(RAGE);
    } // setupUi

    void retranslateUi(QMainWindow *RAGE)
    {
        RAGE->setWindowTitle(QCoreApplication::translate("RAGE", "RAGE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RAGE: public Ui_RAGE {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_H
