#include "Filethread.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

Filethread::Filethread() { cout << "Constructor Filethread was called." << endl; }

Filethread::~Filethread() { cout << "Destructor Filethread was called." << endl; }

void Filethread::scan_text()
{
	try
	{
		string str;
		ifstream ifs;
		ifs.open("data.txt");
		if (!ifs.is_open())
		{
			throw "Error opening file!";
		}
		stringstream iss; //строковыводящая переменная
		string buf;
		char c, c1, c2;
		int flag = 0;

		while (getline(ifs, str)) //цикл вывода предложени, начинающихся с однобуквенного слова
		{
			iss << str;
			c1 = iss.get();
			c2 = iss.get();
			if (c2 == ' ' || c2 == '.' || c2 == '?' || c2 == '!' || c2 == ',')
			{
				flag = 1;
			}
			buf.push_back(c1);
			buf.push_back(c2);
			do {
				c = iss.get();
				if (flag == 1)
				{
					buf.push_back(c);
				}
			} while (c != EOF);
			if (flag == 1)
			{
				cout << buf << endl;
			}
			flag = 0;
			iss.clear();
			buf.clear();
		}

		ifs.close();
		ifs.open("data.txt");
		if (!ifs.is_open())
		{
			throw "Error opening file!";
		}

		while (getline(ifs, str)) //цикл вывода остальных предложений
		{
			iss << str;
			c1 = iss.get();
			c2 = iss.get();
			if (c2 != ' ' && c2 != '.' && c2 != '?' && c2 != '!' && c2 != ',')
			{
				flag = 1;
			}
			buf.push_back(c1);
			buf.push_back(c2);
			do {
				c = iss.get();
				if (flag == 1)
				{
					buf.push_back(c);
				}
			} while (c != EOF);
			if (flag == 1)
			{
				cout << buf << endl;
			}
			flag = 0;
			iss.clear();
			buf.clear();
		}
	}
	catch (const char* ex) { cout << "Error: " << ex << endl; }
}