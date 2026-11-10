import java.util.Scanner;
import java.lang.reflect.Array;
import java.util.ArrayList;

public class main {

    private static void printNumbers(ArrayList<Integer> numbers) {
        for (int i = 0; i < numbers.size(); i++) {
            if (i > 0) {
                System.out.print(" ");
            }
            System.out.print(numbers.get(i));
        }
        System.out.println();
    }
    public static void main(String[] args) {
        System.out.println("Ruslans Popakuls 10. gruppa 261RDB076");
        ArrayList<Integer> numbers = new ArrayList<>();
        Scanner sc = new Scanner(System.in);
        System.out.println("input number: ");
        while (true) {
            int number = sc.nextInt();
            if (number == 0) {
                break;
            }
            numbers.add(number);
        }

        System.out.println("Your input:");
        printNumbers(numbers);

        int position = 0;
        for (int i = 0; i < numbers.size(); i++) {
            if (numbers.get(i) % 2 == 0) {
                int number = numbers.remove(i);
                numbers.add(position, number);
                position++;
            }
        }

        System.out.println("Result:");
        printNumbers(numbers);
        sc.close();

    }

}
