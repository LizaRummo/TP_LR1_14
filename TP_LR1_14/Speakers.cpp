#include "Speakers.h"

string checkNames(string input);

void Speakers::s_input() {

	string s_name, s_organization, s_topic, s_annotation;

	cout << "  [���������� ������������]" << endl << "    ���: ";
	getline(cin, s_name);	//???
	getline(cin, s_name);
	name = checkNames(s_name);
	cout << "    �����������/���: ";
	getline(cin, s_organization);
	organization = checkNames(s_name);
	cout << "    ���� �������: ";
	getline(cin, s_topic);
	topic = s_topic;
	cout << "    ���������: ";
	getline(cin, s_annotation);
	annotation = s_annotation;
}

void Speakers::s_output() {
	cout << "  ���: " << name << endl;
	cout << "  �����������/���: " << organization << endl;
	cout << "  ���� �������: " << topic << endl;
	cout << "  ���������: " << annotation << endl;
}


