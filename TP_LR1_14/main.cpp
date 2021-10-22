using namespace std;

#include <Windows.h>
#include "Conference.h"
#include "Keeper.h"

Keeper keep;

string checkNames(string input) {	//�������� ��� �����, ����������� - � .
	string buf = "", res = "";
	while (true) {
		int length = 0, ctr_err = 0;
			//getline(cin, input);
			int first_letter = NULL, find_numb = 0;
			length = input.length();
			for (int i = 0; i <= length; i++) {
				if ((input[i] >= '!' && input[i] <= ',') ||
					(input[i] >= '/' && input[i] <= '@') ||
					input[i] == '\0' || input[i] == '\n') {
					if (!find_numb) {
						buf.assign(input, first_letter, i - (res.length() + ctr_err));
						res += buf;
						first_letter = NULL;
						find_numb = 1;
						ctr_err++;
					}
				}
				else
					if (find_numb) {
						first_letter = i;
						find_numb = 0;
					}
			}
		return res;
	}
	
}

//�������� ��� ����
string checkDate(string input) {
	string day_buf, month_buf, buf = "", res = "";
	while (true) {
		int length = 0, day, separator = 0;
		//getline(cin, input);
		//getline(cin, input);
		int first_letter = NULL, find_err = 0, ctr_err=0, correct=0;
		length = input.length();
		for (int i = 0; i <= length; i++) {
			if (!separator&& day_buf.length() < 2) {
				if (!(input[i] >= '0' && input[i] <= '9')) {
					if (!find_err) {
						
						buf.assign(input, first_letter, (i - (day_buf.length() + ctr_err)));
						day_buf += buf;
						first_letter = NULL;
						find_err = 1;
						ctr_err++;
						
					}
				}
				else
					if (find_err) {
						first_letter = i - correct;
						find_err = 0;
						//ctr_err = 0;
					}
			}
			else {
				if (!separator && day_buf.length() >= 2) {
					correct = 1;
					//ctr_err = 0;
					//day_buf.assign(input, first_letter, i);
					day = stoi(day_buf);
				}
				if ((input[i - correct] >= '!' && input[i - correct] <= ',') ||
					(input[i - correct] >= '/' && input[i - correct] <= '@')) {
					if (!find_err) {
						buf.assign(input, first_letter, i - (day_buf.length() + ctr_err + separator));
						month_buf += buf;
						first_letter = NULL;
						find_err = 1; 
						ctr_err++;
					}
				}
				else
					if (find_err) {
						first_letter = i - correct;
						find_err = 0;
					}
				if (input[i] == '\0' || input[i] == '\n') {
					if (!find_err) {
						//first_letter = i - correct;
						buf.assign(input, first_letter, i - (day_buf.length() + separator));
						month_buf += buf;

					}
				}
			}
			if (input[i] == ' ') {
				separator = 1;
				ctr_err--;
				//day_buf.assign(input, first_letter, i);
				day = stoi(day_buf);
			}

			//��
			//if (i < 2 ) {
			//	if (!(input[i] >= '0' && input[i] <= '9')) {
			//		input[i] = '0';
			//		//find_err = 1;
			//	}
			//}
			//if (i == 2) {
			//	day_buf.assign(input, first_letter, i);
			//	day = stoi(day_buf);
			//	if (!(input[i] == ' ')) {
			//		//???
			//		correct = 1;
			//	}
			//}
			////��
			//if ((i > 2) || input[i] == '\0' || input[i] == '\n') {
			//	if ((input[i - correct] >= '!' && input[i - correct] <= ',') ||
			//		(input[i - correct] >= '/' && input[i - correct] <= '@')) {
			//		if (!find_err) {
			//			buf.assign(input, first_letter, i-3);
			//			month_buf += buf;
			//			first_letter = NULL;
			//			find_err = 1;
			//		}
			//	}
			//	else
			//		if (find_err) {
			//			first_letter = i- correct;
			//			find_err = 0;
			//		}

			//	if (input[i] == '\0' || input[i] == '\n') {
			//		if (!find_err) {
			//			//first_letter = i - correct;
			//			buf.assign(input, first_letter, i -3);
			//			month_buf += buf;
			//			
			//		}
			//	}
			//}

		}

		if (day <= 29 && month_buf.find("���") + 1 ||
			day <= 30 && (month_buf.find("���") + 1 || month_buf.find("���") + 1 || month_buf.find("���") + 1 || month_buf.find("���") + 1) ||
			day <= 31 && (month_buf.find("���") + 1 || month_buf.find("���") + 1 || month_buf.find("���") + 1 || month_buf.find("���") + 1
				|| month_buf.find("���") + 1 || month_buf.find("���") + 1 || month_buf.find("���") + 1 || month_buf.find("���") + 1))
		{
			if (day_buf.length() == 1) res += "0";
			res += day_buf;
			res += ' ';
			res += month_buf;
		}
		else res = "not set";
		
 		return res;
	}

}

