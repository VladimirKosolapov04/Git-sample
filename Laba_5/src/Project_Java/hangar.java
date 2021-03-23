package Project_Java;
import java.util.ArrayList;
import java.util.Scanner;

public class hangar {
	String model;
	int n;
	ArrayList<auto> ptr1= new ArrayList<auto>();
	
	public String Get_model() {
		return this.model;
	}
	
	public int Get_n() {
		return this.n;
	}
	
	public ArrayList<auto> Get_ptr1(){
		return this.ptr1;
	}
	
	public void Init_hangar(ArrayList<hangar> ptr2, int k) {
		for (int i = 0; i < k; i++) {
			ptr2.get(i).n = 0;
		}
	}
	
	public void Read_hangar(int i) {
		Scanner ptr = new Scanner(System.in);
		System.out.printf("\nВведите тип %d кузова машины: ", i + 1);
		model = ptr.nextLine();
		System.out.printf("Количество машин с типом кузова (%s) : " , model);
		n = ptr.nextInt();
		for (int j = 0; j < n; j++) {
			auto d = new auto();
			d.Read(j);
			ptr1.add(d);
		}
	}
	
	public void Display_hangar(int i) {
		System.out.printf("|   %d   |", i + 1);
		int prob_11 = 16 - model.length();
		while (prob_11 != 0) {
			System.out.printf(" ");
			prob_11--;
		}
		System.out.printf("%s|", model);
		int j, digit_11 = n;
		for (j = 1; digit_11 > 0; j++) {
			digit_11 /= 10;
		}
		int prob_21 = 9 - j;
		while (prob_21 != 0) {
			System.out.printf(" ");
			prob_21--;
		}
		System.out.printf("%d|\n", n);
	}

	public void Sorting() {
		auto plr;
		for (int i = 0; i < n - 1; i++) 
			for (int j = i + 1; j < n; j++) 
				if (ptr1.get(i).car_brand.compareTo(ptr1.get(j).car_brand) > 0) {
					plr = ptr1.get(i);
					ptr1.set(i, ptr1.get(j));
					ptr1.set(j, plr);
				}
	}
	
	public void Sum() {
		int s = 0;
		Scanner ptr = new Scanner(System.in);
		for (int i = 0; i < n; i++)
			s = Add(s, ptr1.get(i).number_of_cars);
		System.out.printf("Количество всех автомобилей в ангаре: %d\nДля продолжения нажмите Enter...\n", s);
		ptr.nextLine();
		ptr.nextLine();
	}
	
	public int Add(int a, int b) {
		return a + b;
	}
}
