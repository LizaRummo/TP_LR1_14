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
		cout << "Administration(...)" << endl; a_input();
	}
	//деструктор ещё

	void a_input();		//ввод с консоли
	void a_output();	//вывод в консоль
	// a_edit();		//редактирование данных администраторов
	// a_add();			//добавление администратора
	// a_delete();		//удаление администратора

	string getName() { return name; }
	string getPosition() { return position; }
	string getResponsibility() { return responsibility; }

	void setName(string name) { this->name = name; }
	void setPosition(string position) { this->position = position; }
	void setResponsibility(string responsibility) { this->responsibility = responsibility; }
};

