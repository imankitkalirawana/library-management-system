
#include "Library.h"
#include <iostream>
#include <string>

using namespace std;

void showMenu()
{
    cout << "\nLibrary Management System\n";
    cout << "1. Add Book\n";
    cout << "2. Search Book by ID\n";
    cout << "3. Search Book by Title\n";
    cout << "4. Issue Book\n";
    cout << "5. Return Book\n";
    cout << "6. List All Books\n";
    cout << "7. Delete Book\n";
    cout << "8. Exit\n";
    cout << "Choose an option: ";
}

int main()
{
    Library lib;
    int choice;
    int id;
    string title, author;

    do
    {
        showMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Book Title: ";
            getline(cin, title);
            cout << "Enter Book Author: ";
            getline(cin, author);
            lib.addBook(id, title, author);
            break;

        case 2:
            cout << "Enter Book ID to search: ";
            cin >> id;
            lib.searchBookByID(id);
            break;

        case 3:
            cout << "Enter Book Title to search: ";
            cin.ignore();
            getline(cin, title);
            lib.searchBookByTitle(title);
            break;

        case 4:
            cout << "Enter Book ID to issue: ";
            cin >> id;
            lib.issueBook(id);
            break;

        case 5:
            cout << "Enter Book ID to return: ";
            cin >> id;
            lib.returnBook(id);
            break;

        case 6:
            lib.listAllBooks();
            break;

        case 7:
            cout << "Enter Book ID to delete: ";
            cin >> id;
            lib.deleteBook(id);
            break;

        case 8:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 8);

    return 0;
}
