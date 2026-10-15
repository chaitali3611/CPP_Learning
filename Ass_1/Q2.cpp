#include <iostream>
#include <string>
using namespace std;

class Book {
    string title, author, publisher;
    double price;
    static int bookCount;

public:
    Book() : title("Unknown"), author("Unknown"),
    publisher("Unknown"), price(0.0) { ++bookCount; }
    Book(string t, string a, string p, double cost)
    : title(t), author(a), publisher(p), price(cost) { ++bookCount; }
    ~Book() { --bookCount; }
    void accept() {
    cout << "Title: "; getline(cin >> ws, title);
    cout << "Author: "; getline(cin, author);
    cout << "Publisher: "; getline(cin, publisher);
    cout << "Price: "; cin >> price;
    }
    inline void display() const {
    cout << "Title: " << title << "\nAuthor: " << author
    << "\nPublisher: " << publisher << "\nPrice: " << price << "\n";
    }
    static int getBookCount() { return bookCount; }
    friend bool costsMoreThan500(const Book& b) { return b.price > 500.0; }
};

int Book::bookCount = 0;
int main() {
    int n;
    cout << "How many books? ";
    cin >> n;
    if (n <= 0) {
    cout << "Number of books must be positive.\n";
    return 0;
    }
    
    Book* books = new Book[n]; // Dynamic allocation using new.
    for (int i = 0; i < n; ++i) {
    cout << "\nEnter details for book " << i + 1 << ":\n";
    books[i].accept();
    }
    cout << "\nAll books:\n";
    for (int i = 0; i < n; ++i) {
    cout << "\nBook " << i + 1 << ":\n";
    books[i].display();
    }
    cout << "\nBooks costing more than 500:\n";
    bool found = false;
    for (int i = 0; i < n; ++i) {
    if (costsMoreThan500(books[i])) {
    books[i].display();
    found = true;
    }
    }
    if (!found) cout << "No books cost more than 500.\n";
    cout << "Current number of Book objects: " << Book::getBookCount() << '\n';
    delete[] books; // Release the dynamically allocated array.
    return 0
}