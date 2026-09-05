import java.util.Scanner;

public class a1 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("a=");
        double a = sc.nextDouble();
        System.out.print("b=");
        double b = sc.nextDouble();
        double s = a * b;
        double p = (a + b) * 2;
        
        
        if (a <= 0 || b <= 0) {
            System.out.println("Error: Error: Values ​A and B must be positive!");
        }
        else {
            System.out.printf("s=%.2f p=%.2f", s, p);
        }
    }   
}