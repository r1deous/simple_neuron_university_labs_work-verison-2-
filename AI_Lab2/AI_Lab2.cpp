#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

void func_AI(int teta, int omega[]) {

	bool check_flag = false; //флаг проверки корректности обучения

	int point = 0;

	const int N0[15] = { 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1 }; //шаблон для числа 6
	const int main_selection[100][15] = { //выборкa
		{1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0},
		{1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
		{1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1},
		{0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1},
		{1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
		{0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0},
		{1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0},
		{1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
		{1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1},
		{0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1},
		{0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1},
		{0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},
		{1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1},
		{0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},
		{0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1},
		{0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1},
		{1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1},
		{1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
		{0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
		{1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1},
		{1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0},
		{0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1},
		{1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
		{1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1},
		{1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0},
		{1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1},
		{1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1},
		{1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0},
		{1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1},
		{0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0},
		{1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0},
		{1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0},
		{1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0},
		{1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1},
		{1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1},
		{0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1},
		{1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
		{0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1},
		{1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0},
		{1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0},
		{1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0},
		{1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1},
		{1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1},
		{1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0},
		{1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0},
		{1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1},
		{1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1},
		{1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1},
		{1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1},
		{1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
		{1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0},
		{1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1},
		{1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
		{0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1},
		{0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},
		{0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1},
		{1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1},
		{1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0},
		{1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1},
		{1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
		{1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0},
		{1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1},
		{0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1},
		{0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1},
		{0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1},
		{1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
		{1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1},
		{0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1},
		{1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
		{1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0},
		{1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1},
		{1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1},
		{1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0},
		{1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1},
		{1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1},
	};

	while (check_flag != true) {

		int massa = 0;
		int temp = 0;
		int zero = 0;
		bool zero_flag = false; //флаг для опеределения цифры 6

		for (int i = 0; i < 15; i++) {
			if (N0[i] == main_selection[point][i]) {
				zero++;
				temp = omega[i] * main_selection[point][i];
			}
			else { temp = omega[i] * main_selection[point][i]; }
			massa += temp;

		}
		if (zero == 15) { zero_flag = true; }
		//cout << "massa: " << massa << endl;
		//cout << "flag_six: " << six_flag << endl;
		if (massa > teta and zero_flag == true) {
			check_flag = true;
		}
		else if (massa <= teta and zero_flag == true) {
			for (int i = 0; i < 15; i++) {
				if (main_selection[point][i] == 1) {
					omega[i]++;
				}
				//cout << omega[i] << ", ";
			}
			point = 0;
			//cout << endl;
		}
		else if (massa > teta and zero_flag == false) {
			for (int i = 0; i < 15; i++) {
				if (main_selection[point][i] == 1) {
					omega[i]--;
				}
				//cout << omega[i] << ", ";
			}
			point = 0;
			//cout << endl;
		}
		else if (massa <= teta and zero_flag == false) {
			point++;
		}
		//cout << "point: " << point << endl;
	}
}
void func_AI_err(int teta, int omega[], int y[]) {

	bool check_flag = false; //флаг проверки корректности обучения
	int err = 0;
	int omega_err[15];
	int point = 0;
	int pth_point = 0;
	string buff;

	for (int i = 0; i < 15; i++) {
		omega_err[i] = omega[i];
	}

	string path[15] = { "C:\\AI_TEST\\err_lab2\\err1.txt",
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

	const int N0[15][15] = {
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
	int main_selection[100][15] = {};

	while (pth_point != 15) {
		//cout << path[pth_point] << endl;
		ifstream file(path[pth_point]);

		if (file.is_open()) {
			int i = 0;
			while (getline(file, buff, '\n')) {
				for (int j = 0; j < 15; j++) {
					main_selection[i][j] = (int)buff[j] - 48;
				}
				i++;
			}
		}
		else { cout << "File is not open! Check path!" << endl; }
		file.close();


		while (check_flag != true) {

			int massa = 0;
			int temp = 0;
			int zero = 0;
			bool zero_flag = false; //флаг для опеределения цифры 0



			for (int i = 0; i < 15; i++) {

				if (N0[pth_point][i] == main_selection[point][i]) {
					zero++;
					temp = omega_err[i] * main_selection[point][i];
				}
				else { temp = omega_err[i] * main_selection[point][i]; }
				massa += temp;

			}
			if (zero == 15) { zero_flag = true; }
			//cout << "massa: " << massa << endl;
			//cout << "flag_six: " << zero_flag << endl;
			if (massa > teta and zero_flag == true) {
				y[pth_point] = err;
				cout << y[pth_point] << endl;
				check_flag = true;
			}
			else if (massa <= teta and zero_flag == true) {
				for (int i = 0; i < 15; i++) {
					if (main_selection[point][i] == 1) {
						omega_err[i]++;
						err++;
					}
					//cout << omega[i] << ", ";
				}
				point = 0;
				//cout << endl;
			}
			else if (massa > teta and zero_flag == false) {
				for (int i = 0; i < 15; i++) {
					if (main_selection[point][i] == 1) {
						omega_err[i]--;
						err++;
					}
					//cout << omega[i] << ", ";
				}
				point = 0;
				//cout << endl;
			}
			else if (massa <= teta and zero_flag == false) {
				point++;
			}

			//cout << "point: " << point << endl;
			//cout << y[1] << endl;
		}
		pth_point++;
		err = 0;
		check_flag = false;
		cout << "Pth_point: " << pth_point << endl;
	}
}


bool test_AI(int teta, int omega[]) {

	int temp = 0;
	int point = 0;
	int counter = 0;
	int weight = 0;

	const int test_selection[10][15] = { //выборка для проверка омеги
		{1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1},
		{0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1},
		{1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1},
		{1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0},
		{1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1},
		{1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1},
		{0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
		{1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0},

	};

	while (point != 10) {
		//блок проверок
		for (int i = 0; i < 15; i++) {

			temp = omega[i] * test_selection[point][i];
			weight += temp;
		}

		if (weight > teta and point == 0) { //0
			counter++;
		}
		else if (weight <= teta and point == 1) { //1
			counter++;
		}
		else if (weight <= teta and point == 2) { //2
			counter++;
		}
		else if (weight <= teta and point == 3) { //3
			counter++;
		}
		else if (weight <= teta and point == 4) { //4
			counter++;
		}
		else if (weight <= teta and point == 5) { //5
			counter++;
		}
		else if (weight <= teta and point == 6) { //6
			counter++;
		}
		else if (weight <= teta and point == 7) { //7
			counter++;
		}
		else if (weight <= teta and point == 8) { //8
			counter++;
		}
		else if (weight <= teta and point == 9) { //9
			counter++;
		}
		//cout << "Weight: " << weight << endl;
		weight = 0;
		point++;
	}
	//cout << "counter: " << counter << endl;
	if (counter == 10) {
		cout << "The test was successful!" << endl;
		return true;
	}
	else {
		cout << "Test faild!" << endl;
		return false;
	}
}

int main()
{	//Написал код Иванов Данила
	srand(time(nullptr)); //задаем рагдомные числа
	int y[15];
	int teta = 0; //порог
	int omega[15] = { 2, 3, 5, 8, 4, 6, 0, 2, 0, 4, 7, 9, 2, 1, 5 }; //омега
	cout << "Enter Teta: "; cin >> teta; cout << endl; //ввод порога 
	cout << "Omega (old): | ";

	for (int i = 0; i < 15; i++) { //ввод омеги
		//cin >> omega[i];
		//cout << " | ";
		//omega[i] = rand() % 10; //получаем рандомное числа в омеге в диапозоне от 0 до 100
		cout << omega[i] << " | ";
	}
	cout << endl;

	func_AI(teta, omega); //функция обучения нейрона
	test_AI(teta, omega); //проверка обучения нейрона

	if (test_AI) {
		cout << "Work succeccfuly!" << endl;
		cout << "Omega (new): | ";
		for (int i = 0; i < 15; i++) {
			cout << omega[i] << " | ";
		}
		cout << endl;
		func_AI_err(teta, omega, y);
		for (int i = 0; i < 15; i++) {
			cout << "X = " << i + 1 << "; Y = " << y[i] << endl;
		}
	}
	else {
		cout << "Restart!" << endl;
	}

}