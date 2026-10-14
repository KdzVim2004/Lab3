#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;
class Book
{
private:
    string title_;
    string author_;
    int year_;
    int pages_;
    bool is_available_;
    bool isValidData(string title, string author, int year, int pages) const;

public:
    Book(string title, string author, int year, int pages);

    string title() const;
    string author() const;
    int year() const;
    int pages() const;
    bool isAvailable() const;
    void checkout();
    void returnBook();

    void updateTitle(string new_title);
    void updateAuthor(string author);
    void updateYear(int year);
    void updatePages(int new_pages);
};

void swap_titles_by_value(Book b1, Book b2);

void swap_titles_by_reference(Book& b1, Book& b2);

bool is_older(const Book& b1, const Book& b2);

void swap_titles_by_pointer(Book* b1, Book* b2);

bool is_book_available(const Book* book);

#endif