#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main() {
    vector<int> a;

    for (int i; i <= 10; i++) {
        a.push_back(rand() % 10 + 1);
    }

    for (int number : a){
        cout << number << "" << endl;
    }
    cout << "amount of elements: " <<  a.size() << '\n' << endl;
    cout << a.front() << '\n' << endl;
    cout << a.back() << '\n' << endl;
    a.insert(a.begin() + 4, 999);
    for (int number : a){
        cout << number << "" << endl;
    }

    cout << '\n' << a.size() << '\n' << endl;


    return 0;


}