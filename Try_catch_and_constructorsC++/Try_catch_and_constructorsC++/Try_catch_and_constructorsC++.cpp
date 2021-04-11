#include <iostream>
#include <windows.h>
#include <cstdio>
#include <clocale>
#include "Hangar.h"

using namespace std;

void Searching_Hangar(Hangar ptr3, int sort_year, int* s) {
	for (int i = 0; i < ptr3.Get_n(); i++)
		if (sort_year < ptr3.ptr[i].Get_year_of_release()) {
			(*s)++;
			cout << "|";
			int prob_sear = 16 - ptr3.model.length();
			while (prob_sear != 0) {
				cout << " ";
				prob_sear--;
			}
			cout << ptr3.model << "|";
			int prob_sear1 = 17 - ptr3.ptr[i].Get_car_brand().length();
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
			cout << ptr3.ptr[i].Get_price_of_one_car() << "|";
			cout << "    " << ptr3.ptr[i].Get_amount_code() << "|" << endl;
		}
}
int Auto::amount = 100;

int main() {
	setlocale(LC_CTYPE, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int k, i, f = 0, f1, model_kuzov, s = 0, sort_year;
	cout << "Класс объявлен конструктором без параметров\n";
	Auto auto0;
	auto0.Display(0);
	cout << "Класс объявлен конструктором с одним параметром\n";
	Auto auto1("Мерседес");
	auto1.Display(0);
	cout << "Класс объявлен конструктором с несколькими параметрами\n";
	Auto auto2("Мерседес", 2019, 7, 300000);
	auto2.Display(0);
	Auto auto3(auto2);
	Auto auto5, auto4;
	auto4 = auto5 = auto3;
	cout << "Следующие классы скопированы с помощью оператора перегрузки\n";
	auto4.Display(1);
	auto5.Display(2);

	try {
		cout << "Введите количество моделей кузова машин в ангаре - ";
		cin >> k;
		if (k < 0)
			throw - 1;
		else
			if (k == 0)
				throw 0;
	}
	catch (int k1) {
		if (k1 == 0) {
			cout << "Должна быть хотя одна модель кузова: кол-ву будет приравнено 1";
			k = 1;
		}
		else {
			cout << "Количество типов кузова не может быть отрицательным: кол-во будет умножено на -1";
			k *= -1;
		}
	}
	Hangar* ptr3 = new Hangar[k];
	for (int i = 0; i < k; i++) {
		ptr3[i].Read_Hangar(ptr3[i], i);
	}
	do {
		system("cls");
		cout << " _________________________________\n";
		cout << "|       |                |        |\n";
		cout << "|   №   |   Тип кузова   | Кол-во |\n";
		cout << "|_______|________________|________|\n";
		for (int  i = 0; i < k; i++)
			ptr3[i].Display_Hangar(i);
		cout << "|_______|________________|________|\n";
		cout << "\n1 - вывести данные о конкретной модели кузова автомобиля;\n";
		cout << "2 - вывести данные о машинах новее определенного года;\n";
		cout << "0 - выход из программы.\n";
		cin >> i;
		switch (i) {
		case 1: {
			f1 = 0;
			cout << "Введите номер конкретной модели кузова - ";
			cin >> model_kuzov;
			model_kuzov--;
			Auto* ptr = ptr3[model_kuzov].Get_ptr();
			do {
				system("cls");
				cout << ptr3[model_kuzov].Get_model() << endl;
				cout << " ___________________________________________________________________" << endl;
				cout << "|       |                 |               |        |        |       |" << endl;
				cout << "|   №   |    Марка авто   |  Год выпуска  | Кол-во |  Цена  |  Код  |" << endl;
				cout << "|_______|_________________|_______________|________|________|_______|" << endl;
				for (int j = 0; j < ptr3[model_kuzov].Get_n(); j++)
					ptr[j].Display(j);
				cout << " ___________________________________________________________________" << "\n";
				cout << endl << "1 - сортировка таблицы по названию марки машины;" << endl;
				cout << "2 - вывести количество всех имеющихся машин в ангаре;" << endl;
				cout << "3 - вернуться к списку моделей кузова машин;" << endl;
				cout << "0 - выход из программы." << endl;
				cin >> i;
				switch (i) {
				case 1:
					ptr3[model_kuzov].Sort();
					break;
				case 2:
					ptr3[model_kuzov].Sum();
					break;
				case 3:
					f1 = 1;
					break;
				case 0:
					f = 1;
					f1 = 1;
					break;

				default:
					break;
				}
			} while (f1 == 0);
			break; }
		case 2:
			cout << "Введите год новее которого автомобили вас интересуют: ";
			cin >> sort_year;
			cout << " ____________________________________________________________________________" << endl;
			cout << "|                |                 |               |        |        |       |" << endl;
			cout << "|   Тип кузова   |    Марка авто   |  Год выпуска  | Кол-во |  Цена  |  Код  |" << endl;
			cout << "|________________|_________________|_______________|________|________|_______|" << endl;
			for (int j = 0; j < k; j++) {
				Searching_Hangar(ptr3[j], sort_year, &s);
			}
			cout << "|________________|_________________|_______________|________|________|_______|" << endl;
			cout << "Количество всех найденных автомобилей: " << s << endl;
			s = 0;
			system("pause");
			break;
		case 0:
			f = 1;
			break;

		default:
			break;
		}
	} while (f == 0);
	for (int i = k - 1; i >= 0; i--)
		ptr3[i].Hangar_Free();
	return 0;
}
