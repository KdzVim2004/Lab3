#include <iostream>
#include <stdexcept>
#include "book.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    try
    {
        Book book1("Война и мир", "Лев Толстой", 1869, 1225);
        Book book2("Гарри Поттер", "Джоан Роулинг", 1997, 500);

        cout << "Передача по значению\n";

        cout << "До обмена:\n";
        cout << "Книга 1: " << book1.title() << '\n';
        cout << "Книга 2: " << book2.title() << '\n';

        swap_titles_by_value(book1, book2);

        cout << "После обмена внутри функции:\n";
        cout << "Книга 1: " << book1.title() << '\n';
        cout << "Книга 2: " << book2.title() << '\n';

        cout << "Оригинальные книги не изменились.\n";

        cout << "\nПередача по ссылке\n";

        cout << "До обмена:\n";
        cout << "Книга 1: " << book1.title() << '\n';
        cout << "Книга 2: " << book2.title() << '\n';

        swap_titles_by_reference(book1, book2);

        cout << "После обмена:\n";
        cout << "Книга 1: " << book1.title() << '\n';
        cout << "Книга 2: " << book2.title() << '\n';

        cout << "\nКонстантные ссылки\n";

        if (is_older(book1, book2))
        {
            cout << "Первая книга старше второй.\n";
        }
        else
        {
            cout << "Первая книга не старше второй.\n";
        }

        const Book book3(
            "Маленький принц",
            "Антуан де Сент-Экзюпери",
            1943,
            96
        );

        cout << "Книга 3: " << book3.title() << '\n';

        if (is_older(book3, book2))
        {
            cout << "Третья книга старше второй.\n";
        }
        else
        {
            cout << "Третья книга не старше второй.\n";
        }

        cout << "\nУказатели\n";

        cout << "До обмена:\n";
        cout << "Книга 1: " << book1.title() << '\n';
        cout << "Книга 2: " << book2.title() << '\n';

        swap_titles_by_pointer(&book1, &book2);

        cout << "После обмена:\n";
        cout << "Книга 1: " << book1.title() << '\n';
        cout << "Книга 2: " << book2.title() << '\n';

        swap_titles_by_pointer(nullptr, &book2);

        cout << "\nДоступность книги\n";

        cout << "Книга доступна: "
            << (is_book_available(&book1) ? "да" : "нет")
            << '\n';

        book1.checkout();

        cout << "После выдачи книги: "
            << (is_book_available(&book1) ? "да" : "нет")
            << '\n';

        cout << "Проверка nullptr: "
            << (is_book_available(nullptr) ? "да" : "нет")
            << '\n';
    }
    catch (const invalid_argument& e)
    {
        cout << "Ошибка: " << e.what() << '\n';
    }

    return 0;
}