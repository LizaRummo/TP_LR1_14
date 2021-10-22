#include "Keeper.h"
#include <fstream>
#include <cstdio>Inport conf.txt

Conference Conf;

void  Keeper::keep_export() {
	ofstream fout("Export conf.txt");		// ������ � ����
	if (!fout.is_open())										// ���� ���� �� ������
		cout << "���� �� ����� ���� ������!" << endl;		// �������� �� ����
	else {
		
		fout << keep_getName_of_conf(); //������� ������������� ������?
		fout << endl << endl;
		fout.width(30);
		fout << "�����������";
		fout.width(2);
		fout << keep_getS_numb() << "|";
		fout.width(30);
		fout << "�������������";
		fout.width(2);
		fout << keep_getA_numb() << "|";
		fout.width(30);
		fout << "����� ���������";
		fout.width(2);
		fout << keep_getP_numb() << "|";
		fout << endl;
		for (int i = 0; i < 99; i++) { fout << "_"; }
		fout << endl << endl;

		Conf.conf_sort(1);
		Speakers* s_pointer = Conf.getS_pointer();
		for (int i = 0; i <= Conf.getS_numb() - 1; i++) {
			fout << " - ����������� " << i + 1 << ":" << endl;
			fout << "    ���: " << s_pointer[i].getName() << endl;
			fout << "    �����������/���: " << s_pointer[i].getOrganization() << endl;
			fout << "    ���� �������: " << s_pointer[i].getTopic() << endl;
			fout << "    ���������: " << s_pointer[i].getAnnotation() << endl;
		}

		fout << endl;
		Conf.conf_sort(2);
		Administration* a_pointer = Conf.getA_pointer();
		for (int i = 0; i <= Conf.getA_numb() - 1; i++) {
			fout << " - ������������� " << i + 1 << ":" << endl;
			fout << "    ���: " << a_pointer[i].getName() << endl;
			fout << "    ���������: " << a_pointer[i].getPosition() << endl;
			fout << "    ������� ���������������: " << a_pointer[i].getResponsibility() << endl;
		}

		fout << endl;
		Conf.conf_sort(3);
		Program* p_pointer = Conf.getP_pointer();
		for (int i = 0; i <= Conf.getP_numb() - 1; i++) {
			fout << " - ����������� ���� " << i + 1 << ":" << endl;
			fout << "    ����: " << p_pointer[i].getDay() << endl;
			fout << "    �����: " << p_pointer[i].getTime() << endl;
			fout << "    ������������ (����): " << p_pointer[i].getTopic() << endl;
		}

		fout.close();
	}
}

void  Keeper::keep_import() {
	string file_name;
	while (1) {
		cout << "������� ��� �����: " << endl << "  ";
		getline(cin, file_name);
		getline(cin, file_name);
		if (!(file_name.find(".txt") + 1 || file_name.find(".dat") + 1 || file_name.find(".csv") + 1)) { cout << "�������� ��� �����" << endl << "[.txt / .dat / .csv]" << endl; }
		else break;
	}
	ifstream fin(file_name);		// ����� �� �����
	//FILE* file;
	
	if (!fin.is_open())										// ���� ���� �� ������
		cout << "���� �� ����� ���� ������!" << endl;		// �������� �� ����
	else {
		string buf, empty = "";
		if (!(fin.eof())) {
			//getline(fin, buf);
			getline(fin, buf);
			//cout << buf << endl;
			Conf.setName(buf);
			getline(fin, buf);
			//cout << buf << endl;
		}
		//getline(fin, buf);
		//cout << buf << endl;
		while (!(fin.eof())/*||(buf!=empty)*/) {
			string input;
			string findCategory = " - ";
			string findValue = ": ";
			
			int length=0;
			
			getline(fin, buf);
			//cout << buf << endl;
			int pos = 0;
			pos = buf.find(findCategory);
			if (pos > -1) {
				if (buf[pos + 3] == '�') {
					Speakers sp;
					int numb = Conf.getS_numb();
					numb++;
					//string s_name, s_organization, s_topic, s_annotation;
					//cout << "����������� " << numb << " ������" << endl;
					for (int i = 0; i < 4; i++) {
						getline(fin, buf);
						length = buf.length();
						int j = 0;
						pos = buf.find(findValue);
						input.assign(buf, pos + 2, length);
						if (i == 0) { sp.setName(input); /*cout << sp.getName();*/ input.clear(); }
						if (i == 1) { sp.setOrganization(input); /*cout << sp.getOrganization();*/ input.clear(); }
						if (i == 2) { sp.setTopic(input); /*cout << sp.getTopic();*/ input.clear(); }
						if (i == 3) { sp.setAnnotation(input); /*cout << sp.getAnnotation();*/ input.clear(); }
						//cout << endl;
					}
					Speakers* s_buf = Conf.getS_pointer();
					Conf.setS_numb(numb);
					Conf.setS_pointer(new Speakers[numb]);
					Speakers* pointer = Conf.getS_pointer();
					for (int i = 0; i < numb - 1; i++)
					{
						pointer[i] = s_buf[i];
					}
					pointer[numb - 1] = sp;
					Conf.conf_sort(1);
					//Conf.conf_sp_full_output();
				}
				if (buf[pos + 3] == '�') {
					Administration adm;
					int numb = Conf.getA_numb();
					numb++;
					//string a_name, a_position, a_responsibility;
					//cout << "������������� " << numb << " ������" << endl;
					for (int i = 0; i < 3; i++) {
						getline(fin, buf);
						length = buf.length();
						int j = 0;
						pos = buf.find(findValue);
						input.assign(buf, pos + 2, length);
						if (i == 0) { adm.setName(input); /*cout << adm.getName();*/ input.clear(); }
						if (i == 1) { adm.setPosition(input); /*cout << adm.getPosition();*/ input.clear(); }
						if (i == 2) { adm.setResponsibility(input); /*cout << adm.getResponsibility();*/ input.clear(); }
						//cout << endl;
					}
					Administration* s_buf = Conf.getA_pointer();
					Conf.setA_numb(numb);
					Conf.setA_pointer(new Administration[numb]);
					Administration* pointer = Conf.getA_pointer();
					for (int i = 0; i < numb - 1; i++)
					{
						pointer[i] = s_buf[i];
					}
					pointer[numb - 1] = adm;
					Conf.conf_sort(2);
					//Conf.conf_adm_full_output();
				}
				if (buf[pos + 3] == '�') {
					Program pr;
					int numb = Conf.getP_numb();
					numb++;
					//string s_name, s_organization, s_topic, s_annotation;
					//cout << "����������� ���� " << numb << " ������" << endl;
					for (int i = 0; i < 3; i++) {
						getline(fin, buf);
						length = buf.length();
						int j = 0;
						pos = buf.find(findValue);
						input.assign(buf, pos + 2, length);
						if (i == 0) { pr.setDay(input); /*cout << pr.getDay();*/ input.clear(); }
						if (i == 1) { pr.setTime(input); /*cout << pr.getTime();*/ input.clear(); }
						if (i == 2) { pr.setTopic(input); /*cout << pr.getTopic();*/ input.clear(); }
						//cout << endl;
					}
					Program* s_buf = Conf.getP_pointer();
					Conf.setP_numb(numb);
					Conf.setP_pointer(new Program[numb]);
					Program* pointer = Conf.getP_pointer();
					for (int i = 0; i < numb - 1; i++)
					{
						pointer[i] = s_buf[i];
					}
					pointer[numb - 1] = pr;
					Conf.conf_sort(3);
					//Conf.conf_pr_full_output();

				}
			}
			else return;
		}
	}
}

