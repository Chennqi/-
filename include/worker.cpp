#include "worker.h"
//#include <string>

//员工基类
Employee::Employee(int id,std::string name,int dId)
{
        this->m_Id =id;
        this->m_Name=name;
        this->m_DeptId=dId;

       
}

void    Employee::showInfo()
{
        std::cout<<"职工编号："<<this->m_Id<<std::endl;
        std::cout<<"职工姓名："<<this->m_Name<<std::endl;
        std::cout<<"职工岗位："<<this->m_DeptId<<std::endl;
        std::cout<<"岗位职责：  完成经理交给的任务"<<std::endl;

}
std::string Employee::getDeptName()
{
        return std::string("员工");
}

//Manager派生类
Manager::Manager(int id,std::string name,int dId)
{
        this->m_Id =id;
        this->m_Name=name;
        this->m_DeptId=dId;

}

void Manager::showInfo()
{
        std::cout<<"职工编号："<<this->m_Id<<std::endl;
        std::cout<<"职工姓名："<<this->m_Name<<std::endl;
        std::cout<<"职工岗位："<<this->m_DeptId<<std::endl;
        std::cout<<"岗位职责：  完成老板交给的任务，并发布任务给员工"<<std::endl;
}

std::string Manager::getDeptName()
{
        return std::string("Manager");
}

//Boss类
Boss::Boss(int id,std::string name,int dId)
{
        this->m_Id =id;
        this->m_Name=name;
        this->m_DeptId=dId;
}


void Boss::showInfo()
{
         std::cout<<"职工编号："<<this->m_Id<<std::endl;
        std::cout<<"职工姓名："<<this->m_Name<<std::endl;
        std::cout<<"职工岗位："<<this->m_DeptId<<std::endl;
        std::cout<<"岗位职责：发布任务给经理"<<std::endl;

}

std::string Boss::getDeptName()
{
        return std::string("Boss");
}