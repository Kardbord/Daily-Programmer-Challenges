#include "ToursDB.h"
#include "PromoDB.h"

/*
 * Created by Tanner
 */

ToursDB initTourDatabase();
PromoDB initPromotionDatabase(ToursDB const &toursDB);

// TODO: take orders via file given from command line
int main(int argc, char *argv[]) {
    ToursDB toursDB = initTourDatabase();
    PromoDB promoDB = initPromotionDatabase(toursDB);
}

ToursDB initTourDatabase() {
    ToursDB toursDB;

    Tour tour("OH", "Opera House Tour", 300);
    Tour tour1("BC", "Sydney Bridge Climb", 110);
    Tour tour2("SK", "Sydney Sky Tower", 30);

    toursDB.addTour(tour);
    toursDB.addTour(tour1);
    toursDB.addTour(tour2);

    return toursDB;
}

PromoDB initPromotionDatabase(ToursDB const &toursDB) {

    // uninitialized vector to use in constructing PromoDB
    std::vector<std::pair<std::string, unsigned int>> emptyVec;
    PromoDB promoDB(toursDB, emptyVec, 0);
    std::vector<std::pair<std::string, unsigned int>> rules;

    // 3 for 2 Opera House deal
    {
        rules.push_back(std::make_pair("OH", 3));
        promoDB.addPromotion("3FOR2", rules, 300, emptyVec);
    }

    rules.clear();

    // Free Sky Tower tour with every Opera House tour
    {
        rules.push_back(std::make_pair("OH", 1));
        std::vector<std::pair<std::string, unsigned int>> freebies;
        freebies.push_back(std::make_pair("SK", 1));
        promoDB.addPromotion("OH=SK", rules, 0, freebies);
    }

    rules.clear();

    // Bulk discount on Sydney Bridge Climb
    {
        rules.push_back(std::make_pair("BC", 4));
        promoDB.addPromotion("BULK", rules, 20, emptyVec);
    }

    return promoDB;
}