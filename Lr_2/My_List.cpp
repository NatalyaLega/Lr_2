#include <iostream>
#include <cstdlib>
#include <string>
#include "My_List.h"

using namespace std;

My_List::My_List() : m_size(0), head(NULL), tail(NULL) {}

My_List::My_List(int size) : head(NULL), tail(NULL) { this->m_size = size; }

My_List::~My_List()
{
	if (head != NULL)
	{
		Elem* buffer;
		while (head->next != NULL)
		{
			buffer = head;
			head = head->next;
			buffer->m_data->~Price();
			delete(buffer);
		}
		head->m_data->~Price();
		delete(head);
	}
}

Price* My_List::operator[] (const int index)
{
	if ((index >= m_size) || (index < 0))
	{
		throw "Incorrect index!";
	}
	else
	{
		Elem* buffer = head;
		for (int i = 0; i < m_size - index - 1; i++)
		{
			buffer = buffer->next;
		}
		return (buffer->m_data);
	}
}

void My_List::insert(int index)
{
	Elem* buffer = head;

	if (m_size == 0)
	{
		throw "There's nothing to delete.";
	}

	if ((index >= m_size) || (index < 0))
	{
		throw "Incorrect index.";
	}

	if (buffer->next == NULL)
	{
		buffer->m_data->~Price();
		--m_size;
		return;
	}

	if (index == 0)
	{
		head = buffer->next;
		head->prev = 0;
		buffer->m_data->~Price();
		--m_size;
		return;
	}

	for (int i = 0; i < index - 1; i++)
	{
		buffer = buffer->next; //Переходим на элемент перед удаляемым
	}

	Elem* buffer1 = buffer1 = buffer->next; //переходим на удаляемый элемент
	buffer->next = buffer1->next;//присавеваем указатель на следующий

	buffer1->m_data->~Price();
	--m_size;
}

void My_List::insert(Price* n_data)
{
	Elem* tmp = new Elem;
	tmp->prev = 0;
	tmp->m_data = n_data;
	tmp->next = head;

	if (head != NULL)
	{
		head->prev = tmp;
	}

	if (m_size == 0)
	{
		head = tail = tmp;
	}
	else
	{
		head = tmp;
	}

	m_size++;
}

int My_List::get_size() { return m_size; }

void My_List::sort()
{
	if (m_size <= 1)
	{
		throw "There's nothing to sort.";
	}
	Elem* left = head;
	Elem* right = head->next;
	Elem* temp = new Elem;

	while (left->next)
	{
		while (right)
		{
			string lper = left->m_data->get_shop();
			string rper = right->m_data->get_shop();
			if (lper.compare(rper) < 0)
			{
				temp->m_data = left->m_data;
				left->m_data = right->m_data;
				right->m_data = temp->m_data;
			}
			right = right->next;
		}
		left = left->next;
		right = left->next;
	}
}

void My_List::finding(string name)
{
	if (m_size == 0)
	{
		throw "There's nothing to find, the list is empty.";
	}

	Elem* tmp;
	tmp = head;
	int shop_is_in = 0; //признак отстутствия введенного названия магазина
	//int name_shop = 0; //признак вывода названия магазина на экран

	for (int i = 0; i < m_size; i++)
	{
		if (tmp->m_data->get_shop().compare(name) == 0)
		{
			cout << tmp->m_data->get_item() << ", " << tmp->m_data->get_cost() << endl;

			shop_is_in = 1;
		}
		tmp = tmp->next;
	}

	if (shop_is_in == 0)
	{
		throw "There's no inputtes shop.";
	}
	//system("pause");
}