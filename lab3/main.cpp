#include <iostream>
#include <numbers>
#include <cmath>
#include <cstdio>
#include <limits>
#include <termios.h>
#include <unistd.h>
using namespace std;

char getch(){
    termios oldSettings{};
    tcgetattr(STDIN_FILENO, &oldSettings);

    termios newSettings = oldSettings;
    newSettings.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);

    char key{};
    read(STDIN_FILENO, &key, 1);

    tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings);
    return key;
}


double angle() {
    bool valid = false;
    double angleGrad;
    while (!valid) {
        cout << "enter angle: ";
            cin >> angleGrad;


           if (cin.fail()) {
            cout << "error!" << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max() , '\n');
            continue;
           }

        if ((angleGrad >= 0 && angleGrad <= 90)) {
            valid = true;
            continue;
        }
        
        cout << "angle must be greater than 0 and lower than 90!" << endl;

    }
    return angleGrad * numbers::pi / 180.0;
        
    
}

void engine(){
    double angleRad = angle();
    double t = 0;
    bool hit_target = false;
    bool collision = false;
    printf("\n %-8s %-10s %-10s \n", "t", "x", "y" "\n");
    while (!collision && !hit_target) {
        double x, y;
        t += 0.05;
        x = 22.0 * t * (cos(angleRad));
        y = 22.0 * t * sin(angleRad) - 23.95 * pow(t, 2) / 2;

        printf(" %-8.2f %-8.3f %-8.3f \n" , t , x , y);

        hit_target = (x >= 17 && x <= 20 && y >= 0 && y <= 3);

        if (!hit_target) {
            bool hit_obstacle = (x <= 10 && x >= 7 && y >= 0 && y <= 4);
            bool hit_ground = (y <=0);

            collision = hit_obstacle || hit_ground;
        }


    }

    if (hit_target) {
        cout << "target was hitted!";
    }
    else {
        cout << "you missed!";
    }

    
}

int main() {
    cout << ("Ruslans Popakuls 10. Grupa \napliecibas numurs - 261RDB076") << endl;
    while (true){
    engine();

    cout <<"\n press q to quit or any other key to continue!" << flush;

    char key = getch();

    if (key == 'q' || key == 'Q') {
        cout << "\n Goodbye!";
        break;
    }

    cout << '\n';

    }
    return 0;
}


//76 Jupiters g - 23.95 C v0 -22 alpha angle - ievadīt no
//tastatūras t += 0.05

