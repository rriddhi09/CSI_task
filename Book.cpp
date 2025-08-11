#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

    Book::Book(int id, string title, string author)
        : id(id), title(title), author(author), issued(false) {}//using initialization list

    int Book::getId() const { return id; }//to get book id
    string Book::getTitle() const { return title; } //to get book title
    string Book::getAuthor() const { return author; } //to get book author
    bool Book::isIssued() const { return issued; } //to check if book is issued

    void Book::issueBook() { issued = true; } //mark the book as issued
    void Book::returnBook() { issued = false; } //remove book from issued
    //displaying books whether issued or available
    void Book::display() const {
        cout << id << " - " << title << " by " << author << (issued ? " [Issued]" : " [Available]") << endl;
    }
    //set title of book for updation
    void Book::setTitle(string newTitle)
     { 
        title = newTitle; 
    }
    //set author of book for updation
    void Book::setAuthor(string newAuthor) { 
        author = newAuthor; 
    }


