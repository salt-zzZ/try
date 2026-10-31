#pragma once
#include<iostream>
using namespace std;
#include"Indentity.h"
#include<vector>
#include"Studemt.h"
#include"Teacher.h"
#include"computerRoom.h"

class Manager : public Identity
{
public:
	Manager();

	Manager(string name, string pwd);

	virtual void openMeNU();

	void addPerson();

	void showPerson();

	void showComputer();

	void cleanFile();

	void intiVector();

	bool checkPepeat(int id, int type);

	vector<Student>vStu;
	vector<Teacher>vTea;
	vector<ComputerRoom>vCom;
};