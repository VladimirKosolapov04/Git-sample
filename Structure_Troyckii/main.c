#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct
{
    char* country;
    char* product;
    int id;
    int volume;
} exporting;

exporting Init(char* country, char* product, int id, int volume)
{
    exporting ex;
    ex.country = country;
    ex.product = product;
    ex.id = id;
    ex.volume = volume;
    return ex;
}

exporting Read()
{
    exporting ex;
    printf("Введите \"Страну Товар ID Объём\": ");
    ex.country = (char *)malloc(20 * sizeof(char));
    ex.product = (char *)malloc(20 * sizeof(char));
    scanf("%s %s %d %d", ex.country, ex.product, &ex.id, &ex.volume);
    return ex;
}

void Display(exporting ex)
{
    printf("%s %s %d %d \n", ex.country, ex.product, ex.id, ex.volume);
}

void Add(exporting ex1, exporting ex2)
{
    printf("(%d + %d) \n", ex1.volume, ex2.volume);
}

void CountryAndProduct(exporting ex)
{
    printf("%s %s \n", ex.country, ex.product);
}

void NumberOfProduct(exporting ex)
{
    printf("ID: %d \n", ex.id);
}

int main()
{
    setlocale(0, "rus");
    exporting name_1 = Init("Russia", "Wood", 3297, 156900);
    exporting name_2 = Read();
    Display(name_1);
    Display(name_2);
    Add(name_1, name_2);
    CountryAndProduct(name_1);
    NumberOfProduct(name_1);

    exporting *p;
    p = (exporting *)malloc(sizeof(exporting));
    *p = Init("Russia_1", "Wood_1", 3297, 156900);
    Display(*p);
    return 0;
}
