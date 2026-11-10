import java.util.Scanner;

public class main{
    static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Ruslans Popakuls 261RDB076");
        System.out.println("input String: ");
        String input = sc.nextLine();
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < input.length(); i++){
            char symbol = input.charAt(i);
            

            if (symbol >= 'A' && symbol <= 'Z'){
                int position = symbol - 'A' + 1;
                result.append(String.format("%02d", position));
            }
            else if (symbol >= 'a' && symbol <= 'z') {
                int position = symbol - 'a' + 1;
                result.append(String.format("%02d", position));
            }
            else {
                result.append(symbol);
            }
        }
        System.out.println("result:\n" + result);
    }

}