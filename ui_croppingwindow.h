/********************************************************************************
** Form generated from reading UI file 'croppingwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CROPPINGWINDOW_H
#define UI_CROPPINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CroppingWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CroppingWindow)
    {
        if (CroppingWindow->objectName().isEmpty())
            CroppingWindow->setObjectName(QString::fromUtf8("CroppingWindow"));
        CroppingWindow->resize(600, 488);
        centralwidget = new QWidget(CroppingWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        CroppingWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CroppingWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 26));
        CroppingWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(CroppingWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CroppingWindow->setStatusBar(statusbar);

        retranslateUi(CroppingWindow);

        QMetaObject::connectSlotsByName(CroppingWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CroppingWindow)
    {
        CroppingWindow->setWindowTitle(QCoreApplication::translate("CroppingWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CroppingWindow: public Ui_CroppingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CROPPINGWINDOW_H
