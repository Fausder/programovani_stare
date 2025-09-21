#pragma once
#include "Book.h"
#include "Member.h"
#include "Loan.h"
#include <string>
using namespace std;

class Library
{
private:
    static const int maxBooks = 100;
    static const int maxMembers = 100;
    static const int maxLoans = 100;
    Book* books;
    Member* members;
    Loan* loans;
    int bookCount;
    int memberCount;
    int loanCount;

public:
    Library();
    ~Library();
    void AddBook(Book b);
    void AddMember(Member m);
    void AddLoan(Loan l);
    Book* FindBookByISBN(string isbn);
    Member* FindMemberByID(int id);
    Loan* GetLoans();
};




