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

// TODO: update this class to be consistent with the new addRule functions in Promotion.h

class PromoDB : protected std::map<std::string, Promotion> {
public:

    /**
     *
     * @param toursDB is a ToursDB object. It is used to build a set of valid tour IDs that Promotions can apply to.
     * @param freebies are any free Tours to be applied to am entire cart regardless of any rules
     * @param discount is the discount to be applied to an entire cart regardless of any rules
     */
    PromoDB(ToursDB const &toursDB, std::vector<std::pair<std::string, unsigned int>> freebies, unsigned int discount);

};


#endif //DAILY_PROG_316I_PROMODB_H
