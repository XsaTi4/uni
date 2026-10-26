#include <iostream>
#include <random>
#include <vector>
#include "import.hpp"

using namespace std;

// ANSI-коды добавляют цвета и позволяют очищать терминал.
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";
const string BOLD = "\033[1m";

void clearScreen() {
    cout << "\033[2J\033[H";
}

void printLine() {
    cout << CYAN << "========================================" << RESET << endl;
}

void printTitle(const string& title) {
    printLine();
    cout << BOLD << CYAN << "              " << title << RESET << endl;
    printLine();
}

random_device rd;
mt19937 generator(rd());
uniform_int_distribution<int> distribution(2, 11);

bool choose() {
    while (true) {
        char key = getch();

        // Было: key == 1. getch() возвращает символ, поэтому нужен '1'.
        if (key == '1') {
            return true;
        }

        if (key == '2') {
            return false;
        }

        cout << RED << "Choose option 1 or 2" << RESET << endl;
    }
}

int calculateSum(const vector<int>& cards) {
    int sum = 0;
    int aces = 0;

    for (int number : cards) {
        sum += number;

    if (number == 11) {
            aces++;
        }
    }

    while (sum > 21 && aces > 0) {
        sum -= 10;
        aces--;
    }

    return sum;
}

int drawCard() {
    return distribution(generator);
}

void printCards(const string& owner, const vector<int>& cards) {
    cout << BOLD << WHITE << owner << " cards: " << RESET;

    for (int card : cards) {
        cout << YELLOW << "[ " << card << " ] " << RESET;
    }

    cout << BOLD << "Total: " << calculateSum(cards) << RESET << endl;
}

void engine() {
    clearScreen();
    printTitle("BLACKJACK");

    vector<int> playerCards;
    vector<int> dealerCards;

    for (int i = 0; i < 2; i++) {
        playerCards.push_back(drawCard());
        dealerCards.push_back(drawCard());
    }

    cout << endl;
    printCards("Your", playerCards);
    cout << WHITE << "Dealer cards: " << YELLOW << "[ "
         << dealerCards[0] << " ] [ ? ]" << RESET << endl;
    printLine();

    // Ход игрока.
    while (calculateSum(playerCards) < 21) {
        cout << endl << BOLD << "[1] Hit" << RESET
             << "    " << BOLD << "[2] Stand" << RESET << endl;

        if (choose()) {
            playerCards.push_back(drawCard());
            printCards("Your", playerCards);
        } else {
            break;
        }
    }

    int playerSum = calculateSum(playerCards);

    if (playerSum > 21) {
        cout << RED << BOLD << "\nBUSTED! You lose." << RESET << endl;
        return;
    }

    // Дилер берёт карты, пока сумма меньше 17.
    while (calculateSum(dealerCards) < 17) {
        dealerCards.push_back(drawCard());
    }

    int dealerSum = calculateSum(dealerCards);

    cout << endl;
    printLine();
    cout << BOLD << "              FINAL RESULT" << RESET << endl;
    printLine();
    printCards("Your", playerCards);
    printCards("Dealer", dealerCards);

    if (dealerSum > 21 || playerSum > dealerSum) {
        cout << GREEN << BOLD << "\n              YOU WON!" << RESET << endl;
    } else if (playerSum == dealerSum) {
        cout << YELLOW << BOLD << "\n              DRAW!" << RESET << endl;
    } else {
        cout << RED << BOLD << "\n              YOU LOSE." << RESET << endl;
    }
}

bool menu() {
    clearScreen();
    printTitle("BLACKJACK");
    cout << endl << BOLD << "              MAIN MENU" << RESET << endl << endl;
    cout << GREEN << "              [1] Start game" << RESET << endl;
    cout << RED << "              [2] Exit" << RESET << endl << endl;
    cout << CYAN << "              Choose an option: " << RESET;

    return choose();
}

int main() {
    // Было: while(menu) — использовался адрес функции, а не её результат.
    while (menu()) {
        engine();

        cout << endl << CYAN << "Press any key to return to menu..." << RESET;
        getch();
    }

    clearScreen();
    cout << GREEN << "Goodbye!" << RESET << endl;
    return 0;
}
