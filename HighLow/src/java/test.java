import java.util.Scanner;

public class test {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double a, b, c, x1, x2, d;
        System.out.print("a=");
        a = sc.nextDouble();
        System.out.print("b=");
        b = sc.nextDouble();
        System.out.print("c=");
        c = sc.nextDouble();
        d = b*b - 4*a*c;
        if (d < 0) {
            System.out.println("no solution");
        }
        else if (d == 0) {
            x1 = -b / (2*a);
            System.out.printf("x1=x2=%f", x1);
        }
        else {
            x1 = (-b + Math.sqrt(d)) / (2*a);
            x2 = (-b - Math.sqrt(d)) / (2*a);
            System.out.printf("x1=%f x2=%f", x1, x2);
        }
}
}
