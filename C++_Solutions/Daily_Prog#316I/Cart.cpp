//
// Created by Tanner on 5/24/2017.
//

#include "Cart.h"

Cart::Cart(PromoDB const &promoDB, ToursDB const &toursDB) : m_promoDB(promoDB), m_tourDB(toursDB), m_items(),
                                                             m_quantities() {}

bool Cart::addTour(Tour const &tour) {
    if (m_tourDB.find(tour.getID()) != m_tourDB.end()) {
        m_items.push_back(tour);

        auto it = m_quantities.find(tour.getID());
        if (it != m_quantities.end()) {
            it->second += 1;
        } else {
            m_quantities[tour.getID()] = 0;
        }

        return true;
    } else return false;
}

unsigned int Cart::total() {
    unsigned int total = 0;
    for (auto &&item : m_items) {
        total += item.getPrice();
    }

    for (auto &&pair : m_promoDB) {
        Promotion promo = pair.second;

        for (auto &&rule : promo.getRules()) {

        }
    }

    return total;
}

