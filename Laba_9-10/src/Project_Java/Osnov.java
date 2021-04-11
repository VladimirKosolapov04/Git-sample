package Project_Java;
import java.util.Scanner;
import java.util.ArrayList;

public class Osnov {
	public static void main(String args[]) {
		Scanner p = new Scanner(System.in);
		ArrayList<hangar> ptr2 = new ArrayList<hangar>();
		int k, i, i1, f, model_kuzov = 0, f1 = 0, j;
		System.out.printf("������������ �������������:\n");
		System.out.printf("1) ��� ����������;\n2) � ����� ����������;\n3) � ����������� �����������.\n");
		auto auto0 = new auto();
		auto auto1 = new auto("��������");
		auto auto2 = new auto("��������", 2019, 7, 300000);
		auto0.Display(0);
		auto1.Display(1);
		auto2.Display(2);
		System.out.printf("������������ �������� ������� � ������� ������������ � ����� ����������:\n");
		auto[] massauto = new auto[] {
				new auto("����"),
				new auto("������"),
				new auto("������"),
				new auto("� �������"),
				new auto("������������")
		};
		for (j = 0; j < 5; j++) {
			massauto[j].Display(j);
		}

		System.out.printf("������� ���������� ������� ������ ����� � ������ - ");
		k = p.nextInt();
		try {
			if (k < 0)
				throw new Exception ("���������� �� ����� ���� < 0. ���-�� ����� ����� �������� �� -1.\n");
			if (k == 0)
				throw new Exception ("���������� �� ����� ���� = 0. ���-�� ����� ����� ���������� 1.\n");
			}
			catch (Exception e){
				System.out.printf(e.getMessage());
				if (k < 0) k *= -1;
				else k = 1;
			}
		for (int m = 0; m < k; m++) {
			hangar z = new hangar();
			z.Read_hangar(m);
			ptr2.add(z);
		}
		
		do {
			System.out.printf(" _________________________________\n");
			System.out.printf("|       |                |        |\n");
			System.out.printf("|   �   |   ��� ������   | ���-�� |\n");
			System.out.printf("|_______|________________|________|\n");
			for (int m = 0; m < k; m++)
				ptr2.get(m).Display_hangar(m);
			System.out.printf("|_______|________________|________|\n");
			System.out.printf("\n1 - ������� ������ � ���������� ������ ������ ����������;\n");
			System.out.printf("2 - ������ ���������� ���������� ������ ����;\n");
			System.out.printf("0 - ����� �� ���������.\n");
			i = p.nextInt();
			switch (i) {
			case 1:
				f = 0;
				System.out.printf("������� ����� ���������� ������ ������ - ");
				model_kuzov = p.nextInt();
				model_kuzov--;
				ArrayList<auto> z = ptr2.get(model_kuzov).Get_ptr1();
				do {
					System.out.printf("\n\n%s", ptr2.get(model_kuzov).Get_model());
					System.out.printf(" ___________________________________________________________________\n");
					System.out.printf("|       |                 |               |        |        |       |\n");
					System.out.printf("|   �   |    ����� ����   |  ��� �������  | ���-�� |  ����  |  ���  |\n");
					System.out.printf("|_______|_________________|_______________|________|________|_______|\n");
					for (int m = 0; m < ptr2.get(model_kuzov).Get_n(); m++)
						z.get(m).Display(m);
					System.out.printf(" ___________________________________________________________________\n");
					System.out.printf("\n1 - ���������� ������� �� �������� ����� ������;\n");
					System.out.printf("2 - ��������� � ������ �����.\n");
					System.out.printf("��� ������ ������� 0.\n");
					i1 = p.nextInt();
					switch (i1) {
						case 1:
							ptr2.get(model_kuzov).Sorting();
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
				}while (f == 0);
				break;
				
			case 2:
				int count;
				System.out.printf("������� ����� ������, ����� ��������� ���������� ����� � ����� ����� ������ - ");
				count = p.nextInt();
				count--;
				ptr2.get(count).Sum();
				break;
				
			case 0:
				f1 = 1;
				break;
				
			default:
				break;
		}		
	}while (f1 == 0);
     }	
}