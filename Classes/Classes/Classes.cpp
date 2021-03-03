#include <iostream>
#include <windows.h>
#include <cstdio>
#include <clocale>

using namespace std;

class Auto {
private:
	char* car_brand = new char;
	int year_of_release;
	int number_of_cars;
	int price_of_one_car;
public:
	void Init(Auto *ptr, int n) {
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
			while (getchar() != '\n');
			fgets(ptr[i].car_brand, 15, stdin);
			ptr[i].car_brand[strlen(ptr[i].car_brand) - 1] = '\0';
			cout << "Введите год выпуска автомобиля - ";
			cin >> ptr[i].year_of_release;
			cout << "Введите количество автомобилей в ангаре - ";
			cin >> ptr[i].number_of_cars;
			cout << "Введите стоимость одного автомобиля данной марки (в $) - ";
			cin >> ptr[i].price_of_one_car;
		}
	}
	void Display(Auto *ptr, int n) {
		cout << " ___________________________________________________________" << endl;
		cout << "|       |                 |               |        |        |" << endl;
		cout << "|   №   |    Марка авто   |  Год выпуска  | Кол-во |  Цена  |" << endl;
		cout << "|_______|_________________|_______________|________|________|" << endl;
		for (int i = 0; i < n; i++) {
			cout << "|   " << i + 1 << "   |";
			int prob_1 = 17 - strlen(ptr[i].car_brand);
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
		return a + b;
	}
	void Sort(Auto* ptr, int n) {
		Auto p;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (strcmp(ptr[i].car_brand, ptr[j].car_brand) > 0) {
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

int main() {
	setlocale(LC_CTYPE, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n, i, f = 0;
	cout << "Введите количество записей: ";
	cin >> n;
	Auto *ptr = new Auto[n];
	ptr -> Init(ptr, n);
	ptr -> Read(ptr, n);
	do {
		ptr->Display(ptr, n);
		cout << "\n\nНажмите 1 чтобы отсортировать таблицу по названию марки автомобиля.\n";
		cout << "Нажмите 2 чтобы узнать количество всех имеющихся автомобилей в ангаре.\n";
		cout << "Для выхода нажмите 0.\n";
		cin >> i;
		switch (i) {
		case 1:
			ptr -> Sort(ptr, n);
			break;
		case 2:
			ptr -> Sum(ptr, n);
			break;
		case 0:
			f = 1;
			break;
		default:
			break;
		}
	} while (f == 0);
	ptr -> Auto_Free(ptr);
	return 0;
}