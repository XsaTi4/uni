import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int n = 0;
        int[] a = new int[n];
        int[] b = new int[n];
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of elements: ");
        n = sc.nextInt();
        a = new int[n];
        System.out.println("Enter the elements of the first array:");
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        System.out.println("Enter the number elements of the second array:");
        n = sc.nextInt();
        b = new int[n];
        System.out.println("Enter the elements of the second array:");
        for (int i = 0; i < n; i++) {
            b[i] = sc.nextInt();
        }
        int n1 = a.length + b.length;
        int[] c = new int[n1];
        for (int i = 0; i < a.length; i++) {
            if (a[i] < a[i + 1]) {
                c[i] = a[i];
            } else {
                c[i] = a[i + 1];
            }
        }
        for (int i = 0; i < b.length; i++) {
            if (b[i] < b[i + 1]) {
                c[i + a.length] = b[i];
            } else {
                c[i + a.length] = b[i + 1];
            }

        }
        System.out.println("The merged array is:");
        for (int i = 0; i < c.length; i++) {
            System.out.print(c[i] + " ");
        }

    }
}