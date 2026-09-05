#include <iostream>
using namespace std;

int main() {
     int option;
    do {
                
        cout << "Choose the option:\n1 - calculate Celsius to Fahrenheit\n2 - calculate Fahrenheit to Celsius \n3 - exit\nType here:";
        cin >> option;
        if (option == 1) {
            double c;
            double temperature;
            cout << "Type the temperature in Celsius:";
            cin >> c;
            temperature = (9 * c / 5 + 32);
            cout << "The temperature in Fahrenheit is: " << temperature << "\n\n";
        }
        else if (option == 2) {
            double f;
            double temperature;
            cout << "Type the temperature in Fahrenheit:";
            cin >> f;
            temperature = (f-32) * 5 / 9;
            cout << "The temperature in Celsius is: " << temperature << "\n\n";
        } 
        
        
        
    }
    while (option != 3);
return 0;
}




//°C = (°F - 32) × 5/9
//9 * tC / 5 + 32;
