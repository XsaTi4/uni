#include <iostream>
using namespace std;

void Solution(double a, double b) {
    double s = a * b;
    double p = (a + b) * 2;
    cout << "area is " << s << "\nperimeter is " << p;
}

int main() {
    double a, b;
    do {
        cout << "Type one side:";
        cin >> a; 
        cout << "Type another side:";
        cin >> b;
            if (a <= 0 || b <= 0) {
                cout << "Error: Values A and B must be positive!\n";
            } 
        }while (a <= 0 || b <= 0);
    Solution(a, b);
    }

