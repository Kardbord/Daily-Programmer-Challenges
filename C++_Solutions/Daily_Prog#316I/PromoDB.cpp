//
// Created by Tanner on 6/1/2017.
//

#include <iostream>
#include "PromoDB.h"

/**
 *
 * @param toursDB is a ToursDB object. It is used to build a set of valid tour IDs that Promotions can apply to.
 * @param freebies are any free Tours to be applied to am entire cart regardless of any rules
 * @param discount is the discount to be applied to an entire cart regardless of any rules
 */
PromoDB::PromoDB(ToursDB const &toursDB, std::vector<std::pair<std::string, unsigned int>> freebies,
                 unsigned int discount) {
    std::vector<std::string> validTourKeys;

    for (auto &&tour : toursDB) {
        validTourKeys.push_back(tour.first);
    }

    Promotion promo("ALL");
    this->insert(std::make_pair(promo.getID(), promo));
    for (int i = 0; i < validTourKeys.size(); ++i) {
        this->at("ALL").addRule(validTourKeys[i], 0, freebies);
        if (discount != 0) {
            this->at("ALL").addRule(validTourKeys[i], 0, discount);
        }
    }
}