void Keeper::keep_s_a_p_add(int id) {
	if (id == 1) {
		//cout << "id == 1" << endl;
		Conf.conf_sp_add();
	}
	if (id == 2) {
		//cout << "id == 2" << endl;
		Conf.conf_adm_add();
	}
	if (id == 3) {
		//cout << "id == 3" << endl;
		Conf.conf_pr_add();
	}
}

void Keeper::keep_s_a_p_full_output(int id) {
	if (id == 1) {
		//cout << "id == 1" << endl;
		if (Conf.getS_numb()) { Conf.conf_sort(id); Conf.conf_sp_full_output(); }
		else cout << "�� ����������� �� ���������������� �� ������ ������������." << endl;
	}
	if (id == 2) {
		//cout << "id == 2" << endl;
		if (Conf.getA_numb()) {	Conf.conf_sort(id); Conf.conf_adm_full_output(); }
		else cout << "�� ����������� �� ���������������� �� ������ ��������������." << endl;
	}
	if (id == 3) {
		//cout << "id == 3" << endl;
		if (Conf.getP_numb()) {	Conf.conf_sort(id); Conf.conf_pr_full_output(); }
		else cout << "�� ����������� �� ���������������� �� ������ ����� ���������." << endl;
	}
}

void Keeper::keep_s_a_p_delete(int id, int del_number) {
	if (id == 1) {
		//cout << "id == 1" << endl;
		Conf.conf_sp_del(del_number);
	}
	if (id == 2) {
		//cout << "id == 2" << endl;
		Conf.conf_adm_del(del_number);
	}
	if (id == 3) {
		//cout << "id == 3" << endl;
		Conf.conf_pr_del(del_number);
	}
}

void Keeper::keep_s_a_p_edit(int id, int number) {
	if (id == 1) {
		//cout << "id == 1" << endl;
		Conf.conf_sp_edit(number);
	}
	if (id == 2) {
		//cout << "id == 2" << endl;
		Conf.conf_adm_edit(number);
	}
	if (id == 3) {
		//cout << "id == 3" << endl;
		Conf.conf_pr_edit(number);
	}
}

void Keeper::keep_add() {
   // Conference Conf;
    Conf.conf_add();
}

string Keeper::keep_getName_of_conf() {
	//Conference Conf;
	return Conf.getName();
}

int Keeper::keep_s_a_p_numb(int id) {
	if (id == 1) {
		//cout << "id == 1" << endl;
		return Conf.getS_numb();
	}
	if (id == 2) {
		//cout << "id == 2" << endl;
		return Conf.getA_numb();
	}
	if (id == 3) {
		//cout << "id == 3" << endl;
		return Conf.getP_numb();
	}
}

int Keeper::keep_getS_numb() {
	return Conf.getS_numb();
}

int Keeper::keep_getA_numb() {
	return Conf.getA_numb();
}

int Keeper::keep_getP_numb() {
	return Conf.getP_numb();
}