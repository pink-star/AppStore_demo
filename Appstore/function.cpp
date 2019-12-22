#include "function.h"
#include <QDebug>
#include <QMessageBox>

void DeleteFile_inUi(int linenum)
{
    vector<int> NeedtoDeleteline;
}

void DeleteFile(vector<int> linenum,int total)          //删除文件中的某一行
{
    fstream infile("software.txt");
    string temp_str;
    string Delete_software;
    string last_software;
    int nowline = 1;
    while (getline(infile,temp_str))
    {
        if (nowline == total)
        {
            last_software += temp_str;
        }
        nowline++;
    }
    infile.close();

    fstream T_infile("software.txt");
    string saveData;
    nowline = 1;
    char lineData[1024];
    while (T_infile.getline(lineData, sizeof(lineData)))
    {
        if (nowline == linenum.front())
        {
            saveData += last_software;
            saveData += '\n';
        }
        else if (nowline == total)
        {
            continue;
        }
        else
        {
            saveData += CharToStr(lineData);
            saveData += '\n';
        }
        nowline++;
    }
    T_infile.close();

    ofstream out;
    out.open("software.txt");
    out.flush();
    //cout << saveData << endl;
    out << saveData;
    out.close();

}

Software_Tree * FindMin(Software_Tree * Head)
{
    if (Head == NULL) return NULL;
    else if (!Head->left)return Head;
    else return FindMin( Head->left);
}

Software_Tree * Delete_TreeNode(string softwarename, Software_Tree * Head)      //
{
    Software_Tree * temp;
    //cout << (Head->App_name.compare(softwarename));

    if ( !Head ) qDebug() << "Tree is void";
    else if ((Head->App_name.compare(softwarename)) < 0) //往右边，compare函数appname > software 的话返回正数
    {
        qDebug() << "往右执行" << endl;
        Head->right = Delete_TreeNode(softwarename,Head->right);
    }
    else if ((Head->App_name.compare(softwarename)) > 0) //往左边，值小于树节点的值
    {
        Head->left = Delete_TreeNode(softwarename,Head->left);
    }
    else	//找到了要删除的节点
    {
        cout << "find" << Head->App_name << endl; //找到了
        if (Head->left && Head->right)
        {
            temp = FindMin(Head->right);
            cout << "同时两有子节点" << temp->App_name << endl;
            Head->App_name = temp->App_name;
            Head->App_versions = temp->App_versions;
            Head->location = temp->location;
            Head->right = Delete_TreeNode(Head->App_name, Head->right);
        }
        else {
            qDebug() << "有执行" << endl;
            temp = Head;
            if (!Head->left) //有右子节点或者没有子节点
            {
                Head = Head->right;
                //cout << Head->App_name << endl;
                qDebug() << "有右子节点或为空" << endl;
                //cout << Head->App_name << endl;
            }
            else if (!Head->right) //有左子节点或者没有 其实不会有左子节点了，否则早就找到了
            {
                Head = Head->left;
                qDebug() << "有左子节点" << endl;
            }

            delete temp;
        }

    }
    return Head;
}

string CharToStr(char * contentChar)
{
    string tempStr;
    for (int i = 0; contentChar[i] != '\0'; i++)
    {
        tempStr += contentChar[i];
    }
    return tempStr;
}

