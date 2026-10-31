#include"Manager.h"
#include<fstream>
#include"globalFile.h"
#include<algorithm>

void printStudent(Student & s)
{
	cout << "学号：" << s.m_Id << " 姓名：" << s.m_Name << " 密码：" << s.m_Pwd << endl;
} 

void printTeacher(Teacher& t)
{
	cout << "职工编号：" << t.m_EmpId << " 姓名：" << t.m_Name << " 密码：" << t.m_EmpId << endl;
}

Manager::Manager()
{

}

Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;

	this->intiVector();

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
	cout << "机房的数量为：" << vCom.size() << endl;
}

void Manager::openMeNU()
{
	cout << "欢迎管理员" << this->m_Name << "登录!" << endl;
	cout << "\t\t--------------------------\n";
	cout << "\t\t|                        |\n";
	cout << "\t\t|       1.添加账号       |\n";
	cout << "\t\t|                        |\n";
	cout << "\t\t|       2.查看账号       |\n";
	cout << "\t\t|                        |\n";
	cout << "\t\t|       3.查看机房       |\n";
	cout << "\t\t|                        |\n";
	cout << "\t\t|       4.清空记录       |\n";
	cout << "\t\t|                        |\n";
	cout << "\t\t|       0.退出登录       |\n";
	cout << "\t\t|                        |\n";
	cout << "\t\t--------------------------\n";
	cout << "请输入您的选择： ";
}

void Manager::addPerson()
{
	cout << "请输入你想添加的类型：" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.添加老师" << endl;

	string fileName;
	string tip;
	string errorTip;

	ofstream ofs;


	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//fileName = STUDENT_FILE;
		tip = "请输入对应学生编号：";
		errorTip = "学生编号重复";
		ofs.open(STUDENT_FILE, ios::out | ios::app);

	}
	else if (select == 2)
	{
		//fileName = TEACHER_FILE;
		tip = "请输入对应职工编号：";
		errorTip = "职工编号重复";
		ofs.open(TEACHER_FILE, ios::out | ios::app);
	}
	else
	{
		cout << "输入错误，请重新选择！" << endl;
		system("pasue");
		system("cls");
	}

	//ofs.open(fileName, ios::out | ios::app);

	int id;
	string name;
	string pwd;

	cout << tip << endl;
	cin >> id;
	bool ret = checkPepeat(id, select);
	if (ret)
		cout << errorTip << endl;

	cout << "请输入对应姓名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << endl;
	cout << "添加成功！" << endl;
	ofs.close();

	this->intiVector();

	system("pause");
	system("cls");
	return;

}

void Manager::showPerson()
{
	cout << "请输入你想查看的类型：" << endl;
	cout << "1.查看学生" << endl;
	cout << "2.查看老师" << endl;

	int select;
	cin >> select;
	switch (select)
	{
	case 1:
		cout << "所有学生的信息如下： " << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);

		system("pause");
		system("cls");
		break;

	case 2:
		cout << "所有老师的信息如下： " << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);

		system("pause");
		system("cls");
		break;

	default:
		cout << "输入错误，请再次尝试" << endl;
		system("pause");
		system("cls");
		break;
	}
}

void Manager::showComputer()
{
	cout << "机房的机器如下：" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "机房编号：" << it->m_ComId << "  机房最大容量：" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

void Manager::cleanFile()
{
	cout << "确认清空预约记录？" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;

	int select;
	cin >> select;

	if (select == 1)
	{
		ofstream ofs(ORDER_FILE, ios::trunc);
		ofs.close();
	}
	system("pause");
	system("cls");
}

void Manager:: intiVector()
{
	vStu.clear();
	vTea.clear();

	//学生
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "当前学生数量为：" << vStu.size() << endl;

	//老师
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		return;
	}

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "当前老师数量为：" << vTea.size() << endl;
}

bool Manager:: checkPepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
		return false;
	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
		return false;
	}
}