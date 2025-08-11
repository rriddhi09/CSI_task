#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "User.h"
#include <iostream>
using namespace std;

User::User(string uname, string pwd) : username(uname), password(pwd) {}
User::~User() {} //virtual destructor

string User::getUsername() const {
    return username;
}

bool User::checkPassword(string pwd)  {
    return password == pwd;
}

Member::Member(string uname, string pwd) : User(uname, pwd) {}
//check the limit of the book to be issued
bool Member::canIssue() const {
    return issuedBooks.size() < MAX_BOOKS;
}

void Member::addBook(int bookId) {
    if (canIssue()) issuedBooks.push_back(bookId);
}

void Member::removeBook(int bookId) {
    for (auto it = issuedBooks.begin(); it != issuedBooks.end(); ++it) {
        if (*it == bookId) {
            issuedBooks.erase(it);
            break;
        }
    }
}

void Member::displayIssuedBooks() const {
    if (issuedBooks.empty()) {
        cout << "No books issued.\n";
    } else {
        cout << "Issued Books IDs: ";
        for (int id : issuedBooks) cout << id << " ";
        cout << endl;
    }
}

Librarian::Librarian(string uname, string pwd) : User(uname, pwd) {}
