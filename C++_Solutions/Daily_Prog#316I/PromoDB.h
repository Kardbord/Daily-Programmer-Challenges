//
// Created by Tanner on 6/1/2017.
//

#ifndef DAILY_PROG_316I_PROMODB_H
#define DAILY_PROG_316I_PROMODB_H

#include <map>
#include "Promotion.h"
#include "ToursDB.h"
#include <fstream>
#include <vector>

class PromoDB : protected std::map<std::string, Promotion> {
public:

    /**
     *
     * @param toursDB is a ToursDB object. It is used to build a set of valid tour IDs that Promotions can apply to.
     * @param freebies are any free Tours to be applied to am entire cart regardless of any rules
     * @param discount is the discount to be applied to an entire cart regardless of any rules
     */
    PromoDB(ToursDB const &toursDB, std::vector<std::pair<std::string, unsigned int>> freebies, unsigned int discount);

    /**
     *
     * @param promo_id is the unique ID of the Promotion
     * @param rules is a vector where each entry contains the id and quantity of that tour that must be present
     * @param discount is the discount to be applied if the rules are met
     * @param freebies are the freebies to be applied if the rules are met
     * @return true if the Promotion was successfully added to the database, false otherwise
     */
    bool addPromotion(std::string const &promo_id, std::vector<std::pair<std::string, unsigned int>> const &rules,
                      unsigned int discount, std::vector<std::pair<std::string, unsigned int>> const &freebies);

    // Allow access to some, but not all superclass functions

    using std::map<std::string, Promotion>::find;

    using std::map<std::string, Promotion>::at;

    using std::map<std::string, Promotion>::operator[];

    using std::map<std::string, Promotion>::erase;

    using std::map<std::string, Promotion>::clear;

    using std::map<std::string, Promotion>::operator=;

    using std::map<std::string, Promotion>::empty;

    using std::map<std::string, Promotion>::end;

    using std::map<std::string, Promotion>::begin;
};


#endif //DAILY_PROG_316I_PROMODB_H
