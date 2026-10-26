import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        double x, y;

        Scanner sc = new Scanner(System.in);

        if (!sc.hasNextDouble()) {
            System.out.println("input-output error");
            sc.close();
            return;
        }

        x = sc.nextDouble();

        if (!sc.hasNextDouble()) {
            System.out.println("input-output error");
            sc.close();
            return;
        }

        y = sc.nextDouble();

        sc.close();

        if (y > 8 &&
            (x - 5) * (x - 5) + (y - 8) * (y - 8) < 1) {

            System.out.println("green");
        }

        else if (y >= 7 &&
                 y <= x + 5 &&
                 y <= -x + 15) {

            System.out.println("blue");
        }

        else if (x >= 3 && x <= 7 &&
                 y >= 3 && y <= 7 &&
                 !(x > 4 && x < 6 &&
                   y > 4 && y < 6)) {

            System.out.println("red");
        }

        else {
            System.out.println("white");
        }
    }
}