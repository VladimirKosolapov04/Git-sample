#pragma once
#include <iostream>
#include <cstdio>
#include "Auto.h"

using namespace std;

class Hangar {
private:
	char* model = new char;
	int n;
	Auto* ptr;
public:
	char* Get_model() {
		return (this->model);
	}
	int Get_n() {
		return (this->n);
	}
	Auto* Get_ptr() {
		return (this->ptr);
	}

	void Init_Hangar(Hangar* ptr3, int k) {
		for (int i = 0; i < n; i++) {
			ptr3[i].n = 0;
		}
	}
	void Read_Hangar(int k, int i) {
			cout << "Введите " << i + 1 << " тип кузова машины: ";
			while (getchar() != '\n');
			fgets(model, 15, stdin);
			model[strlen(model) - 1] = '\0';
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
			int prob_11 = 16 - strlen(ptr3[i].model);
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
	void Searching_Hangar(Hangar ptr3, int sort_year, int* s) {
		for (int i = 0; i < n; i++)
			if (sort_year < ptr3.ptr[i].Get_year_of_release()) {
				(*s)++;
				cout << "|";
				int prob_sear = 16 - strlen(ptr3.model);
				while (prob_sear != 0) {
					cout << " ";
					prob_sear--;
				}
				cout << ptr3.model << "|";
				int prob_sear1 = 17 - strlen(ptr3.ptr[i].Get_car_brand());
				while (prob_sear1 != 0) {
					cout << " ";
					prob_sear1--;
				}
				cout << ptr3.ptr[i].Get_car_brand();
				cout << "|           " << ptr3.ptr[i].Get_year_of_release() << "|";
				int j, digit_1 = ptr3.ptr[i].Get_number_of_cars();
				for (j = 1; digit_1 > 0; j++) {
					digit_1 /= 10;
				}
				int prob_2 = 9 - j;
				while (prob_2 != 0) {
					cout << " ";
					prob_2--;
				}
				cout << ptr3.ptr[i].Get_number_of_cars() << "|";
				int digit_2 = ptr3.ptr[i].Get_price_of_one_car();
				for (j = 1; digit_2 > 0; j++) {
					digit_2 /= 10;
				}
				int prob_3 = 9 - j;
				while (prob_3 != 0) {
					cout << " ";
					prob_3--;
				}
				cout << ptr3.ptr[i].Get_price_of_one_car() << "|" << endl;
			}
	}
	void Hangar_Free(Hangar* ptr3) {
		ptr->Auto_Free(ptr);
		delete[] ptr3;
	}
};