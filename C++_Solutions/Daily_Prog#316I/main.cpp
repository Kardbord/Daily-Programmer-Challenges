#include <iostream>
#include "ToursDB.h"
#include "PromoDB.h"
#include "Cart.h"
#include "Utils.h"

/*
 * Created by Tanner
 */

ToursDB initTourDatabase();
PromoDB initPromotionDatabase(ToursDB const &toursDB);

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        std::cerr << "Incorrect number of command line arguments -- expected 1 to 2" << std::endl;
        return EXIT_FAILURE;
    }

    std::ifstream fin(argv[1]);
    if (!fin) {
        std::cerr << "Could not open input file" << std::endl;
        return EXIT_FAILURE;
    }

    ToursDB toursDB = initTourDatabase();
    PromoDB promoDB = initPromotionDatabase(toursDB);
    std::ofstream fout;
    if (argc == 3) {
        fout.open(argv[2]);
    }


    std::string line = "";
    while (std::getline(fin, line)) {
        Cart cart(promoDB, toursDB);
        for (auto && token : Utils::parseString(line, " ")) {
            cart.addTour(token);
        }

        if (argc == 2) {
            cart.printOrder(std::cout);
        } else if (argc == 3) {
            cart.printOrder(fout);
        }
    }

    fin.close();
    fout.close();
    return EXIT_SUCCESS;
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
        promoDB.addPromotion("BULK", rules, 20, emptyVec, true);
    }

    return promoDB;
}