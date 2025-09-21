#pragma once
#include "Book.h"
#include "Member.h"
#include <string>
using namespace std;

class Loan
{
private:
    Book book;
    Member member;
    string loanDate;

public:
	Loan() : book(), member(), loanDate("") {}
    Loan(Book b, Member m, string d);
    Book GetBook();
    Member GetMember();
    string GetLoanDate();
};



