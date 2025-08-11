#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;
//Book class definition
class Book {
private:
    int id;
    string title;
    string author;
    bool issued;
public:
    Book(int id, string title, string author);
    int getId() const;//to get book id
    string getTitle() const; //to get book title
    string getAuthor() const; //to get book author
    bool isIssued() const; //to check if book is issued
    void issueBook(); //mark the book as issued
    void returnBook() ; //remove book from issued
    //displaying books whether issued or available
    void display() const ;
    //set title of book for updation
    void setTitle(string newTitle);
    //set author of book for updation
    void setAuthor(string newAuthor);
};

#endif
