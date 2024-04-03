#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Book {
    char title[100];
    char author[100];
    int bookID;
    int isBorrowed; 
    struct Book* next;
} Book;


typedef struct Member {
    char name[100];
    int memberID;
    struct Member* next;
} Member;


typedef union BorrowDetails {
    Book* borrowedBook;
    Member* borrowedMember;
} BorrowDetails;


typedef struct BorrowRecord {
    BorrowDetails details;
    int borrowType; 
    struct BorrowRecord* next;
} BorrowRecord;


Book* createBook(char* title, char* author, int bookID);
Member* createMember(char* name, int memberID);
BorrowRecord* createBorrowRecord(BorrowDetails details, int borrowType);
void addBorrowRecord(BorrowRecord** head, BorrowRecord* record);
void borrowBook(Book* book, Member* member, BorrowRecord** borrowHead);

void borrowBook(Book* book, Member* member, BorrowRecord** borrowHead) {
    if (book != NULL && member != NULL && !book->isBorrowed == 0) {
        BorrowDetails details;
        details.borrowedBook = book;
        BorrowRecord* record = createBorrowRecord(details, 0);
        addBorrowRecord(borrowHead, record);
        book->isBorrowed = 1; 
    }
}

void printBooks(Book* head) {
    Book* current = head;
    while (current != NULL) {
        printf("Title: %s, Author: %s, ID: %d\n", current->title, current->author, current->bookID);
        current = current->next;
    }
}

void printMembers(Member* head) {
    Member* current = head;
    while (current != NULL) {
        printf("Name: %s, ID: %d\n", current->name, current->memberID);
        current = current->next;
    }
}

void printBorrowRecords(BorrowRecord* head) {
    BorrowRecord* current = head;
    while (current != NULL) {
        printf("Borrow Type: %d\n", current->borrowType);
        current = current->next;
    }
}




Book* createBook(char* title, char* author, int bookID);
Member* createMember(char* name, int memberID);
BorrowRecord* createBorrowRecord(BorrowDetails details, int borrowType);


void pushBook(Book** stack, Book* book);
Book* popBook(Book** stack);
void pushMember(Member** stack, Member* member);
Member* popMember(Member** stack);


void enqueueBook(Book** front, Book** rear, Book* book);
Book* dequeueBook(Book** front, Book** rear);
void enqueueMember(Member** front, Member** rear, Member* member);
Member* dequeueMember(Member** front, Member** rear);


void addBook(Book** head, Book* book);
void addMember(Member** head, Member* member);
void addBorrowRecord(BorrowRecord** head, BorrowRecord* record);


void printBooks(Book* head);
void printMembers(Member* head);
void printBorrowRecords(BorrowRecord* head);
Book* searchBookByTitle(Book* head, char* title);
Book* searchBookByAuthor(Book* head, char* author);
Book* searchBookByID(Book* head, int bookID);
Member* searchMemberByName(Member* head, char* name);
Member* searchMemberByID(Member* head, int memberID);
void updateBookTitle(Book* book, char* newTitle);
void updateBookAuthor(Book* book, char* newAuthor);
void updateMemberName(Member* member, char* newName);
void borrowBook(Book* book, Member* member, BorrowRecord** borrowHead);
void returnBook(Book* book, BorrowRecord** borrowHead);




Book* createBook(char* title, char* author, int bookID) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->bookID = bookID;
    newBook->isBorrowed = 1; 
    newBook->next = NULL;
    return newBook;
}

Member* createMember(char* name, int memberID) {
    Member* newMember = (Member*)malloc(sizeof(Member));
    strcpy(newMember->name, name);
    newMember->memberID = memberID;
    newMember->next = NULL;
    return newMember;
}


BorrowRecord* createBorrowRecord(BorrowDetails details, int borrowType) {
    BorrowRecord* newRecord = (BorrowRecord*)malloc(sizeof(BorrowRecord));
    newRecord->details = details;
    newRecord->borrowType = borrowType;
    newRecord->next = NULL;
    return newRecord;
}


