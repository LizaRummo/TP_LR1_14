#pragma once

#include"Speakers.h"
#include"Administration.h"
#include"Program.h"

using namespace std;

class Conference
{
	string name;
	Speakers* s_pointer;
	int s_numb;
	Administration* a_pointer;
	int a_numb;
	Program* p_pointer;
	int p_numb;
public:
	Conference() : name("not set"), s_pointer(nullptr), s_numb(0), a_pointer(nullptr), a_numb(0), p_pointer(nullptr), p_numb(0) { cout << "Conference()" << endl; }

	//конструктор копирования
	Conference(const Conference& Conf) {
		cout << "Conference(copy)" << endl;

		name = Conf.name;

		s_pointer = new Speakers[Conf.s_numb];
		s_numb = Conf.s_numb;
		for (int i = 0; i < Conf.s_numb; i++) s_pointer[i] = Conf.s_pointer[i];

		a_pointer = new Administration[Conf.a_numb];
		a_numb = Conf.a_numb;
		for (int i = 0; i < Conf.a_numb; i++) a_pointer[i] = Conf.a_pointer[i];

		p_pointer = new Program[Conf.p_numb];
		p_numb = Conf.p_numb;
		for (int i = 0; i < Conf.p_numb; i++) p_pointer[i] = Conf.p_pointer[i];
	}

	~Conference() {
		cout << "~Conference()" << endl;
		delete[] s_pointer;
		delete[] a_pointer;
		delete[] p_pointer;
	}

	//Conference& operator[](int index);
	Conference& operator=(const Conference&);
	string getName() { return name; }
	void setName(string name) { this->name = name; }

	void resetName(string new_name) { name = new_name; }
	void conf_add();		//добавление конфиренции
	//void conf_delete();	//удаление конфиренции
	//void conf_edit();		//редактирование конфиренции

	void conf_sort(int id);	//сортировка списка

	void conf_sp_add();	//добавление спикера
	void conf_sp_del(int del_numb);	//удаление 
	void conf_sp_edit(int numb);
	void conf_sp_full_output();
	//int getS_numb() { return s_numb; }

	void conf_adm_add();
	void conf_adm_del(int del_numb);
	void conf_adm_edit(int numb);
	void conf_adm_full_output();

	void conf_pr_add();
	void conf_pr_del(int del_numb);
	void conf_pr_edit(int numb);
	void conf_pr_full_output();

	Speakers* getS_pointer() { return s_pointer; }
	int getS_numb() { return s_numb; }
	Administration* getA_pointer() { return a_pointer; }
	int getA_numb() { return a_numb; }
	Program* getP_pointer() { return p_pointer; }
	int getP_numb() { return p_numb; }
	
	void setS_pointer (Speakers* s_pointer) { this->s_pointer = s_pointer; }
	void setS_numb(int s_numb) { this->s_numb = s_numb; }
	void setA_pointer(Administration* a_pointer) { this->a_pointer = a_pointer; }
	void setA_numb(int a_numb) { this->a_numb = a_numb; }
	void setP_pointer(Program* p_pointer) { this->p_pointer = p_pointer; }
	void setP_numb(int p_numb) { this->p_numb = p_numb; }

};

