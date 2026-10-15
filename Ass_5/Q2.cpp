#include <iostream>
using namespace std;

template <typename T>
T comparePrice(T price1, T price2) {
    (price1 > price2) ? price1 : price2;
}
int main() {
    cout << "Higher integer price: " << comparePrice(120, 150) << '\n';
    cout << "Higher float price: " << comparePrice(99.5f, 85.25f) << '\n';
    cout << "Higher double price: " << comparePrice(499.99, 599.50) << '\n';
    return 0;
}