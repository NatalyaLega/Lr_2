#include "Route.h"
#include <iostream>
#include <string>

using namespace std;

Route::Route()
{
	cout << "Constructor Route was called." << endl;
}

Route::Route(string start, string end, string number)
{
	this->start = start;
	this->end = end;
	this->number = number;
	cout << "Constructor Route was called." << endl;
}

Route::Route(const Route& Route_copy)
{
	this->start = Route_copy.start;
	this->end = Route_copy.end;
	this->number = Route_copy.number;
	cout << "Copy constructor Route was called." << endl;
}

Route::~Route()
{
	cout << "Destructor Route was called." << endl;
}

void Route::set_start(string start)
{
	this->start = start;
}

void Route::set_end(string end)
{
	this->end = end;
}

void Route::set_number(string number)
{
	this->number = number;
}

string Route::get_start() const
{
	return start;
}

string Route::get_end() const
{
	return end;
}

string Route::get_number() const
{
	return number;
}

void Route::show()
{
	cout << "------------------------------------" << endl;
	cout << "1. Starting point: " << end << endl;
	cout << "2. Final point: " << start << endl;
	cout << "3. Route number: " << number << endl;
	cout << "------------------------------------" << endl;
}

void Route::redact_str(int num_str, string red_str)
{
	switch (num_str)
	{
	case 1:
		this->end = red_str;
		break;
	case 2:
		this->start = red_str;
		break;
	case 3:
		this->number = red_str;
		break;
	default:
		throw "Incorrect number of string!";
		break;
	}
}