import java.util.Scanner;

class main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.print("x=");
    double x = sc.nextDouble();
    sc.close();
    if (x < -2 || x > -1) {
      System.out.println("error");
      return;
    }
    double y = (1 + x) * (1 + x);
    double s = -y;  
    double a = -y;  
    int i = 1;    

    while (Math.abs(a) > 0.001) {
      a = -a * y * i / (i + 1);  
      s = s + a;  
      i = i + 1;  
    }
    System.out.printf("%.4f%n", Math.log(1.0 / (2 + 2 * x + x * x)));
    System.out.printf("%.4f", s);
  }
}
