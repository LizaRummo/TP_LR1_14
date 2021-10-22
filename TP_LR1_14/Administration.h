#pragma once

#include <iostream>
#include <string>
//#include <fstream>

using namespace std;

class Administration	//администрация
{
	string name;			//фио
	string position;		//должность
	string responsibility;	//область ответственности
public:
	Administration() : name("not set"), position("not set"), responsibility("not set") { cout << "Administration()" << endl; }
	Administration(string a_name, string a_position, string a_responsibility) :
		name(a_name), position(a_position), responsibility(a_responsibility) {
		cout << "Administration(...)" << endl; 
	}
	Administration(const Administration& Adm) {
		cout << "Administration(copy)" << endl;
		name = Adm.name;
		position = Adm.position;
		responsibility = Adm.responsibility;
	}

	~Administration() { cout << "~Administration()" << endl; }

	void a_input();		//ввод с консоли
	void a_output();	//вывод в консоль

	string getName() { return name; }
	string getPosition() { return position; }
	string getResponsibility() { return responsibility; }

	void setName(string name) { this->name = name; }
	void setPosition(string position) { this->position = position; }
	void setResponsibility(string responsibility) { this->responsibility = responsibility; }
};

