#include "Administration.h"

string checkNames();

void Administration::a_input() {

	string a_name, a_position, a_responsibility;

	cout << "  [Добавление администратора]" << endl << "    ФИО: ";
	getline(cin, a_name);	//???
	//getline(cin, a_name);
	name = checkNames();
	cout << "    Должность: ";
	//getline(cin, a_position);
	position = checkNames();
	cout << "    Область ответственности: ";
	getline(cin, a_responsibility);
	responsibility = a_responsibility;
}

void Administration::a_output() {
	cout << "  ФИО: " << name << endl;
	cout << "  Должность: " << position << endl;
	cout << "  Область ответственности: " << responsibility << endl;
}