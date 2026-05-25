#include <iostream>
#include "Film.h"
#include "Serial.h"
#include "Repository.h"
#include "CustomException.h"

namespace kinocritic {

template<typename T>
void Repository<T>::loadFromFile() {}

} // namespace kinocritic

int main() {
    using namespace kinocritic;
    Repository<Film> repo;

    int choice;
    do {
        std::cout << "\n=== КИНОКРИТИК ===\n";
        std::cout << "1. Добавить фильм\n";
        std::cout << "2. Показать все\n";
        std::cout << "3. Сортировка по рейтингу\n";
        std::cout << "4. Удалить по ID\n";
        std::cout << "5. Сохранить в файл\n";
        std::cout << "0. Выход\n";
        std::cout << "Выбор: ";
        std::cin >> choice;
        std::cin.ignore();

        try {
            if (choice == 1) {
                std::string title, genre, extra;
                int year, seasons = 0;
                double rating;
                int type;

                std::cout << "Название: "; std::getline(std::cin, title);
                std::cout << "Жанр: "; std::getline(std::cin, genre);
                std::cout << "Год: "; std::cin >> year;
                std::cout << "Рейтинг (0-10): "; std::cin >> rating;
                std::cin.ignore();

                std::cout << "1. Фильм\n2. Сериал\nВыбор: ";
                std::cin >> type;
                std::cin.ignore();

                if (type == 1) {
                    std::cout << "Режиссёр: "; std::getline(std::cin, extra);
                    repo.add(std::make_unique<Film>(title, genre, year, rating));
                } else {
                    std::cout << "Количество сезонов: "; std::cin >> seasons;
                    std::cin.ignore();
                    std::cout << "Главный актёр: "; std::getline(std::cin, extra);
                    repo.add(std::make_unique<Serial>(title, genre, year, rating, seasons, extra));
                }
                std::cout << "✅ Успешно добавлено!\n";

            } else if (choice == 2) {
                repo.displayAll();
            } else if (choice == 3) {
                repo.sortByRating();
                std::cout << "✅ Отсортировано по рейтингу!\n";
            } else if (choice == 4) {
                int id;
                std::cout << "ID для удаления: ";
                std::cin >> id;
                repo.remove(id);
            } else if (choice == 5) {
                repo.saveToFile();
            }
        }
        catch (const std::exception& e) {
            std::cout << "Ошибка: " << e.what() << std::endl;
        }
    } while (choice != 0);

    std::cout << "До свидания!\n";
    return 0;
}