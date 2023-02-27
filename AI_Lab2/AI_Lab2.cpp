#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int line = 100;
const int column = 15;

int main() {

	setlocale(LC_ALL, "rus");

	int teta;
	cout << "Введите Teta: "; cin >> teta; cout << endl;
	
	vector<int>omega = { 1,4,2,1,6,8,3,5,1,0,11,23,6,1,6 }; //Omega

	string path[column + 1] = {"C:\\AI_TEST\\err_lab2\\err0.txt",
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

	const int N0[column + 1][column] = {
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
	const int main_selection[line][column] = {}; //обучающая выборка


}