#include "Administration.h"

string checkNames(string input);

void Administration::a_input() {

	string a_name, a_position, a_responsibility;

	cout << "  [���������� ��������������]" << endl << "    ���: ";
	getline(cin, a_name);	//???
	getline(cin, a_name);
	name = checkNames(a_name);
	cout << "    ���������: ";
	getline(cin, a_position);
	position = checkNames(a_position);
	cout << "    ������� ���������������: ";
	getline(cin, a_responsibility);
	responsibility = a_responsibility;
}

void Administration::a_output() {
	cout << "  ���: " << name << endl;
	cout << "  ���������: " << position << endl;
	cout << "  ������� ���������������: " << responsibility << endl;
}