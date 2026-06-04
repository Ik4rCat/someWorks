#pragma once
#include "Movie.h"
#include "User.h"
#include "Rental.h"
#include <vector>
#include <memory>
#include <string>

// Класс-фасад: хранит фильмы, пользователей, аренды и предоставляет операции
class VideoStore {
public:
    void addMovie(const std::string& title, int year, double price, int copies);
    void addUser(const std::string& name, const std::string& email, int age);

    bool rentMovie(int userId, int movieId);
    bool returnMovie(int userId, int movieId);

    void listMovies() const;
    void listUsers() const;

private:
    std::vector<std::unique_ptr<Movie>>  movies_;
    std::vector<std::unique_ptr<User>>   users_;
    std::vector<std::unique_ptr<Rental>> rentals_;

    int nextMovieId_  = 1;
    int nextUserId_   = 1;
    int nextRentalId_ = 1;

    Movie* findMovie(int id);
    User*  findUser(int id);
    Rental* findActiveRental(int userId, int movieId);
};
