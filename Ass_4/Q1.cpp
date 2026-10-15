#include <iostream>
#include <string>
using namespace std;

class Student {
    int rollNo;
    string prn, name;
    double marks1, marks2, marks3, percentage;
    void reset() {
    rollNo = 0; prn.clear(); name.clear();
    marks1 = marks2 = marks3 = percentage = 0;
    }
    public:
        Student() { reset(); }
        friend istream& operator>>(istream& in, Student& s) {
        cout << "Roll number: "; in >> s.rollNo;
        cout << "PRN number (digits only): "; in >> s.prn;
        cout << "Name (one word): "; in >> s.name;
        cout << "Marks in three subjects: "; in >> s.marks1 >> s.marks2 >> s.marks3;
        bool validPRN = !s.prn.empty();
        for (char ch : s.prn)
        if (ch < '0' || ch > '9') validPRN = false;
        if (s.rollNo < 0 || !validPRN ||
        s.marks1 < 0 || s.marks1 > 100 ||
        s.marks2 < 0 || s.marks2 > 100 ||
        s.marks3 < 0 || s.marks3 > 100)
        throw 1;
        s.percentage = (s.marks1 + s.marks2 + s.marks3) / 3.0;
        return in;
    }
    friend ostream& operator<<(ostream& out, const Student& s) {
        out << "Roll number: " << s.rollNo << "\nPRN: " << s.prn
        << "\nName: " << s.name << "\nSubject marks: "
        << s.marks1 << ", " << s.marks2 << ", " << s.marks3
        << "\nPercentage: " << s.percentage << "%\n";
        return out;
    }
    void clearAfterError() { reset(); }
};
int main() {
    Student s;
    try {
        cin >> s;
        cout << "\nStudent details:\n" << s;
        } catch (int) {
    s.clearAfterError();
        cout << "\nInvalid student data. Values reset to zero/empty defaults:\n";
        cout << s;
    }
    return 0;
}