#pragma once
#include <string>
#include <vector>

class User {
public:
    User(int id, const std::string& name, const std::string& email, int age);

    int getId() const;
    const std::string& getName() const;
    const std::string& getEmail() const;
    int getAge() const;
    double getBalance() const;

    void addRentedMovie(int movieId);
    void removeRentedMovie(int movieId);
    bool hasRented(int movieId) const;
    const std::vector<int>& getRentedMovies() const;

    void deductBalance(double amount);

private:
    int id_;
    std::string name_;
    std::string email_;
    int age_;
    double balance_;
    std::vector<int> rentedMovieIds_;
};
