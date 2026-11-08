#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>


using namespace std;
const vector<string> vehTypes;

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
    vector<string> params;
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


void add(const Input& input){
    ofstream db("db.csv", ios::app);

    int id = stoi(input.params[0]);
    string city = input.params[1];
    string date = input.params[2];
    int days = stoi(input.params[3]);
    double price = stod(input.params[4]);
    string typeOfVeh = input.params[5];

    db << id << ";" << city << ";" << date << ";" << days << ';' << price << ";" << typeOfVeh;

}


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

    string param;
    getline(ss, param);

    param.erase(0, param.find_first_not_of(" \t"));

    stringstream paramStream(param);
    string value;
    while (getline(paramStream, value, ';')) {
        input.params.push_back(value);
    }

    if (!param.empty() && param.back() == ';'){
        input.params.push_back("");
    }
    return input;

}

void inputManager(const Input& input, const vector<Trip>& trips){
    if (input.command == "print" || input.command == "Print" || input.command == "PRINT"){
        printInfo(trips);
    }
    else if (input.command == "add"){
        cout << "add" << '\n';
        add(input);

    }
    else if (input.command == "find"){
        cout << "find" << '\n';
    }
    else if (input.command == "avg"){
        cout << "avg" << '\n';
    }
    else if (input.command == "del"){
        cout << "del" << '\n';
    }
    else if (input.command == "edit"){
        cout << "edit" << '\n';
    }
    else if (input.command == "sort"){
        cout << "sort" << '\n';
    }
    else if (input.command == "exit"){
        exit(0);
    }
    else{
        cout << "wrong command!" << '\n';
    }
}
int main(){
    const string InputSource = "db.csv";
    vector<Trip> trips = input(InputSource);
    string line;
    while (true){
        vector<Trip> trips = input(InputSource);
        getline(cin,line);
        Input input = parseInput(line);
        inputManager(input, trips);



    }
    return 0;
}
