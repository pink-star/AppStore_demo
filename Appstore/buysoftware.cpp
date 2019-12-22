#include "buysoftware.h"
#include "ui_widget.h"
#include "function.h"

Buysoftware::Buysoftware(QObject *parent) : QObject(parent)
{

}

void Buysoftware::Buyapp(Software_Tree * Head,string software_name,Ui::Widget * ui)
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
    Software_Tree * temp_tree = Buysoftware(Head,softwarename);


}
