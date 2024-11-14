/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *icon_only_widget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QLabel *label;
    QWidget *icon_names_text_widget;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QWidget *main_screen_widget;
    QWidget *heade_widget;
    QLineEdit *lineEdit;
    QPushButton *pushButton_13;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1251, 660);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color:rgb(245,250,254);\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("#main_window_widget{\n"
"	background-color:rgb(131,255,189);\n"
"}"));
        icon_only_widget = new QWidget(centralwidget);
        icon_only_widget->setObjectName(QString::fromUtf8("icon_only_widget"));
        icon_only_widget->setGeometry(QRect(40, 20, 171, 611));
        pushButton = new QPushButton(icon_only_widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 70, 83, 29));
        pushButton_2 = new QPushButton(icon_only_widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(40, 150, 83, 29));
        pushButton_3 = new QPushButton(icon_only_widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(40, 110, 83, 29));
        pushButton_4 = new QPushButton(icon_only_widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(40, 230, 83, 29));
        pushButton_5 = new QPushButton(icon_only_widget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(40, 190, 83, 29));
        pushButton_7 = new QPushButton(icon_only_widget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(40, 560, 83, 29));
        label = new QLabel(icon_only_widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 10, 63, 20));
        icon_names_text_widget = new QWidget(centralwidget);
        icon_names_text_widget->setObjectName(QString::fromUtf8("icon_names_text_widget"));
        icon_names_text_widget->setGeometry(QRect(230, 20, 201, 611));
        label_2 = new QLabel(icon_names_text_widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 10, 31, 20));
        label_2->setPixmap(QPixmap(QString::fromUtf8("../ressource/align-justify.svg")));
        label_3 = new QLabel(icon_names_text_widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(120, 10, 63, 20));
        pushButton_6 = new QPushButton(icon_names_text_widget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(80, 70, 83, 29));
        pushButton_8 = new QPushButton(icon_names_text_widget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(80, 110, 83, 29));
        pushButton_9 = new QPushButton(icon_names_text_widget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(80, 150, 83, 29));
        pushButton_10 = new QPushButton(icon_names_text_widget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(80, 190, 83, 29));
        pushButton_11 = new QPushButton(icon_names_text_widget);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(80, 560, 83, 29));
        pushButton_12 = new QPushButton(icon_names_text_widget);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setGeometry(QRect(80, 230, 83, 29));
        main_screen_widget = new QWidget(centralwidget);
        main_screen_widget->setObjectName(QString::fromUtf8("main_screen_widget"));
        main_screen_widget->setGeometry(QRect(450, 120, 771, 501));
        main_screen_widget->setStyleSheet(QString::fromUtf8("background-color:rgb(147, 237, 255)"));
        heade_widget = new QWidget(centralwidget);
        heade_widget->setObjectName(QString::fromUtf8("heade_widget"));
        heade_widget->setGeometry(QRect(450, 10, 871, 101));
        lineEdit = new QLineEdit(heade_widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(130, 30, 251, 28));
        pushButton_13 = new QPushButton(heade_widget);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        pushButton_13->setGeometry(QRect(20, 30, 83, 29));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_2->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "DashBoard", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
