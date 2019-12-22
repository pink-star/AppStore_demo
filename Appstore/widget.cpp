#include "widget.h"
#include "ui_widget.h"
#include "function.h"
#include <QString>
#include <QDebug>
//#include "buy.h"
#include "addwindow.h"
#include <QMessageBox>
#include <QCoreApplication>
#include <QTime>

bool readfile = false;
int total = 0;                              //打开的软件的个数
string softwarename = "software.txt";       //文件名
vector<string> Data;                        //输出的字符串
Software_Tree * Head;
vector<int> Deleteline;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //treewidget

    //QStringList list;
    //ui->treeWidget->setColumnCount(1);
    //ui->treeWidget->setColumnWidth(0,250);
    //list << "The name of the software" << "version" << "remain" << "price";
    //设置Tree头
    //ui->treeWidget->setHeaderLabels(list);

    //Treewidget中的每个项目类型都为QTreewidgtitem
    //QTreeWidgetItem * QT_item = new QTreeWidgetItem(QStringList() << "Adobe_Photoshop" << "CS5" << "21" << "580");

    //ui->treeWidget->addTopLevelItem(QT_item);

    QStringList Header_list;
    Header_list << "The name of the software" << "version" << "remain" << "price";
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);   //设置表格为按行选择

    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:rgbd(195,74,255,55)}");
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:rgbd(195,74,255,55)}");

    ui->tableWidget->setColumnCount(4);                         //设置标题个数
    ui->tableWidget->setColumnWidth(0,250);                     //设置标题宽度
    ui->tableWidget->setHorizontalHeaderLabels(Header_list);    //设置标题内容
    //qDebug() << "是否有问题";
    //ui->tableWidget->insertRow(0);                                              //插入第一行内容
    //ui->tableWidget->setItem(0,0,new QTableWidgetItem("Adobe_Photoshop"));      //
    //ui->tableWidget->setItem(0,1,new QTableWidgetItem("CS5"));                  //
    //ui->tableWidget->setItem(0,2,new QTableWidgetItem("21"));                   //
    //ui->tableWidget->setItem(0,3,new QTableWidgetItem("580"));                  //

    //int total = 0;                              //打开的软件的个数
    //string softwarename = "software.txt";       //文件名
    //vector<string> Data;                        //输出的字符串
    readTxt(softwarename,Data,total);           //读取文件
    //qDebug() << "是否有问题";
    //Software_Tree * Head;
    Head = BuildTree(total,Data);               //将信息存进树中
    //qDebug() << "是否有问题";
    qDebug() << Head->location;
    //qDebug() << QString::fromStdString(Data[0]) << " " << total;
    //qDebug() << total;

    for(int i = 0;i<total;i++)
    {
        ui->tableWidget->insertRow(i);
        string software[4];
        int tempnum = 0;
        //qDebug() << "是否有问题";
        for(int k = 0; k < Data[i].length(); k++)
        {
            if(Data[i][k] != ' ')
            {
                software[tempnum] += Data[i][k];
            }
            else{
                tempnum++;
                continue;
            }
        }
        for(int j = 0; j<4;j++)
        {
            qDebug() << QString::fromStdString(software[j]);
            ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString::fromStdString(software[j])));
        }
        qDebug() << "是否有问题";

    }
    qDebug() << "是否有问题";
    //qDebug() << "是否有问题";
    //qDebug() << Head->location;
    //qDebug() << "outside" << total;           //如何将引用传进去

//    connect(ui->pushButton_3,&QPushButton::clicked,[=](){
//        qDebug() << "inside" << total;
//        vector<string> DatainFun;
//        fstream intofile("software.txt");
//        assert(intofile.is_open());
//        int nowline = 0;
//        string tempstr;
//        string softwareinfo;
//        int wantline = ui->tableWidget->currentRow();
//        while (getline(intofile, tempstr))
//        {
//            //qDebug() << "while有执行";未执行
//            if(nowline == wantline)
//            {
//                //qDebug() << "have done";
//                softwareinfo = tempstr;
//                break;
//            }
//            nowline++;
//        }
//        //cout << "softwarename" <<softwarename;
//        //qDebug() << "wantlin" << wantline;
//        intofile.close();

//        string softwarename;

//        for(int i = 0; i < softwareinfo.length();i++)
//        {
//            if(softwareinfo[i] != ' ')
//            {
//                softwarename += softwareinfo[i];
//            }
//            else {
//                break;
//            }
//        }
//        //qDebug() << Head->location;           //空树？
//        //qDebug() << QString::fromStdString(softwarename);

//       Software_Tree * temp_tree = Buysoftware(Head,softwarename);
//      // readTxt(softwarename,DatainFun,total);
//       readTxt(softwarename,DatainFun,total);

