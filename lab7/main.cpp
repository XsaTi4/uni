#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void readNumbers(vector<int>& numbers, size_t index){
    if (index == numbers.size()){
        return;
    }


    cin >> numbers[index];
    readNumbers(numbers, index + 1);
}

int findMax(vector<int>& numbers, size_t index) {
    if (index == numbers.size() - 1) {
        return numbers[index];
    }

    int maxFromrest = findMax(numbers, index + 1);
    return max(numbers[index], maxFromrest);
}

int countMax(vector<int>& numbers, size_t index, int max) {
    if (index == numbers.size()){
        return 0;
    }

    int current;

    if (numbers[index] == max) {
        current = 1;
    }
    else {current = 0;}
    return current + countMax(numbers, index + 1, max);
}

int main() {
    int count;
    cout << "count:" << endl;
    cin >> count;
    vector<int> numbers(count);
    cout << "numbers:" << endl;
    readNumbers(numbers, 0);
    int max = findMax(numbers, 0);
    int result = countMax(numbers, 0, max);

    cout << "result: " << result;


    return 0;



}