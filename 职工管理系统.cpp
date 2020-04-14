#include <iostream>
#include "include/workerManager.h"
#include "include/worker.h"
using namespace std;

//
int main()
{

        WorkerManager   wm;
        int choice=0;
        while (true)
        {
                //展示菜单
                wm.Show_Menu();	
                cout<<"Please input your choice:"<<endl;
                cin>>choice;
                switch (choice)
                {
                case 0:
                        //退出系统
                        wm.ExitSystem(); 
                        break;
                case 1:
                        //增加职工信息
                        wm.Add_Emp();
                        break;
                case 2:
                        //展示信息
                        wm.show_Emp();
                        break;
                case 3:
                        //删除节点
                        wm.Del_Emp();
                        break;
                case 4:
                        //x修改信息
                        wm.Mod_Emp();
                        break;
                case 5:
                        //查找信息
                        wm.Find_Emp();
                        break;
                case 6:
                       //排序
                       wm.Sort_Emp();
                        break;
                case 7:
                        //情况所有文档
                        wm.Clean_Emp();
                        break;
    
                default:
                        system("cls");
                        break;
                }
        }
       
        return  0;
}
