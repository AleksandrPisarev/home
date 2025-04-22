//Создайте программу, имитирующую многоквартирный
//дом.Необходимо иметь классы “Человек”, “Квартира”,
//“Дом”.Класс “Квартира” содержит динамический массив
//объектов класса “Человек”.Класс “Дом” содержит массив
//объектов класса “Квартира”.
//Каждый из классов содержит переменные - члены и функции - члены, которые необходимы для предметной области
//класса.Обращаем ваше внимание, что память под строковые значения выделяется динамически.Например, для
//ФИО в классе “Человек”.Не забывайте обеспечить классы
//различными конструкторами(конструктор копирования
//обязателен), деструкторами.В main протестировать работу полученного набора классов.
#include <iostream>
#include <string>
using namespace std;
#include "class.h"
#include "function.h"
int main() {
	setlocale(0, "ru");
	int quantity, choice, number;
	house h;
	cout << "Введите сколько в доме будет квартир: ";
	cin >> quantity;
	h.setHouse(quantity);
	for (int i = 0; i < h.getQuantity_flat(); i++) {
		cout << "Введите сколько человек будет проживать в квартире № " << h.getFlat_arr()[i].getNumber_flat() << " : ";
		cin >> quantity;
		h.getFlat_arr()[i].setFlat(quantity);
	}
	cin.ignore();
	for (int i = 0; i < h.getQuantity_flat(); i++) {
		for (int j = 0; j < h.getFlat_arr()[i].getQuantity_human(); j++) {
			cout << "Квартира №: " << h.getFlat_arr()[i].getNumber_flat() << ", человек id №: " << h.getFlat_arr()[i].getHuman_arr()[j].getId() << endl;
			h.getFlat_arr()[i].getHuman_arr()[j].setHuman();
		}
	}
	do
	{
		cout << "Выберите действие:" << endl;
		cout << "1. Показать сколько в доме квартир." << endl;
		cout << "2. Показать сколько проживает человек в квартире." << endl;
		cout << "3. Показать данные людей проживающих в квартире." << endl;
		cout << "4. Удалить человека из квартиры." << endl;
		cout << "5. Добавить человека в квартиру." << endl;
		cout << "6. Выход." << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "В доме расположены " << h.getQuantity_flat() << " квартиры." << endl;
			break;
		case 2:
			cout << "Последняя квартира с номером " << h.getQuantity_flat() << " Введите номер квартиры: ";
			cin >> number;
			cout << "В квартире № " << h.getFlat_arr()[number-1].getNumber_flat() << " проживает: " << h.getFlat_arr()[number-1].getQuantity_human() << " человека." << endl;
			break;
		case 3:
			cout << "Последняя квартира с номером " << h.getQuantity_flat() << " Введите номер квартиры: ";
			cin >> number;
			if (h.getFlat_arr()[number - 1].getHuman_arr() == nullptr) {
				cout << "В квартире № " << number << " никто не проживает." << endl;
			}
			else {
				for (int i = 0; i < h.getFlat_arr()[number - 1].getQuantity_human(); i++) {
					h.getFlat_arr()[number - 1].getHuman_arr()[i].show();
				}
			}
			break;
		case 4:
			cout << "Последняя квартира с номером " << h.getQuantity_flat() << " Введите номер квартиры из которой нужно удалить человека: ";
			cin >> number;
			if (h.getFlat_arr()[number - 1].getQuantity_human() == 0) {
				cout << "В данной квартире никто не проживает." << endl;
			}
			else {
				h.getFlat_arr()[number - 1].removalHuman();
			}
			break;
		case 5:
			cout << "Последняя квартира с номером " << h.getQuantity_flat() << " Введите номер квартиры в которую нужно добавить человека: ";
			cin >> number;
			h.getFlat_arr()[number - 1].addHuman();
			break;
		default:
			break;
		}
	} while (choice != 6);
}