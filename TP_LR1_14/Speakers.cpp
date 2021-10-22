#include "Speakers.h"

string checkNames(string input);

void Speakers::s_input() {

	string s_name, s_organization, s_topic, s_annotation;

	cout << "  [Добавление выступающего]" << endl << "    ФИО: ";
	getline(cin, s_name);	//???
	getline(cin, s_name);
	name = checkNames(s_name);
	cout << "    Организация/ВУЗ: ";
	getline(cin, s_organization);
	organization = checkNames(s_name);
	cout << "    Тема доклада: ";
	getline(cin, s_topic);
	topic = s_topic;
	cout << "    Аннотация: ";
	getline(cin, s_annotation);
	annotation = s_annotation;
}

void Speakers::s_output() {
	cout << "  ФИО: " << name << endl;
	cout << "  Организация/ВУЗ: " << organization << endl;
	cout << "  Тема доклада: " << topic << endl;
	cout << "  Аннотация: " << annotation << endl;
}


