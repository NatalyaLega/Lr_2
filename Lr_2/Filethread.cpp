#include "Filethread.h"
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <fstream>//��� ������ � �������
#include <sstream>//��� ������ �� ��������
#include <string>
#include <cstdio>//feof
#include "Menu.h"
#define MAX_LINE 100
using namespace std;


Filethread::Filethread() { cout << "Constructor Filethread was called." << endl; }

Filethread::~Filethread() { cout << "Destructor Filethread was called." << endl; }

void Filethread::scan_text()
{
	ifstream in;//���� ��� ������
	setlocale(LC_ALL, "rus");//����������� ��������� � �������� �������
	char str[MAX_LINE];//��������� ������ ��� ����� ������ � �������
	FILE* fpin;
	int choise;
	int cnt = 0;
	int count = 0;
	int size = 0;
	bool flag = false;
	char mas[MAX_LINE];
	bool flag1, flag2, flag3;
	flag1 = flag2 = flag3 = 0;
	int flag4 = 0;//���� ��� �� ����� ����
	while (1)
	{//���� ��� �������� ������������ ��������� ������� � ���� {
		cout << "1 - ������ �� �� ���� �����, ���������� 2������� �����\n2 - �����\n\n";//���������� ��� ������������
		cout << "�������� �������:\n";
		
		cin >> choise;
		
		char ch;
		switch (choise)
		{
		case 1: system("cls");
			try
			{
				in.open("test.txt");
				if (!in)//������ �������� �����
				{
					exception err("������ �������� �����\n");
					throw err;
				}
				if (in.peek() == -1)
				{
					exception err("\n����������� ���� ������\n");
					throw err;
				}
				           ///�������� ������///
				while (((ch = in.get()) != EOF)) //���� �� ����� �����
				{
					size++;
					if (ch >= '0' && ch <= '9')
					{
						flag1 = 1;//������ �����
						cnt++;
					}
					else
					{
						if (flag2 == 1 && (ch == ' ' || ch == '\n'))
						{
							flag3 = 1;  //������, ��� 2 ����� � ����� ������� ��� ����� ������
							cnt = 0; //�������� �������
							flag1 = 0;
							flag2 = 0;
							flag4 = 0;
						}
						else
						{
							if (ch == ' ')
								flag4 = 0; //����������� ������-�� �� 1��
							else
								flag4 = 1; //�� �����������
							flag2 = 0;
							flag1 = 0;
							cnt = 0;
						}
					}

					if (flag1 == 1 && cnt == 2 && flag4 == 0) //2 ����� ������
					{
						flag2 = 1;
					}
					if (flag1 == 1 && cnt == 3)//3 ����� ������
					{
						flag1 = 0;
						flag2 = 0;
						cnt = 0;
						flag4 = 0;
					}
					if ((ch == '\n' && flag2 == 1) || (ch == '\n' && flag3 == 1))
					{
						mas[size - 1] = '\0';
						cout << mas << "\n";
						cnt = 0;
						flag1 = flag2 = flag3 = flag4 = 0;

						for (int i = 0; i < size; i++)
						{
							mas[i] = 0;
						}
						size = 0;
						continue;
					}
					else if (ch == '\n')
					{
						flag1 = flag2 = flag3 = flag4 = 0;
						for (int i = 0; i < size; i++)
						{
							mas[i] = 0;
						}
						size = 0;
					}
					if (size != 0)
						mas[size - 1] = ch;

				}
				in.close();
			}
			catch (exception& err)
			{
				cout << err.what() << endl << endl;

				in.close();
				cout << "\n�������� ���� ������.\n";
			}
			if (flag3 == 1 || flag2 == 1)
			{
				mas[size] = '\0';
				cout << mas << "\n";
				cnt = 0;
				flag1 = flag2 = flag3 = flag4 = 0;
			}
			cout << "\n������� ����� ������...\n";
			_getch();
			//return 0;
			break;
		case 2:
			cout << "\n��������� ����������...\n";
			_getch();
			
			break;

		}
	}
}