#include "Loan.h"

Loan::Loan(Book b, Member m, string d) : book(b), member(m), loanDate(d) {}

Book Loan::GetBook() {
    return book;
}

Member Loan::GetMember() {
    return member;
}

string Loan::GetLoanDate() {
    return loanDate;
}




