#include "Serial.h"
#include <iomanip>

namespace kinocritic {

Serial::Serial(const std::string& title, const std::string& genre, int year,
               double rating, int seasons, const std::string& mainActor)
    : Film(title, genre, year, rating), seasons(seasons), mainActor(mainActor) {}

void Serial::display() const {
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "[" << getId() << "] Сериал: " << getTitle()
              << " (" << getYear() << ") | Жанр: " << getGenre()
              << " | Рейтинг: " << getRating()
              << " | Сезонов: " << seasons
              << " | Главный актёр: " << mainActor << "\n";
}

std::string Serial::getType() const { return "Сериал"; }

}