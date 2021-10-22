#pragma once
#include "Conference.h"

class Keeper
{
	Conference* conf_pointer;
public:
	Keeper(): conf_pointer(nullptr){}
	~Keeper() { delete[] conf_pointer; }

	void keep_add();		//добавление контейнера

	//void keep_output();	//вывод контейнера
	void keep_import();
	void keep_export();

	void keep_s_a_p_add(int id);
	void keep_s_a_p_full_output(int id);
	void keep_s_a_p_delete(int id, int del_number);
	void keep_s_a_p_edit(int id, int number);
	//void keep_sort(int id);

	//void keep_sp_add();		//добавление спикера
	//void keep_sp_full_output();
	//int getS_numb() { return s_numb; }
	//void keep_adm_add();
	//void keep_adm_full_output();
	//void keep_pr_add();
	//void keep_pr_full_output();

	string keep_getName_of_conf();
	int keep_s_a_p_numb(int id);
	int keep_getS_numb();
	int keep_getA_numb();
	int keep_getP_numb();
};

