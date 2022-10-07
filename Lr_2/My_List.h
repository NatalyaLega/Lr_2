#pragma once
#include "Route.h"
using namespace std;

typedef struct Elem
{
	Price* m_data;
	Elem* next;
	Elem* prev;
} Elem;

class My_List //двусвязный список
{
private:
	int m_size = 0;
	Elem* head = NULL;
	Elem* tail = NULL;

public:
	My_List();
	My_List(int size);
	~My_List();

	Price* operator[] (int index);

	int get_size();
	void insert(Price* n_data); //добаляем элемент в начало списка - перегруженная операция
	void insert(int index); //удалить элемент из списка - перегруженная операция
	void sort(); //пузырьковая сортировка магазинов по алфавиту
	void finding(string name); //поиск элементов списка по параметру с клавиатуры
};