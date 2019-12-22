#ifndef WIDGET_H
#define WIDGET_H

//#include "buy.h"
#include <QWidget>
#include "function.h"

extern Software_Tree * Head;
extern int total;

extern bool readfile;

namespace Ui {



class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    //Buy * buy;
    //Software_Tree * Head;
    //int total = 0;
    ~Widget();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Widget *ui;
};



#endif // WIDGET_H
