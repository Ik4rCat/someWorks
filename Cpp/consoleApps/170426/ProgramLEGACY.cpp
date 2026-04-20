#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

struct Movie {
    int id;
    char* title;
    int year;
    double pricePerDay;
    int copies;
    int* ratings;
    int ratingCount;
};

struct User {
    int id;
    char* name;
    char* email;
    double balance;
    int* rentedMovieIds;
    int rentedCount;
};

struct Rental {
    int id;
    int userId;
    int movieId;
    double paid;
    bool returned;
};

vector<void*> g_movies;
vector<void*> g_users;
vector<void*> g_rentals;

int g_nextMovieId = 1;
int g_nextUserId = 1;
int g_nextRentalId = 1;

char* duplicateCString(const char* src) {
    const size_t len = std::strlen(src);
    char* result = new char[len + 1];
    std::strcpy(result, src);
    return result;
}

Movie* findMovieById(int movieId) {
    for (size_t i = 0; i < g_movies.size(); i++) {
        Movie* movie = (Movie*)g_movies[i];
        if (movie->id == movieId) {
            return movie;
        }
    }
    return nullptr;
}

User* findUserById(int userId) {
    for (size_t i = 0; i < g_users.size(); i++) {
        User* user = (User*)g_users[i];
        if (user->id == userId) {
            return user;
        }
    }
    return nullptr;
}

void addMovie(const char* title, int year, double pricePerDay, int copies) {
    Movie* movie = new Movie;
    movie->id = g_nextMovieId++;
    movie->title = duplicateCString(title);
    movie->year = year;
    movie->pricePerDay = pricePerDay;
    movie->copies = copies;
    movie->ratings = nullptr;
    movie->ratingCount = 0;
    g_movies.push_back(movie);
}

void addUser(const char* name, const char* email, double balance) {
    User* user = new User;
    user->id = g_nextUserId++;
    user->name = duplicateCString(name);
    user->email = duplicateCString(email);
    user->balance = balance;
    user->rentedMovieIds = nullptr;
    user->rentedCount = 0;
    g_users.push_back(user);
}

void addRating(int movieId, int rating) {
    Movie* movie = findMovieById(movieId);
    if (movie == nullptr || rating < 1 || rating > 5) {
        return;
    }

    int* newRatings = new int[movie->ratingCount + 1];
    for (int i = 0; i < movie->ratingCount; i++) {
        newRatings[i] = movie->ratings[i];
    }
    newRatings[movie->ratingCount] = rating;

    delete[] movie->ratings;
    movie->ratings = newRatings;
    movie->ratingCount++;
}

double getAverageRating(int movieId) {
    Movie* movie = findMovieById(movieId);
    if (movie == nullptr || movie->ratingCount == 0) {
        return 0.0;
    }

    int sum = 0;
    for (int i = 0; i < movie->ratingCount; i++) {
        sum += movie->ratings[i];
    }
    return (double)sum / (double)movie->ratingCount;
}

void listMovies() {
    cout << "\nMOVIES:\n";
    for (size_t i = 0; i < g_movies.size(); i++) {
        Movie* movie = (Movie*)g_movies[i];
        cout << movie->id << ". " << movie->title << " (" << movie->year << ") "
             << "- $" << movie->pricePerDay << "/day, copies: " << movie->copies
             << ", avg rating: " << getAverageRating(movie->id) << endl;
    }
}

void listUsers() {
    cout << "\nUSERS:\n";
    for (size_t i = 0; i < g_users.size(); i++) {
        User* user = (User*)g_users[i];
        cout << user->id << ". " << user->name << " (" << user->email << ")"
             << " balance: $" << user->balance << " rented: ";
        for (int j = 0; j < user->rentedCount; j++) {
            cout << user->rentedMovieIds[j] << " ";
        }
        cout << endl;
    }
}

