﻿#include "Route.h"
#include "Menu.h"
#include "My_List.h"
/* 
1. Определить класс с именем ROUTE, содержащий следующие поля:
● название начального пункта маршрута;
● название конечного пункта маршрута;
● номер маршрута.
Определить методы доступа к этим полям и перегруженные операции
извлечения и вставки для объектов типа ROUTE.
Написать программу, выполняющую следующие действия:
● ввод с клавиатуры данных в массив, состоящий из восьми объектов
типа ROUTE; записи должны быть упорядочены по номерам
маршрутов;
● вывод на экран информации о маршрутах, которые начинаются или
кончаются в пункте, название которого введено с клавиатуры;
● если таких маршрутов нет, выдать на дисплей соответствующее
сообщение.
2. Файловые и строковые потоки
С использованием файловых и строковых потоков написать программу,
которая считывает текст из файла и выводит на экран только строки, не
содержащие двузначные числа.
*/
int main()
{
	Menu start;
	start.main_menu();
	return 0;
}