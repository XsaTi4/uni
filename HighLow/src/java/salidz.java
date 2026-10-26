import java.util.Scanner;
public class salidz {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double a,b,c;
        System.out.print("a=");
        a = sc.nextDouble();
        System.out.print("b=");
        b = sc.nextDouble();
        System.out.print("c=");
        c = sc.nextDouble();
        if (a >= b && a >= c) {
            System.out.printf("a=%.2f is the largest", a);

        }
        else if (b >= a && b >= c) {
            System.out.printf("b=%.2f is largest", b);
        }
        else {
            System.out.printf("c=%.2f is largest", c);
        }
    }
}
