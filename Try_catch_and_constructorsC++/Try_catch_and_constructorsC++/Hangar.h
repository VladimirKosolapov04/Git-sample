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
	void Read_Hangar(Hangar ptr3, int i) {
		cout << "¬ведите " << i + 1 << " тип кузова машины: ";
		cin >> model;
		try {
			cout << " оличество машин с типом кузова (" << model << "): ";
			cin >> n;
			if (n < 0)
				throw - 1;
			else
				if (n == 0)
					throw 0;
		}
		catch (int n1) {
			if (n1 == 0) {
				cout << "ƒолжна быть хот€ одна модель кузова: кол-ву будет приравнено 1";
				n = 1;
			}
			else {
				cout << " оличество типов кузова не может быть отрицательным: кол-во будет умножено на -1";
				n *= -1;
			}
		}
		ptr = new Auto[n];
		for (int i = 0; i < n; i++)
		ptr[i].Read(i);
	}
	void Display_Hangar(int i) {
			cout << "|   " << i + 1 << "   |";
			int prob_11 = 16 - model.length();
			while (prob_11 != 0) {
				cout << " ";
				prob_11--;
			}
			cout << model << "|";
			int j, digit_11 = n;
			for (j = 1; digit_11 > 0; j++) {
				digit_11 /= 10;
			}
			int prob_21 = 9 - j;
			while (prob_21 != 0) {
				cout << " ";
				prob_21--;
			}
			cout << n << "|" << endl;
	}
	int Add(int a, int b) {
		int sum1 = a + b;
		int& res = sum1;
		return res;
	}
	void Sort() {
		Auto p;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (ptr[i].Get_car_brand() > ptr[j].Get_car_brand()) {
					p = ptr[i];
					ptr[i] = ptr[j];
					ptr[j] = p;

				}
			}
		}
	}
	void Sum() {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum = Add(sum, ptr[i].Get_number_of_cars());
		}
		cout << " оличество всех автомобилей в ангаре: " << sum << endl;
		system("pause");
	}
	void Hangar_Free() {
		delete[] ptr;
	}
};

