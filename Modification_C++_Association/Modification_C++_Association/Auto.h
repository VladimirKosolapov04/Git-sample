#pragma once
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

class Auto {
private:
	string car_brand;
	int year_of_release;
	int number_of_cars;
	int price_of_one_car;
public:
	string Get_car_brand() {
		return this->car_brand;
	}
	int Get_year_of_release() {
		return this->year_of_release;
	}
	int Get_number_of_cars() {
		return this->number_of_cars;
	}
	int Get_price_of_one_car() {
		return this->price_of_one_car;
	}

	void Init(Auto* ptr, int n) {
		for (int i = 0; i < n; i++) {
			ptr[i].year_of_release = 0;
			ptr[i].number_of_cars = 0;
			ptr[i].price_of_one_car = 0;
		}
	}
	void Read(Auto* ptr, int n) {
		for (int i = 0; i < n; i++) {
			cout << "Введите " << i + 1 << " запись:" << endl;
			cout << "Введите марку автомобиля - ";
			cin >> ptr[i].car_brand;
			cout << "Введите год выпуска автомобиля - ";
			cin >> ptr[i].year_of_release;
			cout << "Введите количество автомобилей в ангаре - ";
			cin >> ptr[i].number_of_cars;
			cout << "Введите стоимость одного автомобиля данной марки (в $) - ";
			cin >> ptr[i].price_of_one_car;
		}
	}
	void Display(Auto* ptr, int n) {
		cout << " ___________________________________________________________" << endl;
		cout << "|       |                 |               |        |        |" << endl;
		cout << "|   №   |    Марка авто   |  Год выпуска  | Кол-во |  Цена  |" << endl;
		cout << "|_______|_________________|_______________|________|________|" << endl;
		for (int i = 0; i < n; i++) {
			cout << "|   " << i + 1 << "   |";
			int prob_1 = 17 - ptr[i].car_brand.length();
			while (prob_1 != 0) {
				cout << " ";
				prob_1--;
			}
			cout << ptr[i].car_brand;
			cout << "|           " << ptr[i].year_of_release << "|";
			int j, digit_1 = ptr[i].number_of_cars;
			for (j = 1; digit_1 > 0; j++) {
				digit_1 /= 10;
			}
			int prob_2 = 9 - j;
			while (prob_2 != 0) {
				cout << " ";
				prob_2--;
			}
			cout << ptr[i].number_of_cars << "|";
			int digit_2 = ptr[i].price_of_one_car;
			for (j = 1; digit_2 > 0; j++) {
				digit_2 /= 10;
			}
			int prob_3 = 9 - j;
			while (prob_3 != 0) {
				cout << " ";
				prob_3--;
			}
			cout << ptr[i].price_of_one_car << "|" << endl;
		}
		cout << " ____________________________________________________________" << "\n";
	}
	int Add(int a, int b) {
		int sum1 = a + b;
		int& res = sum1;
		return res;
	}
	void Sort(Auto* ptr, int n) {
		Auto p;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (ptr[i].car_brand > ptr[j].car_brand) {
					p = ptr[i];
					ptr[i] = ptr[j];
					ptr[j] = p;   

				}
			}
		}
	}
	void Sum(Auto* ptr, int n) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum = Add(sum, ptr[i].number_of_cars);
		}
		cout << "Количество всех автомобилей в ангаре: " << sum << endl;
		system("pause");
	}
	void Auto_Free(Auto* ptr) {
		delete[] ptr;
	}
};
