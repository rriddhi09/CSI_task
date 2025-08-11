# Library Management System

A simple console-based Library Management System in C++ to manage books and members.

---

## Features

- Admin (Librarian) login to manage the library
- Admin can add, remove, update, and search books
- Admin can register members
- Only registered members can log in to issue and return books

---

## Usage Instructions

1. **Admin Login**

   - Username: `admin`
   - Password: `admin123`

2. **Admin Functions**

   - Add new books
   - Remove books (only if not issued)
   - Update book details
   - Register new members

3. **Member Login**

   - Only members registered by the admin can log in.
   - Members can issue and return books.
   - Members have a limit on how many books they can issue.
   - Search books by ID, title

---

## How to Build and Run

Compile all source files together:

```bash
g++ main.cpp Library.cpp Book.cpp User.cpp -o library
