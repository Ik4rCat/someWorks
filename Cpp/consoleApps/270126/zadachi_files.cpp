// Задачи (270126)
// 1. Чередование положительных и отрицательных чисел из файла через буфер
// 2. Вывод предложений из файла, содержащих заданное слово
// 3. Замена каждых двух соседних слов в строке

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

// ============================================================
// Задача 1: Чередование через буферный файл
// Вход: файл input.txt с 2n числами (n положит. и n отрицат.)
// Выход: файл output.txt с чередованием: 1пол, 1отр, 2пол, 2отр ...
// ============================================================
void task1_interleave() {
    std::cout << "=== Задача 1: Чередование ===" << std::endl;

    // Для демонстрации создаём входной файл
    {
        std::ofstream f("input1.txt");
        f << "3 7 12 5 9\n-2 -8 -1 -15 -4\n";
    }

    std::vector<int> pos, neg;
    {
        std::ifstream f("input1.txt");
        int n;
        while (f >> n) {
            if (n > 0) pos.push_back(n);
            else if (n < 0) neg.push_back(n);
        }
    }

    // Запись в буферный файл (чередование)
    {
        std::ofstream buf("buffer.txt");
        size_t sz = std::min(pos.size(), neg.size());
        for (size_t i = 0; i < sz; i++) {
            buf << pos[i] << " " << neg[i] << " ";
        }
    }

    // Читаем из буфера и пишем в output
    {
        std::ifstream buf("buffer.txt");
        std::ofstream out("output1.txt");
        int n;
        std::cout << "Результат: ";
        while (buf >> n) {
            out << n << " ";
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }
}

// ============================================================
// Задача 2: Предложения, содержащие заданное слово
// ============================================================
void task2_find_sentences() {
    std::cout << "\n=== Задача 2: Поиск слова в предложениях ===" << std::endl;

    // Создаём тестовый файл
    {
        std::ofstream f("text.txt");
        f << "Сегодня хорошая погода.\n";
        f << "Кот сидит на окне.\n";
        f << "Погода меняется каждый день.\n";
        f << "Кот и пёс подружились.\n";
        f << "Всё хорошо.\n";
    }

    std::string keyword;
    std::cout << "Введите слово для поиска: ";
    std::getline(std::cin >> std::ws, keyword);

    // Приводим к нижнему регистру для сравнения
    auto toLower = [](std::string s) {
        for (char& c : s) c = tolower(c);
        return s;
    };
    std::string kwLower = toLower(keyword);

    std::ifstream f("text.txt");
    std::string line;
    bool found = false;
    while (std::getline(f, line)) {
        // Делим на слова, проверяем совпадение
        std::istringstream ss(line);
        std::string word;
        bool has = false;
        while (ss >> word) {
            // Убираем знаки препинания
            std::string clean;
            for (char c : word) if (isalpha(c) || c > 127) clean += c;
            if (toLower(clean) == kwLower) { has = true; break; }
        }
        if (has) {
            std::cout << line << std::endl;
            found = true;
        }
    }
    if (!found) std::cout << "Предложений с таким словом не найдено." << std::endl;
}

// ============================================================
// Задача 3: Замена каждых двух соседних слов
// ============================================================
void task3_swap_words() {
    std::cout << "\n=== Задача 3: Перестановка соседних слов ===" << std::endl;

    // Тестовый файл
    {
        std::ofstream f("words.txt");
        f << "один два три четыре пять шесть\n";
    }

    std::ifstream in("words.txt");
    std::ofstream out("words_out.txt");
    std::string line;
    while (std::getline(in, line)) {
        std::istringstream ss(line);
        std::vector<std::string> words;
        std::string w;
        while (ss >> w) words.push_back(w);

        // Меняем местами пары
        for (size_t i = 0; i + 1 < words.size(); i += 2) {
            std::swap(words[i], words[i + 1]);
        }

        std::string result;
        for (size_t i = 0; i < words.size(); i++) {
            if (i > 0) result += " ";
            result += words[i];
        }
        out << result << "\n";
        std::cout << "Исходно: " << line << std::endl;
        std::cout << "Итог:    " << result << std::endl;
    }
}

int main() {
    task1_interleave();
    task2_find_sentences();
    task3_swap_words();
    return 0;
}
