/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *main_layout;
    QVBoxLayout *container;
    QPlainTextEdit *console_output;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *currant_path;
    QLineEdit *console_input;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(770, 473);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8("figs/console.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        main_layout = new QVBoxLayout(centralwidget);
        main_layout->setSpacing(0);
        main_layout->setObjectName("main_layout");
        main_layout->setContentsMargins(0, 0, 0, 0);
        container = new QVBoxLayout();
        container->setSpacing(0);
        container->setObjectName("container");
        console_output = new QPlainTextEdit(centralwidget);
        console_output->setObjectName("console_output");
        console_output->setStyleSheet(QString::fromUtf8("QPlainTextEdit {\n"
"	border: none;\n"
"}"));
        console_output->setReadOnly(true);

        container->addWidget(console_output);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(0, 40));
        groupBox->setMaximumSize(QSize(16777215, 40));
        groupBox->setStyleSheet(QString::fromUtf8("QGrouBox {\n"
"	background-color: white;\n"
"}"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        currant_path = new QLabel(groupBox);
        currant_path->setObjectName("currant_path");
        currant_path->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background-color: white;\n"
"}"));

        horizontalLayout->addWidget(currant_path);

        console_input = new QLineEdit(groupBox);
        console_input->setObjectName("console_input");
        sizePolicy.setHeightForWidth(console_input->sizePolicy().hasHeightForWidth());
        console_input->setSizePolicy(sizePolicy);
        console_input->setMinimumSize(QSize(0, 40));
        console_input->setMaximumSize(QSize(16777215, 40));
        console_input->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	border: none;\n"
"}"));

        horizontalLayout->addWidget(console_input);


        container->addWidget(groupBox);


        main_layout->addLayout(container);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 770, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Console", nullptr));
        groupBox->setTitle(QString());
        currant_path->setText(QCoreApplication::translate("MainWindow", "Path", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
