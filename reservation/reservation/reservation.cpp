#include<iostream>
using namespace std;
#include"Indentity.h"
#include"globalFile.h"
#include<fstream>

#include"Studemt.h"
#include"Teacher.h"
#include"Manager.h"

void TeacherMeNu(Identity*& teacher)
{
	while (true)
	{
		teacher->openMeNU();
		Teacher* tea = (Teacher*)teacher;

		int select = 0;
		cin >> select;

		switch (select)
		{
		case 1:
			tea->showAllOrder();
			break;
		case 2:
			tea->vailOrder();
			break;
		case 0:
			delete teacher;
			cout << "退出成功！" << endl;
			system("pause");
			system("cls");
			break;
		default:
			cout << "输入错误，请重新选择！" << endl;
			system("pasue");
			system("cls");
			break;

		}
	}
}

void StudentMeNu(Identity*& student)
{
	while (true)
	{
		student->openMeNU();
		Student* stu = (Student*)student;

		int select = 0;
		cin >> select;

		switch (select)
		{
		case 1:
			cout << "申请预约" << endl;
			stu->applyOrder();
			break;
		case 2:
			cout << "查看预约" << endl;
			stu->showMyOrder();
			break;
		case 3:
			cout << "查看所有预约" << endl;
			stu->showAllOrder();
			break;
		case 4:
			cout << "取消预约" << endl;
			stu->cancelOrder();
			break;
		case 0:
			delete student;
			cout << "退出成功！" << endl;
			system("pause");
			system("cls");
			break;
		default:
			cout << "输入错误，请重新选择！" << endl;
			system("pasue");
			system("cls");
			break;
		}
		
	}
}



void ManagerMeNu(Identity*& manager)
{
	while (true)
	{
		manager->openMeNU();
		Manager* man = (Manager*) manager;

		int select = 0;
		cin >> select;

		switch (select)
		{
		case 1:
			cout << "添加账号: " << endl;
			man->addPerson();
			break;
		case 2:
			cout << "查看账号：" << endl;
			man->showPerson();
			break;
		case 3:
			cout << "查看机房：" << endl;
			man->showComputer();
			break;
		case 4:
			cout << "清空记录" << endl;
			man->cleanFile();
			break;
		case 0:
			delete manager;
			cout << "退出成功！" << endl;
			system("pause");
			system("cls");
			break;
		default:
			cout << "输入错误，请重新选择！" << endl;
			system("pasue");
			system("cls");
			break;
		}

	}
}

void LoginIn(string fileName, int type)
{
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		system("pause");
		system("cls");
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1)
	{
		cout << "请输入你的学号： " << endl;
		cin >> id;
	}
	if (type == 2)
	{
		cout << "请输入你的职工编号： " << endl;
		cin >> id;
	}


	cout << "请输入用户名： " << endl;
	cin >> name;
	cout << "请输入你的密码： " << endl;
	cin >> pwd;

	if (type == 1)
	{
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);

				StudentMeNu(person);
				return;
			}
		}
	}
	if (type == 2)
	{
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "职工验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);


				return;
			}
		}
	}
	if (type == 3)
	{
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "管理员验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);

				ManagerMeNu(person);
				return;
			}
		}

	}

	cout << "验证登录失败！" << endl;
	system("pause");
	system("cls");
	return;
}

int main()
{
	while (true)
	{
		cout << "============欢迎来到智能机房系统============" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t--------------------------\n";
		cout << "\t\t|                        |\n";
		cout << "\t\t|       1.学生代表       |\n";
		cout << "\t\t|                        |\n";
		cout << "\t\t|       2.教师代表       |\n";
		cout << "\t\t|                        |\n";
		cout << "\t\t|        3.管理员        |\n";
		cout << "\t\t|                        |\n";
		cout << "\t\t|         0.退出         |\n";
		cout << "\t\t|                        |\n";
		cout << "\t\t--------------------------\n";
		cout << "请输入您的选择： ";
		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1:
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "欢迎您下次使用！" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入错误，请重新选择！" << endl;
			system("pasue");
			system("cls");
			break;
		}
	}

	return 0;
}