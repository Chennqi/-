//防止头文件重复包含
#pragma once
#include    "worker.h"
#include    <fstream>
#define     FILENAME "../src/empFile.txt"
//using  namespace std

class WorkerManager
{
private:
    //文件中的人数
    int m_EmpNum;
    //员工数组的指针
    Worker  **m_EmpArray;
    //标志文件是否为空
    bool m_FileIsEmpty;
public: 
    WorkerManager();
    ~WorkerManager();

    //展示菜单
    void Show_Menu();
    //退出系统
    void ExitSystem();
    //添加职工
    void    Add_Emp();
    //保存函数
    void save();
    //统计人数
    int get_EmpNum();
    //初始化数组
    void init_Emp();
    //显示职工
    void show_Emp();
    //删除职工
    void Del_Emp();
    //判断职工是否存在,存在返回在数组中的位置，不存在返回-1
    int IsExist(int id);
    //修改职工信息
    void Mod_Emp();
    //查找职工
    void Find_Emp();
    //排序
    void Sort_Emp();
    //清空文档
    void Clean_Emp();


};

