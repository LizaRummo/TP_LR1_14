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

	string keep_getName_of_conf();
	int keep_s_a_p_numb(int id);
};

