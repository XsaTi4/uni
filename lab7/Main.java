import java.util.Scanner;

public class Main {
    static Scanner scanner = new Scanner(System.in);

    static void readNumbers(int[] numbers, int index) {
        if (index == numbers.length) {
            return;
        }

        numbers[index] = scanner.nextInt();
        readNumbers(numbers, index + 1);
    }

    static int findMax(int[] numbers, int index) {
        if (index == numbers.length - 1) {
            return numbers[index];
        }

        int maxFromRest = findMax(numbers, index + 1);
        return Math.max(numbers[index], maxFromRest);
    }

    static int countMax(int[] numbers, int index, int max) {
        if (index == numbers.length) {
            return 0;
        }

        int current;

		if (numbers[index] == max) {
			current = 1;

		}
		else {
			current = 0;
		}
        return current + countMax(numbers, index + 1, max);
    }

    public static void main(String[] args) {
        System.out.println("261RDB076");
        System.out.println("Ruslans Popakuls");

        System.out.println("count:");
        int count = scanner.nextInt();

        int[] numbers = new int[count];

        System.out.println("numbers:");
        readNumbers(numbers, 0);

        int max = findMax(numbers, 0);
        int result = countMax(numbers, 0, max);

        System.out.println("result:");
        System.out.println(result);
    }
}