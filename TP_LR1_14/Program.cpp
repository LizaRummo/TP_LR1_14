#include "Program.h"

string checkDate(string input);
string checkTime(string input);

void Program::p_input() {

	string p_day, p_time, p_topic;

	cout << "  [���������� ����� ���������]" << endl << "    ���� (������ �� �...�): ";
	getline(cin, p_day);
	getline(cin, p_day);
	day = checkDate(p_day);
	cout << "    ����� (������ ��:��): ";
	getline(cin, p_time);
	time = checkTime(p_time);
	cout << "    ������������ (����): ";
	getline(cin, p_topic);
	topic = p_topic;
}

void Program::p_output() {
	cout << "  ����: " << day << endl;
	cout << "  �����: " << time << endl;
	cout << "  ������������ (����): " << topic << endl;
}
