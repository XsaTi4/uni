import java.util.Scanner;

public class b2 {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double tC, tF;
        System.out.print("tC=");
        tC = sc.nextDouble();
        tF = 9 * tC / 5 + 32;
        System.out.printf("tF=%.2f", tF);
    }
}



