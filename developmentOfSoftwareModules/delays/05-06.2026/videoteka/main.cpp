#include "VideoStore.h"
#include <iostream>

int main() {
    VideoStore store;

    store.addMovie("Матрица",       1999, 2.50, 3);
    store.addMovie("Интерстеллар",  2014, 3.00, 2);
    store.addMovie("Inception",     2010, 2.75, 1);

    store.addUser("Алиса", "alice@mail.ru", 22);
    store.addUser("Борис", "boris@mail.ru", 25);

    store.listMovies();
    store.listUsers();

    std::cout << "\n--- Операции ---\n";
    store.rentMovie(1, 1);   // Алиса берёт Матрицу
    store.rentMovie(2, 1);   // Борис берёт Матрицу
    store.rentMovie(1, 1);   // Алиса снова — ошибка

    store.listMovies();

    store.returnMovie(1, 1); // Алиса возвращает

    store.listMovies();

    return 0;
}
