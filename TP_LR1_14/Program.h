#pragma once

#include <iostream>
#include <string>
//#include <fstream>

using namespace std;

class Program
{
	string day;			//день //переоформить структурой?
	string time;		//время	//переоформить структурой?
	string topic;		//наименование (тема)
public:
	Program() : day("not set"), time("not set"), topic("not set") { cout << "Program()" << endl; }
	Program(string p_day, string p_time, string p_topic) :
		day(p_day), time(p_time), topic(p_topic) {
		cout << "Program(...)" << endl; p_input();
	}
	//деструктор ещё

	void p_input();		//ввод с консоли
	void p_output();	//вывод в консоль
	// p_edit();		//редактирование данных программы
	// p_add();			//добавление элемента программы
	// p_delete();		//удаление элемента программы

	string getDay() { return day; }
	string getTime() { return time; }
	string getTopic() { return topic; }

	void setDay(string day) { this->day = day; }
	void setTime(string time) { this->time = time; }
	void setTopic(string topic) { this->topic = topic; }

};

