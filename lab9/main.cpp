#include <iostream>
#include <vector>

using namespace std;

void printNum(const vector<int>& numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        if (i > 0){
            cout << " ";
        }
        cout << numbers[i];
    }
    cout << '\n';
}

int main() {
    vector<int> numbers;
    cout << "Enter numbers: " << endl;
    int num;
    while(cin >> num && num != 0) {
        numbers.push_back(num); 
    }
    printNum(numbers);

    cout << "result:" << endl;
    int place = 0;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] % 2 == 0) {
            int number = numbers[i];

            numbers.erase(numbers.begin() + i);
            numbers.insert(numbers.begin() + place, number);
        }
    }
    printNum(numbers);


}