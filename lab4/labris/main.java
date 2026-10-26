import java.util.Scanner;

class main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.print("x=");
    double x = sc.nextDouble();
    sc.close();
    if (x < -3 || x > 3) { 
      System.out.println("error");
      return;
    }

    double s = x;  
    double a = x;  
    int i = 1;     

    while (Math.abs(a) > 0.001) {
      a = -a * 2 * x / i;  
      s = s + a;  
      i += 1; 
    }

    double result = x * Math.exp(-2 * x);
    System.out.printf("%.4f%n", result); // TODO: izmainīt funkcijas formulu
    System.out.printf("%.4f", s);
  }
}