void rentMovie(int userId, int movieId) {
    User* user = findUserById(userId);
    Movie* movie = findMovieById(movieId);
    if (user == nullptr || movie == nullptr) {
        return;
    }
    if (movie->copies <= 0 || user->balance < movie->pricePerDay) {
        return;
    }

    movie->copies--;
    user->balance -= movie->pricePerDay;

    int* newRented = new int[user->rentedCount + 1];
    for (int i = 0; i < user->rentedCount; i++) {
        newRented[i] = user->rentedMovieIds[i];
    }
    newRented[user->rentedCount] = movieId;
    delete[] user->rentedMovieIds;
    user->rentedMovieIds = newRented;
    user->rentedCount++;

    Rental* rental = new Rental;
    rental->id = g_nextRentalId++;
    rental->userId = userId;
    rental->movieId = movieId;
    rental->paid = movie->pricePerDay;
    rental->returned = false;
    g_rentals.push_back(rental);
}

void returnMovie(int userId, int movieId) {
    User* user = findUserById(userId);
    Movie* movie = findMovieById(movieId);
    if (user == nullptr || movie == nullptr) {
        return;
    }

    int pos = -1;
    for (int i = 0; i < user->rentedCount; i++) {
        if (user->rentedMovieIds[i] == movieId) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        return;
    }

    movie->copies++;
    for (int i = pos; i < user->rentedCount - 1; i++) {
        user->rentedMovieIds[i] = user->rentedMovieIds[i + 1];
    }
    user->rentedCount--;
}

void generateReport() {
    std::ofstream file("report.txt");
    if (!file.is_open()) {
        cout << "Cannot create report!" << endl;
        return;
    }

    file << "VIDEO STORE REPORT" << endl;
    file << "==================" << endl;

    file << "\nMOVIES:" << endl;
    for (size_t i = 0; i < g_movies.size(); i++) {
        Movie* m = (Movie*)g_movies[i];
        file << m->id << ". " << m->title << " (" << m->year << ") - "
             << m->copies << " copies, rating: " << getAverageRating(m->id) << endl;
    }

    file << "\nUSERS:" << endl;
    for (size_t i = 0; i < g_users.size(); i++) {
        User* u = (User*)g_users[i];
        file << u->id << ". " << u->name << " - Balance: $" << u->balance << endl;
        file << "  Rented movies: ";
        for (int j = 0; j < u->rentedCount; j++) {
            file << u->rentedMovieIds[j] << " ";
        }
        file << endl;
    }

    file << "\nRENTAL HISTORY:" << std::endl;
    for (size_t i = 0; i < g_rentals.size(); i++) {
        Rental* r = (Rental*)g_rentals[i];
        file << "Rental #" << r->id << ": User " << r->userId
             << ", Movie " << r->movieId << ", Paid: $" << r->paid << endl;
    }

    file.close();
    cout << "Report generated!" << endl;
}

// ========== ОЧИСТКА ПАМЯТИ ==========
void cleanup() {
    for (size_t i = 0; i < g_movies.size(); i++) {
        Movie* m = (Movie*)g_movies[i];
        delete[] m->title;
        delete[] m->ratings;
        delete m;
    }
    for (size_t i = 0; i < g_users.size(); i++) {
        User* u = (User*)g_users[i];
        delete[] u->name;
        delete[] u->email;
        delete[] u->rentedMovieIds;
        delete u;
    }
    for (size_t i = 0; i < g_rentals.size(); i++) {
        Rental* r = (Rental*)g_rentals[i];
        delete r;
    }
}

// ========== MAIN (пример использования) ==========
int main() {
    addMovie("The Matrix", 1999, 2.5, 3);
    addMovie("Inception", 2010, 3.0, 2);
    addMovie("The Godfather", 1972, 2.0, 1);

    addRating(1, 5);
    addRating(1, 4);
    addRating(2, 5);

    addUser("Alice Johnson", "alice@email.com", 25);
    addUser("Bob Smith", "bob@email.com", 30);

    listMovies();
    listUsers();

    rentMovie(1, 1);
    rentMovie(1, 2);
    rentMovie(2, 1);

    listUsers();

    returnMovie(1, 1);

    listMovies();
    listUsers();

    generateReport();
    cleanup();
    return 0;
}