Software_Tree * Buysoftware(Software_Tree * Head,string software_name,bool& ifnoapp)
{
    qDebug() << "此时的Qdebug有执行！！！！！！！！！！！！";
    //遍历二叉搜索树找到对应software的location
    //通过location删除\修改文件对应行的数据
    //qDebug() << "第一处测试";
    Software_Tree * temp = Search_Software(Head,software_name); //软件所对应的树的结点指针      //该函数有问题
        //软件在文件中的行数
    //qDebug() << "第二处测试";

    if (temp)
    {
        int linenum = temp->location;
        fstream infile("software.txt");
        string temp_str;
        string software_info[4];
        int nowline = 1;
        while (getline(infile,temp_str))
        {
            if (nowline == linenum)
            {
                nowline++;
                int i = 0;
                for (int j = 0; j < temp_str.length(); j++)
                {
                    if (temp_str[j] != ' ')				//如果不是空格就将字符加入字符串中
                        software_info[i] += temp_str[j];
                    else
                    {
                        i++;
                        continue;
                    }
                }
            }
            else
            {
                nowline++;
                continue;
            }
        }
        //将对应行的字符串分割为4个部分
        infile.close();

        string updata_software;
        updata_software += software_info[0];
        updata_software += ' ';
        updata_software += software_info[1];
        updata_software += ' ';
        int software_num;
        software_num = atoi(software_info[2].c_str());
        qDebug() << "========================此时的num = " << software_num;
        if (software_num == 0)
        {
            //cout << "很抱歉！该商品已经售空" << endl;
            //qDebug() << "if no app" << ifnoapp;
            ifnoapp = true;
            qDebug("有没有执行有没有——————————————————————————");
            return Head;
        }
        software_num -= 1;

        qDebug () << "---------------不等于0";

        if (software_num == 0) //当售出最后一份软件时、从树中删除改节点
        {
            //cout << "software_num == 0 || software_num < 0" << endl;
            //cout << "Line ： " << temp->location << endl;
            Deleteline.push_back(temp->location);
            Head = Delete_TreeNode(software_name,Head);
        }

        //cout << (Head==NULL) << endl;
        //cout << Head->App_name << endl;
        //cout << "software_num :" << software_num << endl;
        stringstream ss;		//借助stringstream流来将int转化为字符串
        ss << software_num;
        string num;
        ss >> num;
        updata_software += num;
        updata_software += ' ';
        updata_software += software_info[3];
        //cout << "以下是软件信息" << endl;
        //cout << updata_software << endl;

        fstream T_infile("software.txt");
        string saveData;
        nowline = 1;
        char lineData[1024];
        while (T_infile.getline(lineData, sizeof(lineData)))
        {
            if (linenum == nowline)
            {
                saveData += updata_software;
                saveData += '\n';
            }
            else {
                saveData += CharToStr(lineData);
                saveData += '\n';
            }
            nowline++;

        }
        T_infile.close();

        ofstream out;
        out.open("software.txt");
        out.flush();
        out << saveData;
        out.close();


    }
    else {
        //cout << "软件不存在或者已经售空" << endl;
        ifnoapp = true;
    }

    return Head;
}

Software_Tree * Delete_Software(Software_Tree * Head, string Software_name)
{
    Software_Tree * temp = new Software_Tree;
    return temp;
}
//将软件信息写入文件中
void writeTxt(string Newapp_name,string newapp_version,string newapp_num, string newapp_price,int& total,Software_Tree * Head,bool & ifhave)
{
    int Defult = true;	//判断软件是否已经在文件列表中
    fstream infile("software.txt");
    string temp;
    while (getline(infile, temp))
    {

        //cout << temp.find(Newapp_name) << endl;
        if (temp.find(Newapp_name) != string::npos)
        {
            Defult = false;
            //cout << Newapp << "已经存在软件库中，请勿重复写入" << endl;
            break;
        }
    }
    infile.close();

    if (Defult)
    {
        fstream t_infile("software.txt", ios::app);
        //t_infile << "Java" << " " << "1.0" << " " << "54" << " " << "250" << endl;
        t_infile << Newapp_name << " " << newapp_version << " " << newapp_num << " " << newapp_price << endl;
        qDebug() << "软件添加成功" << endl;
        t_infile.close();
        total += 1;
        Head = Instret(Head, Newapp_name, newapp_version, total);
    }
    else {
        qDebug() << QString::fromStdString(Newapp_name) << "已经存在软件库中，请勿重复写入" << endl;
        ifhave = true;//已经有该软件

    }
}


Software_Tree * Add_Software(Software_Tree * Head,int &total,string software_name,string software_version,string software_num,string software_price,bool & ifhave)	//往树中和软件列表中写入新来的软件
{

    string App_name = software_name;			//软件的名字
    string App_versions = software_version;		//软件的版本
    string App_number = software_num;			//软件的剩余数量
    string App_cost = software_price;			//软件的价格



    //以上是将新软件存入树中
    //cout << Head->right->left->left->left->App_name << endl;
    writeTxt(App_name,App_versions,App_number,App_cost,total,Head,ifhave);
    return Head;
}





