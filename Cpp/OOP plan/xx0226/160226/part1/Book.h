#pragma once

#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string author;
    string title;
    string publisher;
    int year;
    int pages;

public:
    explicit Book(const string& author = "", const string& title = "", const string& publisher = "", int year = 0, int pages = 0);
    Book(const Book& other);
    ~Book();
    
    const string& getAuthor() const;
    const string& getTitle() const;
    const string& getPublisher() const;
    int getYear() const;
    int getPages() const;
    
    void setAuthor(const string& author);
    void setTitle(const string& title);
    void setPublisher(const string& publisher);
    void setYear(int year);
    void setPages(int pages);
    
    void display() const;
    void input();
};
