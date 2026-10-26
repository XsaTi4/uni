package de0915;

import java.util.Scanner;

public class Ld6_261rdb295 {
    private static final int SIZE = 10;

    public static void main(String[] args) {
        printAuthor();

        int[][] numbers = new int[SIZE][SIZE];

        try (Scanner input = new Scanner(System.in)) {
            System.out.print("Ievadiet uzdevuma numuru (1 - A, 2 - B): ");

            if (!input.hasNextInt()) {
                System.out.println("Kļūda: jāievada vesels skaitlis 1 vai 2.");
                return;
            }

            int task = input.nextInt();

            if (task == 1) {
                fillVariantA(numbers);
            } else if (task == 2) {
                fillVariantB(numbers);
            } else {
                System.out.println("Kļūda: uzdevuma numuram jābūt 1 vai 2.");
                return;
            }

            System.out.println();
            printTable(numbers);
        }
    }

    private static void printAuthor() {
        System.out.println("Artjoms Savanovics");
        System.out.println("11 grupa | 261RDB295");

    }

    private static void fillVariantA(int[][] numbers) {
        int value = 1;

        for (int row = numbers.length - 1; row >= 0; row--) {
            int firstColumn = numbers.length - 1 - row;

            for (int column = firstColumn; column < numbers[row].length && column < firstColumn + 4; column++) {
                numbers[row][column] = value++;
            }
        }
    }

    private static void fillVariantB(int[][] numbers) {
        for (int row = 1; row < numbers.length; row++) {
            for (int column = 0; column < row; column++) {
                numbers[row][column] = numbers.length - row + column;
            }
        }
    }

    private static void printTable(int[][] numbers) {
        for (int[] row : numbers) {
            for (int column = 0; column < row.length; column++) {
                if (column > 0) {
                    System.out.print('\t');
                }
                System.out.print(row[column]);
            }
            System.out.println();
        }
    }
}
