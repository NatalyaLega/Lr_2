#pragma once
#include "Route.h"
#include "My_List.h"
#include "Filethread.h"
#include <iostream>

using namespace std;

class Menu
{
private:

	My_List list;
	Filethread initfile;
	int exit_main = 1; //����� �� ���������
	int exit_minor = 1; //����� � ����� ����
	int flag_not_show = 1;

public:

	//����� ������
	void main_menu();
	void point_one();
	void exit_from_programm();
	void exit_to_main_menu();
	int show_options_main_menu();

	//������ ��� ������ ����
	int show_options_point_one();
	void show_items_alphabetic_order();
	void find_shop();
	void add_element();
	void redact_element();
	void delete_element();

	//������ ��� ������ ����
	void point_two();
};