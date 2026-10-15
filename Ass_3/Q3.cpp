#include <iostream>
#include <string>
using namespace std;

class Person {
    protected:
        Object Oriented Programming (PCCO203) — C++ Solutions Page 3
        string name;
        int id;
    public:
        Person(string n, int i) : name(n), id(i) {}
        virtual void calculateResult() const {
        cout << "Result calculation is not applicable to this person.\n";
        }
        virtual double calculateSalary() const { return 0.0; }
        virtual void displayDetails() const {
        cout << "Name: " << name << "\nID: " << id << '\n';
    }
    virtual ~Person() = default;
};
class Student : public Person {
    double marks;
    public:
        Student(string n, int i, double m) : Person(n, i), marks(m) {}
        void calculateResult() const override {
        cout << "Marks: " << marks << "/100; "
        << (marks >= 40 ? "Pass\n" : "Fail\n");
        }
        void displayDetails() const override {
        cout << "\nStudent\n"; Person::displayDetails(); calculateResult();
    }
};
class Teacher : public Person {
    double monthlySalary;
    public:
        Teacher(string n, int i, double s) : Person(n, i), monthlySalary(s) {}
        double calculateSalary() const override { return monthlySalary; }
        void displayDetails() const override {
        cout << "\nTeacher\n"; Person::displayDetails();
        cout << "Monthly salary: " << calculateSalary() << '\n';
    }
};
class AdministrativeStaff : public Person {
    double monthlySalary;
    public:
        AdministrativeStaff(string n, int i, double s) : Person(n, i), monthlySalary(s) {}
        double calculateSalary() const override { return monthlySalary; }
        void displayDetails() const override {
        cout << "\nAdministrative Staff\n"; Person::displayDetails();
        cout << "Monthly salary: " << calculateSalary() << '\n';
    }
};
int main() {
    Student s("Anaya", 101, 86);
    Teacher t("Mr. Patil", 201, 55000);
    AdministrativeStaff a("Sonal", 301, 35000);
    Person* people[] = {&s, &t, &a};
    for (Person* p : people) p->displayDetails();
    return 0;
}