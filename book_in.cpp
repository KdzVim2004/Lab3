#include "book.h"
#include <stdexcept>
#include <utility>
using namespace std;

bool Book::isValidData(string title, string author, int year, int pages) const
{
    if (title.empty() || author.empty())
    {
        return false;
    }
    if (year < 1450 || year > 2025)
    {
        return false;
    }
    if (pages <= 0)
    {
        return false;
    }

    return true;
}

Book::Book(string title, string author, int year, int pages)
    : title_(title), author_(author), year_(year), pages_(pages), is_available_(true) {
    if (!isValidData(title_, author_, year_, pages_))
    {
        throw invalid_argument("Некорректные данные книги");
    }
}

//Геттеры
string Book::title() const
{
    return title_;
}


string Book::author() const
{
    return author_;
}


int Book::year() const
{
    return year_;
}

int Book::pages() const
{
    return pages_;
}

bool Book::isAvailable() const
{
    return is_available_;
}

//Сеттеры
void Book::updateTitle(string new_title) {
    if (!isValidData(new_title, author_, year_, pages_))
    {
        throw invalid_argument("Название не может быть пустым");
    }
    title_ = new_title;
}

void Book::updateAuthor(string new_author) {
    if (!isValidData(title_, new_author, year_, pages_))
    {
        throw invalid_argument("Автор не может быть пустым");
    }
    author_ = new_author;
}

void Book::updateYear(int new_year) {
    if (!isValidData(title_, author_, new_year, pages_))
    {
        throw invalid_argument("Год должен быть от 1450 до 2025");
    }
    year_ = new_year;
}

void Book::updatePages(int new_pages) {
    if (!isValidData(title_, author_, year_, new_pages))
    {
        throw invalid_argument("Страниц должно быть больше 0");
    }
    pages_ = new_pages;
}

void Book::checkout()
{
    is_available_ = false;
}

void Book::returnBook()
{
    is_available_ = true;
}

void swap_titles_by_value(Book b1, Book b2)
{
    std::string temp = b1.title();

    b1.updateTitle(b2.title());
    b2.updateTitle(temp);
}

void swap_titles_by_reference(Book& b1, Book& b2)
{
    std::string temp = b1.title();

    b1.updateTitle(b2.title());
    b2.updateTitle(temp);
}

bool is_older(const Book& b1, const Book& b2)
{
    return b1.year() < b2.year();
}

void swap_titles_by_pointer(Book* b1, Book* b2)
{
    if (b1 == nullptr || b2 == nullptr)
    {
        return;
    }

    std::string temp = b1->title();

    b1->updateTitle(b2->title());
    b2->updateTitle(temp);
}

bool is_book_available(const Book* book)
{
    if (book == nullptr)
    {
        return false;
    }

    return book->isAvailable();
}