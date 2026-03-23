#include <iostream>
#include "Book.h"

Book::Book(const string& author, const string& title, const string& publisher, int year, int pages) {
    this->author = author;
    this->title = title;
    this->publisher = publisher;
    this->year = year;
    this->pages = pages;
}

Book::Book(const Book& other) {
    this->author = other.author;
    this->title = other.title;
    this->publisher = other.publisher;
    this->year = other.year;
    this->pages = other.pages;
}

Book::~Book() {
}

const string& Book::getAuthor() const {
    return author;
}

const string& Book::getTitle() const {
    return title;
}

const string& Book::getPublisher() const {
    return publisher;
}

int Book::getYear() const {
    return year;
}

int Book::getPages() const {
    return pages;
}

void Book::setAuthor(const string& author) {
    this->author = author;
}

void Book::setTitle(const string& title) {
    this->title = title;
}

void Book::setPublisher(const string& publisher) {
    this->publisher = publisher;
}

void Book::setYear(int year) {
    this->year = year;
}

void Book::setPages(int pages) {
    this->pages = pages;
}

void Book::display() const {
    cout << "Author: " << author << endl;
    cout << "Title: " << title << endl;
    cout << "Publisher: " << publisher << endl;
    cout << "Year: " << year << endl;
    cout << "Pages: " << pages << endl;
    cout << "------------------------" << endl;
}

void Book::input() {
    cout << "Author: ";
    getline(cin, author);
    cout << "Title: ";
    getline(cin, title);
    cout << "Publisher: ";
    getline(cin, publisher);
    cout << "Year: ";
    cin >> year;
    cout << "Pages: ";
    cin >> pages;
    cin.ignore();
}
