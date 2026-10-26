import java.util.Scanner;

public class lab {
    public static void main(String[] args) {
        double a;
        Scanner sc = new Scanner(System.in);
        System.out.println("Ievadiet paterejumu liters per 100 kilometers");
        a = sc.nextDouble();
        sc.close();
        System.out.println("Liters Per 100 kilometers: " + a);
        a = (((100/a) * 3.8) / 1.6 );
        System.out.printf("\nMiles per gallon:d= %.2f" , a);


    }
}

//100/ liters per 100 kilometers | kilometer per liter * 3.8 | kilometer per galon / 1.6 = miles per galon.