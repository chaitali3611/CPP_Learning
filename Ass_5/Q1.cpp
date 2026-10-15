#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
    double calculateAverage(T a, T b, T c) {
    return (static_cast<double>(a) + b + c) / 3.0;
}
int main() {
    cout << fixed << setprecision(2);
    cout << "Average of integers (10, 20, 30): "
    << calculateAverage(10, 20, 30) << '\n';
    cout << "Average of floats (1.5f, 2.5f, 3.5f): "
    << calculateAverage(1.5f, 2.5f, 3.5f) << '\n';
    cout << "Average of doubles (2.25, 4.50, 8.75): "
    << calculateAverage(2.25, 4.50, 8.75) << '\n';
    return 0;
}