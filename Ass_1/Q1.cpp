#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Book {
    string title, author;
    int bookID, copies;
    double price;
public:
    Book() : title("Unknown"), author("Unknown"),
    bookID(1001), copies(10), price(500.0) {}
    void accept() {
    cout << "Enter book title: ";
    getline(cin >> ws, title);
    cout << "Enter author name: ";
    getline(cin, author);
    cout << "Enter book ID: ";
    cin >> bookID;
    cout << "Enter price: ";
    cin >> price;
    cout << "Enter number of copies: ";
    cin >> copies;
    }

    void display() const {
    cout << "\nTitle: " << title << "\nAuthor: " << author
    << "\nBook ID: " << bookID << "\nPrice: " << price
    << "\nCopies: " << copies << '\n';
    }
    int getBookID() const { return bookID; }
    friend double totalCopiesCost(const Book& b);
};

double totalCopiesCost(const Book& b) {
 return b.price * b.copies;
}

int main() {
    Book book; // Required default values are initialized here.
    cout << "Default book details:\n";
    book.display();
    cout << "\nEnter replacement book details:\n";
    book.accept();
    book.display();
    int searchID;
    cout << "\nEnter Book ID to search: ";
    cin >> searchID;
    if (searchID == book.getBookID())
    cout << "Book found.\n";
    else
    cout << "Book not found.\n";
    cout << "Total cost of available copies: "
    << totalCopiesCost(book) << '\n';
    return 0;
}