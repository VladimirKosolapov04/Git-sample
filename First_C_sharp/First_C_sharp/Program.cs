using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace First_C_sharp
{
	public class Auto
	{
		String car_brand;
		int year_of_release;
		int number_of_cars;
		int price_of_one_car;

		public String Get_car_brand()
		{
			return this.car_brand;
		}

		public int Get_year_of_release()
		{
			return this.year_of_release;
		}

		public int Get_number_of_cars()
		{
			return this.number_of_cars;
		}

		public int Get_price_of_one_car()
		{
			return this.price_of_one_car;
		}

		public void Init(int n)
		{
			for (int i = 0; i < n; i++)
			{
				year_of_release = 0;
				number_of_cars = 0;
				price_of_one_car = 0;
			}
		}

		public void Read(int i)
		{
			Console.Write($"Введите {i + 1} запись.");
			Console.Write("\nВведите марку автомобиля - ");
			car_brand = Console.ReadLine();
			Console.Write("Введите год выпуска автомобиля - ");
			year_of_release = Convert.ToInt32(Console.ReadLine());
			Console.Write("Введите количество автомобилей в ангаре - ");
			number_of_cars = Convert.ToInt32(Console.ReadLine());
			Console.Write("Введите стоимость одного автомобиля данной марки (в $) - ");
			price_of_one_car = Convert.ToInt32(Console.ReadLine());
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
			Console.Write($"{price_of_one_car}|\n");
		}

	}

	public class Hangar
	{
		String model;
		int n;
		List<Auto> ptr;

		public String Get_model()
		{
			return this.model;
		}

		public int Get_n()
		{
			return this.n;
		}

		public List<Auto> Get_ptr1()
		{
			return this.ptr;
		}

		public void Init_hangar()
		{
			n = 0;
		}

		public void Read_hangar(int i)
		{
			Console.Write($"\nВведите тип {i + 1} кузова машины: ");
			model = Console.ReadLine();
			Console.Write($"Количество машин с типом кузова ({model}) : ");
			n = Convert.ToInt32(Console.ReadLine());
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
					if (String.Compare(ptr[i].Get_car_brand(), ptr[j].Get_car_brand()) > 0)
					{
						Auto plr = new Auto();
						plr = ptr[i];
						ptr[i] = ptr[j];
						ptr[j] = plr;
					}

		}

		public void Sum()
		{
			int s = 0;
			for (int i = 0; i < n; i++)
				s = Add(s, ptr[i].Get_number_of_cars());
			Console.Write($"Количество всех автомобилей в ангаре: {s}\nДля продолжения нажмите Enter...\n");
			Console.ReadKey();
		}

		public int Add(int a, int b)
		{
			return a + b;
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
			int k, i, i1, f = 0, model_kuzov = 0, f1 = 0;
			Console.Write("Введите количество моделей кузова машин в ангаре - ");
			k = Convert.ToInt32(Console.ReadLine());
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
				Console.Write("2 - узнать количество автомобиля одного типа;\n");
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
							List<Auto> z = ptr2[model_kuzov].Get_ptr1();
							Console.Write($"\n\n{ptr2[model_kuzov].Get_model()}\n");
							Console.Write(" ___________________________________________________________\n");
							Console.Write("|       |                 |               |        |        |\n");
							Console.Write("|   №   |    Марка авто   |  Год выпуска  | Кол-во |  Цена  |\n");
							Console.Write("|_______|_________________|_______________|________|________|\n");
							for (int m = 0; m < z.Count; m++)
								z[m].Display(m);
							Console.Write(" ____________________________________________________________\n");
							Console.Write("\n1 - сортировка таблицы по названию марки машины;\n");
							Console.Write("2 - вернуться к списку типов.\n");
							Console.Write("Для выхода нажмите 0.\n");
							i1 = Convert.ToInt32(Console.ReadLine());
							switch (i1)
							{
								case 1:
									ptr2[model_kuzov].Sorting();
									break;

								case 2:
									f = 1;
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
						int count;
						Console.Write("Введите номер строки, чтобы посчитать количество машин с таким типом кузова - ");
						count = Convert.ToInt32(Console.ReadLine());
						count--;
						ptr2[count].Sum();
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
