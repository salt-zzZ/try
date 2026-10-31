#pragma once
#include<iostream>
using namespace std;
#include"Indentity.h"
#include<vector>
#include"computerRoom.h"
#include"orderFile.h"

class Student : public Identity
{
public:
	//默认构造
	Student();

	//有参构造
	Student(int id, string name, string pwd);

	//展示菜单
	virtual void openMeNU();

	//申请预约
	void applyOrder();

	//查看自身预约
	void showMyOrder();

	//展示所有预约
	void showAllOrder();

	//取消预约
	void cancelOrder();

	vector<ComputerRoom>vCom;

	//学生学号
	int m_Id;
};