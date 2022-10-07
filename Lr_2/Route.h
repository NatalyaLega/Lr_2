#pragma once
#include <string>

using namespace std;

class Price
{
private:

	string item; //название товара
	string shop; //название магазина
	string cost; //цена товара в рублях

public:

	Price();
	Price(string item, string shop, int cost);
	Price(const Price& Price_copy);
	~Price();

	void set_item(string item);
	void set_shop(string shop);
	void set_cost(string cost);
	string get_item() const;
	string get_shop() const;
	string get_cost() const;
	void show();
	void redact_str(int num_str, string red_str);
};