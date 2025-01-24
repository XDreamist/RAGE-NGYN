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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
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
    QTitleBar *titleBar;
    QDockWindow *browserDock;
    QWidget *browserDockContent;
    QVBoxLayout *verticalLayout;
    QListView *listView;
    QDockWindow *rendererDock;
    QWidget *rendererDockContent;
    QGridLayout *gridLayout;
    QRenderer *openGLWidget;
    QDockWindow *hierarchyDock;
    QWidget *hierarchyDockContent;
    QGridLayout *gridLayout_2;
    QListWidget *listWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *addObjButton;

    void setupUi(QMainWindow *RAGE)
    {
        if (RAGE->objectName().isEmpty())
            RAGE->setObjectName("RAGE");
        RAGE->resize(1020, 616);
        QIcon icon;
        icon.addFile(QString::fromUtf8("res/Logo/RAGE.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        RAGE->setWindowIcon(icon);
        RAGE->setDockNestingEnabled(true);
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
        titleBar = new QTitleBar(centralwidget);
        titleBar->setObjectName("titleBar");
        QSizePolicy sizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(titleBar->sizePolicy().hasHeightForWidth());
        titleBar->setSizePolicy(sizePolicy);

        CentralLayout->addWidget(titleBar, 2, 0, 1, 1, Qt::AlignTop);

        RAGE->setCentralWidget(centralwidget);
        browserDock = new QDockWindow(RAGE);
        browserDock->setObjectName("browserDock");
        browserDockContent = new QWidget();
        browserDockContent->setObjectName("browserDockContent");
        verticalLayout = new QVBoxLayout(browserDockContent);
        verticalLayout->setObjectName("verticalLayout");
        listView = new QListView(browserDockContent);
        listView->setObjectName("listView");
        listView->setViewMode(QListView::IconMode);

        verticalLayout->addWidget(listView);

        browserDock->setWidget(browserDockContent);
        RAGE->addDockWidget(Qt::DockWidgetArea::TopDockWidgetArea, browserDock);
        rendererDock = new QDockWindow(RAGE);
        rendererDock->setObjectName("rendererDock");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(rendererDock->sizePolicy().hasHeightForWidth());
        rendererDock->setSizePolicy(sizePolicy1);
        rendererDockContent = new QWidget();
        rendererDockContent->setObjectName("rendererDockContent");
        gridLayout = new QGridLayout(rendererDockContent);
        gridLayout->setObjectName("gridLayout");
        openGLWidget = new QRenderer(rendererDockContent);
        openGLWidget->setObjectName("openGLWidget");
        sizePolicy1.setHeightForWidth(openGLWidget->sizePolicy().hasHeightForWidth());
        openGLWidget->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(openGLWidget, 0, 0, 1, 1);

        rendererDock->setWidget(rendererDockContent);
        RAGE->addDockWidget(Qt::DockWidgetArea::TopDockWidgetArea, rendererDock);
        hierarchyDock = new QDockWindow(RAGE);
        hierarchyDock->setObjectName("hierarchyDock");
        hierarchyDockContent = new QWidget();
        hierarchyDockContent->setObjectName("hierarchyDockContent");
        gridLayout_2 = new QGridLayout(hierarchyDockContent);
        gridLayout_2->setObjectName("gridLayout_2");
        listWidget = new QListWidget(hierarchyDockContent);
        listWidget->setObjectName("listWidget");

        gridLayout_2->addWidget(listWidget, 1, 0, 1, 1);

        widget = new QWidget(hierarchyDockContent);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        addObjButton = new QPushButton(widget);
        addObjButton->setObjectName("addObjButton");
        addObjButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout->addWidget(addObjButton);


        gridLayout_2->addWidget(widget, 0, 0, 1, 1);

        hierarchyDock->setWidget(hierarchyDockContent);
        RAGE->addDockWidget(Qt::DockWidgetArea::TopDockWidgetArea, hierarchyDock);

        retranslateUi(RAGE);

        QMetaObject::connectSlotsByName(RAGE);
    } // setupUi

    void retranslateUi(QMainWindow *RAGE)
    {
        RAGE->setWindowTitle(QCoreApplication::translate("RAGE", "RAGE", nullptr));
        browserDock->setWindowTitle(QCoreApplication::translate("RAGE", "File Explorer", nullptr));
        rendererDock->setWindowTitle(QCoreApplication::translate("RAGE", "Viewport", nullptr));
        hierarchyDock->setWindowTitle(QCoreApplication::translate("RAGE", "Content Viewer", nullptr));
        addObjButton->setText(QCoreApplication::translate("RAGE", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RAGE: public Ui_RAGE {};
} // namespace Ui

QT_END_NAMESPACE

#endif // EDITOR_H
