#include "Keeper.h"
#include <fstream>
#include <cstdio>


string checkNames(string input);
string checkDate(string input);
string checkTime(string input);

Conference Conf;

void  Keeper::keep_export() {
	ofstream fout("Export conf.txt");		// запись в файл
	if (!fout.is_open())										// если файл не открыт
		cout << "Файл не может быть открыт!" << endl;		// сообщить об этом
	else {
		
		fout << keep_getName_of_conf(); //сделать принудительно капсом?
		fout << endl << endl;
		fout.width(30);
		fout << "Выступающие";
		fout.width(2);
		fout << keep_s_a_p_numb(1) << "|";
		fout.width(30);
		fout << "Администрация";
		fout.width(2);
		fout << keep_s_a_p_numb(2) << "|";
		fout.width(30);
		fout << "Блоки программы";
		fout.width(2);
		fout << keep_s_a_p_numb(3) << "|";
		fout << endl;
		for (int i = 0; i < 99; i++) { fout << "_"; }
		fout << endl << endl;

		Conf.conf_sort(1);
		Speakers* s_pointer = Conf.getS_pointer();
		for (int i = 0; i <= Conf.getS_numb() - 1; i++) {
			fout << " - Выступающий " << i + 1 << ":" << endl;
			fout << "    ФИО: " << s_pointer[i].getName() << endl;
			fout << "    Организация/ВУЗ: " << s_pointer[i].getOrganization() << endl;
			fout << "    Тема доклада: " << s_pointer[i].getTopic() << endl;
			fout << "    Аннотация: " << s_pointer[i].getAnnotation() << endl;
		}

		fout << endl;
		Conf.conf_sort(2);
		Administration* a_pointer = Conf.getA_pointer();
		for (int i = 0; i <= Conf.getA_numb() - 1; i++) {
			fout << " - Администратор " << i + 1 << ":" << endl;
			fout << "    ФИО: " << a_pointer[i].getName() << endl;
			fout << "    Должность: " << a_pointer[i].getPosition() << endl;
			fout << "    Область ответственности: " << a_pointer[i].getResponsibility() << endl;
		}

		fout << endl;
		Conf.conf_sort(3);
		Program* p_pointer = Conf.getP_pointer();
		for (int i = 0; i <= Conf.getP_numb() - 1; i++) {
			fout << " - Программный блок " << i + 1 << ":" << endl;
			fout << "    День: " << p_pointer[i].getDay() << endl;
			fout << "    Время: " << p_pointer[i].getTime() << endl;
			fout << "    Наименование (тема): " << p_pointer[i].getTopic() << endl;
		}

		fout.close();
		cout << "Данные сохранены в Export conf.txt" << endl;
	}
}

void  Keeper::keep_import() {
	string file_name;
	cout << "Введите имя файла [формат имя.тип]: " << endl << "  ";
	getline(cin, file_name);
	getline(cin, file_name);
	while (1) {
		if (!(file_name.find(".txt") + 1 || file_name.find(".dat") + 1 || file_name.find(".csv") + 1)) { cout << "Неверный тип файла" << endl << "[.txt / .dat / .csv]" << endl; }
		else if (file_name.length() >= 255 || file_name.length() <= 4) { cout << "Недопустимая длина имени файла" << endl; } 
		else if ((file_name.find("<") + 1 )) { cout << "Недопустимые символы в имени файла" << endl; }
		else break;
		cout << "Введите имя файла [формат имя.тип]: " << endl << "  ";
		getline(cin, file_name);
	}
	ifstream fin(file_name);		// вывод из файла
	
	if (!fin.is_open())										// если файл не открыт
		cout << "Файл не может быть открыт!" << endl;		// сообщить об этом
	else {
		string buf, empty = "";
		if (!(fin.eof())) {
			//getline(fin, buf);
			getline(fin, buf);
			buf = checkNames(buf);
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
				if (buf[pos + 3] == 'В') {
					Speakers sp;
					int numb = Conf.getS_numb();
					numb++;
					//string s_name, s_organization, s_topic, s_annotation;
					//cout << "Выступающий " << numb << " найден" << endl;
					for (int i = 0; i < 4; i++) {
						getline(fin, buf);
						length = buf.length();
						int j = 0;
						pos = buf.find(findValue);
						input.assign(buf, pos + 2, length);
						if (i == 0) { input = checkNames(input);  sp.setName(input); /*cout << sp.getName();*/ input.clear(); }
						if (i == 1) { input = checkNames(input); sp.setOrganization(input); /*cout << sp.getOrganization();*/ input.clear(); }
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
				if (buf[pos + 3] == 'А') {
					Administration adm;
					int numb = Conf.getA_numb();
					numb++;
					//string a_name, a_position, a_responsibility;
					//cout << "Администратор " << numb << " найден" << endl;
					for (int i = 0; i < 3; i++) {
						getline(fin, buf);
						length = buf.length();
						int j = 0;
						pos = buf.find(findValue);
						input.assign(buf, pos + 2, length);
						if (i == 0) { input = checkNames(input); adm.setName(input); /*cout << adm.getName();*/ input.clear(); }
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
				if (buf[pos + 3] == 'П') {
					Program pr;
					int numb = Conf.getP_numb();
					numb++;
					//string s_name, s_organization, s_topic, s_annotation;
					//cout << "Программный блок " << numb << " найден" << endl;
					for (int i = 0; i < 3; i++) {
						getline(fin, buf);
						length = buf.length();
						int j = 0;
						pos = buf.find(findValue);
						input.assign(buf, pos + 2, length);
						if (i == 0) { input = checkDate(input); pr.setDay(input); /*cout << pr.getDay();*/ input.clear(); }
						if (i == 1) { input = checkTime(input); pr.setTime(input); /*cout << pr.getTime();*/ input.clear(); }
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
		else cout << "На конференции не зарегистрировано ни одного выступающего." << endl;
	}
	if (id == 2) {
		//cout << "id == 2" << endl;
		if (Conf.getA_numb()) {	Conf.conf_sort(id); Conf.conf_adm_full_output(); }
		else cout << "На конференции не зарегистрировано ни одного администратора." << endl;
	}
	if (id == 3) {
		//cout << "id == 3" << endl;
		if (Conf.getP_numb()) {	Conf.conf_sort(id); Conf.conf_pr_full_output(); }
		else cout << "На конференции не зарегистрировано ни одного блока программы." << endl;
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
	if (id == 4) {
		Conf.setName("");
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
	if (id == 4) {
		cout << "[Изменение назавния конференции]" << endl << "  Название: ";
		string new_conf_name;
		getline(cin, new_conf_name);
		getline(cin, new_conf_name);

		Conf.setName(checkNames(new_conf_name));
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