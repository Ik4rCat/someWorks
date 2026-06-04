#include "User.h"
#include <algorithm>

User::User(int id, const std::string& name, const std::string& email, int age)
    : id_(id), name_(name), email_(email), age_(age), balance_(0.0) {}

int User::getId() const { return id_; }
const std::string& User::getName() const { return name_; }
const std::string& User::getEmail() const { return email_; }
int User::getAge() const { return age_; }
double User::getBalance() const { return balance_; }

void User::addRentedMovie(int movieId) {
    rentedMovieIds_.push_back(movieId);
}

void User::removeRentedMovie(int movieId) {
    auto it = std::find(rentedMovieIds_.begin(), rentedMovieIds_.end(), movieId);
    if (it != rentedMovieIds_.end())
        rentedMovieIds_.erase(it);
}

bool User::hasRented(int movieId) const {
    return std::find(rentedMovieIds_.begin(), rentedMovieIds_.end(), movieId)
           != rentedMovieIds_.end();
}

const std::vector<int>& User::getRentedMovies() const { return rentedMovieIds_; }

void User::deductBalance(double amount) { balance_ -= amount; }
