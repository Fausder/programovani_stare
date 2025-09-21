#include "Library.h"
#include <cstring>

Library::Library() : bookCount(0), memberCount(0), loanCount(0) {
    books = new Book[maxBooks]; 
    members = new Member[maxMembers]; 
    loans = new Loan[maxLoans]; 
}

Library::~Library() {
    delete[] books; 
    delete[] members; 
    delete[] loans; 
}

void Library::AddBook(Book b) {
    if (bookCount < maxBooks) {
        books[bookCount++] = b;
    }
}

void Library::AddMember(Member m) {
    if (memberCount < maxMembers) {
        members[memberCount++] = m;
    }
}

void Library::AddLoan(Loan l) {
    if (loanCount < maxLoans) {
        Book* book = FindBookByISBN(l.GetBook().GetISBN());
        if (book != nullptr && !book->IsLoaned()) {
            loans[loanCount++] = l;
            book->SetLoaned(true); 
        }
    }
}

Book* Library::FindBookByISBN(string isbn) {
    for (int i = 0; i < bookCount; ++i) {
        if (books[i].GetISBN() == isbn) {
            return &books[i];
        }
    }
    return nullptr;
}

Member* Library::FindMemberByID(int id) {
    for (int i = 0; i < memberCount; ++i) {
        if (members[i].GetID() == id) {
            return &members[i];
        }
    }
    return nullptr;
}

Loan* Library::GetLoans() {
    return loans;
}





