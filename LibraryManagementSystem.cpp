#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    string publisher;
    bool isAvailable;

    Book(int bookId, string bookTitle, string bookAuthor, string bookPublisher) {
        id = bookId;
        title = bookTitle;
        author = bookAuthor;
        publisher = bookPublisher;
        isAvailable = true;
    }

    void displayBook() {
        cout << "ID: " << id << "\n";
        cout << "Title: " << title << "\n";
        cout << "Author: " << author << "\n";
        cout << "Publisher: " << publisher << "\n";
        cout << "Status: " << (isAvailable ? "Available" : "Borrowed") << "\n";
        cout << "--------------------------\n";
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook() {
        int id;
        string title, author, publisher;

        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore(); 

        cout << "Enter Title: ";
        getline(cin, title);

        cout << "Enter Author: ";
        getline(cin, author);

        cout << "Enter Publisher: ";
        getline(cin, publisher);

        Book newBook(id, title, author, publisher);
        books.push_back(newBook);

        cout << "Book added successfully!\n\n";
    }

    void displayAllBooks() {
        if (books.empty()) {
            cout << "No books available in the library.\n\n";
            return;
        }

        cout << "\n--- Book List ---\n";
        for (auto &book : books) {
            book.displayBook();
        }
    }

    void searchBookById() {
        int searchId;
        cout << "Enter Book ID to search: ";
        cin >> searchId;

        bool found = false;
        for (auto &book : books) {
            if (book.id == searchId) {
                cout << "\nBook found:\n";
                book.displayBook();
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Book with ID " << searchId << " not found.\n\n";
        }
    }

    void borrowBook() {
        int bookId;
        cout << "Enter Book ID to borrow: ";
        cin >> bookId;

        bool found = false;
        for (auto &book : books) {
            if (book.id == bookId) {
                if (book.isAvailable) {
                    book.isAvailable = false;
                    cout << "Book borrowed successfully!\n\n";
                } else {
                    cout << "Sorry, the book is currently borrowed.\n\n";
                }
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Book with ID " << bookId << " not found.\n\n";
        }
    }

    void returnBook() {
        int bookId;
        cout << "Enter Book ID to return: ";
        cin >> bookId;

        bool found = false;
        for (auto &book : books) {
            if (book.id == bookId) {
                if (!book.isAvailable) {
                    book.isAvailable = true;
                    cout << "Book returned successfully!\n\n";
                } else {
                    cout << "This book was not borrowed.\n\n";
                }
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Book with ID " << bookId << " not found.\n\n";
        }
    }
};

int main() {
    Library lib;
    int choice;

    do {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book by ID\n";
        cout << "4. Borrow Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                lib.addBook();
                break;
            case 2:
                lib.displayAllBooks();
                break;
            case 3:
                lib.searchBookById();
                break;
            case 4:
                lib.borrowBook();
                break;
            case 5:
                lib.returnBook();
                break;
            case 6:
                cout << "Exiting... Thank you!\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
