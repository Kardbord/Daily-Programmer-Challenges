#include <iostream>
#include "ToursDB.h"

int main() {
    ToursDB toursDB;

    Tour tour("OH", "asdf", 200);

    toursDB.addTour(tour);
}