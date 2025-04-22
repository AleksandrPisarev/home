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
		/*cout << "����������� human" << endl;*/
	}
	~human() {
		delete[] surname;
		delete[] name;
		delete[] patronymic;
		/*cout << "���������� human" << endl;*/
	}
	void setHuman();         //��������� ���� ������ �������� ������ ��� ������� 
	void setId();            //�������� id ����� ��� ���������� ��������
	int getId();             //���������� id ��������
	void show();             //���������� ������ ��������
	human& copy(human*, int);//������� ����������� ����� (��������) ��� �������� � ���������� �����
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
		/*cout << "�����������  flat" << endl;*/
	}
	~flat() {
	    delete[] human_arr;
		/*cout << "���������� flat" << endl;*/
	}
	void setFlat(int);       //��������� ���� ������ �������� ������ ��� ������� ������� ������������ ������ human
	human* getHuman_arr();   //���������� ��������� �� ������ ����� (��������)
	int getNumber_flat();    //���������� ����� ��������
	int getQuantity_human(); //���������� ���������� ����� ����������� � ��������
	flat& removalHuman();    //�������� ��������
	flat& addHuman();        //���������� ��������
};
int flat::number = 0;
class house
{
	int quantity_flat;
	flat* flat_arr;
public:
	house() : quantity_flat{ 0 }, flat_arr{ nullptr }
	{
		/*cout << "����������� house" << endl;*/
	}
	~house() {
		delete[] flat_arr;
		/*cout << "���������� house" << endl;*/
	}
	void setHouse(int);     //��������� ���� ������ �������� ������ ��� ������� ������� ������������ ������ flat
	flat* getFlat_arr();    //���������� ��������� �� ������ ������� (��������)
	int getQuantity_flat(); //���������� ���-�� ������� � ����
};