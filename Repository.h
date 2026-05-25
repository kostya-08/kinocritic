#pragma once
#include <vector>
#include <memory>
#include <algorithm>
#include <fstream>
#include <string>
#include "Film.h"

namespace kinocritic {

template<typename T>
class Repository {
private:
    std::vector<std::unique_ptr<T>> items;
    std::string filename = "data.txt";

public:
    void add(std::unique_ptr<T> item) {
        items.push_back(std::move(item));
    }

    void remove(int id) {
        auto it = std::remove_if(items.begin(), items.end(),
            [id](const auto& p){ return p->getId() == id; });
        items.erase(it, items.end());
    }

    void displayAll() const {
        if (items.empty()) {
            std::cout << "Список фильмов пуст.\n";
            return;
        }
        for (const auto& item : items) {
            item->display();
        }
    }

    std::vector<T*> searchByGenre(const std::string& genre) const {
        std::vector<T*> result;
        for (const auto& item : items) {
            if (item->getGenre() == genre)
                result.push_back(item.get());
        }
        return result;
    }

    void sortByRating() {
        std::sort(items.begin(), items.end(),
            [](const auto& a, const auto& b) {
                return a->getRating() > b->getRating(); // лямбда
            });
    }

    void saveToFile() const {
        std::ofstream file(filename);
        for (const auto& item : items) {
            file << item->getType() << "|" << item->getTitle() << "|"
                 << item->getGenre() << "|" << item->getYear() << "|"
                 << item->getRating() << "\n";
        }
    }

    void loadFromFile();
};

} // namespace kinocritic