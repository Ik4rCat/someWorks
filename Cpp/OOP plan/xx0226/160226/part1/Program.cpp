#include <iostream>
#include "Book.h"
#include <vector>

using namespace std;

int main() {
    vector<Book> books;
    int choice;
    
    cout << "===== BOOK LIBRARY =====" << endl;
    
    while (true) {
        cout << "\n1. Add Book" << endl;
        cout << "2. Search by Author" << endl;
        cout << "3. Search by Publisher" << endl;
        cout << "4. Search by Year (after)" << endl;
        cout << "5. Show All Books" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        
        if (choice == 0) {
            break;
        }
        
        switch (choice) {
            case 1: {
                Book book;
                book.input();
                books.push_back(book);
                cout << "Book added" << endl;
                break;
            }
            case 2: {
                string author;
                cout << "Enter author name: ";
                getline(cin, author);
                cout << "\nBooks by " << author << ":" << endl;
                bool found = false;
                for (size_t i = 0; i < books.size(); i++) {
                    if (books[i].getAuthor() == author) {
                        books[i].display();
                        found = true;
                    }
                }
                if (!found) {
                    cout << "No books found" << endl;
                }
                break;
            }
            case 3: {
                string publisher;
                cout << "Enter publisher name: ";
                getline(cin, publisher);
                cout << "\nBooks from " << publisher << ":" << endl;
                bool found = false;
                for (size_t i = 0; i < books.size(); i++) {
                    if (books[i].getPublisher() == publisher) {
                        books[i].display();
                        found = true;
                    }
                }
                if (!found) {
                    cout << "No books found" << endl;
                }
                break;
            }
            case 4: {
                int year;
                cout << "Enter year: ";
                cin >> year;
                cin.ignore();
                cout << "\nBooks after " << year << ":" << endl;
                bool found = false;
                for (size_t i = 0; i < books.size(); i++) {
                    if (books[i].getYear() > year) {
                        books[i].display();
                        found = true;
                    }
                }
                if (!found) {
                    cout << "No books found" << endl;
                }
                break;
            }
            case 5: {
                cout << "\n===== ALL BOOKS =====" << endl;
                if (books.size() == 0) {
                    cout << "No books in library" << endl;
                } else {
                    for (size_t i = 0; i < books.size(); i++) {
                        cout << "Book #" << (i + 1) << endl;
                        books[i].display();
                    }
                }
                break;
            }
            default: {
                cout << "Invalid choice" << endl;
            }
        }
    }
    
    cout << "Goodbye!" << endl;
    return 0;
}
