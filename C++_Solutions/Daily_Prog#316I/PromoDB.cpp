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
        if (freebies.empty()) {
            if (discount == 0) {
                this->at("ALL").addRule(validTourKeys[i], 0, 1);
                this->at("ALL").updateDiscount(0);
            } else {
                this->at("ALL").addRule(validTourKeys[i], 0, discount);
            }
        } else {
            this->at("ALL").addRule(validTourKeys[i], 0, freebies);
        }
    }
}

/**
 *
 * @param promo_id is the unique ID of the Promotion
 * @param rules is a vector where each entry contains the id and quantity of that tour that must be present
 * @param discount is the discount to be applied if the rules are met
 * @param freebies are the freebies to be applied if the rules are met
 * @return true if the Promotion was successfully added to the database, false otherwise
 */
bool PromoDB::addPromotion(std::string const &promo_id, std::vector<std::pair<std::string, unsigned int>> const &rules,
                           unsigned int discount, std::vector<std::pair<std::string, unsigned int>> const &freebies) {

    Promotion newPromo(promo_id);

    for (auto &&tour_qty_pair : rules) {
        if (freebies.empty()) {
            newPromo.addRule(tour_qty_pair.first, tour_qty_pair.second, discount);
        } else {
            newPromo.addRule(tour_qty_pair.first, tour_qty_pair.second, freebies);
        }
    }

    return this->insert(std::make_pair(promo_id, newPromo)).second;
}


