#include <iostream>
#include <string>
using namespace std;

class Employee {
    protected:
        int id;
        string name;
        double baseSalary;
    public:
        Employee(int i, string n, double s) : id(i), name(n), baseSalary(s) {}
        virtual double calculateSalary() const = 0;
        virtual double calculateBonus() const = 0;
        virtual void displayEmployeeDetails() const {
        cout << "ID: " << id << "\nName: " << name
        << "\nBase salary: " << baseSalary << '\n';
    }
    virtual ~Employee() = default;
};
class Manager : public Employee {
    public:
        Manager(int i, string n, double s) : Employee(i, n, s) {}
        double calculateSalary() const override { return baseSalary + 15000; }
        double calculateBonus() const override { return baseSalary * 0.20; }
        void displayEmployeeDetails() const override {
        cout << "\nManager\n"; Employee::displayEmployeeDetails();
        cout << "Salary (base + allowance): " << calculateSalary()
        << "\nBonus: " << calculateBonus() << '\n';
    }
};
class Developer : public Employee {
    public:
        Developer(int i, string n, double s) : Employee(i, n, s) {}
        double calculateSalary() const override { return baseSalary + 8000; }
        double calculateBonus() const override { return baseSalary * 0.15; }
        void displayEmployeeDetails() const override {
        cout << "\nDeveloper\n"; Employee::displayEmployeeDetails();
        cout << "Salary (base + allowance): " << calculateSalary()
        << "\nBonus: " << calculateBonus() << '\n';
    }
};
class Accountant : public Employee {
    public:
        Accountant(int i, string n, double s) : Employee(i, n, s) {}
        double calculateSalary() const override { return baseSalary + 5000; }
        double calculateBonus() const override { return baseSalary * 0.10; }
        void displayEmployeeDetails() const override {
        cout << "\nAccountant\n"; Employee::displayEmployeeDetails();
        cout << "Salary (base + allowance): " << calculateSalary()
        << "\nBonus: " << calculateBonus() << '\n';
    }
};
int main() {
    Manager m(1, "Meera", 70000);
    Developer d(2, "Arjun", 50000);
    Accountant a(3, "Kiran", 40000);
    Employee* team[] = {&m, &d, &a};
    for (Employee* e : team) e->displayEmployeeDetails();
    return 0;
}