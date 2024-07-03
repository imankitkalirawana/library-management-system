#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <vector>

using namespace std;

struct Book
{
    int id;
    string title;
    string author;
    bool isIssued;
};

class Library
{
private:
    vector<Book> books;

public:
    void addBook(int id, const string &title, const string &author);
    void searchBookByID(int id);
    void searchBookByTitle(const string &title);
    void issueBook(int id);
    void returnBook(int id);
    void listAllBooks();
    void deleteBook(int id);
};

#endif
