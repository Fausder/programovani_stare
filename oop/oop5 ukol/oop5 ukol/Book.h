#pragma once
#include <string>
using namespace std;

class Book
{
private:
    string isbn;
    string title;
    string author;
    bool isLoaned;

public:
    Book() : isbn(""), title(""), author(""), isLoaned(false){}
    Book(string i, string t, string a);
    string GetISBN();
    string GetTitle();
    string GetAuthor();
    bool IsLoaned();
    void SetLoaned(bool loaned);
};

