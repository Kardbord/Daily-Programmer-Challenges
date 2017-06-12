//
// Created by Tanner on 5/24/2017.
//

#include "Cart.h"

Cart::Cart(PromoDB const &promoDB, ToursDB const &toursDB) : m_promoDB(promoDB), m_tourDB(toursDB), m_items() {}

bool Cart::addTour(Tour const &tour) {
    if (m_tourDB.find(tour.getID()) != m_tourDB.end()) {
        m_items.push_back(tour);
        return true;
    } else return false;
}

