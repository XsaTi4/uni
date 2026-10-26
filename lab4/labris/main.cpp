#include <iostream>
#include <math.h>

using namespace std;

int main(){
    double x;
    cin >> x;
    if (x < -3 || x > 3){
        cout << "error!" << endl;
        return 0;
    }
    double a = x;
    double s = x;
    int i = 1;
    while (abs(a) > 0.001){
        a = -a * 2 * x / i;
        s = s + a;
        i ++;
    }
    double result = x * exp(-2 * x);
    printf("%.4f\n", result);
    printf("%.4f\n", s);
    return 0;

}

