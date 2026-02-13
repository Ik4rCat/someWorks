#pragma once
#include <string>

class Book {
private:
    std::string author;
    std::string title;
    std::string publisher;
    int year;
    int pages;

public:
    explicit Book(const std::string& a = "", const std::string& t = "", const std::string& p = "", int y = 0, int pg = 0);

    std::string getAuthor() const;
    std::string getTitle() const;
    std::string getPublisher() const;
    int getYear() const;
    int getPages() const;

    void print() const;
};
