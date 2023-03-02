#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

const int LINE = 100;
const int COLUMN = 15;

void ADD(int omega[], int main_selection[]) {
	for (int i = 0; i < COLUMN; i++) {
		if (main_selection[i] == 1) {
			omega[i]++;
		}
	}
	//cout << "+" << endl;
}

void SUB(int omega[], int main_selection[]) {
	for (int i = 0; i < COLUMN; i++) {
		if (main_selection[i] == 1) {
			omega[i]--;
		}
	}
	//cout << "-" << endl;
}

int main() {

	setlocale(LC_ALL, "rus");
	//код Иванов Данила

	int y[COLUMN + 1];
	int teta = 0; //порог
	int omega[COLUMN] = { -5, 3, 0, 8, 1, 2, 6, 2, -8, 4, 0, 3, 2, 1, 0 }; //омега
	cout << "Введите Тету: "; cin >> teta; cout << endl; //ввод порога 

	string path[COLUMN + 1] = {
		"C:\\AI_TEST\\err_lab2\\err0.txt",
		"C:\\AI_TEST\\err_lab2\\err1.txt",
		"C:\\AI_TEST\\err_lab2\\err2.txt",
		"C:\\AI_TEST\\err_lab2\\err3.txt",
		"C:\\AI_TEST\\err_lab2\\err4.txt",
		"C:\\AI_TEST\\err_lab2\\err5.txt",
		"C:\\AI_TEST\\err_lab2\\err6.txt",
		"C:\\AI_TEST\\err_lab2\\err7.txt",
		"C:\\AI_TEST\\err_lab2\\err8.txt",
		"C:\\AI_TEST\\err_lab2\\err9.txt",
		"C:\\AI_TEST\\err_lab2\\err10.txt",
		"C:\\AI_TEST\\err_lab2\\err11.txt",
		"C:\\AI_TEST\\err_lab2\\err12.txt",
		"C:\\AI_TEST\\err_lab2\\err13.txt",
		"C:\\AI_TEST\\err_lab2\\err14.txt",
		"C:\\AI_TEST\\err_lab2\\err15.txt",
	};
	string buff; //записываем строчку из файла

	const int N0[COLUMN + 1][COLUMN + 1] = {
		{ 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1 },
		{ 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1 }, //шаблон для числа 0
		{ 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1 },
		{ 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1 },
		{ 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1 },
		{ 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1 },
		{ 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1 },
		{ 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1 },
		{ 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1 },
		{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1 },
		{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1 },
		{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1 },
		{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1 },
		{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1 },
		{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1 },
		{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0 },
	};
	int buffer_omega[COLUMN] = {};
	int weight = 0;
	int counter_selection = 0; //счетчик проходов по выборке
	bool func_check = false;
	bool fist_omega = false; //флаг для получения идеальной омеги
	bool check_number = false; //флаг для необходимого числа

	cout << "Исходная омега: | ";
	for (int i = 0; i < COLUMN; i++) {
		cout << omega[i] << " | ";
	}cout << endl;

	int main_selection[100][COLUMN] = {};

	for (int pth_point = 0; pth_point < COLUMN + 1; pth_point++) {

		int temp_mass[COLUMN] = {};
		
		vector <int> min; //миниму ошибок за прогон

		ifstream file(path[pth_point]);

		//блок записи выборки из файла
		if (file.is_open()) {
			int i = 0;
			while (getline(file, buff, '\n')) {
				for (int j = 0; j < COLUMN; j++) {
					main_selection[i][j] = (int)buff[j] - 48;
				}
				i++;
			}
		}
		else { cout << "File is not open! Check path!" << endl; }
		file.close();
		int err = 0;//кол-во ошибок

	start:

		/*if (fist_omega == true) {
			for (int i = 0; i < COLUMN; i++) {
				//9cout << buffer_omega[i] << " ";
				omega[i] = buffer_omega[i];
			}
		}cout << endl;*/

		for (int point = 0; point < LINE; point++) {
			for (int i = 0; i < COLUMN; i++) {
				weight += omega[i] * main_selection[point][i];
				temp_mass[i] = main_selection[point][i]; //получаем строку, для корректной работы функций
			}
			int count = 0;
			for (int i = 0; i < COLUMN; i++) {
				if (temp_mass[i] == N0[pth_point][i]) { count++; }
			}
			if (count == COLUMN) { func_check = true; }
			else { func_check = false; }

			if (weight <= teta and func_check == true) {
				ADD(omega, temp_mass);
				err++;
			}
			else if (weight > teta and func_check == false) {
				SUB(omega, temp_mass);
				err++;
			}
			weight = 0;
		}
		min.push_back(err);
		counter_selection++;
		if (counter_selection <= 2) { goto start; }
		else {
			if (fist_omega == false) {
				fist_omega = true;
				cout << "Отколиброванная Омега: | ";
				for (int i = 0; i < COLUMN; i++) {
					buffer_omega[i] = omega[i];
					cout << buffer_omega[i] << " | ";
				}cout<<endl;
			}

			counter_selection = 0;
			int temp_min = *min_element(min.begin(), min.end());
			y[pth_point] = temp_min;
		}
	}
	for (int i = 1; i < COLUMN + 1; i++) {
		cout << i << ") " << y[i] << endl;
	}
}