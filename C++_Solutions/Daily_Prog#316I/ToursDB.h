//
// Created by Tanner on 5/24/2017.
//

#ifndef DAILY_PROG_316I_TOURSDB_H
#define DAILY_PROG_316I_TOURSDB_H

#include <map>
#include <vector>
#include <utility>
#include "Tour.h"

class ToursDB : protected std::map<std::string, Tour> {
public:

    // Constructor
    using std::map<std::string, Tour>::map;

    /**
     * Attempts to add the tour to the database. If the tour's id is already present, returns false.
     * Returns true if insertion is successful.
     *
     * @param tour to be inserted
     * @return true if insertion is successful, false if unsuccessful
     */
    bool addTour(Tour const &tour);

    // Allow access to some, but not all superclass functions

    using std::map<std::string, Tour>::find;

    using std::map<std::string, Tour>::at;

    using std::map<std::string, Tour>::operator[];

    using std::map<std::string, Tour>::erase;

    using std::map<std::string, Tour>::clear;

    using std::map<std::string, Tour>::operator=;

    using std::map<std::string, Tour>::empty;

    using std::map<std::string, Tour>::end;

    using std::map<std::string, Tour>::begin;
};


#endif //DAILY_PROG_316I_TOURSDB_H
