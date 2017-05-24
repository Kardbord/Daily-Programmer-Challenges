//
// Created by Tanner on 5/24/2017.
//

#include "ToursDB.h"

bool ToursDB::addTour(Tour const &tour) {
    return insert(std::make_pair(tour.getID(), tour)).second;
}
