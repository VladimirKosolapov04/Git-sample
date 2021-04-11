using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Try_catch_constructors_C_sharp
{
	public class Auto
	{
		String car_brand;
		public String Car_brand
		{
			get { return car_brand; }
			set { car_brand = value; }
		}
		int year_of_release;
		public int Year_of_release
		{
			get { return year_of_release; }
			set { year_of_release = value; }
		}
		int number_of_cars;
		public int Number_of_cars
		{
			get { return number_of_cars; }
			set { number_of_cars = value; }
		}
		int price_of_one_car;
		public int Price_of_one_car
		{
			get { return price_of_one_car; }
			set { price_of_one_car = value; }
		}
		int amount_code;
		public int Amount_code
		{
			get { return amount_code; }
		}
		static int amount = 0;
		public Auto()
		{
			amount_code = 0;
			car_brand = "Нет названия";
			year_of_release = 0;
			number_of_cars = 0;
			price_of_one_car = 0;
		}
		public Auto(string car)
		{
			Random rnd = new Random();
			Auto.amount = rnd.Next(100, 200);
			amount_code = amount;
			car_brand = car;
			year_of_release = 0;
			number_of_cars = 0;
			price_of_one_car = 0;
		}
		public Auto(string car, int year, int number, int price)
		{
			Random rnd = new Random();
			Auto.amount = rnd.Next(100, 200);
			amount_code = amount;
			car_brand = car;
			year_of_release = year;
			number_of_cars = number;
			price_of_one_car = price;
		}


		public void Read(int i)
		{
			Random rnd = new Random();
			Auto.amount = rnd.Next(100, 200);
			amount_code = amount;
			Console.Write($"Введите {i + 1} запись.");
			Console.Write("\nВведите марку автомобиля - ");
			car_brand = Console.ReadLine();
			try
			{
				Console.Write("Введите год выпуска автомобиля - ");
				year_of_release = Convert.ToInt32(Console.ReadLine());
				if (year_of_release < 0)
					throw new Exception();
			}
			catch (Exception)
            {
				Console.Write("Год не может быть отрицательным\n");
				year_of_release *= -1;
			}
			try
			{
				Console.Write("Введите количество автомобилей в ангаре - ");
				number_of_cars = Convert.ToInt32(Console.ReadLine());
				if (number_of_cars < 0)
					throw new Exception();
			}
			catch (Exception)
            {
				Console.Write("Кол-во не может быть отрицательным\n");
				number_of_cars *= -1;
			}
			try
			{
				Console.Write("Введите стоимость одного автомобиля данной марки (в $) - ");
				price_of_one_car = Convert.ToInt32(Console.ReadLine());
				if (price_of_one_car < 0)
					throw new Exception();
			}
			catch (Exception)
            {
				Console.Write("Цена не может быть отрицательной\n");
				price_of_one_car *= -1;
			}
		}

		public void Display(int i)
		{
			Console.Write($"|   {i + 1}   |");
			int prob_1 = 17 - car_brand.Length;
			while (prob_1 != 0)
			{
				Console.Write(" ");
				prob_1--;
			}
			Console.Write($"{car_brand}");
			Console.Write($"|           {year_of_release}|");
			int j, digit_1 = number_of_cars;
			for (j = 1; digit_1 > 0; j++)
			{
				digit_1 /= 10;
			}
			int prob_2 = 9 - j;
			while (prob_2 != 0)
			{
				Console.Write(" ");
				prob_2--;
			}
			Console.Write($"{number_of_cars}|");
			int digit_2 = price_of_one_car;
			for (j = 1; digit_2 > 0; j++)
			{
				digit_2 /= 10;
			}
			int prob_3 = 9 - j;
			while (prob_3 != 0)
			{
				Console.Write(" ");
				prob_3--;
			}
			Console.Write($"{price_of_one_car}|");
			Console.Write($"    {amount_code}|\n");
		}
		public static Auto operator +(Auto car1, Auto car2)
		{
			return new Auto { price_of_one_car = car1.price_of_one_car + car2.price_of_one_car };
		}
		public static Auto operator ++(Auto car)
		{
			car.price_of_one_car++;
			return car;
		}
	}

	public class Hangar
	{
		String model;
		public String Model
		{
			get { return model; }
			set { model = value; }
		}
		int n;
		public int N
		{
			get { return n; }
			set { n = value; }
		}
		List<Auto> ptr;
		public List<Auto> Ptr
		{
			get { return ptr; }
		}

		public void Init_hangar()
		{
			n = 0;
		}

		public void Read_hangar(int i)
		{
			Console.Write($"\nВведите тип {i + 1} кузова машины: ");
			model = Console.ReadLine();
			try
			{
				Console.Write($"Количество машин с типом кузова ({model}) : ");
				n = Convert.ToInt32(Console.ReadLine());
				if (n < 1)
					throw new Exception();
			}
			catch (Exception)
            {
				if (n < 0)
				{
					Console.Write("Кол-во машин не может быть отрицательным: кол-во будет умножено на -1\n");
					n *= -1;
				}
				else
				{
					Console.Write("Должна быть хотя бы одна машина в категории: кол-ву будет приравнено 1\n");
					n = 1;
				}
			}
			ptr = new List<Auto> { };
			for (int j = 0; j < n; j++)
			{
				Auto d = new Auto();
				d.Read(j);
				ptr.Add(d);
			}
		}

		public void Display_hangar(int i)
		{
			Console.Write($"|   {i + 1}   |");
			int prob_11 = 16 - model.Length;
			while (prob_11 != 0)
			{
				Console.Write(" ");
				prob_11--;
			}
			Console.Write($"{model}|");
			int j, digit_11 = n;
			for (j = 1; digit_11 > 0; j++)
			{
				digit_11 /= 10;
			}
			int prob_21 = 9 - j;
			while (prob_21 != 0)
			{
				Console.Write(" ");
				prob_21--;
			}
			Console.Write($"{n}|\n");
		}

		public void Sorting()
		{
			for (int i = 0; i < n - 1; i++)
				for (int j = i + 1; j < n; j++)
					if (String.Compare(ptr[i].Car_brand, ptr[j].Car_brand) > 0)
					{
						Auto plr = new Auto();
						plr = ptr[i];
						ptr[i] = ptr[j];
						ptr[j] = plr;
					}

		}
		public void Searching_Hangar(int sort_year, out int s)
		{
			s = 0;
			for (int i = 0; i < N; i++)
				if (sort_year < ptr[i].Year_of_release)
				{
					s++;
					Console.Write("|");
					int prob_sear = 16 - Model.Length;
					while (prob_sear != 0)
					{
						Console.Write(" ");
						prob_sear--;
					}
					Console.Write($"{Model}|");
					int prob_sear1 = 17 - ptr[i].Car_brand.Length;
					while (prob_sear1 != 0)
					{
						Console.Write(" ");
						prob_sear1--;
					}
					Console.Write($"{ptr[i].Car_brand}");
					Console.Write($"|           {ptr[i].Year_of_release}|");
					int j, digit_1 = ptr[i].Number_of_cars;
					for (j = 1; digit_1 > 0; j++)
					{
						digit_1 /= 10;
					}
					int prob_2 = 9 - j;
					while (prob_2 != 0)
					{
						Console.Write(" ");
						prob_2--;
					}
					Console.Write($"{ptr[i].Number_of_cars}|");
					int digit_2 = ptr[i].Price_of_one_car;
					for (j = 1; digit_2 > 0; j++)
					{
						digit_2 /= 10;
					}
					int prob_3 = 9 - j;
					while (prob_3 != 0)
					{
						Console.Write(" ");
						prob_3--;
					}
					Console.Write($"{ptr[i].Price_of_one_car}|");
					Console.Write($"    {ptr[i].Amount_code}|\n");
				}
		}
		public void Sum()
		{
			int s = 0;
			for (int i = 0; i < n; i++)
				Add(ref s, ptr[i].Number_of_cars);
			Console.Write($"Количество всех автомобилей в ангаре: {s}\nДля продолжения нажмите Enter...\n");
			Console.ReadKey();
		}

		public void Add(ref int a, int b)
		{
			a += b;
		}

		public void Free_Hangar()
		{
			int a = ptr.Count;
			n = 0;
			model.Remove(0);
			for (int i = a - 1; i >= 0; i--) ptr.RemoveAt(i);
		}
	}
	class Program
	{
		static void Main(string[] args)
		{
			List<Hangar> ptr2 = new List<Hangar> { };
			int k = 0, i, i1, f = 0, model_kuzov, f1 = 0, sort_year, s = 0;
			///*
			Console.WriteLine("Класс объявлен конструктором без параметров\n");
			Auto auto0 = new Auto();
			auto0.Display(0);
			Console.WriteLine("Класс объявлен конструктором с одним параметром\n");
			Auto auto1 = new Auto("Мерседес");
			auto1.Display(0);
			Console.WriteLine("Класс объявлен конструктором с несколькими параметрами\n");
			Auto auto2 = new Auto("Мерседес", 2019, 7, 300000);
			auto2.Display(0);
			//*/
			try
			{
				Console.Write("Введите количество моделей кузова машин в ангаре - ");
				k = Convert.ToInt32(Console.ReadLine());
				if (k < 1)
					throw new Exception();
			}
			catch (Exception)
            {
				if (k < 0)
				{
					Console.Write("Кол-во категорий не может быть отрицательным: кол-во будет умножено на -1\n");
					k *= -1;
				}
				else
				{
					Console.Write("Должен быть хотя одна категория в магазине: кол-во будет приравнено 1\n");
					k = 1;
				}
			}
			for (int m = 0; m < k; m++)
			{
				Hangar z = new Hangar();
				z.Read_hangar(m);
				ptr2.Add(z);
			}
			do
			{
				Console.Write(" _________________________________\n");
				Console.Write("|       |                |        |\n");
				Console.Write("|   №   |   Тип кузова   | Кол-во |\n");
				Console.Write("|_______|________________|________|\n");
				for (int m = 0; m < ptr2.Count; m++)
					ptr2[m].Display_hangar(m);
				Console.Write("|_______|________________|________|\n");
				Console.Write("\n1 - вывести данные о конкретной модели кузова автомобиля;\n");
				Console.Write("2 - вывести данные о машинах новее определенного года;\n");
				Console.Write("0 - выход из программы.\n");
				i = Convert.ToInt32(Console.ReadLine());
				switch (i)
				{
					case 1:
						Console.Write("Введите номер конкретной модели кузова - ");
						model_kuzov = Convert.ToInt32(Console.ReadLine());
						model_kuzov--;
						do
						{
							f = 0;
							List<Auto> z = ptr2[model_kuzov].Ptr;
							Console.Write($"\n\n{ptr2[model_kuzov].Model}\n");
							Console.Write(" ___________________________________________________________________\n");
							Console.Write("|       |                 |               |        |        |       |\n");
							Console.Write("|   №   |    Марка авто   |  Год выпуска  | Кол-во |  Цена  |  Код  |\n");
							Console.Write("|_______|_________________|_______________|________|________|_______|\n");
							for (int m = 0; m < z.Count; m++)
								z[m].Display(m);
							Console.Write(" ___________________________________________________________________\n");
							Console.Write("\n1 - сортировка таблицы по названию марки машины;\n");
							Console.Write("2 - узнать общее количество автомобилей;\n");
							Console.Write("3 - вернуться к списку типов машин;\n");
							Console.Write("4 - рассчитать общую цену двух моделей машин;\n");
							Console.Write("Для выхода нажмите 0.\n");
							i1 = Convert.ToInt32(Console.ReadLine());
							switch (i1)
							{
								case 1:
									ptr2[model_kuzov].Sorting();
									break;
								case 2:
									ptr2[model_kuzov].Sum();
									break;
								case 3:
									f = 1;
									break;
								case 4:
									int p1, p2;
									Console.Write("Введите номер первого автомобиля - ");
									p1 = Convert.ToInt32(Console.ReadLine());
									p1--;
									Console.Write("Введите номер второго автомобиля - ");
									p2 = Convert.ToInt32(Console.ReadLine());
									p2--;
									Auto Car = z[p1] + z[p2];
									Console.WriteLine($"Общая цена моделей: {Car.Price_of_one_car}\nЧтобы продолжить нажмите любую клавишу...");
									Console.ReadKey();
									break;
								case 0:
									f = 1;
									f1 = 1;
									break;
								default:
									break;
							}
						} while (f == 0);
						break;

					case 2:
						Console.Write("Введите год новее которого автомобили вас интересуют - ");
						sort_year = Convert.ToInt32(Console.ReadLine());
						Console.Write(" ____________________________________________________________________________\n");
						Console.Write("|                |                 |               |        |        |       |\n");
						Console.Write("|   Тип кузова   |    Марка авто   |  Год выпуска  | Кол-во |  Цена  |  Код  |\n");
						Console.Write("|________________|_________________|_______________|________|________|_______|\n");
						for (int j = 0; j < k; j++)
						{
							ptr2[j].Searching_Hangar(sort_year, out s);
						}
						Console.Write(" ____________________________________________________________________________\n");
						Console.Write($"Количество всех найденных автомобилей: {s}\n\n");
						s = 0;
						break;

					case 0:
						f1 = 1;
						break;

					default:
						break;
				}
			} while (f1 == 0);
			for (int m1 = k - 1; k >= 0; k--) ptr2[k].Free_Hangar();
		}
	}

}
