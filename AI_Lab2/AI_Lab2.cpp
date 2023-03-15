#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <fstream>

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
	bool flag_zero = false;
	int temp[COLUMN+1] = {};
	int teta = 29; //порог
	
	cout << "Введите Тету: "; cin >> teta; cout << endl; //ввод порога 

	int weight = 0;
	int omega[COLUMN + 1] = { 0,1,4,5,2,10,6,7,-2,-11,1,3,5,5,4,8 }; //омега
	cout << "Исходная омега: | ";
	for (int i = 1; i < COLUMN+1; i++) {
		cout << omega[i] << " | ";
	}cout << endl;
	cout << endl;
	int err = 0;
	int prev_err = 0;
	vector <int> errors = {};
	string buff;

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

	int main_selection[LINE][COLUMN + 1] = {};

	for (int pth_point = 0; pth_point < COLUMN + 1; pth_point++) {
		
		//int omega[COLUMN + 1] = { 0,2,4,1,9,6,6,-3,-6,0,2,5,4,3,7,0 };

		fstream file(path[pth_point]);

		if (file.is_open()) {
			int i = 0;
			while (getline(file, buff, '\n')) {
				for (int j = 0; j < COLUMN + 1; j++) {
					main_selection[i][j] = (int)buff[j] - 48;
				}
				i++;
			}
		}
		else { cout << "File is not open! Check path!" << endl; }
		file.close();
	
	start:
		prev_err = err;
		err = 0;
		for (int point = 0; point < LINE; point++) {
			for (int i = 1; i < COLUMN+1; i++) {
				weight += omega[i] * main_selection[point][i];
				temp[i] = main_selection[point][i];
			}
			if (main_selection[point][0] == 0 and weight > teta) { flag_zero = true; }
			else if (main_selection[point][0] == 0 and weight <= teta) { ADD(omega, temp); flag_zero = false; }
			else if (main_selection[point][0] != 0 and weight > teta) { SUB(omega, temp); flag_zero = false; }
			weight = 0;
		if (main_selection[point][0] == 0 and flag_zero == false) { err++; }
		};
		//if (flag_zero == true) { err = 0; }
		if ((err - prev_err < 0) or (prev_err - err < 0)) { cout << "restart" << endl; goto start; }
		cout << "Err = " << err << endl;
		errors.push_back(err);

		for (int i = 0; i < COLUMN; i++) {
			cout << omega[i] << " ";
		}cout << endl;
	}
/*
	for (int i = 0; i < errors.size(); i++) {
		cout << "Кол - во помех: " << i << ", процент ошибки: " << errors[i] << endl;
	}*/

}
	