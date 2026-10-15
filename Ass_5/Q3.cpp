#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
double calculateDiscount(T price, T discountPercentage) {
    return static_cast<double>(price) *
    static_cast<double>(discountPercentage) / 100.0;
}
int main() {
    cout << fixed << setprecision(2);
    cout << "Discount on integer price (1000, 10%): "
    << calculateDiscount(1000, 10) << '\n';
    cout << "Discount on float price (250.0, 12.5%): "
    << calculateDiscount(250.0f, 12.5f) << '\n';
    cout << "Discount on double price (799.99, 15.0%): "
    << calculateDiscount(799.99, 15.0) << '\n';
    return 0;
}