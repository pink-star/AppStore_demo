#include "addwindow.h"
#include "ui_addwindow.h"
#include "function.h"
#include "widget.h"

Addwindow::Addwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Addwindow)
{
    ui->setupUi(this);
}

Addwindow::~Addwindow()
{
    delete ui;
}

void Addwindow::on_pushButton_2_clicked()
{
    this->close();
}

//bool readfile = false;

void Addwindow::on_pushButton_clicked()
{
    string software_name = ui->lineEdit->text().toStdString();
    string software_version = ui->lineEdit_2->text().toStdString();
    string software_num = ui->lineEdit_3->text().toStdString();
    string software_price = ui->lineEdit_4->text().toStdString();
    //Add_Software(this->ui->,)
    //w1.
    ofstream outfile("temp.txt");
    outfile << software_name << " " << software_version << " " <<software_num << " " << software_price;
    outfile.close();
    this->close();
    readfile = true;
}
