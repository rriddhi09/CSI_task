#ifndef USER_H
#define USER_H
#include <string>
#include<vector>
using namespace std;
//super class user 
class User {
protected:
    string username;
    string password;

public:
    User(string uname, string pwd);
    virtual ~User();//virtual destructor
    string getUsername() const;
    bool checkPassword(string pwd);
};
//class member inheriting from user
class Member : public User {
private:
    vector<int> issuedBooks; // store book IDs
    static const int MAX_BOOKS = 3;

public:
    Member(string uname, string pwd);
    bool canIssue() const ;//check the limit of the book to be issued
    void addBook(int bookId);
    void removeBook(int bookId);
    void displayIssuedBooks() const ;
};
//librarian inheriting from user
class Librarian : public User {
public:
    Librarian(string uname, string pwd);
};

#endif
