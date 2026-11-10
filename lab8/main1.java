import java.util.Scanner;

public class main1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        printStudentInfo();
        System.out.println("input string:");
        String text = scanner.nextLine();

        String result = convertText(text);
        int letterCount = countLetters(text);

        System.out.println("result:");
        System.out.println(result);
        System.out.println("Replaced letters: " + letterCount);

        scanner.close();
    }

    static void printStudentInfo() {
        // Замени эти строки своими данными.
        System.out.println("Studenta apliecibas numurs: XXXXX");
        System.out.println("Vards Uzvards");
    }

    static boolean isLatinLetter(char symbol) {
        if (symbol >= 'A' && symbol <= 'Z') {
            return true;
        } else if (symbol >= 'a' && symbol <= 'z') {
            return true;
        } else {
            return false;
        }
    }

    static int getLetterNumber(char symbol) {
        if (symbol == 'A' || symbol == 'a') {
            return 1;
        } else if (symbol == 'B' || symbol == 'b') {
            return 2;
        } else if (symbol == 'C' || symbol == 'c') {
            return 3;
        } else if (symbol == 'D' || symbol == 'd') {
            return 4;
        } else if (symbol == 'E' || symbol == 'e') {
            return 5;
        } else if (symbol == 'F' || symbol == 'f') {
            return 6;
        } else if (symbol == 'G' || symbol == 'g') {
            return 7;
        } else if (symbol == 'H' || symbol == 'h') {
            return 8;
        } else if (symbol == 'I' || symbol == 'i') {
            return 9;
        } else if (symbol == 'J' || symbol == 'j') {
            return 10;
        } else if (symbol == 'K' || symbol == 'k') {
            return 11;
        } else if (symbol == 'L' || symbol == 'l') {
            return 12;
        } else if (symbol == 'M' || symbol == 'm') {
            return 13;
        } else if (symbol == 'N' || symbol == 'n') {
            return 14;
        } else if (symbol == 'O' || symbol == 'o') {
            return 15;
        } else if (symbol == 'P' || symbol == 'p') {
            return 16;
        } else if (symbol == 'Q' || symbol == 'q') {
            return 17;
        } else if (symbol == 'R' || symbol == 'r') {
            return 18;
        } else if (symbol == 'S' || symbol == 's') {
            return 19;
        } else if (symbol == 'T' || symbol == 't') {
            return 20;
        } else if (symbol == 'U' || symbol == 'u') {
            return 21;
        } else if (symbol == 'V' || symbol == 'v') {
            return 22;
        } else if (symbol == 'W' || symbol == 'w') {
            return 23;
        } else if (symbol == 'X' || symbol == 'x') {
            return 24;
        } else if (symbol == 'Y' || symbol == 'y') {
            return 25;
        } else if (symbol == 'Z' || symbol == 'z') {
            return 26;
        } else {
            return 0;
        }
    }

    static String convertText(String text) {
        return convertFrom(text, 0);
    }

    static String convertFrom(String text, int index) {
        if (index >= text.length()) {
            return "";
        } else {
            char symbol = text.charAt(index);
            int number = getLetterNumber(symbol);
            String replacement;

            if (number == 0) {
                replacement = "" + symbol;
            } else if (number < 10) {
                replacement = "0" + number;
            } else {
                replacement = "" + number;
            }

            return replacement + convertFrom(text, index + 1);
        }
    }

    static int countLetters(String text) {
        return countFrom(text, 0);
    }

    // При достижении конца строки рекурсия останавливается.
    static int countFrom(String text, int index) {
        if (index >= text.length()) {
            return 0;
        } else if (isLatinLetter(text.charAt(index))) {
            return 1 + countFrom(text, index + 1);
        } else {
            return countFrom(text, index + 1);
        }
    }
}
