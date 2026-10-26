// 000RDB000 Jānis Programmētājs

// Programma ievada veselo skaitļu secību un izvada skaitli 1,
// ja ievadītie skaitļi ir sakārtoti augošā secībā
// un vērtību 2, ja skaitļi nav sakārtoti.

import java.util.Scanner;

public class MainArr {
	
	static Scanner sc; 
	public static int[] a;
	
	public static void inputArr(int i) {
		if (i < a.length) {
			a[i] = sc.nextInt();
			inputArr(i+1);
		}
	}
	
	public static boolean checkNum(int i) {
		if (i < a.length-1) {
			if (a[i] <= a[i+1])
				return checkNum(i+1);
			else 
				return false;
		}
		return true;
	}
	
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		
		System.out.println("000RDB000 Jānis Programmētājs");
		
		int count;
		System.out.print("count:");
		count = sc.nextInt();
		a = new int[count];
		
		System.out.println("numbers:");
		inputArr(0); 
		
		boolean result = checkNum(0);
		
		System.out.print("result:");
		if (result)
			System.out.println(1);
		else
			System.out.println(2);
		
		sc.close();

	}

}
