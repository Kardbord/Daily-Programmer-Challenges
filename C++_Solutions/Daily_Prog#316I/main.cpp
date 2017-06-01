#include <iostream>
#include "ToursDB.h"

// TODO: provide database inputs via cmd line args
// TODO: take tour id's via user input when building a cart

int main() {
    ToursDB toursDB;

    Tour tour("OH", "asdf", 200);

    toursDB.addTour(tour);
}