void addBook(Book** head, Book* book) {
    Book* current = *head;
    if (*head == NULL) {
        *head = book;
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = book;
}


void addMember(Member** head, Member* member) {
    Member* current = *head;
    if (*head == NULL) {
        *head = member;
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = member;
}


void addBorrowRecord(BorrowRecord** head, BorrowRecord* record) {
    BorrowRecord* current = *head;
    if (*head == NULL) {
        *head = record;
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = record;
}
Book* searchBookByTitle(Book* head, char* title) {
    Book* current = head;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL; 
}

Book* searchBookByAuthor(Book* head, char* author) {
    Book* current = head;
    while (current != NULL) {
        if (strcmp(current->author, author) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL; 
}

Book* searchBookByID(Book* head, int bookID) {
    Book* current = head;
    while (current != NULL) {
        if (current->bookID == bookID) {
            return current;
        }
        current = current->next;
    }
    return NULL; 
}

Member* searchMemberByName(Member* head, char* name) {
    Member* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL; 
}

Member* searchMemberByID(Member* head, int memberID) {
    Member* current = head;
    while (current != NULL) {
        if (current->memberID == memberID) {
            return current;
        }
        current = current->next;
    }
    return NULL; 
}

void updateBookTitle(Book* book, char* newTitle) {
    if (book != NULL) {
        strcpy(book->title, newTitle);
    }
}

void updateBookAuthor(Book* book, char* newAuthor) {
    if (book != NULL) {
        strcpy(book->author, newAuthor);
    }
}

void updateMemberName(Member* member, char* newName) {
    if (member != NULL) {
        strcpy(member->name, newName);
    }
}



void returnBook(Book* book, BorrowRecord** borrowHead) {
    if (book != NULL && book->isBorrowed) {
        BorrowRecord* current = *borrowHead;
        BorrowRecord* prev = NULL;
        while (current != NULL) {
            if (current->borrowType == 0 && current->details.borrowedBook == book) {
                if (prev == NULL) {
                    *borrowHead = current->next;
                } else {
                    prev->next = current->next;
                }
                free(current);
                book->isBorrowed = 0; 
                return;
            }
            prev = current;
            current = current->next;
        }
    }
}


int main() {
    
    Book* bookHead = NULL;
    Member* memberHead = NULL;
    BorrowRecord* borrowHead = NULL;

    
    Book* book1 = createBook("The Great Gatsby", "F. Scott Fitzgerald", 1);
    Book* book2 = createBook("To Kill a Mockingbird", "Harper Lee", 2);
    addBook(&bookHead, book1);
    addBook(&bookHead, book2);

    Member* member1 = createMember("John Doe", 1);
    Member* member2 = createMember("Jane Smith", 2);
    addMember(&memberHead, member1);
    addMember(&memberHead, member2);

    
    BorrowDetails details1;
    details1.borrowedBook = book1;
    BorrowRecord* borrowRecord1 = createBorrowRecord(details1, 0); 
    addBorrowRecord(&borrowHead, borrowRecord1);

    
    BorrowDetails details2;
    details2.borrowedBook = book2;
    BorrowRecord* borrowRecord2 = createBorrowRecord(details2, 0); 
    addBorrowRecord(&borrowHead, borrowRecord2);
  
    
    Book* foundBook = searchBookByTitle(bookHead, "The Great Gatsby");
    Member* foundMember = searchMemberByName(memberHead, "Jane Smith");

    
    updateBookTitle(book1, "The Great Gatsby (New Edition)");
    updateMemberName(member2, "Jane Miller");

    
    borrowBook(book1, member1, &borrowHead);
    returnBook(book1, &borrowHead);

    
    printf("Book List:\n");
    printBooks(bookHead);

    
    printf("\nMember List:\n");
    printMembers(memberHead);

    
    printf("\nBorrow Records:\n");
    printBorrowRecords(borrowHead);

    return 0;    
}