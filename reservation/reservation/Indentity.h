#pragma once
#include<iostream>
using namespace std;
#include<string>

class Identity
{
public:

	virtual void openMeNU() = 0;

	string m_Name;
	string m_Pwd;
};