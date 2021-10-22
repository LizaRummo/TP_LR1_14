#include "Conference.h"

string checkNames(string input);
string checkDate(string input);
string checkTime(string input);
int selection(int first, int last);

Conference& Conference::operator=(const Conference& Conf)
{
	if (this == &Conf)
		return *this;

	name = Conf.name;

	delete[] s_pointer;
	s_pointer = new Speakers[Conf.s_numb];
	s_numb = Conf.s_numb;
	for (int i = 0; i < Conf.s_numb; i++)
		s_pointer[i] = Conf.s_pointer[i];

	delete[] a_pointer;
	a_pointer = new Administration[Conf.a_numb];
	a_numb = Conf.a_numb;
	for (int i = 0; i < Conf.a_numb; i++)
		a_pointer[i] = Conf.a_pointer[i];

	delete[] p_pointer;
	p_pointer = new Program[Conf.p_numb];
	p_numb = Conf.p_numb;
	for (int i = 0; i < Conf.p_numb; i++)
		p_pointer[i] = Conf.p_pointer[i];

	return *this;
}

void Conference::conf_sort(int id) {
	if (id == 1) {
		Speakers s_buf;
		for (int i = 0; i < s_numb; i++) {
			for (int j = i + 1; j < s_numb; j++) {
				if (s_pointer[i].getName() > s_pointer[j].getName()) {
					s_buf = s_pointer[i];
					s_pointer[i] = s_pointer[j];
					s_pointer[j] = s_buf;
				}
			}
		}
	}
	if (id == 2) {
		Administration a_buf;
		for (int i = 0; i < a_numb; i++) {
			for (int j = i + 1; j < a_numb; j++) {
				if (a_pointer[i].getName() > a_pointer[j].getName()) {
					a_buf = a_pointer[i];
					a_pointer[i] = a_pointer[j];
					a_pointer[j] = a_buf;
				}
			}
		}
	}
	if (id == 3) {
		Program p_buf;

		//���������� �� ����
		for (int i = 0; i < p_numb; i++) {
			for (int j = i + 1; j < p_numb; j++) {
				if (p_pointer[i].getDay() > p_pointer[j].getDay()) {
					p_buf = p_pointer[i];
					p_pointer[i] = p_pointer[j];
					p_pointer[j] = p_buf;
				}
			}
		}

		//���������� �� �������
		if (p_numb > 1) {	//���� ��������� ��� ���������� ������ 1
			int start = 0, stop = 0;
			for (int a = stop; a < p_numb; a += stop) {
				start = stop;
				if ((stop + 1 < p_numb) && (p_pointer[stop].getDay() != p_pointer[stop + 1].getDay())) { start++; stop++; }
				else {
					while ((stop + 1 < p_numb) && (p_pointer[stop].getDay() == p_pointer[stop + 1].getDay())) {
						stop++;
					}
					for (int i = start; i <= stop; i++) {
						for (int j = i + 1; j <= stop; j++) {
							if (p_pointer[i].getTime() > p_pointer[j].getTime()) {
								p_buf = p_pointer[i];
								p_pointer[i] = p_pointer[j];
								p_pointer[j] = p_buf;
							}
						}
					}
				}
			}
		}
	}
}

//�������������� ������ ������������
void Conference::conf_sp_edit(int numb) {
	
	string name, organization, topic, annotation, empty="";

	cout << "  [�������������� ������ ������������]" << endl << "  [���� ���� �� ��������� ������������� - �������� ��� ������ � ������� enter]" << endl << "    ���: ";
	getline(cin, name);	//???
	getline(cin, name);
	name = checkNames(name);
	if (name != empty)	s_pointer[numb-1].setName(name);
	//�������� �� ������ ����� ?
	cout << "    �����������/���: ";
	getline(cin, organization);
	organization = checkNames(organization);
	if (organization != empty)	s_pointer[numb-1].setOrganization(organization);
	cout << "    ���� �������: ";
	getline(cin, topic);
	if (topic != empty)	s_pointer[numb-1].setTopic(topic);
	cout << "    ���������: ";
	getline(cin, annotation);
	if (annotation != empty)	s_pointer[numb-1].setAnnotation(annotation);
}
//�������������� ������ ��������������
void Conference::conf_adm_edit(int numb) {

	string name, position, responsibility, empty = "";

	cout << "  [�������������� ������ ��������������]" << endl << "  [���� ���� �� ��������� ������������� - �������� ��� ������ � ������� enter]" << endl << "    ���: ";
	getline(cin, name);	//???
	getline(cin, name);
	name = checkNames(name);
	if (name != empty)	a_pointer[numb - 1].setName(name);
	cout << "    ���������: ";
	getline(cin, position);
	if (position != empty)	a_pointer[numb - 1].setPosition(position);	
	cout << "    ������� ���������������: ";
	getline(cin, responsibility);	
	if (responsibility != empty) a_pointer[numb - 1].setResponsibility(responsibility);
}
//�������������� ����� ���������
void Conference::conf_pr_edit(int numb) {

	string day, time, topic, empty = "";

	cout << "  [�������������� ����� ���������]" << endl << "  [���� ���� �� ��������� ������������� - �������� ��� ������ � ������� enter]" << endl << "    ����: ";
	getline(cin, day);
	getline(cin, day);
	day = checkDate(day);
	if (day != empty)	p_pointer[numb - 1].setDay(day);
	cout << "    �����: ";
	getline(cin, time);
	time = checkTime(time);
	if (time != empty)	p_pointer[numb - 1].setTime(time);
	cout << "    ������������ (����): ";
	getline(cin, topic);
	if (topic != empty) p_pointer[numb - 1].setTopic(topic);
}

