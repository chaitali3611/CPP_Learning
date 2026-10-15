#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Account {
    protected:
        string holder;
        int accountNumber;
        double balance;
    public:
        Account(string h, int n, double b) : holder(h), accountNumber(n), balance(b) {}
        virtual double calculateInterest() const { return 0.0; }
        virtual double calculateCharges() const { return 0.0; }
        virtual void displayAccountDetails() const {
        cout << "Holder: " << holder << "\nAccount number: " << accountNumber
        << "\nBalance: " << balance << '\n';
    }
    virtual ~Account() = default;
};
class SavingsAccount : public Account {
    public:
        SavingsAccount(string h, int n, double b) : Account(h, n, b) {}
        double calculateInterest() const override { return balance * 0.04; }
        double calculateCharges() const override { return 0.0; }
        void displayAccountDetails() const override {
        cout << "\nSavings Account\n"; Account::displayAccountDetails();
        cout << "Annual interest (4%): " << calculateInterest()
        << "\nCharges: " << calculateCharges() << '\n';
    }
};
class CurrentAccount : public Account {
    public:
        CurrentAccount(string h, int n, double b) : Account(h, n, b) {}
        double calculateInterest() const override { return 0.0; }
        double calculateCharges() const override { return 250.0; }
        void displayAccountDetails() const override {
        cout << "\nCurrent Account\n"; Account::displayAccountDetails();
        cout << "Interest: " << calculateInterest()
        << "\nService charges: " << calculateCharges() << '\n';
    }
};
    class SalaryAccount : public Account {
        public:
            SalaryAccount(string h, int n, double b) : Account(h, n, b) {}
            double calculateInterest() const override { return balance * 0.03; }
            double calculateCharges() const override { return 0.0; }
            void displayAccountDetails() const override {
            cout << "\nSalary Account\n"; Account::displayAccountDetails();
            cout << "Annual interest (3%): " << calculateInterest()
            << "\nCharges: " << calculateCharges() << '\n';
    }
};
int main() {
    SavingsAccount s("Asha", 1001, 25000);
    CurrentAccount c("Ravi", 1002, 40000);
    SalaryAccount p("Neha", 1003, 30000);
    Account* accounts[] = {&s, &c, &p};
    for (Account* a : accounts) a->displayAccountDetails();
    return 0;
}