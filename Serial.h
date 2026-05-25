#include "Film.h"

namespace kinocritic {

class Serial : public Film {
private:
    int seasons;
    std::string mainActor;

public:
    explicit Serial(const std::string& title, const std::string& genre,
                    int year, double rating, int seasons, const std::string& mainActor);

    void display() const override;
    std::string getType() const override;
};

}