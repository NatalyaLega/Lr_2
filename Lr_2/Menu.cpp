#include "Menu.h"
#include "Filethread.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void Menu::main_menu()
{
	while (exit_main == 1)
	{
		switch (show_options_main_menu())
		{
		case 1:
			point_one();
			break;
		case 2:
			point_two();
			break;
		default:
			exit_from_programm();
			break;
		}
	}
}

int Menu::show_options_main_menu()
{
	int c;
	cout << "Choose the point with whitch you'd like to work:" << endl;
	cout << "1 - Standart threads" << endl;
	cout << "2 - File threads" << endl;
	cout << "0 - Exit from programm" << endl;
	cout << "-> ";
	cin >> c;
	system("cls");
	return c;
}

void Menu::exit_from_programm()
{
	exit_main = 0;
}

void Menu::exit_to_main_menu()
{
	exit_minor = 0;
}

int Menu::show_options_point_one()
{
	system("cls");
	int c;
	cout << "What do you want to do?" << endl;
	cout << "1 - Show all routes (order by numbers)" << endl;
	cout << "2 - Find route by its start or finish" << endl;
	cout << "3 - Add routes" << endl;
	cout << "4 - Redact routes" << endl;
	cout << "5 - Delete routes" << endl;
	cout << "6 - Count same routes " << endl;
	cout << "0 - Back to main menu" << endl;
	cout << "-> ";
	cin >> c;
	system("cls");
	return c;
}

void Menu::show_items_order()
{
	try
	{
		if (list.get_size() == 0)
		{
			throw "There's nothing to show.";
		}

		list.sort();

		for (int i = 0; i < list.get_size(); i++)
		{
			list[i]->show();
		}
	}
	catch (const char* ex) { cout << "Error: " << ex << endl; }
	system("pause");
}

void Menu::find_route()
{
	system("cls");
	string input_name;
	cin.ignore(32767, '\n');
	cout << "Input routes name: ";
	getline(cin, input_name);

	try
	{
		cout << "------------------------------------" << endl;
		list.finding(input_name);
		cout << "------------------------------------" << endl;
	}
	catch (const char* ex) { cout << "Error: " << ex << endl; }
	system("pause");
}


void Menu::add_element()
{
	system("cls");
	try
	{
		for (int i = 1; i <=8; i++) {
			Route* new_route = new Route;
			string new_start, new_end, new_number;

			cin.ignore(32767, '\n');
			cout << "You want to add new item.\nInput its start names: ";
			getline(cin, new_start);
			new_route->set_start(new_start);
			cout << "Input its finish names: ";
			getline(cin, new_end);
			new_route->set_end(new_end);
			cout << "Input its number: ";
			getline(cin, new_number);
			new_route->set_number(new_number);

			list.insert(new_route);
		}
	}
	catch (const char* ex) { cout << "Error: " << ex << endl; }
	system("pause");
}

void Menu::redact_element()
{
	system("cls");
	int c2, c3;
	string redact;

	try
	{
		if (list.get_size() == 0)
		{
			throw "There's nothing to redact.";
		}
		list.sort();
		for (int i = 0; i < list.get_size(); i++)
		{
			list[i]->show();
		}

		cout << "\nWhat element do you want to change (from 1 to " << list.get_size() << "): " << endl;
		cin >> c2;

		if (c2 < 1 || c2 > list.get_size())
		{
			throw "Incorrect number!";
		}

		list[c2 - 1]->show();
		cout << "Input string which you want to change: " << endl;
		cin >> c3;
		cin.ignore(32767, '\n');
		cout << "Input new value in this string: " << endl;
		getline(cin, redact);
		list[c2 - 1]->redact_str(c3, redact);
		cout << "The string was redacted." << endl;
	}
	catch (const char* ex) { cout << "Error: " << ex << endl; }
	system("pause");
}

void Menu::delete_element()
{
	system("cls");
	int c2;
	try
	{
		if (list.get_size() == 0)
		{
			throw "There's nothing to delete.";
		}
		list.sort();
		for (int i = 0; i < list.get_size(); i++)
		{
			list[i]->show();
		}

		cout << "\nWhat element do you want to delete (from 1 to " << list.get_size() << "): " << endl;
		cin >> c2;

		if (c2 < 1 || c2 > list.get_size())
		{
			throw "Incorrect number!";
		}

		list.insert(c2);
	}
	catch (const char* ex) { cout << "Error: " << ex << endl; }
	system("pause");
}

void Menu::countt_route()
{
	system("cls");
	string input_name;
	cin.ignore(32767, '\n');
	cout << "Input routes name: ";
	getline(cin, input_name);

	try
	{
		cout << "------------------------------------" << endl;
		list.count_route(input_name);
		cout << "------------------------------------" << endl;
	}
	catch (const char* ex) { cout << "Error: " << ex << endl; }
	system("pause");
}

void Menu::point_one()
{
	while (exit_minor == 1)
	{
		switch (show_options_point_one())
		{
		case 1:
			show_items_order();
			break;
		case 2:
			find_route();
			break;
		case 3:
			add_element();
			break;
		case 4:
			redact_element();
			break;
		case 5:
			delete_element();
			break;
		case 6:
			countt_route();
		case 0:
			exit_to_main_menu();
			break;
		default:
			exit_to_main_menu();
			break;
		}
	}
}

void Menu::point_two()
{
	initfile.scan_text();
}