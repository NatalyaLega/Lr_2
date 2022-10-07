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
	cout << "1 - Show all items (alphabetic order by shops)" << endl;
	cout << "2 - Find shop by its name" << endl;
	cout << "3 - Add element" << endl;
	cout << "4 - Redact element" << endl;
	cout << "5 - Delete element" << endl;
	cout << "0 - Back to main menu" << endl;
	cout << "-> ";
	cin >> c;
	system("cls");
	return c;
}

void Menu::show_items_alphabetic_order()
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

void Menu::find_shop()
{
	system("cls");
	string input_name;
	cin.ignore(32767, '\n');
	cout << "Input shop name: ";
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
		Price* new_price = new Price;
		string new_item, new_shop, new_cost;

		cin.ignore(32767, '\n');
		cout << "You want to add new item.\nInput its name: ";
		getline(cin, new_item);
		new_price->set_item(new_item);
		cout << "Input its shop: ";
		getline(cin, new_shop);
		new_price->set_shop(new_shop);
		cout << "Input its cost in rubles: ";
		getline(cin, new_cost);
		new_price->set_cost(new_cost);

		list.insert(new_price);
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

void Menu::point_one()
{
	while (exit_minor == 1)
	{
		switch (show_options_point_one())
		{
		case 1:
			show_items_alphabetic_order();
			break;
		case 2:
			find_shop();
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