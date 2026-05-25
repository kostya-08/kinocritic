#include "Film.h"

namespace kinocritic {

int Film::objectCount = 0;

Film::Film(const std::string& title, const std::string& genre, int year, double rating)
    : id(++objectCount), title(title), genre(genre), year(year), rating(rating) {}

void Film::display() const {
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "[" << getId() << "] Фильм: " << getTitle() 
              << " (" << getYear() << ") | Жанр: " << getGenre()
              << " | Рейтинг: " << getRating() << "\n";
}

std::string Film::getType() const { return "Фильм"; }

int Film::getId() const { return id; }
std::string Film::getTitle() const { return title; }
std::string Film::getGenre() const { return genre; }
int Film::getYear() const { return year; }
double Film::getRating() const { return rating; }

} // namespace kinocritic