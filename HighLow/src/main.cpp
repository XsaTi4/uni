#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

bool option() {
    int Selection;
    
    do {
        cout << "Main menu:\n" << "choose the option:\n\n" << "1 - Start the game" << "\n2 - exit the game" << "\n" << endl;
        cin >> Selection;
        switch(Selection){
        case 1:
            return true;
            break;  
        case 2:
            return false;
            break;
        default:
            cout << "Error: select option between 1 and 2!" << endl;
            break;
        
    }
    } while (Selection != 1 && Selection != 2);
    return false;
}

int Game_Options(int CurrentNumber) {
    int GO_selection;
    do {
         cout << "Your current number is " << CurrentNumber << "\nNext number will be:" << "\nHigher - 1" << "\nLower - 2" << "\nGood Luck! \n\n:" << endl;
         cin >> GO_selection;

         if (GO_selection != 1 && GO_selection != 2) {
            cout << "please choose option between 1 (higher) and 2 (lower)\n";

         } 


    } while (GO_selection != 1 && GO_selection != 2);
    return GO_selection;

}
void Game() {
    int CurrentNumber, NextNumber;
    CurrentNumber = rand() % 7 + 2;

    while (true) {
        int Guess = Game_Options(CurrentNumber);
        NextNumber = rand() % 7 + 2;
        cout << "NextNumber is:" << NextNumber << endl;
        if ((Guess == 1 && NextNumber > CurrentNumber) || (Guess == 2 && NextNumber < CurrentNumber)){
            cout << "you won!" << endl;
            CurrentNumber = NextNumber;
        }
        else if (NextNumber == CurrentNumber) {
            cout << "Draw! Try again!" << endl;

        }
        else {
            cout << "You lose!" << endl;
            break;
        }


            
        }
    }
    


int main() {
    srand (time(NULL));

    while (option()) {
        Game();
    }
    return 0;
}
