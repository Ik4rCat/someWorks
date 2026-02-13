#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

string author;
string bookName;
string publishingHouse;

int year;
int count;
int pagesCount;

void GetBookInfo(){
    cout << endl;
    cout << "Book info:" << endl;

    cout << " - author: " << author << endl;
    cout << " - tittle: " << bookName << endl;
    cout << " - publishing House: " << publishingHouse << endl;

    cout << " - year: " << year << endl;
    cout << " - books count: " << count << endl;
    cout << " - book's count of pages : " << pagesCount << endl;
}

