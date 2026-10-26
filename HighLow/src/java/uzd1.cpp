#include <iostream>
using namespace std;

int main() {
    int sum = 0;

    cout << "Ievadiet 10 skaitlus:\n";

    for (int i = 1; i <= 10; i++) {
        int number;
        cin >> number;

        if (number > 0) {
            sum ++;
        }
    }

    cout << "Pozitivo skaitlu summa: " << sum << '\n';

    return 0;
}