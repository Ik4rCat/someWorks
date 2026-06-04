#pragma once
#include <string>
#include <vector>

class Movie {
public:
    Movie(int id, const std::string& title, int year, double price, int copies);

    int getId() const;
    const std::string& getTitle() const;
    int getYear() const;
    double getPrice() const;
    int getCopies() const;

    void addCopy();
    bool removeCopy();   // возвращает false если нет копий

    void addRating(int rating);
    double getAverageRating() const;

private:
    int id_;
    std::string title_;
    int year_;
    double price_;
    int copies_;
    std::vector<int> ratings_;
};
