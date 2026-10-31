#pragma once
#include<iostream>
using namespace std;
#include"Indentity.h"
#include<vector>


class Teacher : public Identity
{
public:
	Teacher();
	Teacher(int empID, string nmae, string pwd);

	virtual void openMeNU();
	
	void showAllOrder();

	void vailOrder();

	int m_EmpId;
};