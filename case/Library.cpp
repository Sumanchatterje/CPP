#include <iostream>
#include <map>
#include <string>
using namespace std;

class Library {
private:
    struct Book {
        string title;
        string author;
        bool isBorrowed;
    };
    map<int, Book> books;
    map<int, string> borrowers; // Maps book ID to borrower's name

public:
    void addBook(int bookID, string title, string author) {
        if (books.count(bookID) == 0) {
            books[bookID] = {title, author, false};
            cout << "Book added: " << title << " by " << author << endl;
        } else {
            cout << "Book ID already exists!" << endl;
        }
    }

    void borrowBook(int bookID, string borrowerName) {
        if (books.count(bookID)) {
            if (!books[bookID].isBorrowed) {
                books[bookID].isBorrowed = true;
                borrowers[bookID] = borrowerName;
                cout << borrowerName << " borrowed \"" << books[bookID].title << "\"" << endl;
            } else {
                cout << "Book is already borrowed!" << endl;
            }
        } else {
            cout << "Book ID not found!" << endl;
        }
    }

    void returnBook(int bookID) {
        if (books.count(bookID) && books[bookID].isBorrowed) {
            books[bookID].isBorrowed = false;
            cout << borrowers[bookID] << " returned \"" << books[bookID].title << "\"" << endl;
            borrowers.erase(bookID);
        } else {
            cout << "Book ID not found or not borrowed!" << endl;
        }
    }

    void displayAvailableBooks() {
        cout << "Available books:\n";
        for (const auto &entry : books) {
            if (!entry.second.isBorrowed) {
                cout << "ID: " << entry.first << ", Title: " << entry.second.title
                     << ", Author: " << entry.second.author << endl;
            }
        }
    }
};

int main() {
    Library library;
    library.addBook(1, "The Great Gatsby", "F. Scott Fitzgerald");
    library.addBook(2, "1984", "George Orwell");
    library.addBook(3, "To Kill a Mockingbird", "Harper Lee");

    library.displayAvailableBooks();

    library.borrowBook(1, "Alice");
    library.borrowBook(2, "Bob");

    library.displayAvailableBooks();

    library.returnBook(1);

    library.displayAvailableBooks();

    return 0;
}
