#include <iostream>
#include <string>
using namespace std;

// Base Class
class Student {
protected:
    int rollNo;
    string name;

public:
    void getStudentDetails() {
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
    }
};

// Derived Class 1
class Exam : public Student {
protected:
    double marks[6];

public:
    void getMarks() {
        cout << "Enter marks for 6 subjects: ";
        for (int i = 0; i < 6; i++) {
            cin >> marks[i];
        }
    }
};

// Derived Class 2
class Result : public Exam {
private:
    double totalMarks;

public:
    void displayResult() {
        totalMarks = 0;
        for (int i = 0; i < 6; i++) {
            totalMarks += marks[i];
        }

        cout << "\n--- Result ---" << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Total Marks: " << totalMarks << " / 600" << endl;
        cout << "Percentage: " << (totalMarks / 6.0) << "%" << endl;
    }
};

int main() {
    Result student;

    student.getStudentDetails();
    student.getMarks();
    student.displayResult();

    return 0;
}