//�������� ������������
void Conference::conf_sp_del(int del_numb) {
	Speakers* s_buf;
	s_buf = new Speakers[s_numb];
	for (int i = 0; i < s_numb; i++)
	{
		s_buf[i] = s_pointer[i];
	}
	s_pointer = new Speakers[s_numb-1];
	for (int j = 0; j < s_numb-1; j++)
	{
		if (j < del_numb-1) s_pointer[j] = s_buf[j];
		else s_pointer[j] = s_buf[j + 1];
	}
	s_numb--;
}
//�������� ��������������
void Conference::conf_adm_del(int del_numb) {
	Administration* a_buf;
	a_buf = new Administration[a_numb];
	for (int i = 0; i < a_numb; i++)
	{
		a_buf[i] = a_pointer[i];
	}
	a_pointer = new Administration[a_numb - 1];
	for (int j = 0; j < a_numb - 1; j++)
	{
		if (j < del_numb - 1) a_pointer[j] = a_buf[j];
		else a_pointer[j] = a_buf[j + 1];
	}
	a_numb--;
}
//�������� ����� ���������
void Conference::conf_pr_del(int del_numb) {
	Program* p_buf;
	p_buf = new Program[p_numb];
	for (int i = 0; i < p_numb; i++)
	{
		p_buf[i] = p_pointer[i];
	}
	p_pointer = new Program[p_numb - 1];
	for (int j = 0; j < p_numb - 1; j++)
	{
		if (j < del_numb - 1) p_pointer[j] = p_buf[j];
		else p_pointer[j] = p_buf[j + 1];
	}
	p_numb--;
}

//���������� ������������
void Conference::conf_sp_add() {
	Speakers sp;
	sp.s_input();
	Speakers* s_buf = s_pointer;
	s_numb++;
	
	s_pointer = new Speakers[s_numb];
	for (int i = 0; i < s_numb - 1; i++)
	{
		s_pointer[i] = s_buf[i];
	}
	s_pointer[s_numb - 1] = sp;
}
//���������� ��������������
void Conference::conf_adm_add() {
	Administration adm;
	adm.a_input();
	Administration* a_buf = a_pointer;
	a_numb++;

	a_pointer = new Administration[a_numb];
	for (int i = 0; i < a_numb - 1; i++)
	{
		a_pointer[i] = a_buf[i];
	}
	a_pointer[a_numb - 1] = adm;
}
//���������� ����� ���������
void Conference::conf_pr_add() {
	Program pr;
	pr.p_input();
	Program* p_buf = p_pointer;
	p_numb++;

	p_pointer = new Program[p_numb];
	for (int i = 0; i < p_numb - 1; i++)
	{
		p_pointer[i] = p_buf[i];
	}
	p_pointer[p_numb - 1] = pr;
}

//����� ������� ������ �����������
void Conference::conf_sp_full_output() {
	for (int i = 0; i <= s_numb - 1; i++) {
		cout << " - ����������� " << i+1 << ":" << endl;
		cout << "    ���: " << s_pointer[i].getName() << endl;
		cout << "    �����������/���: " << s_pointer[i].getOrganization() << endl;
		cout << "    ���� �������: " << s_pointer[i].getTopic() << endl;
		cout << "    ���������: " << s_pointer[i].getAnnotation() << endl;
	}
}
//����� ������� ������ ���������������
void Conference::conf_adm_full_output() {
	for (int i = 0; i <= a_numb - 1; i++) {
		cout << " - ������������� " << i + 1 << ":" << endl;
		cout << "    ���: " << a_pointer[i].getName() << endl;
		cout << "    ���������: " << a_pointer[i].getPosition() << endl;
		cout << "    ������� ���������������: " << a_pointer[i].getResponsibility() << endl;
	}
}
//����� ������� ������ ���������
void Conference::conf_pr_full_output() {
	for (int i = 0; i <= p_numb - 1; i++) {
		cout << " - ����������� ���� " << i + 1 << ":" << endl;
		cout << "    ����: " << p_pointer[i].getDay() << endl;
		cout << "    �����: " << p_pointer[i].getTime() << endl;
		cout << "    ������������ (����): " << p_pointer[i].getTopic() << endl;
	}
}

void Conference::conf_add() {
	string conf_name;
	
	cout << "[�������� �����������]" << endl << "  ��������: ";
	getline(cin, conf_name);
	getline(cin, conf_name);
	name = conf_name;

	cout << "  �������� ������������?" << endl << "    1. ��" << endl << "    0. ���" << endl << "    >> ";
	int input;
	input = selection(0, 1);
	while (input) {	
		if (input) {
			conf_sp_add();
			cout << "  �������� ��� ������ ������������?" << endl << "    1. ��" << endl << "    0. ���" << endl << "    >> ";
			input = selection(0, 1);
		}
	} 
	
	cout << "  �������� ��������������?" << endl << "    1. ��" << endl << "    0. ���" << endl << "    >> ";
	input = selection(0, 1);
	while (input) {
		if (input) {
			conf_adm_add();
			cout << "  �������� ��� ������ ��������������?" << endl << "    1. ��" << endl << "    0. ���" << endl << "    >> ";
			input = selection(0, 1);
		}
	
	} 

	cout << "  �������� ���� ���������?" << endl << "    1. ��" << endl << "    0. ���" << endl << "    >> ";
	input = selection(0, 1);
	while (input) {
		if (input) {
			conf_pr_add();
			cout << "  �������� ��� ���� ���� ���������?" << endl << "    1. ��" << endl << "    0. ���" << endl << "    >> ";
			input = selection(0, 1);
		}
	
	} 

}
