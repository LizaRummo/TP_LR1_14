#pragma once

#include <iostream>
#include <string>
//#include <fstream>

using namespace std;

class Administration	//�������������
{
	string name;			//���
	string position;		//���������
	string responsibility;	//������� ���������������
public:
	Administration() : name("not set"), position("not set"), responsibility("not set") { cout << "Administration()" << endl; }
	Administration(string a_name, string a_position, string a_responsibility) :
		name(a_name), position(a_position), responsibility(a_responsibility) {
		cout << "Administration(...)" << endl; a_input();
	}
	//���������� ���

	void a_input();		//���� � �������
	void a_output();	//����� � �������
	// a_edit();		//�������������� ������ ���������������
	// a_add();			//���������� ��������������
	// a_delete();		//�������� ��������������

	string getName() { return name; }
	string getPosition() { return position; }
	string getResponsibility() { return responsibility; }

	void setName(string name) { this->name = name; }
	void setPosition(string position) { this->position = position; }
	void setResponsibility(string responsibility) { this->responsibility = responsibility; }
};

