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
			cout << ptr3.ptr[i].Get_price_of_one_car() << "|" << endl;
		}
}

int main() {
	setlocale(LC_CTYPE, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int k, i, f = 0, f1, model_kuzov, s = 0, sort_year;
	cout << "Введите количество моделей кузова машин в ангаре - ";
	cin >> k;
	Hangar* ptr3 = new Hangar[k];
	ptr3->Init_Hangar(ptr3, k);
	for (int i = 0; i < k; i++) {
		ptr3[i].Read_Hangar(k, i);
	}
	do {
		ptr3->Display_Hangar(ptr3, k);
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
				ptr->Display(ptr, ptr3[model_kuzov].Get_n());
				cout << endl << "1 - сортировка таблицы по названию марки машины;" << endl;
				cout << "2 - вывести количество всех имеющихся машин в ангаре;" << endl;
				cout << "3 - вернуться к списку моделей кузова машин;" << endl;
				cout << "0 - выход из программы." << endl;
				cin >> i;
				switch (i) {
				case 1:
					ptr->Sort(ptr, ptr3[model_kuzov].Get_n());
					break;
				case 2:
					ptr->Sum(ptr, ptr3[model_kuzov].Get_n());
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
			cout << " ____________________________________________________________________" << endl;
			cout << "|                |                 |               |        |        |" << endl;
			cout << "|   Тип кузова   |    Марка авто   |  Год выпуска  | Кол-во |  Цена  |" << endl;
			cout << "|________________|_________________|_______________|________|________|" << endl;
			for (int j = 0; j < k; j++) {
				Searching_Hangar(ptr3[j], sort_year, &s);
			}
			cout << "|________________|_________________|_______________|________|________|" << endl;
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
	ptr3->Hangar_Free(ptr3);
	return 0;
}