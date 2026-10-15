#include <iostream>
#include <string>
using namespace std;

class Employee {
    protected:
        int employeeID;
        string name, department, designation;
        double basicSalary;
    public:
        Employee() : employeeID(0), basicSalary(0) {}
        void acceptEmployee() {
        cout << "Employee ID: "; cin >> employeeID;
        cout << "Name: "; getline(cin >> ws, name);
        cout << "Department: "; getline(cin, department);
        cout << "Designation: "; getline(cin, designation);
        cout << "Basic salary: "; cin >> basicSalary;
    }
    void displayEmployee() const {
        cout << "Employee ID: " << employeeID << "\nName: " << name
        << "\nDepartment: " << department << "\nDesignation: " << designation
        << "\nBasic salary: " << basicSalary << '\n';
    }
};
class Performance : virtual public Employee {
    protected:
        double rating, appraisalScore, bonus;
    public:
        Performance() : rating(0), appraisalScore(0), bonus(0) {}
        void acceptPerformance() {
        cout << "Performance rating: "; cin >> rating;
        cout << "Appraisal score: "; cin >> appraisalScore;
        cout << "Performance bonus: "; cin >> bonus;
    }
    };
    class Allowance : virtual public Employee {
    protected:
        da, travelAllowance, deductions;
    public:
        Allowance() : hra(0), da(0), travelAllowance(0), deductions(0) {}
        void acceptAllowance() {
        cout << "HRA: "; cin >> hra;
        cout << "DA: "; cin >> da;
        cout << "Travel allowance: "; cin >> travelAllowance;
        cout << "Total deductions: "; cin >> deductions;
    }
};
class Salary : public Performance, public Allowance {
    public:
    void accept() {
    acceptEmployee();
    acceptPerformance();
    acceptAllowance();
    }
    void displaySalary() const {
    double gross = basicSalary + hra + da + travelAllowance + bonus;
    double net = gross - deductions;
    cout << "\n--- Salary Statement ---\n";
    displayEmployee();
    cout << "Performance rating: " << rating
    << "\nAppraisal score: " << appraisalScore
    << "\nPerformance bonus: " << bonus
    << "\nHRA: " << hra << "\nDA: " << da
    << "\nTravel allowance: " << travelAllowance
    << "\nGross salary: " << gross
    << "\nTotal deductions: " << deductions
    << "\nNet salary: " << net << '\n';
    }
};
int main() {
    Salary s;
    s.accept();
    s.displaySalary();
    return 0;
}