//111RDB111 Jānis Programmētājs

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		System.out.println("261RDB076 Ruslans Popakuls");
		System.out.println("29. variants");
				
		double x, y;
		
		System.out.print("x=");
		x = sc.nextDouble();
		
		System.out.print("y=");
		y = sc.nextDouble();
		
		System.out.println("result:");

		boolean Triangle = x < 5 && y < 6 && y > -1 * x + 7;
		boolean Cirkle = Math.pow(x - 7, 2) + Math.pow(y - 4, 2) < 4;
		boolean Square = x >= 6 && x <= 7 && y >= 3 && y <= 4;
		
		if ((Triangle || Cirkle) && !Square) {
			System.out.print("grey");
		}
		else {
			System.out.print("white");
		}
		
		sc.close();
}
	}



//triangle
//2 = 5*a + b
//4 = 3 * a + b
//b= -5a + 2
//b = -3a +4
//-5a + 2 = -3a +4 
//-5a + 3 a = 4 - 2
//-2a = 2
//a = -1
// b = -3 * (-1) + 4
//b = 3 + 4
//b = 7
//y = -1x + 7 

//cirkle centre (7;4)
//formula (x-7)^^2 + (y-4)^^2 = 4


