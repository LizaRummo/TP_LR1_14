#include "Program.h"

string checkDate();
string checkTime();

void Program::p_input() {

	string p_day, p_time, p_topic;

	cout << "  [Добавление блока программы]" << endl << "    День (формат ДД м...м): ";
	getline(cin, p_day);
	//getline(cin, p_day);
	day = checkDate();
	cout << "    Время (формат ЧЧ:ММ): ";
	//getline(cin, p_time);
	time = checkTime();
	cout << "    Наименование (тема): ";
	getline(cin, p_topic);
	topic = p_topic;
}

void Program::p_output() {
	cout << "  День: " << day << endl;
	cout << "  Время: " << time << endl;
	cout << "  Наименование (тема): " << topic << endl;
}
