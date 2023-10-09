#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Book {
public:
    string title;
    string author;
    string ISBN;
    bool isAvailable;

    Book(string t, string a, string i) : title(t), author(a), ISBN(i), isAvailable(true) {}
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(string title, string author, string ISBN) {
        Book newBook(title, author, ISBN);
        books.push_back(newBook);
        cout << "Book added successfully!\n";
    }

    void searchBook(string query) {
        cout << "Search Results:\n";
        for (const auto& book : books) {
            if (book.title.find(query) != string::npos ||
                book.author.find(query) != string::npos ||
                book.ISBN.find(query) != string::npos) {
                cout << "Title: " << book.title << ", \nAuthor: " << book.author << ", \nISBN: " << book.ISBN << endl;
            }
        }
    }

    void checkoutBook(string ISBN) {
        auto it = find_if(books.begin(), books.end(), [&ISBN](const Book& b) { return b.ISBN == ISBN && b.isAvailable; });
        if (it != books.end()) {
            it->isAvailable = false;
            cout << "Book checked out successfully!\n";
        } else {
            cout << "Book not available for checkout or ISBN is incorrect.\n";
        }
    }

    void returnBook(string ISBN) {
        auto it = find_if(books.begin(), books.end(), [&ISBN](const Book& b) { return b.ISBN == ISBN && !b.isAvailable; });
        if (it != books.end()) {
            it->isAvailable = true;
            cout << "Book returned successfully!\n";
        } else {
            cout << "Invalid ISBN or book is already available.\n";
        }
    }
};

int main() {
    Library library;
    int choice;
    string title, author, ISBN, searchQuery;

    cout<<endl<<endl;
	cout<<" ====================================================="<<endl;
    cout<<"|                LIBRARY MANAGEMENT SYSTEM            |"<<endl;
    cout<<" ====================================================="<<endl;


    do {
        cout << endl;
        cout << "1. Add Book\n";
        cout << "2. Search Book\n";
        cout << "3. Checkout Book\n";
        cout << "4. Return Book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                cout << "Enter ISBN: ";
                getline(cin, ISBN);
                library.addBook(title, author, ISBN);
                break;
            case 2:
                cout << "Enter search query (title, author, or ISBN): ";
                cin.ignore();
                getline(cin, searchQuery);
                library.searchBook(searchQuery);
                break;
            case 3:
                cout << "Enter ISBN of the book to checkout: ";
                cin.ignore();
                getline(cin, ISBN);
                library.checkoutBook(ISBN);
                break;
            case 4:
                cout << "Enter ISBN of the book to return: ";
                cin.ignore();
                getline(cin, ISBN);
                library.returnBook(ISBN);
                break;
            case 5:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
