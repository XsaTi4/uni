#include <iostream>
#include <vector>

using namespace std;

class Card {
    private:
        string suit;
        string rank;

    public:
        Card(string s, string r) : suit(s), rank(r) {}

    void setSuit(string s) {
        suit = s;
    }
    void setRank(string r) {
        rank = r;
    }

    string getSuit() {
        return suit;
    }

    string getRank() {
        return rank;
    }

    void displayCard() {
        cout << rank << " of " << suit << endl;
    }

};

class Deck {
    private:
        vector<Card> cards;

    public:
        Deck() {
            string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
            string ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

            for (const auto& suit : suits) {
                for (const auto& rank : ranks) {
                    cards.emplace_back(suit, rank);
                }
            }
        }

    void displayDeck() {
        for (const auto& card : cards) {
            card.displayCard();
        }
    }
};

bool mainMenu() {
    bool choise;
    while (true) {
        cout << "1 - start game \n2 - exit game\n";
        if (cin >> choise && (choise == 1 || choise == 2)) {
            return choise;
        } else {
            cout << "Invalid input. Please enter 1 or 2.\n";
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        }
    }
}





int main() {
    deck.displayDeck();
}