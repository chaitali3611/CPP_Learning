#include <iostream>
#include <string>
using namespace std;

class BankAccount {
    long long accountNumber;
    string holderName, accountType;
    double balance;
    void reset() {
    accountNumber = 0;
    holderName.clear();
    accountType.clear();
    balance = 0.0;
    }
    public:
        BankAccount() { reset(); }
        friend istream& operator>>(istream& in, BankAccount& a) {
            cout << "Account number (positive integer): "; in >> a.accountNumber;
            cout << "Account holder name (one word): "; in >> a.holderName;
            cout << "Account type: "; in >> a.accountType;
            cout << "Balance: "; in >> a.balance;
        if (a.accountNumber <= 0 || a.balance < 0 || a.balance > 1000000)
        throw 1;
        return in;
        }
        friend ostream& operator<<(ostream& out, const BankAccount& a) {
            out << "Account number: " << a.accountNumber
            << "\nHolder name: " << a.holderName
            << "\nAccount type: " << a.accountType
            << "\nBalance: $" << a.balance << '\n';
            return out;
        }
        void clearAfterError() { reset(); }
};
int main() {
    BankAccount account;
    try {
        cin >> account;
        cout << "\nBank account details:\n" << account;
        } catch (int) {
        account.clearAfterError();
        cout << "\nInvalid account data. Values reset to defaults:\n";
        cout << account;
    }
    return 0;
}