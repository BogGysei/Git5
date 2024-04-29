#include <iostream>
#include <string>
#include <Windows.h> 
using namespace std;

const int MAX_BOOKS = 100; 

class Book {
protected:
    string author;
    string title;
    int pages;
    int year;

public:
    Book(string author, string title, int pages, int year)
        : author(author), title(title), pages(pages), year(year) {}

    void display_info() {
        cout << "Автор: " << author << '\n';
        cout << "Назва: " << title << '\n';
        cout << "Сторінок: " << pages << '\n';
        cout << "Рік: " << year << '\n';
    }
};

class SpecializedBook : public Book {
private:
    string genre;
    string condition;

public:
    SpecializedBook(string author, string title, int pages, int year, string genre, string condition)
        : Book(author, title, pages, year), genre(genre), condition(condition) {}

    void display_info() {
        Book::display_info();
        cout << "Жанр: " << genre << '\n';
        cout << "Стан: " << condition << '\n';
    }
};

int main() {
    SetConsoleOutputCP(1251);

    Book* library[MAX_BOOKS]; 
    int num_books = 0; 

    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Додати книгу\n";
        cout << "2. Видалити книгу\n";
        cout << "3. Вивести інформацію про всі книги\n";
        cout << "4. Вийти\n";
        cout << "Виберіть опцію: "<<'\n';

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            if (num_books < MAX_BOOKS) {
                string author, title, genre, condition;
                int pages, year;

                cout << "Введіть автора: ";
                cin.ignore();
                getline(cin, author);

                cout << "Введіть назву: ";
                getline(cin, title);

                cout << "Введіть кількість сторінок: ";
                cin >> pages;

                cout << "Введіть рік видання: ";
                cin >> year;

                cout << "Введіть жанр: ";
                cin.ignore(); 
                getline(cin, genre);

                cout << "Введіть стан: ";
                getline(cin, condition);

                library[num_books] = new SpecializedBook(author, title, pages, year, genre, condition);
                num_books++;
                cout << "Книга додана успішно!\n";
            }
            else {
                cout << "Бібліотека заповнена!\n";
            }
            break;
        }
        case 2: {
            if (num_books > 0) {
                cout << "Введіть індекс книги, яку ви хочете видалити: ";
                int index;
                cin >> index;

                if (index >= 0 && index < num_books) {
                    delete library[index];
                    for (int i = index; i < num_books - 1; ++i) {
                        library[i] = library[i + 1];
                    }
                    num_books--;
                    cout << "Книга видалена успішно!\n";
                }
                else {
                    cout << "Недійсний індекс книги!\n";
                }
            }
            else {
                cout << "Бібліотека порожня!\n";
            }
            break;
        }
        case 3: {
            if (num_books > 0) {
                cout <<'\n' << "Інформація про всі книги в бібліотеці:\n";
                for (int i = 0; i < num_books; ++i) {
                    cout << "Книга " << i + 1 << ":\n";
                    library[i]->display_info();
                    cout << endl;
                }
            }
            else {
                cout << "Бібліотека порожня!\n";
            }
            break;
        }
        case 4: {
            cout << "До побачення!\n";
            for (int i = 0; i < num_books; ++i) {
                delete library[i];
            }
            return 0;
        }
        default:
            cout << "Невірний вибір опції. Спробуйте ще раз.\n";
        }
    }
}
