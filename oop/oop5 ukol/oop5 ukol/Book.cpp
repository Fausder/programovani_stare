#include "Book.h"

Book::Book(string i, string t, string a) : isbn(i), title(t), author(a), isLoaned(false) {}

string Book::GetISBN() {
    return isbn;
}

string Book::GetTitle() {
    return title;
}

string Book::GetAuthor() {
    return author;
}

bool Book::IsLoaned() {
    return isLoaned;
}

void Book::SetLoaned(bool loaned) {
    isLoaned = loaned;
}