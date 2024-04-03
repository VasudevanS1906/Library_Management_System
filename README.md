# Library_Management_System in C
![](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)  ![Replit](https://img.shields.io/badge/Replit-DD1200?style=for-the-badge&logo=Replit&logoColor=white)

The program is a library management system that utilizes linked lists to store book and member information, along with records of book borrowings. Users can create, update, and display book and member details, borrow and return books, and view lists of books, members, and borrow records. To showcase borrow records, users should create borrow records by borrowing books from members. The system provides basic functionality for managing a library's operations efficiently.

# Key Features

- **Book Management**: Add, search, and update book details such as title, author, and book ID.
- **Member Management**: Add, search, and update member details such as name and member ID.
- **Borrowing Management**: Borrow and return books, track borrowing records.
- **Linked List Implementation**: Efficient storage and manipulation of data using linked lists.
- **Dynamic Memory Allocation**: Allocate memory dynamically for new books, members, and borrowing records.
- **String Handling**: Manipulate and compare strings for book titles, author names, and member names.
- **Function Pointers**: Pass functions as arguments to other functions for modular and flexible design.

# Installation

1. Clone the repository or download the source code files.
2. Ensure you have a C compiler installed on your system (e.g., GCC for Linux/macOS or Visual Studio for Windows).

# Usage

1. Compile the source code files using your C compiler.
2. Run the compiled executable.
3. The program will demonstrate the usage of the library management system with sample data.

# Documentation

## Data Structures

- `Book`: Represents a book with its title, author, bookID, borrowing status, and a pointer to the next book in the linked list.
- `Member`: Represents a library member with their name, memberID, and a pointer to the next member in the linked list.
- `BorrowDetails`: A union that can hold either a borrowed book or a borrowed member.
- `BorrowRecord`: Represents a borrowing record with the borrow details (book or member), borrow type (book or member), and a pointer to the next borrow record in the linked list.

## Functions

## Book Management
- `createBook(char* title, char* author, int bookID)`: Creates a new book with the given title, author, and bookID.
- `addBook(Book** head, Book* book)`: Adds a new book to the linked list of books.
- `searchBookByTitle(Book* head, char* title)`: Searches for a book by its title and returns a pointer to the found book.
- `searchBookByAuthor(Book* head, char* author)`: Searches for a book by its author and returns a pointer to the found book.
- `searchBookByID(Book* head, int bookID)`: Searches for a book by its bookID and returns a pointer to the found book.
- `updateBookTitle(Book* book, char* newTitle)`: Updates the title of a given book.
- `updateBookAuthor(Book* book, char* newAuthor)`: Updates the author of a given book.
- `printBooks(Book* head)`: Prints the details of all books in the linked list.

## Member Management
- `createMember(char* name, int memberID)`: Creates a new member with the given name and memberID.
- `addMember(Member** head, Member* member)`: Adds a new member to the linked list of members.
- `searchMemberByName(Member* head, char* name)`: Searches for a member by their name and returns a pointer to the found member.
- `searchMemberByID(Member* head, int memberID)`: Searches for a member by their memberID and returns a pointer to the found member.
- `updateMemberName(Member* member, char* newName)`: Updates the name of a given member.
- `printMembers(Member* head)`: Prints the details of all members in the linked list.

## Borrowing Management
- `createBorrowRecord(BorrowDetails details, int borrowType)`: Creates a new borrow record with the given borrow details and borrow type.
- `addBorrowRecord(BorrowRecord** head, BorrowRecord* record)`: Adds a new borrow record to the linked list of borrow records.
- `borrowBook(Book* book, Member* member, BorrowRecord** borrowHead)`: Handles the process of borrowing a book by a member. 

# Support and Contact

If you have any questions, please feel free to contact me at [vasudevanswornampillai@gmail.com].

# License

This project is licensed under the **Apache 2.0 License**.

# Share with the community

If you find this project interesting or helpful, don't hesitate to share with your community! Let's learn and grow together!

# Conclusion

In this project, we’ve developed a robust solution for Library Management Systems. The model, a beacon of performance, awaits those go into the beautiful world of C.
