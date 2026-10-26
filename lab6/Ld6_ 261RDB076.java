import java.util.Scanner;

public class Main {
      public static void main(String[] args) {


        System.out.println("Nikola Šafare 10grupa 261RDB069");
        
        Scanner sc = new Scanner(System.in);
        System.out.print("Ievadiet uzdevuma numuru (1 vai 2): ");
        
        if (!sc.hasNextInt()) {
            System.out.println("Kļūda: ievadiet veselu skaitlii (1 vai 2)!");
            return;
        }
    
        int a = sc.nextInt();
        
        if (a != 1 && a != 2) {
            System.out.println("Kļūda: Ievadīts nederīgs uzdevuma numurs! Jābūt 1 vai 2.");
            return;
        }
        
        int[][] M = new int[10][10]; //izveidoju masivu 10x10
        
        if (a == 1) {
            
            int sk = 1; //skaitlis ir sk
            for (int i = 0; i < 10; i++) {
                
                int k = 9 - i;  //sakums ir k un tad sākuma un beigu kolonna katrai rindai aprekinasana
                int b = 12 - i; //beigas ir b
                
                for (int j = 0; j < 10; j++) //ieksejam ciklam pabaude
                {
                    if (j >= k && j <= b) {
                        M[i][j] = sk;
                    } else {
                        M[i][j] = 0;
                    }
                }
            }
        } else {
            // B varianta dala
            for (int i = 0; i < 10; i++) {
                int k = 9 - i;
                int sk = 1;
                for (int j = 0; j < 10; j++) {
                    if (j >= k) {
                        M[i][j] = sk++;
                    } else {
                        M[i][j] = 0;
                    }
                }
            }
        }
        
        //  Masīva izvadīšana ekrānā tabulas veidā (atdalot ar \t)
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                System.out.print(M[i][j] + "\t");
            }
            System.out.println(); // Jauna rinda pēc katras rindas 
        }
        
        sc.close();
    }
}