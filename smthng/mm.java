package uni.smthng;

public class mm {
    public static void main(String[] args) {
        int s, x, a;
        x = 1; // Example value for x
        s = 1/x;
        a = 1/x;
        for (int i = 2; i <= 10; i++) {
            a = a / x;
            s = s+a;
            System.out.println(s);
            System.out.println(a);

        }

    }
}
