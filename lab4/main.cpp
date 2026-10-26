#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main(){
cout << "x: " << endl;
double x;
cin >> x;

if (x < -2 || x > -1) {
    cout << "error!" << endl;
    return 0;
}

double y = (1 + x) * (1 + x);
double a = -y;
double s = 0.0;
int i = 1;

while (abs(a) > 0.001) {
    s += a;
    a = -a * y * i / (i+1);
    i++;
}

double result = log(1.0 / (2 + 2 * x + x * x));
printf("%.4f\n", result);
printf("%.4f\n", s);
}