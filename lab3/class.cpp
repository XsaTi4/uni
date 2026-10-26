#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

class Student {
private:
    string name;
    vector<double> grades;

public:
    Student(const string& studentName) {
        name = studentName;
    }

    void addGrade(double grade) {
        if (grade < 0 || grade > 100) {
            throw invalid_argument("Mark must be in range 0-100");
        }

        grades.push_back(grade);
    }

    double averageGrade() const {
        if (grades.empty()) {
            return 0.0;
        }

        double sum = 0;

        for (double grade : grades) {
            sum += grade;
        }

        return sum / grades.size();
    }

    string getName() const {
        return name;
    }
};

int main() {
    string name;
    cin >> name;
    Student student(name);

    bool status = false;
    
    while(true) {
        cout << "enter some shi to stop -1" << endl;

        double grade;
        cin >> grade;

        if (grade == -1) {
            break;
        }
        if (grade < 0 || grade > 100) {
            cout << "grade must be from 0-100" << endl;
            continue;
        }

        student.addGrade(grade);




    }

    

    cout << "avg: " << student.getName() << ": " << student.averageGrade() << endl;

}
