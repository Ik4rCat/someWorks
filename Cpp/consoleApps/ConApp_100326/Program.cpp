#include <iostream>
#include <string>
#include <map>

class PhoneBook {
public:
    // Добавление записи. Если имя уже есть, вернёт false.
    bool add(const std::string& name, const std::string& phone) {
        auto [it, inserted] = entries.emplace(name, phone);
        return inserted;
    }

    // Обновление телефона по имени. Если имени нет, вернёт false.
    bool update(const std::string& name, const std::string& phone) {
        auto it = entries.find(name);
        if (it == entries.end()) {
            return false;
        }
        it->second = phone;
        return true;
    }

    // Удаление записи по имени. Если имени нет, вернёт false.
    bool remove(const std::string& name) {
        return entries.erase(name) > 0;
    }

    // Поиск телефона по имени. Вернёт true, если найдено, и заполнит outPhone.
    bool search(const std::string& name, std::string& outPhone) const {
        auto it = entries.find(name);
        if (it == entries.end()) {
            return false;
        }
        outPhone = it->second;
        return true;
    }

    // Опционально: печать всех записей
    void printAll() const {
        if (entries.empty()) {
            std::cout << "Телефонная книга пуста.\n";
            return;
        }
        std::cout << "Содержимое телефонной книги:\n";
        for (const auto& [name, phone] : entries) {
            std::cout << name << " : " << phone << '\n';
        }
    }

private:
    std::map<std::string, std::string> entries;
};

void printMenu() {
    std::cout << "\n=== Телефонная книга ===\n";
    std::cout << "1. Добавить контакт\n";
    std::cout << "2. Обновить телефон\n";
    std::cout << "3. Удалить контакт\n";
    std::cout << "4. Найти телефон по имени\n";
    std::cout << "5. Показать все контакты\n";
    std::cout << "0. Выход\n";
    std::cout << "Выберите пункт меню: ";
}

int main() {
    std::locale::global(std::locale("")); // попытка включить локаль системы

    PhoneBook book;
    int choice = -1;

    while (true) {
        printMenu();
        if (!(std::cin >> choice)) {
            std::cout << "Некорректный ввод. Завершение работы.\n";
            break;
        }
        
        if (choice == 0) {
            std::cout << "Выход...\n";
            break;
        }

        std::string name;
        std::string phone;
        std::string foundPhone;

        switch (choice) {
        case 1:
            std::cout << "Введите имя: ";
            std::cin >> name;
            std::cout << "Введите телефон: ";
            std::cin >> phone;
            if (book.add(name, phone)) {
                std::cout << "Контакт добавлен.\n";
            } else {
                std::cout << "Контакт с таким именем уже существует.\n";
            }
            break;

        case 2:
            std::cout << "Введите имя: ";
            std::cin >> name;
            std::cout << "Введите новый телефон: ";
            std::cin >> phone;
            if (book.update(name, phone)) {
                std::cout << "Телефон обновлён.\n";
            } else {
                std::cout << "Контакт не найден.\n";
            }
            break;

        case 3:
            std::cout << "Введите имя для удаления: ";
            std::cin >> name;
            if (book.remove(name)) {
                std::cout << "Контакт удалён.\n";
            } else {
                std::cout << "Контакт не найден.\n";
            }
            break;

        case 4:
            std::cout << "Введите имя для поиска: ";
            std::cin >> name;
            if (book.search(name, foundPhone)) {
                std::cout << "Телефон: " << foundPhone << '\n';
            } else {
                std::cout << "Контакт не найден.\n";
            }
            break;

        case 5:
            book.printAll();
            break;

        default:
            std::cout << "Нет такого пункта меню.\n";            break;
        }
    }

    return 0;
}

