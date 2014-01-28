/********************************************************************************
** Form generated from reading UI file 'SideBySideRenderWindowsQt.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIDEBYSIDERENDERWINDOWSQT_H
#define UI_SIDEBYSIDERENDERWINDOWSQT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_SideBySideRenderWindowsQt
{
public:
    QAction *actionOpen;
    QWidget *centralwidget;
    QSlider *horizontalSliderLeft;
    QVTKWidget *qvtkWidgetLeft;
    QVTKWidget *qvtkWidgetRight;
    QVTKWidget *qvtkWidgetCenter;
    QSlider *horizontalSliderRight;
    QSlider *horizontalSliderCenter;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButtonBlue;
    QPushButton *pushButtonRed;
    QPushButton *pushButtonGreen;
    QPushButton *clearLeft;
    QPushButton *clearCenter;
    QPushButton *clearRight;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SideBySideRenderWindowsQt)
    {
        if (SideBySideRenderWindowsQt->objectName().isEmpty())
            SideBySideRenderWindowsQt->setObjectName(QString::fromUtf8("SideBySideRenderWindowsQt"));
        SideBySideRenderWindowsQt->resize(786, 1009);
        SideBySideRenderWindowsQt->setAutoFillBackground(true);
        actionOpen = new QAction(SideBySideRenderWindowsQt);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        centralwidget = new QWidget(SideBySideRenderWindowsQt);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalSliderLeft = new QSlider(centralwidget);
        horizontalSliderLeft->setObjectName(QString::fromUtf8("horizontalSliderLeft"));
        horizontalSliderLeft->setGeometry(QRect(50, 500, 160, 19));
        horizontalSliderLeft->setOrientation(Qt::Horizontal);
        qvtkWidgetLeft = new QVTKWidget(centralwidget);
        qvtkWidgetLeft->setObjectName(QString::fromUtf8("qvtkWidgetLeft"));
        qvtkWidgetLeft->setGeometry(QRect(50, 280, 201, 201));
        qvtkWidgetRight = new QVTKWidget(centralwidget);
        qvtkWidgetRight->setObjectName(QString::fromUtf8("qvtkWidgetRight"));
        qvtkWidgetRight->setGeometry(QRect(550, 280, 201, 201));
        qvtkWidgetCenter = new QVTKWidget(centralwidget);
        qvtkWidgetCenter->setObjectName(QString::fromUtf8("qvtkWidgetCenter"));
        qvtkWidgetCenter->setGeometry(QRect(290, 280, 201, 201));
        horizontalSliderRight = new QSlider(centralwidget);
        horizontalSliderRight->setObjectName(QString::fromUtf8("horizontalSliderRight"));
        horizontalSliderRight->setGeometry(QRect(550, 500, 160, 19));
        horizontalSliderRight->setOrientation(Qt::Horizontal);
        horizontalSliderCenter = new QSlider(centralwidget);
        horizontalSliderCenter->setObjectName(QString::fromUtf8("horizontalSliderCenter"));
        horizontalSliderCenter->setGeometry(QRect(290, 500, 160, 19));
        horizontalSliderCenter->setOrientation(Qt::Horizontal);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 520, 31, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(350, 520, 31, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(620, 520, 31, 21));
        pushButtonBlue = new QPushButton(centralwidget);
        pushButtonBlue->setObjectName(QString::fromUtf8("pushButtonBlue"));
        pushButtonBlue->setGeometry(QRect(690, 60, 75, 23));
        QFont font;
        font.setFamily(QString::fromUtf8("Perpetua"));
        font.setBold(true);
        font.setWeight(75);
        pushButtonBlue->setFont(font);
        pushButtonBlue->setAutoFillBackground(true);
        pushButtonRed = new QPushButton(centralwidget);
        pushButtonRed->setObjectName(QString::fromUtf8("pushButtonRed"));
        pushButtonRed->setGeometry(QRect(690, 120, 75, 23));
        pushButtonGreen = new QPushButton(centralwidget);
        pushButtonGreen->setObjectName(QString::fromUtf8("pushButtonGreen"));
        pushButtonGreen->setGeometry(QRect(690, 180, 75, 23));
        clearLeft = new QPushButton(centralwidget);
        clearLeft->setObjectName(QString::fromUtf8("clearLeft"));
        clearLeft->setGeometry(QRect(90, 560, 75, 23));
        clearCenter = new QPushButton(centralwidget);
        clearCenter->setObjectName(QString::fromUtf8("clearCenter"));
        clearCenter->setGeometry(QRect(330, 560, 75, 23));
        clearRight = new QPushButton(centralwidget);
        clearRight->setObjectName(QString::fromUtf8("clearRight"));
        clearRight->setGeometry(QRect(600, 560, 75, 23));
        SideBySideRenderWindowsQt->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SideBySideRenderWindowsQt);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 786, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        SideBySideRenderWindowsQt->setMenuBar(menubar);
        statusbar = new QStatusBar(SideBySideRenderWindowsQt);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SideBySideRenderWindowsQt->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);

        retranslateUi(SideBySideRenderWindowsQt);

        QMetaObject::connectSlotsByName(SideBySideRenderWindowsQt);
    } // setupUi

    void retranslateUi(QMainWindow *SideBySideRenderWindowsQt)
    {
        SideBySideRenderWindowsQt->setWindowTitle(QApplication::translate("SideBySideRenderWindowsQt", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("SideBySideRenderWindowsQt", "Open ", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SideBySideRenderWindowsQt", "Slicing", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SideBySideRenderWindowsQt", "Slicing", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SideBySideRenderWindowsQt", "Slicing", 0, QApplication::UnicodeUTF8));
        pushButtonBlue->setText(QString());
        pushButtonRed->setText(QString());
        pushButtonGreen->setText(QString());
        clearLeft->setText(QApplication::translate("SideBySideRenderWindowsQt", "Erase", 0, QApplication::UnicodeUTF8));
        clearCenter->setText(QApplication::translate("SideBySideRenderWindowsQt", "Erase", 0, QApplication::UnicodeUTF8));
        clearRight->setText(QApplication::translate("SideBySideRenderWindowsQt", "Erase", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("SideBySideRenderWindowsQt", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SideBySideRenderWindowsQt: public Ui_SideBySideRenderWindowsQt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIDEBYSIDERENDERWINDOWSQT_H
