#include "Rental.h"
#include <algorithm>

Rental::Rental(int id, int userId, int movieId, double pricePerDay)
    : id_(id), userId_(userId), movieId_(movieId),
      pricePerDay_(pricePerDay), paid_(0.0),
      rentDate_(std::time(nullptr)), returnDate_(0), returned_(false) {}

int Rental::getId() const { return id_; }
int Rental::getUserId() const { return userId_; }
int Rental::getMovieId() const { return movieId_; }
double Rental::getPaid() const { return paid_; }
bool Rental::isReturned() const { return returned_; }

double Rental::closeRental() {
    returnDate_ = std::time(nullptr);
    double days = std::difftime(returnDate_, rentDate_) / (60.0 * 60 * 24);
    paid_ = std::max(1.0, days) * pricePerDay_;
    returned_ = true;
    return paid_;
}
