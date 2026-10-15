#include <iostream>
#include <string>
using namespace std;

class Book {
    int bookID, pages, publicationYear;
    string title;
    double price;
    void reset() {
    bookID = pages = publicationYear = 0;
    title.clear();
    price = 0.0;
    }
    public:
        Book() { reset(); }
        friend istream& operator>>(istream& in, Book& b) {
        cout << "Book ID: "; in >> b.bookID;
        cout << "Title (one word): "; in >> b.title;
        cout << "Number of pages: "; in >> b.pages;
        cout << "Publication year (1000-2026): "; in >> b.publicationYear;
        cout << "Price: "; in >> b.price;
        if (b.bookID < 0 || b.pages < 10 || b.pages > 5000 ||
        b.publicationYear < 1000 || b.publicationYear > 2026 ||
        b.price < 0 || b.price > 1000)
        throw 1;
        return in;
    }
    friend ostream& operator<<(ostream& out, const Book& b) {
        out << "Book ID: " << b.bookID << "\nTitle: " << b.title
        << "\nPages: " << b.pages << "\nPublication year: "
        << b.publicationYear << "\nPrice: $" << b.price << '\n';
        return out;
    }
    void clearAfterError() { reset(); }
};

int main() {
    Book b;
    try {
    cin >> b;
    cout << "\nBook details:\n" << b;
    } catch (int) {
    b.clearAfterError();
    cout << "\nInvalid book data. Numeric values reset to zero:\n";
    cout << b;
    }
    return 0;
}