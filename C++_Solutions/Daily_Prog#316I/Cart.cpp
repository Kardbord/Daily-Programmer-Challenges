//
// Created by Tanner on 5/24/2017.
//

#include "Cart.h"

Cart::Cart(PromoDB const &promoDB, ToursDB const &toursDB) : m_promoDB(promoDB), m_tourDB(toursDB), m_items(),
                                                             m_quantities() {}

bool Cart::addTour(std::string const &tour_id) {
    if (m_tourDB.find(tour_id) != m_tourDB.end()) {
        m_items.push_back(m_tourDB.at(tour_id)); // This compiles fine.

        auto it = m_quantities.find(tour_id);
        if (it != m_quantities.end()) {
            it->second += 1;
        } else {
            m_quantities[tour_id] = 0;
        }

        return true;
    } else return false;
}

unsigned int Cart::total() const {
    unsigned int total = 0;
    for (auto &&item : m_items) {
        total += item.getPrice();
    }

    for (auto &&pair : m_promoDB) {
        if (promoApplies(pair.second)) {
            total -= pair.second.getDiscountValue();
        }
    }

    return total;
}

void Cart::printOrder(std::ostream &out) const {
    out << "***Receipt***" << std::endl << std::endl;
    out << "Items:" << std::endl;

    for (auto &&item : m_items) {
        out << item.getID() << " ";
    }

    out << std::endl << std::endl << "Free Items:" << std::endl;

    for (auto &&pair : m_promoDB) {
        if (promoApplies(pair.second)) {

            for (auto &&freebie : pair.second.getFreebies()) {
                out << freebie.first << "x" << freebie.second << " ";
            }

        }
    }

    out << std::endl << std::endl << "Total: " << total() << std::endl << std::endl;

}

bool Cart::promoApplies(Promotion const &promo) const {

    for (auto &&rule : promo.getRules()) {
        auto it = m_quantities.find(rule.first);
        if (it != m_quantities.end()) {
            if (it->second != rule.second) {
                return false;
            }
        } else {
            return false;
        }
    }
    return true;
}


