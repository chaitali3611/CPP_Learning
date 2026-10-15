#include <iostream>
#include <string>
using namespace std;

class Patient {
    string name, contact, admittedDate, aadhaar, address, policyNumber;
    int age;

public:
    Patient() : name("Unknown"), contact("0000000000"), age(0),
    admittedDate("01/01/2026"), aadhaar("000000000000"),
    address("Not Available"), policyNumber("Not Assigned") {}
    void accept() {
    cout << "Patient name: "; getline(cin >> ws, name);
    cout << "Contact number: "; getline(cin, contact);
    cout << "Age: "; cin >> age;
    cout << "Admitted date (DD/MM/YYYY): "; getline(cin >> ws, admittedDate);
    cout << "Aadhaar number: "; getline(cin, aadhaar);
    cout << "Address: "; getline(cin, address);
    cout << "Policy number: "; getline(cin, policyNumber);
    }
    void display() const {
    cout << "\nName: " << name << "\nContact: " << contact
    << "\nAge: " << age << "\nAdmitted Date: " << admittedDate
    << "\nAadhaar: " << aadhaar << "\nAddress: " << address
    << "\nPolicy Number: " << policyNumber << '\n';
    }

    friend bool searchPatient(const Patient* patients, int count,
    const string& aadhaarToFind);
};

bool searchPatient(const Patient* patients, int count,
    const string& aadhaarToFind) {
    for (int i = 0; i < count; ++i) {
    if (patients[i].aadhaar == aadhaarToFind) {
    cout << "\nPatient found:\n";
    patients[i].display();
    return true;
    }
    }
    return false;
}

int main() {
    int n;
    cout << "Enter number of patients: ";
    cin >> n;
    if (n <= 0) {
    cout << "Number of patients must be positive.\n";
    return 0;
    }
    Patient* patients = new Patient[n];
    for (int i = 0; i < n; ++i) {
    cout << "\nEnter patient " << i + 1 << " details:\n";
    patients[i].accept();
    }
    cout << "\nAll patient records:\n";
    for (int i = 0; i < n; ++i) patients[i].display();
    string key;
    cout << "\nEnter Aadhaar number to search: ";
    getline(cin >> ws, key);
    if (!searchPatient(patients, n, key))
    cout << "No patient found with that Aadhaar number.\n";
    delete[] patients;
    return 0;
}