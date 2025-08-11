#include <iostream>
#include <string>
#include <vector>
#include "library.h"  // header file with class declaration
#include "book.h"
#include "user.h"

using namespace std;

// Constructor
Library::Library() : librarian("admin", "admin123") {}

// Librarian functions

// to check whether the added uname and pwd are same as that of admin
bool Library::librarianLogin(string uname, string pwd) {
    return librarian.getUsername() == uname && librarian.checkPassword(pwd);
}

// add book to library
void Library::addBook(int id, string title, string author) {
    books.push_back(Book(id, title, author));
    cout << "Book added successfully.\n";
}

// remove book from library
void Library::removeBook(int id) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->getId() == id) {
            if (it->isIssued()) {
                cout << "Cannot remove: book is currently issued.\n";
                return;
            }
            books.erase(it);
            cout << "Book removed.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

// display books in library
void Library::displayBooks() const {
    if (books.empty()) {
        cout << "No books in library.\n";
    } else {
        for (auto &b : books) b.display();
    }
}

// register a member 
void Library::registerMember(string uname, string pwd) {
    members.push_back(Member(uname, pwd));
    cout << "Member registered.\n";
}

// Member functions

// check if the entered uname and pwd member exists
Member* Library::memberLogin(string uname, string pwd) {
    for (auto &m : members) {
        if (m.getUsername() == uname && m.checkPassword(pwd)) {
            return &m;
        }
    }
    return nullptr;
}

// issue book to member
void Library::issueBook(Member* member, int id) {
    for (auto &b : books) {
        if (b.getId() == id) {
            if (b.isIssued()) {
                cout << "Book already issued.\n";
                return;
            }
            if (!member->canIssue()) {
                cout << "You have reached your book limit.\n";
                return;
            }
            b.issueBook();
            member->addBook(id);
            cout << "Book issued successfully.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

// return book
void Library::returnBook(Member* member, int id) {
    for (auto &b : books) {
        if (b.getId() == id) {
            if (!b.isIssued()) {
                cout << "Book is not issued.\n";
                return;
            }
            b.returnBook();
            member->removeBook(id);
            cout << "Book returned successfully.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

// update book info
void Library::updateBook(int id, string newTitle, string newAuthor) {
    for (auto &b : books) {
        if (b.getId() == id) {
            b.setTitle(newTitle);
            b.setAuthor(newAuthor);
            cout << "Book details updated successfully.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

// search book by id
void Library::searchById(int id) const {
    for (auto &b : books) {
        if (b.getId() == id) {
            b.display();
            return;
        }
    }
    cout << "Book not found.\n";
}

// search book by title
void Library::searchByTitle(const string &title) const {
    bool found = false;
    for (auto &b : books) {
        if (b.getTitle().find(title) != string::npos) {
            b.display();
            found = true;
        }
    }
    if (!found) cout << "No books found matching title.\n";
}


