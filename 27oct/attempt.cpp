#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <thread>

using namespace std;

const char frames[] = {'|', '/', '-', '\\'};

const vector<int> numbers;

void printArr(const vector<int> &numbers)
{
    int i = 0;
    for (int number : numbers)
    {
        i++;
        cout << number << ' ';
        cout << '\t';
        if (i % 10 == 0)
        {
            cout << '\n';
        }
    }
}
void delay(int milliseconds)
{
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
}

void loadingScreen(int milliseconds)
{

    for (int i = 0; i < milliseconds / 100; i++)
    {
        cout << "\r Loading..." << frames[i % 4] << flush;
        delay(100);
    }
}

void arrCreation()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1, 100);
    int s;
    while (true)
    {
        cout << "S: " << endl;

        if (cin >> s && s >= 0)
        {
            break;
        }

        cout << "error! Cin must be a positive integer!" << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    vector<int> numbers;
    numbers.reserve(s);
    for (int i = 0; i < s; i++)
    {
        numbers.push_back(distr(gen));
    }
    
    numbers = &numbers;

    loadingScreen(600);

}

bool mainMenu()
{
    int chs;
    while (true){
    
    cout << "start programm - 1 \nexit programm - 2 \n";
    if (cin >> chs && chs > 0 && chs < 3){
    switch (chs)
    {
    case 1:
        cout << "redirecting to array generation..." << endl;
        loadingScreen(300);
        arrCreation();
        break;
    case 2:
        cout << "goodbye!" << endl;
        loadingScreen(300);
        return false;

    default:
        cout << "please choose between 1 and 2!" << endl;

    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

}
}

void sortedarray(vector<int>& numbers){
    string input;
    sort(numbers.begin(), numbers.end());
    loadingScreen(300);
    printArr(numbers);
    cout << "here is sorted array, press any button to leave to the main menu." << endl;
    getline(cin, input);
    mainMenu();
}

void choose(vector<int>& numbers){
    int chs;
    while (true){
          
    cout << "Choose next operation: 1 - sort array, 2 - main menu" << endl;
    if (cin >> chs && chs > 0 && chs < 3){
    switch (chs)
    {
    case 1:
        cout << "generating sorted array..." << endl;
        loadingScreen(600);
        sortedarray(numbers);
    case 2:
        cout << "Redirecting to main menu" << endl;
        loadingScreen(300);
        mainMenu();

    default:
        cout << "please choose between 1 and 2!" << endl;

    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

}

}



int main()
{
    cout << "\033[?1049h" << flush;
  while (mainMenu()) {
  }
  cout << "\033[?1049l" << flush;
  return 0;
}