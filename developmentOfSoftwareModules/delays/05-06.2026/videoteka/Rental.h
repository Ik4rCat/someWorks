#pragma once
#include <ctime>

class Rental {
public:
    Rental(int id, int userId, int movieId, double pricePerDay);

    int getId() const;
    int getUserId() const;
    int getMovieId() const;
    double getPaid() const;
    bool isReturned() const;

    double closeRental();  // вычисляет стоимость, помечает как возвращённый

private:
    int id_;
    int userId_;
    int movieId_;
    double pricePerDay_;
    double paid_;
    std::time_t rentDate_;
    std::time_t returnDate_;
    bool returned_;
};
