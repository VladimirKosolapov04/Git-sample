package Project_Java;
import java.util.Scanner;

public class auto {
	String car_brand;
	int year_of_release;
	int number_of_cars;
	int price_of_one_car;
	
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
	
	public void Init(int n) {
		for(int i = 0; i < n; i++) {
			year_of_release = 0;
			number_of_cars = 0;
			price_of_one_car = 0;
		}
	}
	
	public void Read(int i) {
		Scanner ptr = new Scanner(System.in);
		System.out.printf("¬ведите %d запись.", i + 1);
		System.out.printf("\n¬ведите марку автомобил€ - ");
		car_brand = ptr.nextLine();
		System.out.printf("¬ведите год выпуска автомобил€ - ");
		year_of_release = ptr.nextInt();
		System.out.printf("¬ведите количество автомобилей в ангаре - ");
		number_of_cars = ptr.nextInt();
		System.out.printf("¬ведите стоимость одного автомобил€ данной марки (в $) - ");
		price_of_one_car = ptr.nextInt();
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
		System.out.printf("%d|\n", price_of_one_car);
	}
}