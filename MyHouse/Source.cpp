//�������� ���������, ����������� ���������������
//���.���������� ����� ������ ��������, ����������,
//����.����� ���������� �������� ������������ ������
//�������� ������ ��������.����� ���� �������� ������
//�������� ������ ����������.
//������ �� ������� �������� ���������� - ����� � ������� - �����, ������� ���������� ��� ���������� �������
//������.�������� ���� ��������, ��� ������ ��� ��������� �������� ���������� �����������.��������, ���
//��� � ������ ��������.�� ��������� ���������� ������
//���������� ��������������(����������� �����������
//����������), �������������.� main �������������� ������ ����������� ������ �������.
#include <iostream>
#include <string>
using namespace std;
#include "class.h"
#include "function.h"
int main() {
	setlocale(0, "ru");
	int quantity, choice, number;
	house h;
	cout << "������� ������� � ���� ����� �������: ";
	cin >> quantity;
	h.setHouse(quantity);
	for (int i = 0; i < h.getQuantity_flat(); i++) {
		cout << "������� ������� ������� ����� ��������� � �������� � " << h.getFlat_arr()[i].getNumber_flat() << " : ";
		cin >> quantity;
		h.getFlat_arr()[i].setFlat(quantity);
	}
	cin.ignore();
	for (int i = 0; i < h.getQuantity_flat(); i++) {
		for (int j = 0; j < h.getFlat_arr()[i].getQuantity_human(); j++) {
			cout << "�������� �: " << h.getFlat_arr()[i].getNumber_flat() << ", ������� id �: " << h.getFlat_arr()[i].getHuman_arr()[j].getId() << endl;
			h.getFlat_arr()[i].getHuman_arr()[j].setHuman();
		}
	}
	do
	{
		cout << "�������� ��������:" << endl;
		cout << "1. �������� ������� � ���� �������." << endl;
		cout << "2. �������� ������� ��������� ������� � ��������." << endl;
		cout << "3. �������� ������ ����� ����������� � ��������." << endl;
		cout << "4. ������� �������� �� ��������." << endl;
		cout << "5. �������� �������� � ��������." << endl;
		cout << "6. �����." << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "� ���� ����������� " << h.getQuantity_flat() << " ��������." << endl;
			break;
		case 2:
			cout << "��������� �������� � ������� " << h.getQuantity_flat() << " ������� ����� ��������: ";
			cin >> number;
			cout << "� �������� � " << h.getFlat_arr()[number-1].getNumber_flat() << " ���������: " << h.getFlat_arr()[number-1].getQuantity_human() << " ��������." << endl;
			break;
		case 3:
			cout << "��������� �������� � ������� " << h.getQuantity_flat() << " ������� ����� ��������: ";
			cin >> number;
			if (h.getFlat_arr()[number - 1].getHuman_arr() == nullptr) {
				cout << "� �������� � " << number << " ����� �� ���������." << endl;
			}
			else {
				for (int i = 0; i < h.getFlat_arr()[number - 1].getQuantity_human(); i++) {
					h.getFlat_arr()[number - 1].getHuman_arr()[i].show();
				}
			}
			break;
		case 4:
			cout << "��������� �������� � ������� " << h.getQuantity_flat() << " ������� ����� �������� �� ������� ����� ������� ��������: ";
			cin >> number;
			if (h.getFlat_arr()[number - 1].getQuantity_human() == 0) {
				cout << "� ������ �������� ����� �� ���������." << endl;
			}
			else {
				h.getFlat_arr()[number - 1].removalHuman();
			}
			break;
		case 5:
			cout << "��������� �������� � ������� " << h.getQuantity_flat() << " ������� ����� �������� � ������� ����� �������� ��������: ";
			cin >> number;
			h.getFlat_arr()[number - 1].addHuman();
			break;
		default:
			break;
		}
	} while (choice != 6);
}