#include <iostream>
using namespace std;

bool isLeapYear(int year){
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
        return true;
    }
    else {
        return false;
    }
    }



int main() {
    int day, month, year;
    cin >> year;
    cin >> month;
    cin >> day;

    if (year < 1900 || year > 2100) {
        cout << "Input-output error!" << endl;
        return 1;
    }

    if (month < 1 || month > 12) {
        cout << "Input-output error!" << endl;
        return 1;
    }

    if (day < 1 || day >31 ) {
        cout << "Input-output error!" << endl;
        return 1;
    }
    int totaldays = 0;
    totaldays = (year - 1900) * 365 + (year - 1900) / 4;
    if (isLeapYear(year) && month <= 2) {
        totaldays --;
    }
    for (int i = 1; i < month; i++)
        switch (i) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                totaldays += 31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                totaldays += 30;
                break;
            case 2:
                totaldays += 28;
                break;
        }

        totaldays += day;

        int dayOfWeek;
        switch(totaldays % 7) {
            case 0:
                dayOfWeek = 0;
                cout << "Sunday" << endl;
                break;
            case 1:
                dayOfWeek = 1;
                cout << "Monday" << endl;
                break;
            case 2:
                dayOfWeek = 2;
                cout << "Tuesday" << endl;
                break;
            case 3:
                dayOfWeek = 3;
                cout << "Wednesday" << endl;
                break;
            case 4:
                dayOfWeek = 4;
                cout << "Thursday" << endl;
                break;
            case 5:
                dayOfWeek = 5;
                cout << "Friday" << endl;
                break;
            case 6:
                dayOfWeek = 6;  
                cout << "Saturday" << endl;
                break;
        }
        

        
}