//�������� ��� �������
string checkTime(string input) {
	string hour_buf, minute_buf, buf = "", res = "";
	while (true) {
		int length = 0, hour=0, minute=0, separator = 0;
		//getline(cin, input);
		//getline(cin, input);
		int first_letter = NULL, find_err = 0, ctr_err = 0, correct = 0;
		length = input.length();
		for (int i = 0; i <= length; i++) {
			if (!separator && hour_buf.length() < 2) {
				if (!(input[i] >= '0' && input[i] <= '9')) {
					if (!find_err) {
						buf.assign(input, first_letter, (i - (hour_buf.length() + ctr_err)));
						hour_buf += buf;
						first_letter = NULL;
						find_err = 1;
						ctr_err++;

					}
				}
				else
					if (find_err) {
						first_letter = i - correct;
						find_err = 0;
						//ctr_err = 0;
					}
			}
			else {
				if (!separator && hour_buf.length() == 2) {
					correct = 1;
					//ctr_err = 0;
					//day_buf.assign(input, first_letter, i);
					
				}
				if (!(input[i] >= '0' && input[i] <= '9') && minute_buf.length() < 2) {
					if (!find_err) {
						buf.assign(input, first_letter, i - (hour_buf.length() + ctr_err + separator));
						minute_buf += buf;
						first_letter = NULL;
						find_err = 1;
						ctr_err++;
					}
				}
				else
					if (find_err) {
						first_letter = i - correct;
						find_err = 0;
					}
				if (input[i] == '\0' || input[i] == '\n') {
					if (!find_err) {
						//first_letter = i - correct;
						buf.assign(input, first_letter, i - (hour_buf.length() + separator));
						minute_buf += buf;
						

					}
				}
			}
			if (input[i] == ':') {
				separator = 1;
				ctr_err--;
				//day_buf.assign(input, first_letter, i);
				hour = stoi(hour_buf);
			}
		}

		hour = stoi(hour_buf);
		minute = stoi(minute_buf);

		if (hour < 24 && minute < 60)
		{
			res += hour_buf;
			res += ':';
			res += minute_buf;
		}
		else res = "not set";

		return res;
	}

}

int selection(int first, int last) {
	int input;
	while (true) {
		try
		{
			cin >> input;
			if (!(cin.fail() || input < first || input > last)) return input;
			else throw "������ ������������� ����� ����";
		}
		catch (const char*) {
			cin.clear();
			cerr << "������ ������������� ����� ����. ���������� ����" << endl << "> ";
		}
		cin.ignore(32767, '\n');
	}
	return input;
}

void statusbar() {
	//cout.width(99);
	cout << keep.keep_getName_of_conf(); //������� ������������� ������?
	cout << endl << endl;
	cout.width(30);
	cout << "�����������";
	cout.width(2);
	cout << keep.keep_s_a_p_numb(1) << "|";
	cout.width(30);
	cout << "�������������";
	cout.width(2);
	cout << keep.keep_s_a_p_numb(2) << "|";
	cout.width(30);
	cout << "����� ���������";
	cout.width(2);
	cout << keep.keep_s_a_p_numb(3) << "|";
	cout << endl;
	for (int i = 0; i < 99; i++) { cout << "_"; }
	cout << endl;
}

void print_Menu_X() {
	system("cls");
	statusbar();
	//cout << "������� ����" << endl;
	cout << endl << "�������� ����� ����:" << endl;
	cout << "  1. �����������" << endl;
	cout << "  2. �������������" << endl;
	cout << "  3. ���������" << endl;
	cout << "  ---" << endl;
	cout << "  4. ������ ������" << endl;
	cout << "  5. ������� ������" << endl;
	cout << "  ---" << endl;
	cout << "  6. �������� ������� �����������" << endl;
	cout << "  7. �������� �����������" << endl;
	cout << "  8. ������� ������ ����������� �� �����" << endl;
	cout << "  ---" << endl;
	cout << "  0. ����� �� ���������" << endl;
	cout << "  >> ";
}

