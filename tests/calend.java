import java.util.Scanner;

public class calend {
    public static void main(String[] args) {
        int day, month, year;

        Scanner sc = new Scanner(System.in);
        
        day = sc.nextInt();
        month = sc.nextInt();
        year = sc.nextInt();
        
        sc.close();

        int totalDays = 0;

        totalDays = (year - 1900) * 365 + (year - 1900) / 4;

        if (isLeapYear(year) && month <= 2) {
            totalDays--;
            }
        
            for (int m = 1; m < month; m++) {
                totalDays += getDaysInMonth(m);
            }

        totalDays += day;

        if (month < 1 || month > 12) {
            System.out.println("input-output error");
            return;
        }

        if (day < 1 || day > 31) {
            System.out.println("input-output error");
            return;
        }

         if (isLeapYear(year) && day > 29) {
            System.out.println("input-output error");
            if (!isLeapYear(year) && day > 28) {
                System.out.println("input-output error");
            }
        }

        int dayOfWeek;
        switch (totalDays % 7) {
            case 0:
                dayOfWeek = 0;
                System.out.println("sunday");
                break;
            case 1:
                dayOfWeek = 1;
                System.out.println("monday");
                break;
            case 2:
                dayOfWeek = 2;
                System.out.println("tuesday");
                break;
            case 3:
                dayOfWeek = 3;
                System.out.println("wednesday");
                break;
            case 4:
                dayOfWeek = 4;
                System.out.println("thursday");
                break;
            case 5:
                dayOfWeek = 5;
                System.out.println("friday");
                break;
            case 6:
                dayOfWeek = 6;
                System.out.println("saturday");
                break;
            default:
                System.out.println("input-output error");
                return;
        }
        }

        public static boolean isLeapYear(int year) {
            return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        }

        public static int getDaysInMonth(int month) {
            switch (month) {
                case 1: 
                case 3: 
                case 5: 
                case 7: 
                case 8: 
                case 10: 
                case 12: 
                    return 31;
                case 4: 
                case 6: 
                case 9: 
                case 11: 
                    return 30;
                case 2: 
                    return 28;
                default:
                    return 1; 
            }
        
  
    }

}



// (year - 1900) * 365 + (year - 1900) / 4 +  = totalDays;
//totalDays % 7 = dayOfWeek;
// 