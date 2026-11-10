#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Trip
{
    int id;
    string city;
    string date;
    int days;
    double price;
    string typeOfVeh;
};

struct Input
{
    string command;
    vector<string> params;
};

vector<Trip> input(const string &filename)
{
    ifstream db(filename);
    vector<Trip> trips;

    if (!db.is_open())
    {
        cerr << "cannot open file" << '\n';
        return trips;
    }

    string line;

    while (getline(db, line))
    {

        if (!line.empty() && line.back() == '\r')
        {
            line.pop_back();
        }

        if (line.find_first_not_of(" \t") == string::npos){
            continue;
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

    return trips;
}

bool saveTrips(const string &filename, const vector<Trip> &trips)
{
    ofstream db(filename);

    if (!db.is_open())
    {
        cerr << "cannot open file" << '\n';
        return false;
    }

    for (const Trip &trip : trips)
    {
        db << trip.id << ';'
           << trip.city << ';'
           << trip.date << ';'
           << trip.days << ';'
           << fixed << setprecision(2) << trip.price << ';'
           << trip.typeOfVeh << '\n';
    }

    return true;
}

void printInfo(const vector<Trip> &trips)
{
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

    for (const Trip &trip : trips)
    {
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

vector<Trip> findTrips(const vector<Trip> &trips, double maxPrice)
{
    vector<Trip> result;

    for (const Trip &trip : trips)
    {
        if (trip.price <= maxPrice)
        {
            result.push_back(trip);
        }
    }

    return result;
}

void printAverage(const vector<Trip> &trips)
{
    double total = 0.0;

    for (const Trip &trip : trips)
    {
        total += trip.price;
    }

    double average = trips.empty() ? 0.0 : total / trips.size();
    cout << "average=" << fixed << setprecision(2) << average << '\n';
}

int dateKey(const string &date)
{
    return stoi(date.substr(6, 4)) * 10000
         + stoi(date.substr(3, 2)) * 100
         + stoi(date.substr(0, 2));
}

void sortTrips(vector<Trip> &trips)
{
    sort(trips.begin(), trips.end(), [](const Trip &left, const Trip &right)
    {
        return dateKey(left.date) < dateKey(right.date);
    });
}

bool deleteTrip(vector<Trip> &trips, int id)
{
    auto tripToDelete = find_if(trips.begin(), trips.end(), [id](const Trip &trip)
    {
        return trip.id == id;
    });

    if (tripToDelete == trips.end())
    {
        return false;
    }

    trips.erase(tripToDelete);
    return true;
}

void addTrip(vector<Trip> &trips, const Input &input)
{
    Trip trip{
        stoi(input.params[0]),
        input.params[1],
        input.params[2],
        stoi(input.params[3]),
        stod(input.params[4]),
        input.params[5]
    };

    trips.push_back(trip);
}

bool editTrip(vector<Trip> &trips, const Input &input)
{
    int id = stoi(input.params[0]);
    auto tripToEdit = find_if(trips.begin(), trips.end(), [id](const Trip &trip)
    {
        return trip.id == id;
    });

    if (tripToEdit == trips.end())
    {
        return false;
    }

    if (!input.params[1].empty())
    {
        tripToEdit->city = input.params[1];
    }
    if (!input.params[2].empty())
    {
        tripToEdit->date = input.params[2];
    }
    if (!input.params[3].empty())
    {
        tripToEdit->days = stoi(input.params[3]);
    }
    if (!input.params[4].empty())
    {
        tripToEdit->price = stod(input.params[4]);
    }
    if (!input.params[5].empty())
    {
        tripToEdit->typeOfVeh = input.params[5];
    }

    return true;
}

Input parseInput(const string &line)
{
    Input input;
    stringstream ss(line);
    ss >> input.command;

    string param;
    getline(ss, param);

    param.erase(0, param.find_first_not_of(" \t"));

    stringstream paramStream(param);
    string value;
    while (getline(paramStream, value, ';'))
    {
        input.params.push_back(value);
    }

    if (!param.empty() && param.back() == ';')
    {
        input.params.push_back("");
    }
    return input;
}

bool inputManager(
    const Input &input,
    vector<Trip> &trips,
    const string &filename)
{
    if (input.command == "print")
    {
        printInfo(trips);
    }
    else if (input.command == "find")
    {
        double maxPrice = stod(input.params[0]);
        printInfo(findTrips(trips, maxPrice));
    }
    else if (input.command == "avg")
    {
        printAverage(trips);
    }
    else if (input.command == "sort")
    {
        sortTrips(trips);

        if (saveTrips(filename, trips))
        {
            cout << "sorted" << '\n';
        }
    }
    else if (input.command == "del")
    {
        int id = stoi(input.params[0]);

        if (deleteTrip(trips, id))
        {
            if (saveTrips(filename, trips))
            {
                cout << "deleted" << '\n';
            }
        }
        else
        {
            cout << "wrong id" << '\n';
        }
    }
    else if (input.command == "add")
    {
        addTrip(trips, input);

        if (saveTrips(filename, trips))
        {
            cout << "added" << '\n';
        }
    }
    else if (input.command == "edit")
    {
        if (editTrip(trips, input))
        {
            if (saveTrips(filename, trips))
            {
                cout << "changed" << '\n';
            }
        }
        else
        {
            cout << "wrong id" << '\n';
        }
    }
    else if (input.command == "exit")
    {
        saveTrips(filename, trips);
        return false;
    }
    else
    {
        cout << "wrong command" << '\n';
    }

    return true;
}

int main()
{
    const string inputSource = "db.csv";

    vector<Trip> trips = input(inputSource);

    string line;
    while (getline(cin, line))
    {
        Input userInput = parseInput(line);

        if (!inputManager(userInput, trips, inputSource))
        {
            break;
        }
    }

    return 0;
}
