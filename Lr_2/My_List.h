#pragma once
#include "Route.h"
using namespace std;

typedef struct Elem
{
	Route* m_data; 
	Elem* next;
	Elem* prev;
} Elem;

class My_List //���������� ������
{
private:
	int m_size = 0;
	Elem* head = NULL;
	Elem* tail = NULL;

public:
	My_List();
	My_List(int size);
	~My_List();

	Route* operator[] (int index);

	int get_size();
	void insert(Route* n_data); //�������� ������� � ������ ������ - ������������� ��������
	void insert(int index); //������� ������� �� ������ - ������������� ��������
	void sort(); //����������� ���������� ��������� �� ��������(��� ���� ���������� �� ������)
	void finding(string name); //����� ��������� ������ �� ��������� � ����������
};