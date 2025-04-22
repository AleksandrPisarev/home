#pragma once
void human::setHuman() {
	string str;
	cout << "Введите фамилию человека: ";
	getline(cin, str);
	surname = new char[str.size() + 1];
	for (int i = 0; i < str.size(); i++) {
		surname[i] = str[i];
	}
	surname[str.size()] = '\0';
	cout << "Введите имя человека: ";
	getline(cin, str);
	name = new char[str.size() + 1];
	for (int i = 0; i < str.size(); i++) {
		name[i] = str[i];
	}
	name[str.size()] = '\0';
	cout << "Введите отчество человека: ";
	getline(cin, str);
	patronymic = new char[str.size() + 1];
	for (int i = 0; i < str.size(); i++) {
		patronymic[i] = str[i];
	}
	patronymic[str.size()] = '\0';
	cout << "Введите дату рождения человека: ";
	getline(cin, birthday);
}
void human::setId() {
	id = num_id;
}
int human::getId() {
	return id;
}
void human::show() {
	cout << "номер id: " << id << endl;
	cout << "фамилия: " << surname << endl;
	cout << "имя: " << name << endl;
	cout << "отчество: " << patronymic << endl;
	cout << "дата рождения: " << birthday << endl;
}
human& human::copy(human* arr, int i) {
	id = arr[i].id;
	surname = new char[strlen(arr[i].surname) + 1];
	name = new char[strlen(arr[i].name) + 1];
	patronymic = new char[strlen(arr[i].patronymic) + 1];
	strcpy_s(surname, strlen(arr[i].surname) + 1, arr[i].surname);
	strcpy_s(name, strlen(arr[i].name) + 1, arr[i].name);
	strcpy_s(patronymic, strlen(arr[i].patronymic) + 1, arr[i].patronymic);
	birthday= arr[i].birthday;
	human::num_id--;
	return *this;
}
void flat::setFlat(int quantity) {
	quantity_human = quantity;
	if (quantity_human > 0) {
		human_arr = new human[quantity_human];
	}
	else human_arr = nullptr;
}
human* flat::getHuman_arr() {
	return human_arr;
}
int flat::getNumber_flat() {
	return number_flat;
}
int flat::getQuantity_human() {
	return quantity_human;
}
flat& flat::removalHuman() {
	if (quantity_human == 1) {
		cout << "В данной квартире проживает один человек." << endl;
		human_arr[0].show();
		quantity_human = 0;
		delete[] human_arr;
		human_arr = nullptr;
		cout << "Данный человек удален." << endl;
	}
	else {
		cout << "В данной квартире проживают: " << endl;
		for (int i = 0; i < quantity_human; i++) {
			human_arr[i].show();
		}
		int id;
		cout << "Введите номер id человека которого необходимо удалить: ";
		cin >> id;
		for (int i = 0; i < quantity_human; i++) {
			if (human_arr[i].getId() == id) {
				id = i;
				break;
			}
		}
		human* new_human_arr = new human[quantity_human - 1];
		for (int i = 0; i < id; i++) {
			new_human_arr[i].copy(human_arr, i);
		}
		for (int i = id; i < quantity_human - 1; i++) {
			new_human_arr[i].copy(human_arr, i+1);
		}
		quantity_human--;
		delete[] human_arr;
		human_arr = new_human_arr;
		cout << "Данный человек удален." << endl;
	}
	return *this;
}
flat& flat::addHuman() {
	human* new_human_arr = new human[quantity_human + 1];
	for (int i = 0; i < quantity_human; i++) {
		new_human_arr[i].copy(human_arr, i);
	}
	cin.ignore();
	new_human_arr[quantity_human].setHuman();
	new_human_arr[quantity_human].setId();
	quantity_human++;
	delete[] human_arr;
	human_arr = new_human_arr;
	return *this;
}
void house::setHouse(int quantity) {
	quantity_flat = quantity;
	flat_arr = new flat[quantity_flat];
}
flat* house::getFlat_arr() {
	return flat_arr;
}
int house::getQuantity_flat() {
	return quantity_flat;
}