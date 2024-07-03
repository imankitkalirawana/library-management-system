#include "Library.h"
#include <iostream>
#include <algorithm>

using namespace std;

void Library::addBook(int id, const string &title, const string &author)
{
    Book newBook = {id, title, author, false};
    books.push_back(newBook);
    cout << "Book added successfully.\n";
}

void Library::searchBookByID(int id)
{
    auto it = find_if(books.begin(), books.end(), [&id](Book &book)
                      { return book.id == id; });

    if (it != books.end())
    {
        cout << "Book found: " << it->title << " by " << it->author << "\n";
    }
    else
    {
        cout << "Book not found.\n";
    }
}

void Library::searchBookByTitle(const string &title)
{
    auto it = find_if(books.begin(), books.end(), [&title](Book &book)
                      { return book.title == title; });

    if (it != books.end())
    {
        cout << "Book found: " << it->title << " by " << it->author << "\n";
    }
    else
    {
        cout << "Book not found.\n";
    }
}

void Library::issueBook(int id)
{
    auto it = find_if(books.begin(), books.end(), [&id](Book &book)
                      { return book.id == id; });

    if (it != books.end() && !it->isIssued)
    {
        it->isIssued = true;
        cout << "Book issued successfully.\n";
    }
    else
    {
        cout << "Book is already issued or not found.\n";
    }
}

void Library::returnBook(int id)
{
    auto it = find_if(books.begin(), books.end(), [&id](Book &book)
                      { return book.id == id; });

    if (it != books.end() && it->isIssued)
    {
        it->isIssued = false;
        cout << "Book returned successfully.\n";
    }
    else
    {
        cout << "Book is not issued or not found.\n";
    }
}

void Library::listAllBooks()
{
    sort(books.begin(), books.end(), [](Book &a, Book &b)
         {
             return a.id < b.id; // Change this to a.title < b.title for sorting by title
         });

    for (const auto &book : books)
    {
        cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author << ", Status: " << (book.isIssued ? "Issued" : "Available") << "\n";
    }
}

void Library::deleteBook(int id)
{
    auto it = find_if(books.begin(), books.end(), [&id](Book &book)
                      { return book.id == id; });

    if (it != books.end())
    {
        books.erase(it);
        cout << "Book deleted successfully.\n";
    }
    else
    {
        cout << "Book not found.\n";
    }
}
