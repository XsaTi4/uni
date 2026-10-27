#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <thread>
#include <algorithm>
#include <limits>
#include <sys/ioctl.h>
#include <unistd.h>



using namespace std;

const char frames[] = {'|', '/', '-', '\\'}; //Фреймы для анимки загрузки

namespace animations {

    const char frames[] = {'|', '/', '-', '\\'};

    void delay(int ms) {
        this_thread::sleep_for(chrono::milliseconds(ms));
    }

    void clearScreen() {
        cout << "\033[2J\033[H" << flush;
    }

    void setColor(int r, int g, int b) {
        cout << "\033[38;2;"
             << r << ";" << g << ";" << b << "m";
    }

    void getTerminalSize(int& width, int& height) {
        winsize w{};

        if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0 &&
            w.ws_col > 0 && w.ws_row > 0) {
            width = w.ws_col;
            height = w.ws_row;
        } else {
            width = 80;
            height = 24;
        }
    }

    void printCentered(const string& text, int r, int g, int b) {
        int width, height;
        getTerminalSize(width, height);

        int x = max(1, (width - static_cast<int>(text.size())) / 2 + 1);
        int y = (height + 1) / 2;

        // Move cursor and clear row
        cout << "\033[" << y << ";1H\033[2K";

        // Move to center
        cout << "\033[" << y << ";" << x << "H";

        setColor(r, g, b);
        cout << text << flush;
    }

    void loadingScreen(int milliseconds) {
        for (int i = 0; i < milliseconds / 100; i++) {
            cout << "\rLoading... "
                 << frames[i % 4] << flush;

            delay(100);
        }

        cout << "\r\033[2K" << flush;
    }

    void goodbyeAnimation() {
        string text = "Goodbye!";

        clearScreen();
        cout << "\033[?25l" << flush;

        // Typewriter effect
        for (size_t i = 1; i <= text.size(); i++) {
            printCentered(text.substr(0, i), 70, 255, 150);
            delay(120);
        }

        delay(400);

        // Flickering effect
        int brightness[] = {
            255, 40, 220, 20, 255, 70, 255
        };

        for (int level : brightness) {
            printCentered(
                text,
                70 * level / 255,
                level,
                150 * level / 255
            );

            delay(90);
        }

        delay(300);

        // Fade out
        for (int i = 30; i >= 0; i--) {
            printCentered(
                text,
                70 * i / 30,
                255 * i / 30,
                150 * i / 30
            );

            delay(45);
        }

        clearScreen();
        cout << "\033[0m\033[?25h" << flush;
    }

}




void delay(int milliseconds) 
{
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
}

void loadingScreen(int milliseconds) //анимка лодинг скрина для вайба чисто
{
    cout << '\n';
    for (int i = 0; i < milliseconds / 100; i++)
    {
        cout <<"\r Loading..." << frames[i % 4] << flush;
        delay(100);
    }
    cout << '\n';
}

bool mainMenu(){ // функционал мейн менюхи
    int choose;

    while (true){
    cout << "start programm - 1 \nexit programm - 2 \n";
    if (cin >> choose && choose > 0 && choose < 3){
        switch(choose){
            case 1:
                cout << "redirecting to array generation..." << '\n';
                return true;
            case 2:
                delay(100);
                system("clear");
                animations::goodbyeAnimation();
                delay(200);
                return false;
            default:
                cout << "choose between 1 and 2!!!\n";

            
        }
    }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    }}



void arrayGenerator(vector<int>& numbers){ //генератор основного массива
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(1, 100);
    int ArrayLength;
    while (true){
        cout << "ArrayLenght: " << '\n';
        if (cin >> ArrayLength && ArrayLength > 0){
            break;
        }

        cout << "error! Cin must be a positive integer! '\n'" ;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    numbers.resize(ArrayLength);
    for (int& number : numbers){
        number = distr(gen);
    }

}

bool nextChoose(){ // менюха для выбора след действия
    int choose;

    while (true){
    cout << "sort this array- 1 \nexit to main menu - 2 \n";
    if (cin >> choose && choose > 0 && choose < 3){
        switch(choose){
            case 1:
                cout << "generating sorted array!" << endl;
                return true;
            case 2:
                cout << "redirecting to main menu" << endl;
                loadingScreen(1500);
                return false;
            default:
                cout << "choose between 1 and 2!!!";

            
        }
    }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    }
}

void sortedArray(vector<int>& numbers) { // сортировка массива
    sort(numbers.begin(), numbers.end());
}

void printArr(const vector<int>& numbers){ // принт массива с пагинацией 
   const size_t pageSize = 100;
   size_t page = 0;

   if (numbers.empty()){
    cout << "Array is empty!" << '\n';
    return;
   }

   size_t totalPages = ((numbers.size() + pageSize - 1) / pageSize);

   char input;

   while(true){
    cout << "total elements:  " << numbers.size() << '\n';
    cout << "page:  " << page + 1 << '/' << totalPages << '\n';
    size_t start = page * pageSize;
    size_t end = min(start + pageSize, numbers.size());

    for (size_t i = start ; i < end; i++){
        cout << numbers[i] << '\t';

        if ((i - start) % 10 == 0 ) {
            cout << '\n';
        }

    }

    cout << '\n' << '\n';
    cout << "N - next page\nP - previous\nQ - quit to menu\n";
    cout << "Choise: " << flush;

    if (!(cin >> input)) {
        return;
    }
    if (input == 'n' || input == 'N'){
        if (page + 1 < totalPages){
            page++;
        }
    }
    else if (input == 'p' || input == 'P'){
        if (page > 0){
            page--;
        }
    }
    else if (input == 'q' || input == 'Q'){
        return;
    }
   }

}

bool scenarioManager(vector<int>& numbers){ // сценарий выполнения программы
    while(true){
        if (!mainMenu()){
            return false;
        }
        loadingScreen(1000);
        arrayGenerator(numbers);
        loadingScreen(2500);
        system("clear");
        printArr(numbers);
        if (nextChoose()){
            sortedArray(numbers);
            loadingScreen(2500);
            system("clear");
            printArr(numbers);
            
        }
        
}
}



int main(){ // точка входа 
    cout << "\033[?1049h" << flush; // эта херь делает так что бы окно в терминале перекрывало все предыдущее (типа создает новое)
    vector<int> numbers;

    while (scenarioManager(numbers));
    cout << "\033[?1049l" << flush; // эта херня возвращает старое окно терминала
    return 0;

    
    
}