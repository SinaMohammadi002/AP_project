/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_2;
    QLabel *label_4;
    QLineEdit *Username;
    QLineEdit *Password;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *mail;
    QPushButton *signpush;
    QGroupBox *groupBox;
    QPushButton *logpush;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label1;
    QLineEdit *username;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout;
    QLabel *label2;
    QLineEdit *password;
    QLabel *label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/key.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("image: url(:/Images/Background3.jpg);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(510, 110, 221, 361));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        groupBox_2->setFont(font);
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(93, 156, 147);"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 40, 121, 21));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("image : none"));
        Username = new QLineEdit(groupBox_2);
        Username->setObjectName("Username");
        Username->setGeometry(QRect(0, 70, 221, 21));
        Username->setStyleSheet(QString::fromUtf8("background-color: rgb(74, 74, 74);"));
        Password = new QLineEdit(groupBox_2);
        Password->setObjectName("Password");
        Password->setGeometry(QRect(0, 170, 221, 21));
        Password->setStyleSheet(QString::fromUtf8("background-color: rgb(74, 74, 74);"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 140, 121, 21));
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("image : none"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(0, 240, 121, 21));
        label_6->setFont(font1);
        label_6->setStyleSheet(QString::fromUtf8("image : none"));
        mail = new QLineEdit(groupBox_2);
        mail->setObjectName("mail");
        mail->setGeometry(QRect(0, 270, 221, 21));
        mail->setStyleSheet(QString::fromUtf8("background-color: rgb(74, 74, 74);"));
        signpush = new QPushButton(groupBox_2);
        signpush->setObjectName("signpush");
        signpush->setGeometry(QRect(60, 340, 111, 21));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        signpush->setFont(font2);
        signpush->setStyleSheet(QString::fromUtf8("\n"
"#signpush {\n"
"background-color: rgb(0, 85, 0);\n"
"image : none\n"
"}\n"
"#signpush:hover{\n"
"background-color: rgb(0, 170, 255);\n"
"}"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(50, 110, 221, 321));
        groupBox->setFont(font);
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(93, 156, 147);\n"
"image : none ;"));
        groupBox->setFlat(false);
        logpush = new QPushButton(groupBox);
        logpush->setObjectName("logpush");
        logpush->setGeometry(QRect(60, 300, 111, 21));
        logpush->setFont(font2);
        logpush->setAutoFillBackground(false);
        logpush->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 85, 0);\n"
"image : none"));
        logpush->setAutoDefault(false);
        logpush->setFlat(false);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 40, 221, 81));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label1 = new QLabel(layoutWidget);
        label1->setObjectName("label1");
        label1->setFont(font1);
        label1->setStyleSheet(QString::fromUtf8("image : none ;"));

        verticalLayout_2->addWidget(label1);

        username = new QLineEdit(layoutWidget);
        username->setObjectName("username");
        username->setStyleSheet(QString::fromUtf8("background-color: rgb(74, 74, 74);\n"
"image : none ;"));

        verticalLayout_2->addWidget(username);

        layoutWidget_2 = new QWidget(groupBox);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(0, 140, 221, 71));
        verticalLayout = new QVBoxLayout(layoutWidget_2);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label2 = new QLabel(layoutWidget_2);
        label2->setObjectName("label2");
        label2->setFont(font1);
        label2->setStyleSheet(QString::fromUtf8("image : none ;"));

        verticalLayout->addWidget(label2);

        password = new QLineEdit(layoutWidget_2);
        password->setObjectName("password");
        password->setStyleSheet(QString::fromUtf8("background-color: rgb(74, 74, 74);\n"
"image : none ;"));
        password->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(password);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(200, 0, 511, 61));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font3.setPointSize(36);
        font3.setBold(true);
        label->setFont(font3);
        label->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(0, 170, 255);\n"
"image : none ;"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        logpush->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Registe/Login Page", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Sign in", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "UserName : ", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Password : ", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "E-Mail :", nullptr));
        signpush->setText(QCoreApplication::translate("MainWindow", "Sign in", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Login", nullptr));
        logpush->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        label1->setText(QCoreApplication::translate("MainWindow", "UserName : ", nullptr));
        label2->setText(QCoreApplication::translate("MainWindow", "Password : ", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Login/Register Game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
