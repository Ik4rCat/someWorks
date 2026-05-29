#pragma once

class Country {
private:
    char* name;
    int citizens;
    char* president;

public:
    Country();
    Country( char* n, int c, char* p);
    Country(const Country& other);
    ~Country();

    void show() const;
    void setName(const char* n);
    void setCitizens(int c);
    void setPresident(const char* p);
    char* getName() const;
    int getCitizens() const;
    char* getPresident() const;
};
