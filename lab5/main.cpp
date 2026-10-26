#include <iostream>
#include <array>
#include <random>
using namespace std;

//Пустой массив на 30 чисел. в ряду 10 чисел, 3 столбца, функции: Задание числа К, заполнение массива в зависимости от условий
//Функция сортировки массива, функция печати массива. 
constexpr size_t ARRAY_SIZE = 30;
constexpr size_t ROW_SIZE = 10;
random_device seed;
mt19937 generator(seed());
uniform_int_distribution<int> distribution(0, 11);


void RandomSeed(array<int, ARRAY_SIZE>& a) {
    random_device seed;
    mt19937 generator(seed());
    uniform_int_distribution<int> distribution(0, 11);
    for (size_t i = 0; i < a.size();i++) {
        a[i] = distribution(generator);
    }
}

void QueryFill(array<int, ARRAY_SIZE> & a, int K) {
    int value = 0;
    for (int i = 0; i < a.size(); i++){
        a[i] = value;
        if (a[i] == K) {
            value = 0;
        }
        else{
        value ++;
        }
    }
    
}

void Nulls(array<int, ARRAY_SIZE>& a){
    int nextPos = 0;
    for (int value : a) {
        if (value != 0) {
            nextPos ++;
        }
        a[nextPos] = value;
    }
    while (nextPos < (sizeof(a) / sizeof(a[0]))){
        a[nextPos] = 0;
        nextPos ++;
    }

}

void printArr(array<int, ARRAY_SIZE> & a ){
    cout << "A:" << endl;
    for (int i = 0 ; i < ARRAY_SIZE; i ++){
        cout << a[i] << " ";
        if ((i + 1) % ROW_SIZE == 0){
            cout << endl;
        }
    }
}

int main() {
    array<int, ARRAY_SIZE> a;
    int K;
    cout << "K= ";
    cin >> K;

    if (K <= 0) {
        RandomSeed(a);
    }
    else{
        QueryFill(a, K);
    }

    printArr(a);
    Nulls(a);
    printArr(a);

    return 0;


}