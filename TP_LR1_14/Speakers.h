#pragma once
#include <iostream>
#include <string>
//#include <fstream>

using namespace std;

class Speakers		//выступающие
{
	string name;			//фио
	string organization;	//организация/вуз
	string topic;			//доклад (тема)
	string annotation;		//аннотация
	//int count;				//количество 
public:
	Speakers() : name("not set"), organization("not set"), topic("not set"), annotation("not set") {cout << "Speakers()" << endl;}
	Speakers(string s_name, string s_organization, string s_topic, string s_annotation): 
		name(s_name), organization(s_organization), topic(s_topic), annotation(s_annotation) {
		cout << "Speakers(...)" << endl; s_input();  /* ??? */}
	//деструктор ещё

	void s_input();		//ввод с консоли
	//void s_output(int i);
	void s_output();	//вывод в консоль
	// s_edit();		//редактирование данных выступающего
	//void s_add();			//добавление выступающего
	// s_delete();		//удаление выступающего
	//void setCount();
	string getName() { return name; }
	string getOrganization() { return organization; }
	string getTopic() { return topic; }
	string getAnnotation() { return annotation; }

	void setName(string name) { this->name = name; }
	void setOrganization(string organization) { this->organization = organization; }
	void setTopic(string topic) { this->topic = topic; }
	void setAnnotation(string annotation) { this->annotation = annotation; }
};

