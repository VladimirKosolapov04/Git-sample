#include <stdio.h>
#include <windows.h>
#include <malloc.h>
#include <locale.h>


class cars {
	char* name = new char;
	int year;
	int amount;
	int price;
public:
	void Init(cars* a, int n) {
		for (int i = 0; i < n; i++) {
			a[i].year = 0;
			a[i].amount = 0;
			a[i].price = 0;
		}
	}

	void Read(cars* a, int n) {
		for (int i = 0; i < n; i++) {
			printf("\nВведите %d запись:\nМарка авто: ", i + 1);
			while (getchar() != '\n');
			fgets(a[i].name, 15, stdin);
			a[i].name[strlen(a[i].name) - 1] = '\0';
			printf("Год выпуска: ");
			scanf_s("%d", &a[i].year);
			printf("Количество: ");
			scanf_s("%d", &a[i].amount);
			printf("Цена: ");
			scanf_s("%d", &a[i].price);
		}
	}

	void Display(cars* a, int n) {
		system("cls");
		printf(" _______________________________________________________\n");
		printf("|\t|\t\t|\t\t|\t|\t|\n");
		printf("|   №   |    Марка авто   |  Год выпуска  |Кол-во |  Цена |\n");
		printf("|_______|_______________|_______________|_______|_______|\n");
		for (int i = 0; i < n; i++) {
			printf("|%d\t", i + 1);
			if (strlen(a[i].name) < 7)
				printf("|%s\t\t", a[i].name);
			else
				printf("|%s\t", a[i].name);
			printf("|%d\t\t", a[i].year);
			printf("|%d\t", a[i].amount);
			printf("|%d\t|\n", a[i].price);
		}
		printf("|_______|_______________|_______________|_______|_______|\n");
	}

	int Add(int a, int b) {
		return a + b;
	}

	void Sort(cars* a, int n) {
		cars d;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (strcmp(a[i].name, a[j].name) > 0) {
					d = a[i];
					a[i] = a[j];
					a[j] = d;
				}
			}
		}
	}


	void Sum(cars* a, int n) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum = Add(sum, a[i].amount);
		}
		printf("Количество всех автомобилей в ангаре: %d\n", sum);
		system("pause");
	}

	void Cars_Free(cars* a) { delete[] a; }
};

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n, flag = 0, i;
	printf("Количество записей: ");
	scanf_s("%d", &n);
	cars* a = new cars[n];
	a->Init(a, n);
	a->Read(a, n);
	do {
		a->Display(a, n);
		printf("\n\nНажмите 1 чтобы отсортировать таблицу по названию марки автомобилей.\n");
		printf("Нажмите 2 чтобы узнать количество всех имеющихся автомобилей.\n");
		printf("Для выхода нажмите 0.\n");
		scanf_s("%d", &i);
		switch (i) {
		case 1:
			a->Sort(a, n);
			break;
		case 2:
			a->Sum(a, n);
			break;

		case 0:
			flag = 1;
			break;

		default:
			break;
		}
	} while (flag == 0);
	a->Cars_Free(a);
	return 0;
}