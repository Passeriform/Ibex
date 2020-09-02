/********************************************************************************
** Form generated from reading UI file 'WorkspacezGVaup.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef WORKSPACEZGVAUP_H
#define WORKSPACEZGVAUP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction* actionNew;
    QAction* actionOpen;
    QAction* actionSave;
    QAction* actionSave_As;
    QAction* actionCull;
    QAction* actionLoad;
    QAction* actionVertices;
    QAction* actionLoad_2;
    QAction* actionSave_2;
    QAction* actionSave_As_2;
    QAction* actionUndo;
    QAction* actionRedo;
    QWidget* centralwidget;
    QGridLayout* gridLayout;
    QVBoxLayout* windowLayout;
    QHBoxLayout* controlsLayout;
    QSpacerItem* leftControlSpacer;
    QPushButton* playWorld;
    QPushButton* pauseWorld;
    QPushButton* stopWorld;
    QSpacerItem* rightControlSpacer;
    QHBoxLayout* contentLayout;
    QVBoxLayout* contentBrowserLayout;
    QTreeView* resourcePicker;
    QGraphicsView* resourceDisplay;
    QProgressBar* progressBar;
    QVBoxLayout* engineLayout;
    QOpenGLWidget* engineDisplay;
    QVBoxLayout* engineOperationLayout_2;
    QLabel* engineOperationControlDescription;
    QHBoxLayout* engineOperationControlLayout;
    QPushButton* engineOperation1;
    QPushButton* engineOperation2;
    QPushButton* engineOperation3;
    QPushButton* engineOperation4;
    QPushButton* engineOperation5;
    QPushButton* engineOperation6;
    QPushButton* engineOperation7;
    QVBoxLayout* componentLayout;
    QToolBox* componentPallette;
    QWidget* primitives;
    QWidget* interactions;
    QListView* componentProperties;
    QMenuBar* menubar;
    QMenu* menuFile;
    QMenu* menuEdit;
    QMenu* menuModel;
    QMenu* menuWorld;
    QStatusBar* statusbar;

    void setupUi(QMainWindow* MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1044, 587);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionCull = new QAction(MainWindow);
        actionCull->setObjectName(QString::fromUtf8("actionCull"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionVertices = new QAction(MainWindow);
        actionVertices->setObjectName(QString::fromUtf8("actionVertices"));
        actionLoad_2 = new QAction(MainWindow);
        actionLoad_2->setObjectName(QString::fromUtf8("actionLoad_2"));
        actionSave_2 = new QAction(MainWindow);
        actionSave_2->setObjectName(QString::fromUtf8("actionSave_2"));
        actionSave_As_2 = new QAction(MainWindow);
        actionSave_As_2->setObjectName(QString::fromUtf8("actionSave_As_2"));
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        windowLayout = new QVBoxLayout();
        windowLayout->setObjectName(QString::fromUtf8("windowLayout"));
        controlsLayout = new QHBoxLayout();
        controlsLayout->setObjectName(QString::fromUtf8("controlsLayout"));
        leftControlSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        controlsLayout->addItem(leftControlSpacer);

        playWorld = new QPushButton(centralwidget);
        playWorld->setObjectName(QString::fromUtf8("playWorld"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(playWorld->sizePolicy().hasHeightForWidth());
        playWorld->setSizePolicy(sizePolicy1);
        playWorld->setMinimumSize(QSize(0, 0));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("Play")));
        playWorld->setIcon(icon);

        controlsLayout->addWidget(playWorld);

        pauseWorld = new QPushButton(centralwidget);
        pauseWorld->setObjectName(QString::fromUtf8("pauseWorld"));
        sizePolicy1.setHeightForWidth(pauseWorld->sizePolicy().hasHeightForWidth());
        pauseWorld->setSizePolicy(sizePolicy1);

        controlsLayout->addWidget(pauseWorld);

        stopWorld = new QPushButton(centralwidget);
        stopWorld->setObjectName(QString::fromUtf8("stopWorld"));
        sizePolicy1.setHeightForWidth(stopWorld->sizePolicy().hasHeightForWidth());
        stopWorld->setSizePolicy(sizePolicy1);
        stopWorld->setMinimumSize(QSize(0, 0));

        controlsLayout->addWidget(stopWorld);

        rightControlSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        controlsLayout->addItem(rightControlSpacer);


        windowLayout->addLayout(controlsLayout);

        contentLayout = new QHBoxLayout();
        contentLayout->setObjectName(QString::fromUtf8("contentLayout"));
        contentBrowserLayout = new QVBoxLayout();
        contentBrowserLayout->setObjectName(QString::fromUtf8("contentBrowserLayout"));
        resourcePicker = new QTreeView(centralwidget);
        resourcePicker->setObjectName(QString::fromUtf8("resourcePicker"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(resourcePicker->sizePolicy().hasHeightForWidth());
        resourcePicker->setSizePolicy(sizePolicy2);

        contentBrowserLayout->addWidget(resourcePicker);

        resourceDisplay = new QGraphicsView(centralwidget);
        resourceDisplay->setObjectName(QString::fromUtf8("resourceDisplay"));
        sizePolicy2.setHeightForWidth(resourceDisplay->sizePolicy().hasHeightForWidth());
        resourceDisplay->setSizePolicy(sizePolicy2);

        contentBrowserLayout->addWidget(resourceDisplay);

        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy3);
        progressBar->setMinimumSize(QSize(256, 0));
        progressBar->setAutoFillBackground(false);
        progressBar->setValue(24);
        progressBar->setTextVisible(false);
        progressBar->setInvertedAppearance(false);

        contentBrowserLayout->addWidget(progressBar);


        contentLayout->addLayout(contentBrowserLayout);

        engineLayout = new QVBoxLayout();
        engineLayout->setObjectName(QString::fromUtf8("engineLayout"));
        engineDisplay = new QOpenGLWidget(centralwidget);
        engineDisplay->setObjectName(QString::fromUtf8("engineDisplay"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(engineDisplay->sizePolicy().hasHeightForWidth());
        engineDisplay->setSizePolicy(sizePolicy4);

        engineLayout->addWidget(engineDisplay);

        engineOperationLayout_2 = new QVBoxLayout();
        engineOperationLayout_2->setObjectName(QString::fromUtf8("engineOperationLayout_2"));
        engineOperationControlDescription = new QLabel(centralwidget);
        engineOperationControlDescription->setObjectName(QString::fromUtf8("engineOperationControlDescription"));
        QSizePolicy sizePolicy5(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(engineOperationControlDescription->sizePolicy().hasHeightForWidth());
        engineOperationControlDescription->setSizePolicy(sizePolicy5);

        engineOperationLayout_2->addWidget(engineOperationControlDescription);

        engineOperationControlLayout = new QHBoxLayout();
        engineOperationControlLayout->setObjectName(QString::fromUtf8("engineOperationControlLayout"));
        engineOperation1 = new QPushButton(centralwidget);
        engineOperation1->setObjectName(QString::fromUtf8("engineOperation1"));
        sizePolicy1.setHeightForWidth(engineOperation1->sizePolicy().hasHeightForWidth());
        engineOperation1->setSizePolicy(sizePolicy1);

        engineOperationControlLayout->addWidget(engineOperation1);

        engineOperation2 = new QPushButton(centralwidget);
        engineOperation2->setObjectName(QString::fromUtf8("engineOperation2"));
        sizePolicy1.setHeightForWidth(engineOperation2->sizePolicy().hasHeightForWidth());
        engineOperation2->setSizePolicy(sizePolicy1);

        engineOperationControlLayout->addWidget(engineOperation2);

        engineOperation3 = new QPushButton(centralwidget);
        engineOperation3->setObjectName(QString::fromUtf8("engineOperation3"));
        sizePolicy1.setHeightForWidth(engineOperation3->sizePolicy().hasHeightForWidth());
        engineOperation3->setSizePolicy(sizePolicy1);

        engineOperationControlLayout->addWidget(engineOperation3);

        engineOperation4 = new QPushButton(centralwidget);
        engineOperation4->setObjectName(QString::fromUtf8("engineOperation4"));
        sizePolicy1.setHeightForWidth(engineOperation4->sizePolicy().hasHeightForWidth());
        engineOperation4->setSizePolicy(sizePolicy1);

        engineOperationControlLayout->addWidget(engineOperation4);

        engineOperation5 = new QPushButton(centralwidget);
        engineOperation5->setObjectName(QString::fromUtf8("engineOperation5"));
        sizePolicy1.setHeightForWidth(engineOperation5->sizePolicy().hasHeightForWidth());
        engineOperation5->setSizePolicy(sizePolicy1);

        engineOperationControlLayout->addWidget(engineOperation5);

        engineOperation6 = new QPushButton(centralwidget);
        engineOperation6->setObjectName(QString::fromUtf8("engineOperation6"));
        sizePolicy1.setHeightForWidth(engineOperation6->sizePolicy().hasHeightForWidth());
        engineOperation6->setSizePolicy(sizePolicy1);

        engineOperationControlLayout->addWidget(engineOperation6);

        engineOperation7 = new QPushButton(centralwidget);
        engineOperation7->setObjectName(QString::fromUtf8("engineOperation7"));
        sizePolicy1.setHeightForWidth(engineOperation7->sizePolicy().hasHeightForWidth());
        engineOperation7->setSizePolicy(sizePolicy1);

        engineOperationControlLayout->addWidget(engineOperation7);


        engineOperationLayout_2->addLayout(engineOperationControlLayout);


        engineLayout->addLayout(engineOperationLayout_2);


        contentLayout->addLayout(engineLayout);

        componentLayout = new QVBoxLayout();
        componentLayout->setObjectName(QString::fromUtf8("componentLayout"));
        componentPallette = new QToolBox(centralwidget);
        componentPallette->setObjectName(QString::fromUtf8("componentPallette"));
        QSizePolicy sizePolicy6(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(componentPallette->sizePolicy().hasHeightForWidth());
        componentPallette->setSizePolicy(sizePolicy6);
        componentPallette->setSizeIncrement(QSize(0, 0));
        componentPallette->setBaseSize(QSize(40, 0));
        componentPallette->setFrameShape(QFrame::NoFrame);
        primitives = new QWidget();
        primitives->setObjectName(QString::fromUtf8("primitives"));
        primitives->setGeometry(QRect(0, 0, 69, 189));
        componentPallette->addItem(primitives, QString::fromUtf8("Primitives"));
        interactions = new QWidget();
        interactions->setObjectName(QString::fromUtf8("interactions"));
        interactions->setGeometry(QRect(0, 0, 69, 189));
        componentPallette->addItem(interactions, QString::fromUtf8("Interactions"));

        componentLayout->addWidget(componentPallette);

        componentProperties = new QListView(centralwidget);
        componentProperties->setObjectName(QString::fromUtf8("componentProperties"));
        sizePolicy6.setHeightForWidth(componentProperties->sizePolicy().hasHeightForWidth());
        componentProperties->setSizePolicy(sizePolicy6);

        componentLayout->addWidget(componentProperties);


        contentLayout->addLayout(componentLayout);


        windowLayout->addLayout(contentLayout);


        gridLayout->addLayout(windowLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1044, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuModel = new QMenu(menubar);
        menuModel->setObjectName(QString::fromUtf8("menuModel"));
        menuWorld = new QMenu(menubar);
        menuWorld->setObjectName(QString::fromUtf8("menuWorld"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuModel->menuAction());
        menubar->addAction(menuWorld->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);

        retranslateUi(MainWindow);
        QObject::connect(playWorld, SIGNAL(clicked()), engineDisplay, SLOT(setFocus()));

        componentPallette->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow* MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
#if QT_CONFIG(shortcut)
        actionNew->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open...", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save...", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave_As->setText(QCoreApplication::translate("MainWindow", "Save As...", nullptr));
#if QT_CONFIG(shortcut)
        actionSave_As->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCull->setText(QCoreApplication::translate("MainWindow", "Cull", nullptr));
#if QT_CONFIG(shortcut)
        actionCull->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionLoad->setText(QCoreApplication::translate("MainWindow", "Load...", nullptr));
        actionVertices->setText(QCoreApplication::translate("MainWindow", "Vertices", nullptr));
        actionLoad_2->setText(QCoreApplication::translate("MainWindow", "Load...", nullptr));
        actionSave_2->setText(QCoreApplication::translate("MainWindow", "Save...", nullptr));
        actionSave_As_2->setText(QCoreApplication::translate("MainWindow", "Save As...", nullptr));
        actionUndo->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
#if QT_CONFIG(shortcut)
        actionUndo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRedo->setText(QCoreApplication::translate("MainWindow", "Redo", nullptr));
#if QT_CONFIG(shortcut)
        actionRedo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Y", nullptr));
#endif // QT_CONFIG(shortcut)
        playWorld->setText(QCoreApplication::translate("MainWindow", "|>", nullptr));
        pauseWorld->setText(QCoreApplication::translate("MainWindow", "||", nullptr));
        stopWorld->setText(QCoreApplication::translate("MainWindow", "[]", nullptr));
#if QT_CONFIG(tooltip)
        resourcePicker->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        engineOperationControlDescription->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        engineOperation1->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        engineOperation2->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        engineOperation3->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        engineOperation4->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        engineOperation5->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        engineOperation6->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        engineOperation7->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        componentPallette->setItemText(componentPallette->indexOf(primitives), QCoreApplication::translate("MainWindow", "Primitives", nullptr));
        componentPallette->setItemText(componentPallette->indexOf(interactions), QCoreApplication::translate("MainWindow", "Interactions", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuModel->setTitle(QCoreApplication::translate("MainWindow", "Model", nullptr));
        menuWorld->setTitle(QCoreApplication::translate("MainWindow", "World", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow : public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // WORKSPACEZGVAUP_H
