//
// Created by Tanner on 5/24/2017.
//

#ifndef DAILY_PROG_316I_TOURSDB_H
#define DAILY_PROG_316I_TOURSDB_H

#include <map>
#include <vector>
#include <utility>
#include "Tour.h"

class ToursDB : public std::map<std::string, Tour> {
public:

    ToursDB() {}

    /**
     * Attempts to add the tour to the database. If the tour's id is already present, returns false.
     * Returns true if insertion is successful.
     *
     * @param tour to be inserted
     * @return true if insertion is successful, false if unsuccessful
     */
    bool addTour(Tour const &tour);

};


#endif //DAILY_PROG_316I_TOURSDB_H
