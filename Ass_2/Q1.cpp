#include <iostream>
#include <string>
using namespace std;

    class Student {
        protected:
            int rollNo;
            string prn, name, collegeCode;
        public:
            Student() : rollNo(0) {}
            void acceptStudent() {
            cout << "Roll number: "; cin >> rollNo;
            cout << "PRN number: "; getline(cin >> ws, prn);
            cout << "Name: "; getline(cin, name);
            cout << "College code: "; getline(cin, collegeCode);
            }
            void displayStudent() const {
            cout << "Roll No: " << rollNo << "\nPRN: " << prn
            << "\nName: " << name << "\nCollege Code: " << collegeCode << '\n';
        }
};
class Exam : virtual public Student {
protected:
    cia, ese;
public:
    Exam() : cia(0), ese(0) {}
    void acceptExam() {
    cout << "CIA marks: "; cin >> cia;
    cout << "ESE marks: "; cin >> ese;
    }
};
class Sport : virtual public Student {
    protected:
        string sportName, level;
        double sportsMarks;
    public:
    Sport() : sportsMarks(0) {}
    void acceptSport() {
        cout << "Sport name: "; getline(cin >> ws, sportName);
        cout << "Participation level: "; getline(cin, level);
        cout << "Sports marks: "; cin >> sportsMarks;
    }
};
class Result : public Exam, public Sport {
    public:
        void accept() {
            acceptStudent();
            acceptExam();
            acceptSport();
        }
        void display() const {
            cout << "\n--- Complete Student Result ---\n";
            displayStudent();
            cout << "CIA: " << cia << "\nESE: " << ese
            << "\nSport: " << sportName << "\nParticipation level: " << level
            << "\nSports marks: " << sportsMarks << '\n';
            cout << "Academic total (CIA + ESE): " << cia + ese << '\n';
        }
};
int main() {
    Result r;
    r.accept();
    r.display();
    return 0;
}