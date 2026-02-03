#include <iostream>
#include "../library/library.h"

using namespace std;

int main() {

    Library lib;

    lib.name = "My Library";
    cout << "Enter the amount of books: ";
    cin >> lib.count;

    lib.books = new Book[lib.count];

    //template: lib.books[0] = createBook("1984", "George Orwell", 1949, 15.50);

    for (int i = 0; i < lib.count; i++) {
        cout << "\nEnter the book's title: ";
        cin >> lib.books[i].title;
        cout << "\nEnter the book's author: ";
        cin >> lib.books[i].author;
        cout << "\nEnter the book's year: ";
        cin >> lib.books[i].year;
        cout << "\nEnter the book's price: ";
        cin >> lib.books[i].price;
        lib.books[i] = createBook(lib.books[i].title, lib.books[i].author, lib.books[i].year, lib.books[i].price);
    }

    printLibrary(lib);

    cout << "Average price: "
        << averageBookPrice(lib) << endl;

    Book oldest = oldestBookInLibrary(lib);

    cout << "Oldest book:" << endl;

    printBook(oldest);

    delete[] lib.books;

    return 0;

}
