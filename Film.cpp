#include "Film.h"
#include <algorithm>

namespace kinocritic {

int Film::objectCount = 0;

Film::Film(const std::string& title, const std::string& genre, int year, double rating)
    : id(++objectCount), 
      title(title), 
      genre(genre), 
      year(std::clamp(year, 1900, 2026)),   // Ограничение года
      rating(std::clamp(rating, 0.0, 10.0)) 
{}

void Film::display() const {
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "[" << getId() << "] " << getType() << ": " << getTitle() 
              << " (" << getYear() << ") | Жанр: " << getGenre()
              << " | Рейтинг: " << getRating() << "\n";
}

std::string Film::getType() const {
    return "Фильм";
}

int Film::getId() const { return id; }
std::string Film::getTitle() const { return title; }
std::string Film::getGenre() const { return genre; }
int Film::getYear() const { return year; }
double Film::getRating() const { return rating; }

void Film::setRating(double r) {
    rating = std::clamp(r, 0.0, 10.0);
}

} // namespace kinocritic