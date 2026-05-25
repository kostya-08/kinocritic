#pragma once
#include <string>
#include <iostream>
#include <iomanip>

namespace kinocritic {

class Film {
protected:
    static int objectCount;
    int id;
    std::string title;
    std::string genre;
    int year;
    double rating;

public:
    Film(const std::string& title, const std::string& genre, int year, double rating);
    virtual ~Film() = default;

    virtual void display() const;
    virtual std::string getType() const;

    int getId() const;
    std::string getTitle() const;
    std::string getGenre() const;
    int getYear() const;
    double getRating() const;
};

} // namespace kinocritic