/********************************************************************************
** Form generated from reading UI file 'SideBySideRenderWindowsQt1.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIDEBYSIDERENDERWINDOWSQT1_H
#define UI_SIDEBYSIDERENDERWINDOWSQT1_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QSlider>
#include <QtGui/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_SideBySideRenderWindowsQt
{
public:
    QAction *actionOpenFile;
    QAction *actionExit;
    QAction *actionPrint;
    QAction *actionHelp;
    QAction *actionSave;
    QWidget *centralwidget;
    QVTKWidget *qvtkWidgetLeft;
    QVTKWidget *qvtkWidgetRight;
    QVTKWidget *qvtkWidgetCenter;
    QSlider *horizontalSlider;

    void setupUi(QMainWindow *SideBySideRenderWindowsQt)
    {
        if (SideBySideRenderWindowsQt->objectName().isEmpty())
            SideBySideRenderWindowsQt->setObjectName(QString::fromUtf8("SideBySideRenderWindowsQt"));
        SideBySideRenderWindowsQt->resize(990, 583);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        SideBySideRenderWindowsQt->setWindowIcon(icon);
        SideBySideRenderWindowsQt->setIconSize(QSize(22, 22));
        actionOpenFile = new QAction(SideBySideRenderWindowsQt);
        actionOpenFile->setObjectName(QString::fromUtf8("actionOpenFile"));
        actionOpenFile->setEnabled(true);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icons/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpenFile->setIcon(icon1);
        actionExit = new QAction(SideBySideRenderWindowsQt);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon2);
        actionPrint = new QAction(SideBySideRenderWindowsQt);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Icons/print.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrint->setIcon(icon3);
        actionHelp = new QAction(SideBySideRenderWindowsQt);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        actionHelp->setIcon(icon);
        actionSave = new QAction(SideBySideRenderWindowsQt);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Icons/filesave.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon4);
        centralwidget = new QWidget(SideBySideRenderWindowsQt);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        qvtkWidgetLeft = new QVTKWidget(centralwidget);
        qvtkWidgetLeft->setObjectName(QString::fromUtf8("qvtkWidgetLeft"));
        qvtkWidgetLeft->setGeometry(QRect(30, 360, 271, 161));
        qvtkWidgetRight = new QVTKWidget(centralwidget);
        qvtkWidgetRight->setObjectName(QString::fromUtf8("qvtkWidgetRight"));
        qvtkWidgetRight->setGeometry(QRect(580, 400, 241, 171));
        qvtkWidgetCenter = new QVTKWidget(centralwidget);
        qvtkWidgetCenter->setObjectName(QString::fromUtf8("qvtkWidgetCenter"));
        qvtkWidgetCenter->setGeometry(QRect(320, 340, 261, 161));
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(30, 550, 160, 19));
        horizontalSlider->setOrientation(Qt::Horizontal);
        SideBySideRenderWindowsQt->setCentralWidget(centralwidget);

        retranslateUi(SideBySideRenderWindowsQt);

        QMetaObject::connectSlotsByName(SideBySideRenderWindowsQt);
    } // setupUi

    void retranslateUi(QMainWindow *SideBySideRenderWindowsQt)
    {
        SideBySideRenderWindowsQt->setWindowTitle(QApplication::translate("SideBySideRenderWindowsQt", "SimpleView", 0, QApplication::UnicodeUTF8));
        actionOpenFile->setText(QApplication::translate("SideBySideRenderWindowsQt", "Open File...", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("SideBySideRenderWindowsQt", "Exit", 0, QApplication::UnicodeUTF8));
        actionPrint->setText(QApplication::translate("SideBySideRenderWindowsQt", "Print", 0, QApplication::UnicodeUTF8));
        actionHelp->setText(QApplication::translate("SideBySideRenderWindowsQt", "Help", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("SideBySideRenderWindowsQt", "Save", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SideBySideRenderWindowsQt: public Ui_SideBySideRenderWindowsQt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIDEBYSIDERENDERWINDOWSQT1_H
