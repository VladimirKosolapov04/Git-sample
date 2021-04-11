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
	int amount_code;
	static int amount;
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
	int Get_amount_code() {
		return amount_code;
	}
	static int Get_amount() {
		return amount;
	}

	Auto() {
		amount_code = 0;
		car_brand = "Нет названия";
		year_of_release = 0;
		number_of_cars = 0;
		price_of_one_car = 0;
	}
	Auto(string car) {
		Auto::amount = 100 + rand() % 100;
		amount_code = amount;
		car_brand = car;
		year_of_release = 0;
		number_of_cars = 0;
		price_of_one_car = 0;
	}
	Auto(string car, int year, int number, int price) {
		Auto::amount = 100 + rand() % 100;
		amount_code = amount;
		car_brand = car;
		year_of_release = year;
		number_of_cars = number;
		price_of_one_car = price;
	}
	Auto(const Auto &obj) {
		this->car_brand = obj.car_brand;
		this->amount_code = obj.amount_code;
		this->year_of_release = obj.year_of_release;
		this->number_of_cars = obj.number_of_cars;
		this->price_of_one_car = obj.price_of_one_car;
		cout << "Класс скопирован с помощью конструктора копирования\n";
		int prob_1 = 17 - car_brand.length();
		while (prob_1 != 0) {
			cout << " ";
			prob_1--;
		}
		cout << this->car_brand;
		cout << "|           " << this->year_of_release << "|";
		int j, digit_1 = this->number_of_cars;
		for (j = 1; digit_1 > 0; j++) {
			digit_1 /= 10;
		}
		int prob_2 = 9 - j;
		while (prob_2 != 0) {
			cout << " ";
			prob_2--;
		}
		cout << this->number_of_cars << "|";
		int digit_2 = this->price_of_one_car;
		for (j = 1; digit_2 > 0; j++) {
			digit_2 /= 10;
		}
		int prob_3 = 9 - j;
		while (prob_3 != 0) {
			cout << " ";
			prob_3--;
		}
		cout << this->price_of_one_car << "|";
		cout << "    " << this->amount_code << "|" << endl;
	}
	Auto& operator = (const Auto& obj) {
		if (this == &obj)
			return *this;
		this->car_brand = obj.car_brand;
		this->amount_code = obj.amount_code;
		this->year_of_release = obj.year_of_release;
		this->number_of_cars = obj.number_of_cars;
		this->price_of_one_car = obj.price_of_one_car;
		return *this;
	}
	void Read(int i) {
			Auto::amount = 100 + rand() % 100;
			amount_code = amount;
			cout << "Введите " << i + 1 << " запись:" << endl;
			cout << "Введите марку автомобиля - ";
			cin >> car_brand;
			try {
				cout << "Введите год выпуска автомобиля - ";
				cin >> year_of_release;
				if (year_of_release < 0)
					throw year_of_release;
			}
			catch (int) {
				cout << "Год не может быть отрицательным\n";
				year_of_release *= -1;
			}
			try {
				cout << "Введите количество автомобилей в ангаре - ";
				cin >> number_of_cars;
				if (number_of_cars < 0)
					throw number_of_cars;
			}
			catch (int) {
				cout << "Количество не может быть отрицательным\n";
				number_of_cars *= -1;
			}
			try {
				cout << "Введите стоимость одного автомобиля данной марки (в $) - ";
				cin >> price_of_one_car;
				if (price_of_one_car < 0)
					throw price_of_one_car;
			}
			catch (int) {
				cout << "Цена не может быть отрицательной\n";
				price_of_one_car *= -1;
			}
		}
void Display(int i) {
	cout << "|   " << i + 1 << "   |";
	int prob_1 = 17 - car_brand.length();
	while (prob_1 != 0) {
		cout << " ";
		prob_1--;
	}
	cout << car_brand;
	cout << "|           " << year_of_release << "|";
	int j, digit_1 = number_of_cars;
	for (j = 1; digit_1 > 0; j++) {
		digit_1 /= 10;
	}
	int prob_2 = 9 - j;
	while (prob_2 != 0) {
		cout << " ";
		prob_2--;
	}
	cout << number_of_cars << "|";
	int digit_2 = price_of_one_car;
	for (j = 1; digit_2 > 0; j++) {
		digit_2 /= 10;
	}
	int prob_3 = 9 - j;
	while (prob_3 != 0) {
		cout << " ";
		prob_3--;
	}
	cout << price_of_one_car << "|";
	cout << "    " << amount_code << "|" << endl;
}

};

