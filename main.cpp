#include <iostream>
#include "library.h"
using namespace std;

int main() {
    //created lib object
    Library lib;
    int mainChoice;
    //main menu choice selection loop 
    do {
        cout << "\n########### Library Management System ###########\n";
        cout << "1) Librarian Login\n";
        cout << "2) Member Login\n";
        cout << "3) Exit\n";
        cout << "Enter choice: ";
        cin >> mainChoice;
        //if librarian logins
         if (mainChoice == 1) {
            string uname, pwd;
            cout << "Enter Librarian Username:(username=admin) ";
            cin >> uname;
            cout << "Enter Password:(pwd=admin123)";
            cin >> pwd;
            if (lib.librarianLogin(uname, pwd)) { //check whether the password and username is correct
                int choice;
                do {
                    cout << "\n--- Librarian Menu ---\n";
                    cout << "1) Add Book\n";
                    cout << "2) Remove Book\n";
                    cout << "3) Display Books\n";
                    cout << "4) Register Member\n";
                    cout << "5) Update Book Details\n";
                     cout << "6) Back to Main Menu\n";
                    cout << "Enter choice: ";
                    cin >> choice;
                   //to add book
                    if (choice == 1) {
                        int id; string title, author;
                        cout << "Enter Book ID: "; cin >> id;
                        cin.ignore();
                        cout << "Enter Title: "; getline(cin, title);
                        cout << "Enter Author: "; getline(cin, author);
                        lib.addBook(id, title, author);
                    }
                    //to remove book
                    else if (choice == 2) {
                        int id; cout << "Enter Book ID to remove: "; cin >> id;
                        lib.removeBook(id);
                    } 
                    //to display books
                    else if (choice == 3) {
                        lib.displayBooks();
                    }
                    //to regester member
                    else if (choice == 4) {
                        string memname, mempwd;
                        cout << "Enter Member Username: "; cin >> memname;
                        cout << "Enter Password: "; cin >> mempwd;
                        lib.registerMember(memname, mempwd);
                    }
                    //to update book info
                    else if (choice == 5) {
                        int id;
                        string title, author;
                        cout << "Enter Book ID to update: ";
                        cin >> id;
                        cin.ignore();
                        cout << "Enter new Title: ";
                        getline(cin, title);
                         cout << "Enter new Author: ";
                         getline(cin, author);
                        lib.updateBook(id, title, author);
                    }

                } while (choice != 6);//back to main menu option

            } else {
                cout << "Invalid credentials.\n";
            }
    }
        // if member logins(member can login only if he/she is regestered by librarian with that uname and pwd)
        else if (mainChoice == 2) {
            string uname, pwd;
            cout << "Enter Member Username:(user must be regestered by librarian first) ";
            cin >> uname;
            cout << "Enter Password: ";
            cin >> pwd;

            Member* mem = lib.memberLogin(uname, pwd);
            if (mem) {
                int choice;
                do {
                    cout << "\n--- Member Menu ---\n";
                    cout << "1) Display Books\n";
                    cout << "2) Issue Book\n";
                    cout << "3) Return Book\n";
                    cout << "4) View Issued Books\n";
                    cout << "5) Search Book by ID\n";
                    cout << "6) Search Book by Title\n";
                    cout << "7) Back to Main Menu\n";
                    cout << "Enter choice: ";
                    cin >> choice;
                    //display available books
                    if (choice == 1) {
                        lib.displayBooks();
                    }
                    //issue a book 
                    else if (choice == 2) {
                        int id; cout << "Enter Book ID to issue: "; cin >> id;
                        lib.issueBook(mem, id);
                    }
                    //return a book
                    else if (choice == 3) {
                        int id; cout << "Enter Book ID to return: "; cin >> id;
                        lib.returnBook(mem, id);
                    } 
                    //view issued books
                    else if (choice == 4) {
                        mem->displayIssuedBooks();
                    }
                    //search book by id
                    else if (choice == 5) {
                        int id;
                        cout << "Enter Book ID: ";
                        cin >> id;
                        lib.searchById(id);
                    } 
                    //search book by title
                    else if (choice == 6) {
                        string title;
                        cout << "Enter title keyword: ";
                        cin.ignore();
                        getline(cin, title);
                        lib.searchByTitle(title);
                    }
                   
                } while (choice != 7);//back to main menu

            } else {
                cout << "Invalid credentials.\n";
            }
        }

    } while (mainChoice != 3);//exit the system
    cout << "Exiting system...\n";
    return 0;
}
