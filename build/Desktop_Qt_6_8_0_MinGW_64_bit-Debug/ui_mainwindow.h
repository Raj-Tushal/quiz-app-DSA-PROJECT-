/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *questionLabel;
    QRadioButton *option1;
    QRadioButton *option2;
    QRadioButton *option3;
    QRadioButton *option4;
    QPushButton *submitButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        questionLabel = new QLabel(centralwidget);
        questionLabel->setObjectName("questionLabel");
        questionLabel->setGeometry(QRect(60, 50, 301, 16));
        option1 = new QRadioButton(centralwidget);
        option1->setObjectName("option1");
        option1->setGeometry(QRect(60, 80, 89, 20));
        option2 = new QRadioButton(centralwidget);
        option2->setObjectName("option2");
        option2->setGeometry(QRect(60, 110, 89, 20));
        option3 = new QRadioButton(centralwidget);
        option3->setObjectName("option3");
        option3->setGeometry(QRect(60, 140, 89, 20));
        option4 = new QRadioButton(centralwidget);
        option4->setObjectName("option4");
        option4->setGeometry(QRect(60, 170, 89, 20));
        submitButton = new QPushButton(centralwidget);
        submitButton->setObjectName("submitButton");
        submitButton->setGeometry(QRect(240, 170, 75, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        questionLabel->setText(QCoreApplication::translate("MainWindow", "Q1: capital of pakistan??", nullptr));
        option1->setText(QCoreApplication::translate("MainWindow", "karachi", nullptr));
        option2->setText(QCoreApplication::translate("MainWindow", "islamabad", nullptr));
        option3->setText(QCoreApplication::translate("MainWindow", "peshawar", nullptr));
        option4->setText(QCoreApplication::translate("MainWindow", "khyber pakhtunkhwa", nullptr));
        submitButton->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
