package Project_Java;
import java.util.Scanner;
import java.util.Random;

public class auto {
	String car_brand;
	int year_of_release;
	int number_of_cars;
	int price_of_one_car;
	int amount_code;
	static int amount = 0;
	
	public String Get_car_brand() {
		return this.car_brand;
	}
	
	public int Get_year_of_release() {
		return this.year_of_release;
	}
	
	public int Get_number_of_cars() {
		return this.number_of_cars;
	}
	
	public int Get_price_of_one_car() {
		return this.price_of_one_car;
	}
	
	public static int Get_amount() {
		return amount;
	}
	
	public auto() {
		amount_code = 0;
		car_brand = "Нет названия";
		year_of_release = 0;
		number_of_cars = 0;
		price_of_one_car = 0;
	}
	
	public auto(String car) {
		Random rand = new Random();
		amount = rand.nextInt(100) + 100;
		amount_code = amount;
		car_brand = car;
		year_of_release = 0;
		number_of_cars = 0;
		price_of_one_car = 0;
	}
	
	public auto(String car, int year, int number, int price) {
		Random rand = new Random();
		amount = rand.nextInt(100) + 100;
		amount_code = amount;
		car_brand = car;
		year_of_release = year;
		number_of_cars = number;
		price_of_one_car = price;
	}
	
	public void Read(int i) {
		Random rand = new Random();
		amount = rand.nextInt(100) + 100;
		amount_code = amount;
		Scanner ptr = new Scanner(System.in);
		System.out.printf("Введите %d запись.", i + 1);
		System.out.printf("\nВведите марку автомобиля - ");
		car_brand = ptr.nextLine();
		System.out.printf("Введите год выпуска автомобиля - ");
		year_of_release = ptr.nextInt();
		try {
			if (year_of_release < 0)
				throw new Exception ("Количество не может быть < 0. Кол-во типов будет умножено на -1.\n");

		}
		catch (Exception e) {
			System.out.printf(e.getMessage());
			year_of_release *= -1;
		}
		System.out.printf("Введите количество автомобилей в ангаре - ");
		number_of_cars = ptr.nextInt();
		try {
			if (number_of_cars < 0)
				throw new Exception ("Количество не может быть < 0. Кол-во типов будет умножено на -1.\n");

		}
		catch (Exception e) {
			System.out.printf(e.getMessage());
			number_of_cars *= -1;
		}
		System.out.printf("Введите стоимость одного автомобиля данной марки (в $) - ");
		price_of_one_car = ptr.nextInt();
		try {
			if (price_of_one_car < 0)
				throw new Exception ("Количество не может быть < 0. Кол-во типов будет умножено на -1.\n");

		}
		catch (Exception e) {
			System.out.printf(e.getMessage());
			price_of_one_car *= -1;
		}
	}
	
	public void Display(int i) {
		System.out.printf("|   %d   |", i + 1);
		int prob_1 = 17 - car_brand.length();
		while (prob_1 != 0) {
			System.out.printf(" ");
			prob_1--;
		}
		System.out.printf("%s", car_brand);
		System.out.printf("|           %d|", year_of_release);
		int j, digit_1 = number_of_cars;
		for (j = 1; digit_1 > 0; j++) {
			digit_1 /= 10;
		}
		int prob_2 = 9 - j;
		while (prob_2 != 0) {
			System.out.printf(" ");
			prob_2--;
		}
		System.out.printf("%d|", number_of_cars);
		int digit_2 = price_of_one_car;
		for (j = 1; digit_2 > 0; j++) {
			digit_2 /= 10;
		}
		int prob_3 = 9 - j;
		while (prob_3 != 0) {
			System.out.printf(" ");
			prob_3--;
		}
		System.out.printf("%d|", price_of_one_car);
		System.out.printf("    %d|\n", amount_code);
	}
}