#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>


using namespace std;

struct Trip{
    int id;
    string city;
    string date;
    int days;
    double price;
    string typeOfVeh;
};

struct Input{
    string command;
    string param;
};

vector<Trip> input(string filename){
 ifstream db(filename);
    vector<Trip> trips;
    
    string line;

    while(getline(db, line)){

        if (!line.empty() && line.back() == '\r'){
            line.pop_back();
        }

        stringstream ss(line);
        string id, city, date, days, price, typeOfVeh;

        getline(ss, id, ';');
        getline(ss, city, ';');
        getline(ss, date, ';');
        getline(ss, days, ';');
        getline(ss, price, ';');
        getline(ss, typeOfVeh, ';');

        Trip trip;


        trip.id = stoi(id);
        trip.city = city;
        trip.date = date;
        trip.days = stoi(days);
        trip.price = stod(price);
        trip.typeOfVeh = typeOfVeh;

        trips.push_back(trip);
    }

    db.close();
    return trips;
}



//void add(vector<Trip>& trips, string input, Trip trip.id, Trip city, Trip date, Trip days, Trip price, Trip typeOfVeh){
//    ofstream output(input, ios::app);
//
//    output << id << ";" << city << ";" << date << ";" << days << ";" << price << ";" << typeOfVeh;
//}

void printInfo(const vector<Trip>& trips){
    cout << string(60, '-') << '\n';
    cout << left
         << setw(4) << "ID"
         << setw(21) << "City"
         << setw(11) << "Date"
         << right
         << setw(6) << "Days"
         << setw(10) << "Price"
         << " Vehicle\n";
    cout << string(60, '-') << '\n';
    
    for (const Trip& trip : trips) {
        cout << left
             << setw(4) << trip.id
             << setw(21) << trip.city
             << setw(11) << trip.date
             << right
             << setw(6) << trip.days
             << setw(10) << fixed << setprecision(2) << trip.price
             << " " << trip.typeOfVeh << '\n';
    }

    cout << string(60, '-') << '\n';
}

Input parseInput(const string& line){
    Input input;
    stringstream ss(line);
    ss >> input.command;

    input.param.erase(0, input.param.find_first_not_of(" \t"));
    return input;
}

void inputManager(const Input& input, const vector<Trip>& trips){
    if (input.command == "print" || input.command == "Print" || input.command == "PRINT"){
        printInfo(trips);
    }
    else if (input.command == "add"){
        cout << "add";
    }
    else if (input.command == "find"){
        cout << "find";

    }

    else if (input.command == "avg"){
        cout << "avg";
    }
    else if (input.command == "del"){
        cout << "del";
    }
    else if (input.command == "edit"){
        cout << "edit";
    }
    else if (input.command == "sort"){
        cout << "sort";
    }

    else{
        cout << "wrong command!";
    }
}
int main(){
    const string InputSource = "db.csv";
    vector<Trip> trips = input(InputSource);
    while(true){
        string chose;
        cin >> chose;
        Input input = parseInput(chose);
        inputManager(input, trips);
    }
    return 0;
}