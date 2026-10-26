import java.util.Random;
import java.util.Scanner;

public class Main {
    private static final int ARRAY_SIZE = 30;
    private static final int ELEMENTS_PER_LINE = 10;

    public static void main(String[] args) {
        int[] A = new int[ARRAY_SIZE];
        Scanner sc = new Scanner(System.in);

        System.out.println("18. variants");
        System.out.println("261RDB076 Ruslans Popakuls");
        System.out.print("K=");
        int K = sc.nextInt();
        sc.close();

        if (K <= 0) {
            fillRandom(A, new Random());
        } else {
            fillSequence(A, K);
        }

        printArray(A);
        moveZerosToEnd(A);
        printArray(A);
    }

    static void fillRandom(int[] array, Random random) {
        for (int i = 0; i < array.length; i++) {
            array[i] = random.nextInt(11);
        }
    }

    static void fillSequence(int[] array, int K) {
        int value = 0;

        for (int i = 0; i < array.length; i++) {
            array[i] = value;
            if (value == K) {
                value = 0;
            }
            else {
                value++;
            }
        }
    }

    static void moveZerosToEnd(int[] array) {
        int nextPosition = 0;

        for (int value : array) {
            if (value != 0) {
                array[nextPosition] = value;
                nextPosition++;
            }
        }

        while (nextPosition < array.length) {
            array[nextPosition] = 0;
            nextPosition++; 
        }
    }

    static void printArray(int[] array) {
        System.out.println("A:");

        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + "\t");

            if ((i + 1) % ELEMENTS_PER_LINE == 0) {
                System.out.println();
            }
        }
    }
}
