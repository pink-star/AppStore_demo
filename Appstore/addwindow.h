#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QWidget>
#include "widget.h"
#include "function.h"


namespace Ui {
class Addwindow;
}

class Addwindow : public QWidget
{
    Q_OBJECT

public:
    explicit Addwindow(QWidget *parent = nullptr);
    ~Addwindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Addwindow *ui;
    Widget w1;
};

#endif // ADDWINDOW_H
