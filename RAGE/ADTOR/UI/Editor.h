/********************************************************************************
** Form generated from reading UI file 'Editor.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef EDITOR_H
#define EDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QtCustom/QDockWindow.h"
#include "QtCustom/QRenderer.h"
#include "QtCustom/QTitleBar.h"

QT_BEGIN_NAMESPACE

class Ui_RAGE
{
public:
    QWidget *centralwidget;
    QGridLayout *CentralLayout;
    QTitleBar *TitleBar;
    QDockWindow *dockWidget_5;
    QWidget *dockWidgetContents_2;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QDockWidget *dockWidget_6;
    QWidget *dockWidgetContents_3;
    QGridLayout *gridLayout;
    QRenderer *openGLWidget;
    QDockWidget *dockWidget_7;
    QWidget *dockWidgetContents_7;

    void setupUi(QMainWindow *RAGE)
    {
        if (RAGE->objectName().isEmpty())
            RAGE->setObjectName("RAGE");
        RAGE->resize(1020, 616);
        QPalette palette;
        QBrush brush(QColor(211, 211, 211, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(25, 22, 29, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(211, 211, 211, 128));
        brush2.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush2);
#endif
        RAGE->setPalette(palette);
        QIcon icon;
        icon.addFile(QString::fromUtf8("res/Logo/RAGE.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        RAGE->setWindowIcon(icon);
        RAGE->setDockNestingEnabled(true);
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush3(QColor(34, 34, 34, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush2);
#endif
        RAGE->setProperty("DarkTheme", QVariant(palette1));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        QBrush brush4(QColor(25, 22, 29, 128));
        brush4.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        QBrush brush5(QColor(120, 120, 120, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        QBrush brush6(QColor(0, 0, 0, 128));
        brush6.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
        RAGE->setProperty("LightTheme", QVariant(palette2));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush2);
#endif
        RAGE->setProperty("RageTheme", QVariant(palette3));
        centralwidget = new QWidget(RAGE);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setProperty("RageLogo", QVariant(icon));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("res/Title/Minus.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        centralwidget->setProperty("MinusIcon", QVariant(icon1));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("res/Title/Maximize.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        centralwidget->setProperty("MaximIcon", QVariant(icon2));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("res/Title/Minimize.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        centralwidget->setProperty("MinimIcon", QVariant(icon3));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("res/Title/Close.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        centralwidget->setProperty("CloseIcon", QVariant(icon4));
        CentralLayout = new QGridLayout(centralwidget);
        CentralLayout->setSpacing(0);
        CentralLayout->setObjectName("CentralLayout");
        CentralLayout->setContentsMargins(0, 0, 0, 0);
        TitleBar = new QTitleBar(centralwidget);
        TitleBar->setObjectName("TitleBar");
        QSizePolicy sizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TitleBar->sizePolicy().hasHeightForWidth());
        TitleBar->setSizePolicy(sizePolicy);

        CentralLayout->addWidget(TitleBar, 2, 0, 1, 1, Qt::AlignTop);

        RAGE->setCentralWidget(centralwidget);
        dockWidget_5 = new QDockWindow(RAGE);
        dockWidget_5->setObjectName("dockWidget_5");
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName("dockWidgetContents_2");
        verticalLayout = new QVBoxLayout(dockWidgetContents_2);
        verticalLayout->setObjectName("verticalLayout");
        pushButton = new QPushButton(dockWidgetContents_2);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        textEdit = new QTextEdit(dockWidgetContents_2);
        textEdit->setObjectName("textEdit");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(textEdit);

        dockWidget_5->setWidget(dockWidgetContents_2);
        RAGE->addDockWidget(Qt::DockWidgetArea::TopDockWidgetArea, dockWidget_5);
        dockWidget_6 = new QDockWidget(RAGE);
        dockWidget_6->setObjectName("dockWidget_6");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(dockWidget_6->sizePolicy().hasHeightForWidth());
        dockWidget_6->setSizePolicy(sizePolicy2);
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName("dockWidgetContents_3");
        gridLayout = new QGridLayout(dockWidgetContents_3);
        gridLayout->setObjectName("gridLayout");
        openGLWidget = new QRenderer(dockWidgetContents_3);
        openGLWidget->setObjectName("openGLWidget");
        sizePolicy2.setHeightForWidth(openGLWidget->sizePolicy().hasHeightForWidth());
        openGLWidget->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(openGLWidget, 0, 0, 1, 1);

        dockWidget_6->setWidget(dockWidgetContents_3);
        RAGE->addDockWidget(Qt::DockWidgetArea::TopDockWidgetArea, dockWidget_6);
        dockWidget_7 = new QDockWidget(RAGE);
        dockWidget_7->setObjectName("dockWidget_7");
        dockWidgetContents_7 = new QWidget();
        dockWidgetContents_7->setObjectName("dockWidgetContents_7");
        dockWidget_7->setWidget(dockWidgetContents_7);
        RAGE->addDockWidget(Qt::DockWidgetArea::TopDockWidgetArea, dockWidget_7);

        retranslateUi(RAGE);

        QMetaObject::connectSlotsByName(RAGE);
    } // setupUi

    void retranslateUi(QMainWindow *RAGE)
    {
        RAGE->setWindowTitle(QCoreApplication::translate("RAGE", "RAGE", nullptr));
        dockWidget_5->setWindowTitle(QCoreApplication::translate("RAGE", "Heierarchy", nullptr));
        pushButton->setText(QCoreApplication::translate("RAGE", "PushButton", nullptr));
        dockWidget_6->setWindowTitle(QCoreApplication::translate("RAGE", "Viewport", nullptr));
        dockWidget_7->setWindowTitle(QCoreApplication::translate("RAGE", "Content Browser", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RAGE: public Ui_RAGE {};
} // namespace Ui

QT_END_NAMESPACE

#endif // EDITOR_H
