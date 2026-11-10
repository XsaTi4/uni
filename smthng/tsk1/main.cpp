#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

struct Student {
    string name;
    vector<int> grades;

};


bool isNumber(const string& line){
    char extra;
    int number;
    stringstream ss(line);
    return (ss >> number) && !(ss >> extra);
}


bool choise(){
    std::cout << "to enter data manualy, press 1, to exit programm press 2.\n: ";
    int choise;
    while (true){
        if (cin >> choise && choise == 1 || choise == 2){
            switch(choise){
                case 1:
                    return true;
                case 2:
                    return false;

            }
    }
}
}


void fillFile(){
    ofstream inputFile("students.txt");
    std::cout << "enter data Name Surname middlename and grades\nwhen you done enter 0\n";
    string line;
    while (getline(cin, line)){
        if (line == "0"){
            break;
        }
        inputFile << line << '\n';
    }
}

bool scholarship(const Student& student){
    int sevens = 0;
    for (int grades : student.grades){
        if (grades < 7){
            return false;
        }
        if (grades == 7){
            sevens++;
        }

    }
    return sevens <=2;
}

int countSevens(const Student& student){
    int sevens = 0;

    for (int grades : student.grades) {
        if (grades == 7) {
            sevens ++;
        }
    }
    return sevens;
}

void printGrade(const Student& student){
    for (int grade : student.grades){
        std::cout << " " << grade;
    }
}

void printInput() {
    ifstream inputFile("students.txt");
    string line;
    while(getline(inputFile, line)){
        std::cout << line << '\n';
    }
    inputFile.close();

}

void printOutput() {
    ifstream outputFile("scholarship.txt");

    string line;

    while (getline(outputFile, line)){
        std::cout << line << '\n';
    }

    outputFile.close();
}


int main(){
    ifstream inputFile("students.txt");
    vector<Student> students;
    if (!(inputFile.is_open()) || inputFile.peek() == EOF){
        inputFile.close();

        std::cout << "file is empty, does not exist or unavialiable!" << endl;

        if (choise()){
            fillFile();
            inputFile.open("students.txt");
        }
        else {
            return 0;
        }

    }
    string line;

    while(getline(inputFile, line)){
        stringstream ss(line);
        Student student;
        string word;

        vector<string> names;

        bool readingGrades = false;
        bool valid = true;

        while(ss >> word){

            if (!readingGrades && !isNumber(word)){
                names.push_back(word);
            }
            else{
                readingGrades = true;

                if(!isNumber(word)){
                    valid = false;
                    break;
                }
                student.grades.push_back(stoi(word));
            }
        }

        if (!valid || names.size() < 2 || student.grades.empty()){
            cout << "Invalid student:" << line << '\n';
            continue;
        }

        for (const string& name : names){
            if(!student.name.empty()){
                student.name += " ";
            }
            student.name += name;
        }

        students.push_back(student);


    }

    inputFile.close();

    printInput();

    ofstream outputFile("scholarship.txt");

    for (const auto& student : students){
        if (scholarship(student)){
            outputFile << student.name << " " << countSevens(student) << '\n';
        }
    }
    outputFile.close();
    std::cout << "output:" << '\n';
    printOutput();


    return 0;

}
