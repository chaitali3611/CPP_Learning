#include <iostream>
#include <string>
using namespace std;

class Customer {
    protected:
        int customerID;
        string name, address, mobile, pan;
    public:
        Customer() : customerID(0) {}
        void acceptCustomer() {
        cout << "Customer ID: "; cin >> customerID;
        cout << "Name: "; getline(cin >> ws, name);
        cout << "Address: "; getline(cin, address);
        cout << "Mobile number: "; getline(cin, mobile);
        cout << "PAN number: "; getline(cin, pan);
        }
        void displayCustomer() const {
        cout << "Customer ID: " << customerID << "\nName: " << name
        << "\nAddress: " << address << "\nMobile: " << mobile
        << "\nPAN: " << pan << '\n';
    }
};
    class Account : virtual public Customer {
    protected:
        string accountNumber, accountType;
        double balance;
    public:
        Account() : balance(0) {}
        void acceptAccount() {
        cout << "Account number: "; getline(cin >> ws, accountNumber);
        cout << "Account type: "; getline(cin, accountType);
        cout << "Account balance: "; cin >> balance;
    }
};
class Loan : virtual public Customer {
    protected:
        string loanNumber;
        double loanAmount, interestRate, tenureYears;
    public:
        Loan() : loanAmount(0), interestRate(0), tenureYears(0) {}
        void acceptLoan() {
        cout << "Loan number: "; getline(cin >> ws, loanNumber);
        cout << "Loan amount: "; cin >> loanAmount;
        cout << "Annual interest rate (%): "; cin >> interestRate;
        cout << "Loan tenure (years): "; cin >> tenureYears;
        }
};
class CustomerFinancialReport : public Account, public Loan {
    public:
        void accept() {
            acceptCustomer();
            acceptAccount();
            acceptLoan();
        }
        void displayReport() const {
            double interest = loanAmount * interestRate * tenureYears / 100.0;
            cout << "\n--- Customer Financial Report ---\n";
            displayCustomer();
            cout << "Account number: " << accountNumber
            << "\nAccount type: " << accountType
            << "\nAccount balance: " << balance
            << "\nLoan number: " << loanNumber
            << "\nLoan amount: " << loanAmount
            << "\nSimple interest for full tenure: " << interest
            << "\nOutstanding loan (principal + simple interest): "
            << loanAmount + interest << '\n';
    }
};
int main() {
    CustomerFinancialReport report;
    report.accept();
    report.displayReport();
    return 0;
}