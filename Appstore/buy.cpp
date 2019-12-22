#include "buy.h"
#include "ui_widget.h"
#include "function.h"

Buy::Buy(QObject *parent) : QObject(parent)
{

}

void Buy::Buyapp(Software_Tree * Head,Ui::Widget * ui,int & total)
{
    vector<string> DatainFun;
    fstream intofile("software.txt");
    assert(intofile.is_open());
    int nowline = 0;
    string tempstr;
    string softwareinfo;
    int wantline = ui->tableWidget->currentRow();
    while (getline(intofile, tempstr))
    {
        //qDebug() << "while有执行";未执行
        if(nowline == wantline)
        {
            //qDebug() << "have done";
            softwareinfo = tempstr;
            break;
        }
        nowline++;
    }
    //cout << "softwarename" <<softwarename;
    //qDebug() << "wantlin" << wantline;
    intofile.close();


    string softwarename;

    for(int i = 0; i < softwareinfo.length();i++)
    {
        if(softwareinfo[i] != ' ')
        {
            softwarename += softwareinfo[i];
        }
        else {
            break;
        }
    }

    //Software_Tree * temp_tree = Buysoftware(Head,softwarename);
    readTxt(softwarename,DatainFun,total);

    for(int i = 0;i<total;i++)
    {
        ui->tableWidget->removeRow(i);
    }

    //*******************

    for(int i = 0;i<total;i++)
    {
        ui->tableWidget->insertRow(i);
        string software[4];
        int tempnum = 0;
        for(int k = 0; k < DatainFun[i].length(); k++)
        {
            if(DatainFun[i][k] != ' ')
            {
                software[tempnum] += DatainFun[i][k];
            }
            else{
                tempnum++;
                continue;
            }
        }
        for(int j = 0; j<4;j++)
        {
            ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString::fromStdString(software[j])));
        }

    }

}
