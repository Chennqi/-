#pragma once

#include <iostream>
#include <string>

//职工抽象基类
class Worker
{
        private:
        public:
        //显示个人信息
        virtual void showInfo()=0;
        //获取岗位名称
        virtual std::string getDeptName()=0;

        //职工编号
        int m_Id;
        //职工姓名
        std::string m_Name;
        //职工所在部门编号
        int m_DeptId;
};

//创建员工类
class Employee :public Worker
{
private:
      
public:
        //构造函数
        Employee(int id,std::string name,int dId);
        ~Employee();
        virtual void showInfo();
        virtual std::string getDeptName();
};

//创建经理类
class Manager :public Worker
{
private:
        
public:
        Manager (int id,std::string name,int dId);
        ~Manager ();
        virtual void showInfo();
        virtual std::string getDeptName();
};

//BOSS类
class Boss :public Worker
{
        private:
        public:
        Boss(int id,std::string name,int dId);
        ~Boss();
        virtual void showInfo();
        virtual std::string getDeptName();
};

