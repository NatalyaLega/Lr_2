#pragma once
#include <string>

using namespace std;

class Route
{
private:

	string start; //название начального пункта
	string end; //название конечного пункта
	string number; //номер маршрута

public:

	Route();
	Route(string start, string shop, string number);
	Route(const Route& Price_copy);
	~Route();

	void set_start(string start);
	void set_end(string end);
	void set_number(string number);
	string get_start() const;
	string get_end() const;
	string get_number() const;
	void show();
	void redact_str(int num_str, string red_str);
};