Software_Tree * Search_Software(Software_Tree * Head, string Software_name)
{
    qDebug() << "第1.1处测试";
    while (Head)
    {
        qDebug() << "第1.2处测试";
        //qDebug() <<Head->App_name.compare(Software_name);
//        if((Head->App_name.compare(Software_name)) < 0)
//        {
//            qDebug() << "第1.31处测试";
//            Head = Head->right;
//            //cout << "Debug" << endl; //有执行
//        }
        qDebug() << Head->location;     //空树？
        qDebug() << "进入判断前";
        if(QString::compare(QString::fromStdString(Head->App_name),QString::fromStdString(Software_name)) < 0)
        {
            qDebug() << "第1.31处测试";
            Head = Head->right;
            //cout << "Debug" << endl; //有执行
        }
        else if (QString::compare(QString::fromStdString(Head->App_name),QString::fromStdString(Software_name)) > 0)
        {
            Head = Head->left;
            qDebug() << "第1.32处测试";
        }
        else{
            return Head;
            qDebug() << "第1.33处测试";
        }
//        else if ((Head->App_name.compare(Software_name)) > 0)
//        {
//            Head = Head->left;
//            qDebug() << "第1.32处测试";
//        }
//        else{
//            return Head;
//            qDebug() << "第1.33处测试";
//        }
    }
    //cout << "找不到" << endl;
    qDebug() << "找不到";
    return nullptr;
}

Software_Tree * Instret(Software_Tree * T, string app_name, string app_versions, int location)
{
    if (!T) T = NewNode(app_name,app_versions,location);
    //该节点为空，则新建一个节点、即递归到了没有左儿子或右儿子时候新建一个左儿子或者右儿子
    else {
        //如果还有左儿子或者右儿子，则进行下面的递归调用
        if (!(T->App_name > app_name))
            T->right = Instret(T->right,app_name,app_versions,location);
        //往右进行递归调用，知道递归到函数所需参数为空时建立一个新节点并返回指向该节点的指针
        else
            T->left = Instret(T->left,app_name,app_versions,location);
        //传入值小于节点值，往右进行递归调用，与上类似
    }
    return T;
}

Software_Tree * NewNode(string app_name, string app_versions, int location)
{
    Software_Tree * TreeNode = new Software_Tree;
    TreeNode->App_name = app_name;
    TreeNode->App_versions = app_versions;
    TreeNode->location = location;
    TreeNode->left = TreeNode->right = NULL;
    return TreeNode;
}

Software_Tree * BuildTree(int total, vector<string> Data)       //创建一颗搜索树
{
    Software_Tree * T;			//树根
    string software[4];			//用于存放软件的所有信息
    int i = 0;
    for (int j = 0; j < Data[0].length(); j++)
    {
        if (Data[0][j] != ' ')				//如果不是空格就将字符加入字符串中
            software[i] += Data[0][j];
        else
        {
            i++;
            continue;
        }
    }
    //将信息分为四块储存在software字符串数组中

    T = NewNode(software[0],software[1],1);
    for (int j = 1; j < total; j++)
    {
        i = 0;
        for (int i = 0; i < 4; i++)
        {
            software[i].clear();
        }
        //清空用于存放软件信息的字符串
        for (int k = 0; k < Data[j].length(); k++)
        {
            if (Data[j][k] != ' ')
                software[i] += Data[j][k];
            else
            {
                i++;
                continue;
            }
        }
        //将向量中剩余的每个软件信息分割为4块

        T = Instret(T,software[0],software[1], j+1);
    }
    return T;

}

void readTxt(string file, vector<string>& Data, int& num)       //读取文件
{
    fstream infile(file);
    string temp;
    assert(infile.is_open());		//若失败,则输出错误消息,并终止程序运行
    while (getline(infile, temp))
    {
        //qDebug() << "readtext中有执行";
        num++;
        //cout << temp << endl;
        Data.push_back(temp);
    }
    //cout << "当前软件数量为" << num << "个" << endl;
    infile.close();				 //关闭文件输入流
}
