#include <iostream>
using namespace std;

class Complex {
    double real, imag;

    public:
        Complex() : real(0), imag(0) {}
        Complex(double r, double i) : real(r), imag(i) {}
        Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
        }
        Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
        }
        void display() const {
        cout << real;
        if (imag >= 0) cout << " + " << imag << "i\n";
        else cout << " - " << -imag << "i\n";
    }
};

int main() 
{
    double r1, i1, r2, i2;
    cout << "Enter real and imaginary parts of first number: ";
    cin >> r1 >> i1;
    cout << "Enter real and imaginary parts of second number: ";
    cin >> r2 >> i2;
    Complex c1(r1, i1), c2(r2, i2);
    Complex sum = c1 + c2;
    Complex difference = c1 - c2;
    cout << "First complex number: "; c1.display();
    cout << "Second complex number: "; c2.display();
    cout << "Addition: "; sum.display();
    cout << "Subtraction: "; difference.display();
    return 0;
}