#pragma once

#include <iostream>
#include <string>
//#include <fstream>

using namespace std;

class Program
{
	string day;			//���� //������������ ����������?
	string time;		//�����	//������������ ����������?
	string topic;		//������������ (����)
public:
	Program() : day("not set"), time("not set"), topic("not set") { cout << "Program()" << endl; }
	Program(string p_day, string p_time, string p_topic) :
		day(p_day), time(p_time), topic(p_topic) {
		cout << "Program(...)" << endl; p_input();
	}
	//���������� ���

	void p_input();		//���� � �������
	void p_output();	//����� � �������
	// p_edit();		//�������������� ������ ���������
	// p_add();			//���������� �������� ���������
	// p_delete();		//�������� �������� ���������

	string getDay() { return day; }
	string getTime() { return time; }
	string getTopic() { return topic; }

	void setDay(string day) { this->day = day; }
	void setTime(string time) { this->time = time; }
	void setTopic(string topic) { this->topic = topic; }

};

