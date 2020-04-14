#include	"workerManager.h"
#include	"worker.h"
#include <iostream>
#include <fstream>

using namespace	std;

WorkerManager::WorkerManager()
{	
	//初始化
	m_EmpNum=0;
	m_EmpArray=NULL;
	
	ifstream	ifs;
	ifs.open(FILENAME,ios::in);
	//判断文件是存在
	if(!ifs.is_open())
	{
     		cout<<FILENAME<<"文件不存在"<<endl;
     		this->m_EmpNum=0;
		this->m_EmpArray=NULL;
		this->m_FileIsEmpty=true;
		ifs.close();
		return; 
	}
	char ch;
	 ifs>>ch;
	//判断文件是否为空
	if(ifs.eof())
	{
		cout<<FILENAME<<"文件为空"<<endl;
     		this->m_EmpNum=0;
		this->m_EmpArray=NULL;
		this->m_FileIsEmpty=true;
		ifs.close();
		return; 
	}
	//文件不为空
	this->m_FileIsEmpty=false;
	this->m_EmpNum=get_EmpNum();
	cout<<"职工人数为"<<this->m_EmpNum<<endl;

	//根据人数创建数组
	this->m_EmpArray=new Worker 	*[this->m_EmpNum];
	//讲文件中的数据存放到数组中
	this->init_Emp();
	
	
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray!=NULL)
	{
		for(int i=0;i<this->m_EmpNum;i++)
		{
			if (this->m_EmpArray[i]!=NULL)
			{
				delete	this->m_EmpArray[i];
			}
	 			
		}
		this->m_EmpNum=0;
		delete[] this->m_EmpArray;
		this->m_EmpArray=NULL;
		this->m_FileIsEmpty=true;
	}

}

//展示菜单
void    WorkerManager::Show_Menu()
{
	cout<<"*********************************************************"<<endl;
	cout<<"************欢迎使用职工管理系统*************************"<<endl;
	cout<<"***************0.退出管理程序****************************"<<endl;
	cout<<"***************1.增加职工信息****************************"<<endl;
	cout<<"***************2.显示职工信息****************************"<<endl;
	cout<<"***************3.删除离职职工****************************"<<endl;
	cout<<"***************4.修改职工信息****************************"<<endl;
	cout<<"***************5.查找职工信息****************************"<<endl;
	cout<<"***************6.按照编号排序****************************"<<endl;
	cout<<"***************7.清空所有文档****************************"<<endl;
	cout<<"*********************************************************"<<endl;

}
void WorkerManager::ExitSystem()
{
	cout<<"欢迎下次使用"<<endl;
	
	//正常退出：系统调用级别的退出，表示一个进程退出
	exit(0);
}

  void	WorkerManager::Add_Emp()
  {
	  cout<<"Please input the number of Employee needs to add:"<<endl;
	  int addNum;
	  cin>>addNum;

	  if(addNum>0)
	  {	
		  //计算新的空间的大小
		int newsize=this->m_EmpNum+addNum;
		//开辟新空间
		Worker	**newspace=new Worker*[newsize];

		//将原空间的内容存放到新空间下
		if(this->m_EmpArray!=NULL)
		{
			for(int i=0;i<this->m_EmpNum;i++)
			{
				newspace[i]=this->m_EmpArray[i];
			}
		} 
		//输入新数据
		for(int i=0;i<addNum;i++)
		{
			int id;
			string	name;
			int dSelect;

			cout<<"请输入第"<<i+1<<"位新员工编号"<<endl;
			cin>>id;
			cout<<"请输入第"<<i+1<<"位新员工姓名"<<endl;
			cin>>name;

			cout<<"请选择新员工的岗位："<<endl;
			cout<<"1. 普通员工"<<endl;
			cout<<"2. 经理"<<endl;
			cout<<"3. 老板"<<endl;
			cin>>dSelect;

			Worker *worker=NULL;
			switch (dSelect )
			{
			case 1:
				worker=new Employee(id,name,dSelect);
				break;
			case 2:
				worker=new Employee(id,name,dSelect);
				break;
			case 3:
				worker=new Employee(id,name,dSelect);
				break;
			
			default:
				break;
			}
		newspace[this->m_EmpNum+i]=worker;

		}

		 delete[] this->m_EmpArray;

		 this->m_EmpArray=newspace;

		 this->m_EmpNum=newsize;   

		 this->m_FileIsEmpty=false;

		 cout<<"成功添加"<<addNum<<"名新员工"<<endl;
		 //保存到文件中
		 this->save();
		 

	  }
	  else
	  {
		  cout<<"输入有误！"<<endl;
	  }
	  
  }

  void WorkerManager::save()
  {
	ofstream	ofs;
	ofs.open(FILENAME,ios::out);

	//
	if(!ofs)
	{
     		cout<<"打开文件失败！"<<FILENAME<<endl;
     		exit(1);//失败退回操作系统   
	}
	for(int i=0;i<m_EmpNum;i++)
	{
		ofs<<this->m_EmpArray[i]->m_Id<<"	"
		  	<<this->m_EmpArray[i]->m_Name<<"	"
			<<this->m_EmpArray[i]->m_DeptId<<"	"<<endl;

	}
	ofs.close();  
  }

