#include "Movie.h"
#include <numeric>

Movie::Movie(int id, const std::string& title, int year, double price, int copies)
    : id_(id), title_(title), year_(year), price_(price), copies_(copies) {}

int Movie::getId() const { return id_; }
const std::string& Movie::getTitle() const { return title_; }
int Movie::getYear() const { return year_; }
double Movie::getPrice() const { return price_; }
int Movie::getCopies() const { return copies_; }

void Movie::addCopy() { ++copies_; }

bool Movie::removeCopy() {
    if (copies_ <= 0) return false;
    --copies_;
    return true;
}

void Movie::addRating(int rating) {
    if (rating >= 1 && rating <= 10)
        ratings_.push_back(rating);
}

double Movie::getAverageRating() const {
    if (ratings_.empty()) return 0.0;
    double sum = std::accumulate(ratings_.begin(), ratings_.end(), 0.0);
    return sum / ratings_.size();
}
