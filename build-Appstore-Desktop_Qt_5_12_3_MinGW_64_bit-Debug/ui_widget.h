/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QTableWidget *tableWidget;
    QLabel *label;
    QLabel *buy;
    QLabel *add;
    QLabel *exit;
    QLabel *label_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(900, 527);
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(710, 275, 120, 100));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        pushButton_3 = new QPushButton(Widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(710, 140, 120, 100));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        pushButton_4 = new QPushButton(Widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(710, 410, 120, 100));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        tableWidget = new QTableWidget(Widget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 130, 650, 400));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setMinimumSize(QSize(650, 400));
        tableWidget->setMaximumSize(QSize(650, 400));
        tableWidget->setStyleSheet(QString::fromUtf8("background-color: rgba(102, 25, 255, 50);\n"
"color: rgb(255, 255, 255);"));
        tableWidget->setFrameShape(QFrame::Box);
        tableWidget->setFrameShadow(QFrame::Raised);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 900, 527));
        label->setStyleSheet(QString::fromUtf8("background-image: url(:/Image/bg.jpg);"));
        buy = new QLabel(Widget);
        buy->setObjectName(QString::fromUtf8("buy"));
        buy->setGeometry(QRect(710, 140, 120, 100));
        buy->setStyleSheet(QString::fromUtf8("image: url(:/Image/\350\264\255\344\271\260 (1).png);"));
        add = new QLabel(Widget);
        add->setObjectName(QString::fromUtf8("add"));
        add->setGeometry(QRect(710, 275, 120, 100));
        add->setStyleSheet(QString::fromUtf8("image: url(:/Image/\346\267\273\345\212\240.png);"));
        exit = new QLabel(Widget);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setGeometry(QRect(720, 410, 120, 100));
        exit->setStyleSheet(QString::fromUtf8("image: url(:/Image/\351\200\200\345\207\272.png);"));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(260, 40, 351, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(28);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(85, 255, 255);"));
        label_2->setAlignment(Qt::AlignCenter);
        label->raise();
        exit->raise();
        add->raise();
        buy->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        tableWidget->raise();
        label_2->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        label->setText(QString());
        buy->setText(QString());
        add->setText(QString());
        exit->setText(QString());
        label_2->setText(QApplication::translate("Widget", "Easy AppShop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
