import java.util.Scanner;

public class pisitive {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double a, b, c;
        a = sc.nextDouble();      
        b = sc.nextDouble();   
        c = sc.nextDouble();     
        double s;
        if (a > 0) {
            s = a;
            if (a < 0) {
                s = 0;
            }
        }
        else if (b > 0) {
            s = s + b;

        }
        else if (c > 0) {
            s = s + c;
        }

        System.out.println("s");
    }
}