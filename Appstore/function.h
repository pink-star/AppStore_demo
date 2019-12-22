#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <QMetaType>

using namespace std;

class Software_Tree
{
public:
    string App_name;
    string App_versions;
    int location;
    Software_Tree * left;
    Software_Tree * right;
};

Q_DECLARE_METATYPE(Software_Tree);

extern int Defult;


extern vector<int> Deleteline;
void readTxt(string, vector<string>&, int&);																						//读取文件
void writeTxt(string Newapp_name, string newapp_version, string newapp_num, string newapp_price,int& total,Software_Tree * Head,bool &);	//写入文件
void DeleteFile(vector<int>,int total);
Software_Tree * Buysoftware(Software_Tree * Head, string software_name,bool &);																//购买软件
Software_Tree * BuildTree(int total, vector<string> Data);						//建立二叉树的函数
Software_Tree * NewNode(string app_name,string app_versions,int location);		//建数时候建立新节点
Software_Tree * Instret(Software_Tree * T, string app_name, string app_versions, int location);		//插入新节点
Software_Tree * Search_Software(Software_Tree * Head, string Software_name);	//传入一颗二叉搜索树搜索树中的软件
Software_Tree * Add_Software(Software_Tree * Head,int &total,string,string,string,string,bool &);					//添加软件						//往树中和软件列表中写入新来的软件
Software_Tree * Delete_Software(Software_Tree * Head, string Software_name);	//往树中和软件列表中删除售空的软件
string CharToStr(char * contentChar);
Software_Tree * Delete_TreeNode(string softwarename, Software_Tree * Head);
Software_Tree * FindMin(Software_Tree * Head);
void DeleteFile_inUi(int linenum);

#endif // FUNCTION_H
