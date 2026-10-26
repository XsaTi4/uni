#include <iostream>
#include <vector>
#include <random>
#include "import.hpp"
using namespace std;


random_device rd;
mt19937 generator(rd());
uniform_int_distribution<int> distribution(2, 11);


bool menu(){
    cout << "Main menu: \n To start press 1 or to exit press 2" << endl;
    char key = getch();

    if (key == 1){
        return true;
    }
    if (key == 2){
        return false;
    }
}

char choose(){
    cout << "please choose option - 1 pick next card is higher, 2 next card is lower";
    while(true){
    char key = getch();
    if (key == '1' || key == '2'){
        break;
    }
    return key;
    }
}

int drawCard(){
    return distribution(generator);
}



vector<int> countCards(int& card){
    vector<int> cards;
    cards.push_back(card);
    return cards;

}


void engine(){
    int firstCard = drawCard();
    cout << "here is your first card-" << firstCard << "\nguess the next one . \n 1 - Higher \n 2 - lower!" << endl;
   
}



