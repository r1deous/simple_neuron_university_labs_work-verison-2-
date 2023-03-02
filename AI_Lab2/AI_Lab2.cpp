#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int LINE = 10;
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
	bool flag_zero = false;
	int temp[COLUMN] = {};
	int teta = 0; //порог
	int omega[COLUMN] = { -5, 3, 0, 8, 1, 2, 6, 2, -8, 4, 0, 3, 2, 1, 0 }; //омега
	cout << "Введите Тету: "; cin >> teta; cout << endl; //ввод порога 

	int weight = 0;

	cout << "Исходная омега: | ";
	for (int i = 0; i < COLUMN; i++) {
		cout << omega[i] << " | ";
	}cout << endl;

	int main_selection[LINE][COLUMN] = {
		{1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1}, //0
		{0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1}, //1
		{1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1}, //2
		{1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0}, //3
		{1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1}, //4
		{1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1}, //5
		{0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1}, //6
		{1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, //7
		{1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1}, //8
		{1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0}, //9
	};

	for (int iter = 0; iter < LINE; iter++) {
		for (int point = 0; point < LINE; point++) {
			for (int i = 0; i < COLUMN; i++) {
				weight += omega[i] * main_selection[point][i];
				temp[i] = main_selection[point][i];
			}
			if (point == 0 and weight > teta) { flag_zero = true; }
			else if (point == 0 and weight <= teta) { ADD(omega, temp); flag_zero = false; }
			else if (point != 0 and weight > teta) { SUB(omega, temp); flag_zero = false; }
		}
	}
}