//        for(int i = 0;i<total;i++)
//        {
//            ui->tableWidget->removeRow(i);
//        }
//        *******************

//        for(int i = 0;i<total;i++)
//        {
//            ui->tableWidget->insertRow(i);
//            string software[4];
//            int tempnum = 0;
//            for(int k = 0; k < DatainFun[i].length(); k++)
//            {
//                if(DatainFun[i][k] != ' ')
//                {
//                    software[tempnum] += DatainFun[i][k];
//                }
//                else{
//                    tempnum++;
//                    continue;
//                }
//            }
//            for(int j = 0; j<4;j++)
//            {
//                ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString::fromStdString(software[j])));
//            }

//        }

//        //*******************

//    });


    //buy = new Buy(this);
    //Software_Tree * Head,string software_name,Ui::Widget * ui,int & total
    //connect(ui->pushButton_3,&QPushButton::myclick(false,Head,ui,total),buy,&Buy::Buyapp(Head,ui,total));


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_3_clicked()          //Buy
{
    qDebug() << ui->tableWidget->currentRow();
    qDebug() << "inside" << total;
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
    //qDebug() << Head->location;           //空树？
    //qDebug() << QString::fromStdString(softwarename);

   bool ifnoapp = false;

   Head = Buysoftware(Head,softwarename,ifnoapp);
   qDebug() << "是否售空" << ifnoapp;

   if(ifnoapp == true)
   {
       // QMessageBox::information(this,"很抱歉",(QString::fromStdString(softwarename)+"已售空"));
        QMessageBox * msb = new QMessageBox(this);
        msb->resize(500,500);
        msb->setText((QString::fromStdString(softwarename)+"已售空"));
        msb->setWindowTitle("sorry");
        msb->show();

   }

    // readTxt(softwarename,DatainFun,total);
   total = 0;
   readTxt("software.txt",DatainFun,total);

   qDebug() << "删除后的total" << total;


   //void QTableWidget::clearContents() [ui->tablewidget];
   //ui->tableWidget->clear();

   for(int i = 0;i<total;i++)
   {
       ui->tableWidget->removeRow(i);
   }
   int iLen = ui->tableWidget->rowCount();
   for(int i=0;i<iLen;i++)
   {
        ui->tableWidget->removeRow(0);
   }


  //*******************
                     //设置标题宽度


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

void Widget::on_pushButton_2_clicked()
{
    //弹出对话框接收三个字符串：
    //修改Add函数传入该三个字符串即可
//    fstream tempfile;
//    tempfile.open("temp.txt");
//    tempfile << '\0';
//    tempfile.close();
    readfile = false;
    Addwindow * window = new Addwindow;
    window->show();

    //while(!readfile)
   // {

    //}

    QTime t;
    t.start();
    while(t.elapsed()<1000*200)
    {
        QCoreApplication::processEvents();
        qDebug() << "readfile" << readfile;
        if(readfile == true)
        {
            break;
        }
    }

    fstream finbutton2;
    finbutton2.open("temp.txt");
    string software_info;
    string tempstr;
    while(getline(finbutton2, tempstr))
    {
        software_info = tempstr;
    }
    string software[4];
    int temp = 0;
    for(int i = 0;i<software_info.length();i++)
    {
        if(software_info[i] != ' ')
        {
            software[temp] += software_info[i];
        }
        else {
            temp++;
            continue;
        }
    }

    bool ifhane = false;

    Head = Add_Software(Head,total,software[0],software[1],software[2],software[3],ifhane);

    //Head = Add_Software(Head,total);

    /************************************/
    vector<string> DatainFun;
    total = 0;
    readTxt("software.txt",DatainFun,total);

    qDebug() << "删除后的total" << total;


    //void QTableWidget::clearContents() [ui->tablewidget];
    //ui->tableWidget->clear();

    for(int i = 0;i<total;i++)
    {
        ui->tableWidget->removeRow(i);
    }
    int iLen = ui->tableWidget->rowCount();
    for(int i=0;i<iLen;i++)
    {
         ui->tableWidget->removeRow(0);
    }


                      //设置标题宽度


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

   if(ifhane == true)
   {
        QMessageBox::information(this,"你好",(QString::fromStdString(software[0])+"已经商城中"));
   }
    /***********************************/

}

void Widget::on_pushButton_4_clicked()
{

    if(!Deleteline.empty())
    {
        qDebug() << Deleteline.front();
        //DeleteFile(Deleteline.front(),total);
        DeleteFile(Deleteline,total);
    }


    QMessageBox * msb = new QMessageBox(this);
    msb->resize(500,500);
    msb->setText("感谢您使用本软件");
    msb->setWindowTitle("再见");
    msb->show();

    QTime t;
    t.start();
    while(t.elapsed()<1000*2)
    {
        QCoreApplication::processEvents();
    }

    msb->close();
    this->close();
}
