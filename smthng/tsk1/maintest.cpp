#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>


using namespace std;

struct Student { // как это работет?
    string name;
    string surname;
    vector<int> grades;
};

bool scholarShip(const Student& student){ // как это работает и что тут в инпуте
    int sevens = 0;
    for (int grade : student.grades) {
        if (grade == 7) {
            sevens ++;
        }
        if (grade < 7) {
            return false;
        }
    }
    return sevens <= 2;
}

void printGrades(const Student& student) { // опять же таки инпут в функции не понимаю
    for (int grade : student.grades) {
        cout << grade << " ";
    }
}

void createFile(const Student& student) { // как создать файл и записать в него то что надо
    ofstream outputFile("scholarship.txt");
    int sevens = scholarShip(student);

    for (int grade : student.grades) {
        if (scholarShip(student)) {
            outputFile << student.name << " " << student.surname << " ";
            int sevens = scholarShip(student);
            cout << " " << sevens << endl;
        }
    }
}

int main() { // как идет работа с структурой
    ifstream inputfile("students.txt");
    vector<Student> students; // тут создается массив с чем???

    string line;//дальше этой строчки не опнимаю
    while (getline(inputfile, line)) {
        stringstream ss(line);

        Student student;

        ss >> student.name >> student.surname;
        int grade;
        while (ss >> grade) {
            student.grades.push_back(grade);
        }
        students.push_back(student);
    }
    for (const Student& student : students) {
        if (scholarShip(student)) {
            cout << student.name << " " << student.surname << " ";
            printGrades(student);
            cout << "scholarsip approved!" << endl;
        }
        else {
            cout << student.name << " " << student.surname << " ";
            printGrades(student);
            cout << "scholarship denied!" << endl;
        }
    }
    inputfile.close();
    printGrades(students[0]);
    return 0;
}