int WorkerManager::get_EmpNum()
{
	ifstream	ifs;
	ifs.open(FILENAME,ios::in);

	int Id;
	string	name;
	int	dId;

	int Num=0;
	 
	 while (ifs>>Id&&ifs>>name&&ifs>>dId)
	 {
		 Num++;
	 }
	 ifs.close();

	 return	Num;
}

void WorkerManager::init_Emp()
{
	ifstream	ifs;
	ifs.open(FILENAME,ios::in);

	int Id;
	string	name;
	int dId;

	int	index=0;
	 while (ifs>>Id&&ifs>>name&&ifs>>dId)
	 {
		 Worker		*worker=NULL;
		 if (dId==1)
		 {
			 worker=new Employee(Id,name,dId);
		 }
		 else if (dId==2)
		 {
			 worker=new Manager(Id,name,dId);
		 }
		 else if (dId==3)
		 {
			 worker=new Boss(Id,name,dId);
		 }	
		 this->m_EmpArray[index]=worker;
		index++;
	 }
	 ifs.close();
}
//显示职工
void WorkerManager::show_Emp()
{
	if(this->m_FileIsEmpty)
	{
		cout<<"文件为空！"<<endl;
	}
	else
	{
		for(int i=0;i<this->m_EmpNum;i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}	
}
 //删除职工
void WorkerManager::Del_Emp()
{	
	if(this->m_FileIsEmpty)
	cout<<"文件不存在或内容为空"<<endl;
	else
	{
		cout<<"Plese input the number of the worker to be delete:"<<endl;
		int id=0;
		cin>>id;
		int index=this->IsExist(id);
		//若职工存在，则删除
		if( index!=-1)
		{	
			delete	this->m_EmpArray[index];
			for(int i= index;i<this->m_EmpNum-1;i++)
			{	
				//数据前移
				this->m_EmpArray[i]=this->m_EmpArray[i+1];
			}
			this->m_EmpNum--;
			//数据保存到文件中
			this->save();
			cout<<"删除成功！"<<endl;


		}
		else
		{
			cout<<"删除失败！ "<<endl;
		}
		
	}

}
 //判断职工是否存在,存在返回在数组中的位置，不存在返回-1
int WorkerManager::IsExist(int id)
{
	int index=-1;
	for (int i = 0; i<this->m_EmpNum; i++)
	{	
		
		if(this->m_EmpArray[i]->m_Id==id)
		{
			index=i;
		}
	}
	return	index;
}
//修改职工信息
void WorkerManager::Mod_Emp()
{
	if(this->m_FileIsEmpty)
	{
		cout<<"文件不存在！"<<endl;
	}
	else
	{
		cout<<"请输入需要修改的职工的编号："<<endl;
		int id;
		cin>>id;
		int index=this->IsExist(id);
		if (index!=-1)
		{
			delete	this->m_EmpArray[index];
			int newId=0;
			string	newname="";
			int dSelect=0;

			cout<<"查找到："<<id<<"号职工,请输入新工号"<<endl;
			cin>>newId;
			cout<<"请输入新姓名："<<endl;
			cin>>newname;

			cout<<"请选择新员工的岗位："<<endl;
			cout<<"1. 普通员工"<<endl;
			cout<<"2. 经理"<<endl;
			cout<<"3. 老板"<<endl;
			cin>>dSelect;

			Worker *worker=NULL;
			switch (dSelect )
			{
			case 1:
				worker=new Employee(id,newname,dSelect);
				break;
			case 2:
				worker=new Employee(id,newname,dSelect);
				break;
			case 3:
				worker=new Employee(id,newname,dSelect);
				break;
			
			default:
				break;
			}
			this->m_EmpArray[index]=worker;

			cout<<"修改成功！"<<endl;

			this->save();
		}
		else
		{
			cout<<"修改失败，查无此人！"<<endl;
		}			
	}
}
  //查找职工
void WorkerManager::Find_Emp()
{
	if(this->m_FileIsEmpty)
	{
		cout<<"文件不存在！"<<endl;
	}
	else
	{
		cout<<"请输入查找的方式："<<endl;
		cout<<"1.按职工编号查找"<<endl;
		cout<<"2.按职工姓名查找"<<endl;
		int dSelect;
		cin>>dSelect;

		if (dSelect==1 )
		{
			int id;
			cout<<"请输入职工编号："<<endl;
			cin>>id;

			int index=this->IsExist(id);
			if (index!=-1)
			{
				cout<<"查找成功，信息如下"<<endl;
				this->m_EmpArray[index]->showInfo();
			}
			else
			{
				cout<<"查无此人！"<<endl;
			}
		}
		else if (dSelect==2)
		{
			string	name;
			cout<<"请输入职工姓名："<<endl;
			cin>>name;

			bool flag=false;
			for(int i=0;i<this->m_EmpNum;i++)
			{
				if (name==this->m_EmpArray[i]->m_Name)	
				{
					cout<<"查找成功，信息如下"<<endl;
					this->m_EmpArray[i]->showInfo();
					flag=true;
				}			
			}
			if (flag==false)
			{
				cout<<"查无此人！"<<endl;
			}
		}
		else
		{
			cout<<"查询方式有误！"<<endl;
		}
				
	}
}
    //排序
 void WorkerManager::Sort_Emp()
 {
	if(this->m_FileIsEmpty)
	{
		cout<<"文件不存在！"<<endl;
	}
	else
	{
		cout<<"请输入排序的方式："<<endl;
		cout<<"1.按职工编号升序排序"<<endl;
		cout<<"2.按职工编号降序排序"<<endl;

		int dSelect;
		cin>>dSelect;

		for(int i=0;i<this->m_EmpNum;i++)
		{
			int MinOrMax=i;
			for(int j=i+1;j<this->m_EmpNum;j++)
			{
				if (dSelect==1)//升序排序
				{
					if (this->m_EmpArray[MinOrMax]->m_Id>this->m_EmpArray[j]->m_Id)
					{
						MinOrMax=j;//最小值
					}
				}
				else if (dSelect==2)
				{
					if (this->m_EmpArray[MinOrMax]->m_Id<this->m_EmpArray[j]->m_Id)
					{
						MinOrMax=j;//最大值
					}
				}
			}
			if (i!=MinOrMax)
			{
				Worker	*temp=this->m_EmpArray[i];
				this->m_EmpArray[i]=this->m_EmpArray[MinOrMax];
				this->m_EmpArray[MinOrMax]=temp;
			}						
		 }
		 cout<<"排序完成！"<<endl;
	}	
}
//清空
void WorkerManager::Clean_Emp()
{
	cout<<"确认清空？？？"<<endl;
	cout<<"1.确认"<<endl;
	cout<<"2.取消"<<endl;

	int dSelect;
	cin>>dSelect;

	if (dSelect==1)
	{
		ofstream ofs;
		ofs.open(FILENAME,ios::trunc);
		ofs.close();

		if (this->m_EmpArray!=NULL)
		{
			for(int i=0;i<this->m_EmpNum;i++)
			{
				if (this->m_EmpArray[i]!=NULL)
				{
					delete	this->m_EmpArray[i];
				}
				
			}
			this->m_EmpNum=0;
			delete[] this->m_EmpArray;
			this->m_EmpArray=NULL;
			this->m_FileIsEmpty=true;
		}
		cout<<"文件清理完毕！"<<endl;
	}
	

}