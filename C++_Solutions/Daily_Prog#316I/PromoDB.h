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

// TODO: a thing

class PromoDB : protected std::map<std::string, Promotion> {
public:
    PromoDB(ToursDB const &toursDB);

    /**
     * @param fin is the input file through which promotions will be created and added to the PromoDB
     *
     * The input file must be formatted as follows:
     *     - One Promotion per line
     *     - Each line follows the format:
     *         <promo_id> <number of tour_id's (keys) to expect> <appropriate number of tour id's> <appropriate number of amt_req values to go with the tour_ids>
     */
    PromoDB(ToursDB const &toursDB, std::ifstream &fin);

};


#endif //DAILY_PROG_316I_PROMODB_H
