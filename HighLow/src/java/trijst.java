import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int a, b, c;
    a = sc.nextInt();
    b = sc.nextInt();
    c = sc.nextInt();
    sc.close();

    if (a + b <= c || b + c <= a || a + c <= b) {
        System.out.println("Trijsturis neeksiste");
    }
    else if (a == b && b == c) {
        System.out.println("Trijsturis eksiste un tas ir:");
        System.out.println("equilateral triangle");
    }
    else if (a == b || b == c || a == c) {
        System.out.println("Trijsturis eksiste un tas ir:");
        System.out.println("Isosceles");
    }
    else if (a*a + b*b == c*c || a*a + c*c == b*b ||
    b*b + c*c == a*a) {
        System.out.println("Trujsturis eksiste un tas ir:");
        System.out.println("Right-angled");
}
else {
    System.out.println("trijsturis ekstiste un tas ir:");
    System.out.println("scalene");
}

  }

  }

