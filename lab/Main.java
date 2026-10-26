//111RDB111 Jānis Programmētājs

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Ruslans Popakuls");
		System.out.println("0. variants");
				
		double x, y;

		System.out.print("x=");
		x = sc.nextDouble();
		
		System.out.print("y=");
		y = sc.nextDouble();

		boolean Triangle = x >= 1 && y >= 4 && x + y <= 8;

		boolean Cirkle = (x-5)*(x-5)+(y-3)*(y-3) <= 4;

		boolean square = x >= 4.5 && x <= 5.5 && y >= 2.5 && y <= 3.5;

		boolean grey = Triangle || (Cirkle && !square);

		if (grey){
			System.out.println("Result: Grey");
			
		}
		else {
			System.out.println("Result: White");
		}
		
		sc.close();
	}

}
