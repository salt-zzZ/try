#include"orderFile.h"
#include<fstream>
#include"globalFile.h"

OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;
	string interval;
	string stuId;
	string stuName;
	string roomId;
	string status;

	this->m_Size = 0;

	while (ifs >> date && ifs >> interval && ifs >> roomId && ifs >> stuId && ifs >> stuName && ifs >> status)
	{
		//cout << date << endl;
		//cout << interval << endl;
		//cout << stuId << endl;
		//cout << stuName << endl;
		//cout << roomId << endl;
		//cout << status << endl;

		string key;
		string val;
		map<string, string>m;

		//date:1
		int pos = date.find(":"); //4
		if (pos != -1)
		{
			key = date.substr(0, pos);
			val = date.substr(pos + 1, date.size());
		}
		
		pos = interval.find(":"); //4
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			val = interval.substr(pos + 1, interval.size());
		}

		pos = roomId.find(":"); //4
		if (pos != -1)
		{
			key = roomId.substr(0, pos);
			val = roomId.substr(pos + 1, roomId.size());
		}

		pos = status.find(":"); //4
		if (pos != -1)
		{
			key = status.substr(0, pos);
			val = status.substr(pos + 1, status.size());
		}

		this->m_orderDate.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}
	ifs.close();
}

void OrderFile::updateOrder()
{
	if (this->m_Size == 0)
	{
		return;
	}
	ofstream ofs(ORDER_FILE, ios::out || ios::trunc);
	for (int i = 0; i < this->m_Size; i++)
	{
		ofs << "date:" << this->m_orderDate[i]["date"] << " ";
		ofs << "interval:" << this->m_orderDate[i]["interval"] << " ";
		ofs << "stuId:" << this->m_orderDate[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderDate[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_orderDate[i]["rooomId"] << " ";
		ofs << "status:" << this->m_orderDate[i]["status"] << endl;
	}

	ofs.close();
}