void print_Menu_XX(int point) {
	system("cls");
	statusbar();
	cout << endl << "�������� ����� ����:" << endl;
	if (point == 1) cout << "  1. �����������" << endl;
	if (point == 2) cout << "  2. �������������" << endl;
	if (point == 3) cout << "  3. ���������" << endl;
	cout << "    " << point << ".1. ������� ������ ������" << endl;
	cout << "    " << point << ".2. �������� ������" << endl;
	cout << "    " << point << ".3. ��������" << endl;
	cout << "    " << point << ".4. �������" << endl;
	cout << "    ---" << endl;
	cout << "    " << point << ".0. ��������� � ��������� ����" << endl;
	cout << "  >>" << point << ".";
}

int Menu_XX(int type) {
	while (1) {
		print_Menu_XX(type);
		switch (selection(0, 4)) {
		case 1:
		{
			keep.keep_s_a_p_full_output(type);
			cout << "������� ����� �������, ����� ����������..." << endl;
			cin.get(); cin.get();
		}
		break;
		case 2:
		{
			keep.keep_s_a_p_full_output(type);
			cout << "������������� ������" << endl << "  [0 - ������ ��������������]" << endl << "  >> ";
			int number = selection(0, keep.keep_s_a_p_numb(type));
			if (number != 0) {
				keep.keep_s_a_p_edit(type, number);
				cout << "���������� ������:" << endl;
				keep.keep_s_a_p_full_output(type);
				
			} else cout << "������ ��������������" << endl;
			cout << "������� ����� �������, ����� ����������..." << endl;
			cin.get(); cin.get();
		}
		break;
		case 3:
		{
			keep.keep_s_a_p_add(type);
			cout << "���������� ������:" << endl;
			keep.keep_s_a_p_full_output(type);
			cout << "������� ����� �������, ����� ����������..." << endl;
			cin.get();
		}
		break;
		case 4:
		{
			if (keep.keep_s_a_p_numb(type) > 0) {
				keep.keep_s_a_p_full_output(type);
				cout << "������� ������" << endl << "  >>";
				int del_number = selection(1, keep.keep_s_a_p_numb(type));
				keep.keep_s_a_p_delete(type, del_number);
				cout << "���������� ������:" << endl;
				keep.keep_s_a_p_full_output(type);
			}
			else cout << "������������ ������� ��� ��������" << endl;
			cout << "������� ����� �������, ����� ����������..." << endl;
			cin.get(); cin.get();
		}
		break;
		case 0:
			return(0);
		}
	}
}

void Menu_X() {
	int point;
	while (1) {
		print_Menu_X();
		switch (point = selection(0, 8)) {
		case 1:
		{
			Menu_XX(point);
		}
		break;
		case 2:
		{
			Menu_XX(point);
		}
		break;
		case 3:
		{
			Menu_XX(point);
		}
		break;
		case 4:
		{
			keep.keep_import();
			cout << "������� ����� �������, ����� ����������..." << endl;
			cin.get(); cin.get();
		}
		break;
		case 5:
		{
			keep.keep_export();
			cout << "������ ������� ���������" << endl;
			cout << "������� ����� �������, ����� ����������..." << endl;
			cin.get(); cin.get();
		}
		break;
		case 6:
		{
			//������� �������� �����
			keep.keep_s_a_p_edit(4, 0);
		}
		break;
		case 7:
		{
			for (int i = 1; i < 4; i++) {
				int numb = keep.keep_s_a_p_numb(i);
				for (int j = numb; j >= 1; j--) {
					keep.keep_s_a_p_delete(i, j);
				}
			}
			keep.keep_s_a_p_delete(4,0);
		}
		break;
		case 8:
		{
			for (int i = 1; i < 4; i++) {
				keep.keep_s_a_p_full_output(i);
				cout << endl;
			}
			cout << "������� ����� �������, ����� ����������..." << endl;
			cin.get(); cin.get();
		}
		break;
		case 0:
			exit(0);
		}
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int input;
	cout << "����� ����������!" << endl;
	// ����� ���� ������ ��� / ���� � �����
	cout << "��������� ������ �� �����?" << endl << "  1. ��" << endl << "  0. ���" << endl << "  >> ";
	input = selection(0,1);
	if (input) {
		keep.keep_import();
		keep.keep_s_a_p_full_output(1);
		keep.keep_s_a_p_full_output(2);
		keep.keep_s_a_p_full_output(3);
		cout << "������� ����� �������, ����� ����������..." << endl;
		cin.get(); //cin.get();
	}
	if (!(input)) {
		keep.keep_add();
	}

	Menu_X();

	return 0;
}
