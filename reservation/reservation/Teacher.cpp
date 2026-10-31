#include"Teacher.h"
#include"orderFile.h"

Teacher::Teacher()
{

}

Teacher::Teacher(int empID, string name, string pwd)
{
	this->m_EmpId = empID;
	this->m_Name = name;
	this->m_Pwd = pwd;

}

void Teacher::openMeNU()
{
	cout << "欢迎教师" << this->m_Name << "登录!" << endl;
	cout << "\t\t--------------------------\n";
	cout << "\t\t|                        |\n";
	cout << "\t\t|       1.查看预约       |\n";
	cout << "\t\t|                        |\n";
	cout << "\t\t|       2.审核预约       |\n";
	cout << "\t\t|                        |\n";
	cout << "\t\t|       0.退出登录       |\n";
	cout << "\t\t|                        |\n";
	cout << "\t\t--------------------------\n";
	cout << "请输入您的选择： ";
}

void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "." << endl;
		cout << "预约时间：周" << of.m_orderDate[i]["date"];
		cout << " 时间段：" << (of.m_orderDate[i]["interval"] == "1" ? "上午" : "下午");
		cout << "学号：" << of.m_orderDate[i]["stuId"];
		cout << "姓名：" << of.m_orderDate[i]["stuName"];
		cout << " 机房：" << of.m_orderDate[i]["roomId"];
		string status = "状态：";
		//1 审核中   2 已预约  -1 预约失败  0 取消
		if (of.m_orderDate[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderDate[i]["status"] == "2")
		{
			status += "已预约";
		}
		else if (of.m_orderDate[i]["status"] == "-1")
		{
			status += "预约失败,审核未通过";
		}
		else
		{
			status += "预约已取消";
		}
		cout << status << endl;
	}

		system("pause");
		system("cls");
}

void Teacher::vailOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "待审核的预约记录如下：" << endl;

	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_orderDate[i]["status"] == "1")
		{
			cout << i + 1 << "." << endl;
			cout << "预约时间：周" << of.m_orderDate[i]["date"];
			cout << " 时间段：" << (of.m_orderDate[i]["interval"] == "1" ? "上午" : "下午");
			cout << "学生编号：" << of.m_orderDate[i]["stuId"];
			cout << "学生姓名：" << of.m_orderDate[i]["stuName"];
			cout << " 机房：" << of.m_orderDate[i]["roomId"];
			cout << "状态：审核中" << endl;
		}
	}

	vector<int>v;
	int select = 0;
	int ret = 0;

	while (true)
	{
		cout << "请输入审核通过的预约记录，0代表退出" << endl;
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
				break;
			else
			{
				cout << "请输入审核结果：" << endl;
				cout << "1.通过" << endl;
				cout << "2.不通过" << endl;
				cin >> ret;

				if (ret == 1)
				{
					of.m_orderDate[v[select - 1]]["status"] = "2";
				}
				if (ret == 2)
				{
					of.m_orderDate[v[select - 1]]["status"] = "-1";
				}
				break;
			}
		}
		cout << "输入错误，请重新输入：" << endl;
	}
	system("pause");
	system("cls");
}