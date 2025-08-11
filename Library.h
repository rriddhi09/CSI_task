#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include "book.h"
#include "user.h"
using namespace std;
class Library {
private:
    vector<Book> books;
    vector<Member> members;
    Librarian librarian;
public:
    Library();
    // Librarian functions
    bool librarianLogin(string uname, string pwd);
    void addBook(int id, string title, string author);
    void removeBook(int id);
    void displayBooks() const ;
    void registerMember(string uname, string pwd) ;
    // Member functions
    Member* memberLogin(string uname, string pwd) ;
    void issueBook(Member* member, int id) ;
    void returnBook(Member* member, int id);
    void updateBook(int id, string newTitle, string newAuthor) ;
    void searchById(int id) const ;
    void searchByTitle(const string &title) const ;
};


#endif
