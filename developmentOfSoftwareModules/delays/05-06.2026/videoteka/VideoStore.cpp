#include "VideoStore.h"
#include <iostream>
#include <iomanip>

void VideoStore::addMovie(const std::string& title, int year, double price, int copies) {
    movies_.push_back(std::make_unique<Movie>(nextMovieId_++, title, year, price, copies));
}

void VideoStore::addUser(const std::string& name, const std::string& email, int age) {
    users_.push_back(std::make_unique<User>(nextUserId_++, name, email, age));
}

Movie* VideoStore::findMovie(int id) {
    for (auto& m : movies_) if (m->getId() == id) return m.get();
    return nullptr;
}

User* VideoStore::findUser(int id) {
    for (auto& u : users_) if (u->getId() == id) return u.get();
    return nullptr;
}

Rental* VideoStore::findActiveRental(int userId, int movieId) {
    for (auto& r : rentals_)
        if (r->getUserId() == userId && r->getMovieId() == movieId && !r->isReturned())
            return r.get();
    return nullptr;
}

bool VideoStore::rentMovie(int userId, int movieId) {
    User*  user  = findUser(userId);
    Movie* movie = findMovie(movieId);

    if (!user)  { std::cout << "Пользователь не найден.\n"; return false; }
    if (!movie) { std::cout << "Фильм не найден.\n";        return false; }
    if (movie->getCopies() <= 0) { std::cout << "Нет свободных копий.\n"; return false; }
    if (user->hasRented(movieId)) { std::cout << "Пользователь уже взял этот фильм.\n"; return false; }

    movie->removeCopy();
    user->addRentedMovie(movieId);
    rentals_.push_back(std::make_unique<Rental>(nextRentalId_++, userId, movieId, movie->getPrice()));

    std::cout << "Фильм \"" << movie->getTitle() << "\" выдан " << user->getName() << ".\n";
    return true;
}

bool VideoStore::returnMovie(int userId, int movieId) {
    User*   user   = findUser(userId);
    Movie*  movie  = findMovie(movieId);
    Rental* rental = findActiveRental(userId, movieId);

    if (!user || !movie || !rental) {
        std::cout << "Аренда не найдена.\n";
        return false;
    }

    double cost = rental->closeRental();
    movie->addCopy();
    user->removeRentedMovie(movieId);
    user->deductBalance(cost);

    std::cout << "Фильм возвращён. Стоимость: $" << std::fixed << std::setprecision(2) << cost << "\n";
    return true;
}

void VideoStore::listMovies() const {
    std::cout << "\n=== ФИЛЬМЫ ===\n";
    for (const auto& m : movies_) {
        std::cout << "  [" << m->getId() << "] " << m->getTitle()
                  << " (" << m->getYear() << ") $" << m->getPrice()
                  << " | Копии: " << m->getCopies()
                  << " | Рейтинг: " << std::fixed << std::setprecision(1) << m->getAverageRating() << "\n";
    }
}

void VideoStore::listUsers() const {
    std::cout << "\n=== ПОЛЬЗОВАТЕЛИ ===\n";
    for (const auto& u : users_) {
        std::cout << "  [" << u->getId() << "] " << u->getName()
                  << " | " << u->getEmail()
                  << " | На руках: " << u->getRentedMovies().size() << " шт.\n";
    }
}
