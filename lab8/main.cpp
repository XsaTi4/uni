#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "input string:" << '\n';

    string input;
    getline(cin, input);

    cout << "result:" << '\n';

    for (char symbol : input) {
        if (symbol >= 'A' && symbol <= 'Z') {
            int position = symbol - 'A' + 1;
            cout << setw(2) << setfill('0') << position;
        } else if (symbol >= 'a' && symbol <= 'z') {
            int position = symbol - 'a' + 1;
            cout << setw(2) << setfill('0') << position;
        } else {
            cout << symbol;
        }
    }

    cout << '\n';
    return 0;
}