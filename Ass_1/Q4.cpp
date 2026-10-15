#include <iostream>
using namespace std;

class Rectangle {
    length, width;
    
public:
    Rectangle(double l = 0, double w = 0) : length(l), width(w) {}
    bool operator==(const Rectangle& other) const {
    return length == other.length && width == other.width;

    }
};
int main() {
    double l1, w1, l2, w2;
    cout << "Enter length and width of rectangle 1: ";
    cin >> l1 >> w1;
    cout << "Enter length and width of rectangle 2: ";
    cin >> l2 >> w2;
    Rectangle r1(l1, w1), r2(l2, w2);
    if (r1 == r2)
    cout << "Both rectangles have the same dimensions.\n";
    else
    cout << "The rectangles have different dimensions.\n";
    return 0;
}