#pragma once
class human
{
	int id;
	char* surname;
	char* name;
	char* patronymic;
	string birthday;
	static int num_id;
public:
	human() : birthday{ '0' }, surname{ nullptr }, name{ nullptr }, patronymic{ nullptr }
	{
		num_id++;
		id = num_id;
		/*cout << "Конструктор human" << endl;*/
	}
	~human() {
		delete[] surname;
		delete[] name;
		delete[] patronymic;
		/*cout << "Деструктор human" << endl;*/
	}
	void setHuman();         //заполняет поля класса выделяет память для массива 
	void setId();            //изменяет id нужна при добавлении человека
	int getId();             //возвращает id человека
	void show();             //показывает данные человека
	human& copy(human*, int);//функция копирования людей (объектов) при удалении и добавлении людей
};
int human::num_id = 0;
class flat
{
	int number_flat;
	int quantity_human;
	human* human_arr;
	static int number;
public:
	flat() : quantity_human{ 0 }, human_arr{ nullptr }
	{
		number++;
		number_flat = number;
		/*cout << "Конструктор  flat" << endl;*/
	}
	~flat() {
	    delete[] human_arr;
		/*cout << "Деструктор flat" << endl;*/
	}
	void setFlat(int);       //заполняет поля класса выделяет память для массива вызыват конструкторы класса human
	human* getHuman_arr();   //возвращает указатель на массив людей (объектов)
	int getNumber_flat();    //возвращает номер квартиры
	int getQuantity_human(); //возвращает количество людей проживающих в квартире
	flat& removalHuman();    //удаление человека
	flat& addHuman();        //добавление человека
};
int flat::number = 0;
class house
{
	int quantity_flat;
	flat* flat_arr;
public:
	house() : quantity_flat{ 0 }, flat_arr{ nullptr }
	{
		/*cout << "Конструктор house" << endl;*/
	}
	~house() {
		delete[] flat_arr;
		/*cout << "Деструктор house" << endl;*/
	}
	void setHouse(int);     //заполняет поля класса выделяет память для массива вызыват конструкторы класса flat
	flat* getFlat_arr();    //возвращает указатель на массив квартир (объектов)
	int getQuantity_flat(); //возвращает кол-во квартир в доме
};