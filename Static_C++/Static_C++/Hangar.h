#pragma once
#include <iostream>
#include <cstdio>
#include "Auto.h"

using namespace std;

class Hangar {
private:
	string model;
	int n;
	Auto* ptr;
public:
	string Get_model() {
		return (this->model);
	}
	int Get_n() {
		return (this->n);
	}
	Auto* Get_ptr() {
		return (this->ptr);
	}

	friend void Searching_Hangar(Hangar ptr3, int sort_year, int* s);

	void Init_Hangar(Hangar* ptr3, int k) {
		for (int i = 0; i < n; i++) {
			ptr3[i].n = 0;
		}
	}
	void Read_Hangar(int k, int i) {
		cout << "Введите " << i + 1 << " тип кузова машины: ";
		cin >> model;
		cout << "Количество машин с типом кузова (" << model << "): ";
		cin >> n;
		ptr = new Auto[n];
		ptr->Read(ptr, n);
	}
	void Display_Hangar(Hangar* ptr3, int k) {
		system("cls");
		cout << " _________________________________\n";
		cout << "|       |                |        |\n";
		cout << "|   №   |   Тип кузова   | Кол-во |\n";
		cout << "|_______|________________|________|\n";
		for (int i = 0; i < k; i++) {
			cout << "|   " << i + 1 << "   |";
			int prob_11 = 16 - ptr3[i].model.length();
			while (prob_11 != 0) {
				cout << " ";
				prob_11--;
			}
			cout << ptr3[i].model << "|";
			int j, digit_11 = ptr3[i].n;
			for (j = 1; digit_11 > 0; j++) {
				digit_11 /= 10;
			}
			int prob_21 = 9 - j;
			while (prob_21 != 0) {
				cout << " ";
				prob_21--;
			}
			cout << ptr3[i].n << "|" << endl;
		}
		cout << "|_______|________________|________|\n";
	}
	void Hangar_Free(Hangar* ptr3) {
		ptr->Auto_Free(ptr);
		delete[] ptr3;
	}
};


