import java.util.Scanner;
public class Main1 {
    Scanner sc = new Scanner(System.in);

    static void readNumber(int[] numbers, int index) {
        if (index == numbers.length) {
            return;
        }

        numbers[index] = sc.nextint();
        readNumbers(numbers, index + 1);
    }
    static void main(String[] args) {
        int[] numbers = new int[count];


    }
}
