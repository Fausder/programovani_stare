#include "Book.h"
#include "Member.h"
#include "Loan.h"
#include "Library.h"
#include <iostream>

using namespace std;

void AddLoanToLibrary(Library& library, const string& isbn, int memberId, const string& loanDate)
{
    Book* book = library.FindBookByISBN(isbn);
    Member* member = library.FindMemberByID(memberId);
    if (book != nullptr && member != nullptr)
    {
        if (book->IsLoaned()) 
        {
            cout << "Kniha s ISBN " << isbn << " je jiz pujcena." << endl;
            cout << endl;
        }
        else 
        {
            library.AddLoan(Loan(*book, *member, loanDate));
        }
    }
    else
    {
        cout << "Kniha nebo clen nebyl nalezen." << endl;
        cout << endl;
    }
}

int main()
{
    Library library;

    library.AddBook(Book("978-3-16-148410-0", "Citanka", "Jan Novotny"));
    library.AddBook(Book("978-1-23-456789-7", "Pejsek a Kocicka", "Josef Capek"));
    library.AddBook(Book("978-9-85-654586-3", "50 odstinu sedi", "Josef Capek"));

    library.AddMember(Member(1, "Petr"));
    library.AddMember(Member(2, "Anna"));


    AddLoanToLibrary(library, "978-3-16-148410-0", 1, "2025-03-20");
    AddLoanToLibrary(library, "978-1-23-456789-7", 1, "2025-03-20");
    AddLoanToLibrary(library, "978-6666-7777-889", 1, "2025-03-20");  //tu ta neni
    AddLoanToLibrary(library, "978-9-85-654586-3", 2, "2025-03-22");

    AddLoanToLibrary(library, "978-3-16-148410-0", 2, "2025-03-20");


    Loan* loans = library.GetLoans();
    for (int i = 0; i < 100; ++i) {
        if (loans[i].GetLoanDate() != "")
        {
            cout << "Kniha: " << loans[i].GetBook().GetTitle() << " | Autor: " << loans[i].GetBook().GetAuthor() << " | Clen: " << loans[i].GetMember().GetName() << " | Datum vypujceni: " << loans[i].GetLoanDate() << endl;
        }
    }

    return 0;
}






