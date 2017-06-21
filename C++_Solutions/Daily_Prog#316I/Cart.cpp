//
// Created by Tanner on 5/24/2017.
//

#include <cmath>
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
            m_quantities[tour_id] = 1;
        }

        return true;
    } else return false;
}

unsigned int Cart::total() const {
    unsigned int total = 0;
    for (auto &&item : m_items) {
        total += item.getPrice();
    }

    for (auto &&id_promo_pair : m_promoDB) {
        if (promoApplies(id_promo_pair.second)) {
            total -= id_promo_pair.second.getDiscount();

            for (auto && freebie : id_promo_pair.second.getFreebies()) {

                int itemCount = 0;

                for (auto &&item : m_items) {
                    if (item.getID() == freebie.first) {
                        ++itemCount;
                    }
                }

                total -= itemCount * m_tourDB.at(freebie.first).getPrice();

            }


            // req_ids are the ids of tours that must be present. For every one of the tours present in the cart with
            // the proper id, the discountPerItem must be applied.
            std::vector<std::string> req_ids;
            for (auto &&rule : id_promo_pair.second.getRules()) {
                req_ids.push_back(rule.first);
            }

            for (auto &&tour : m_items) {
                for (auto &&id : req_ids) {
                    if (tour.getID() == id) {
                        total -= id_promo_pair.second.getDiscountPerItem();
                        break;
                    }
                }
            }
        }
    }

    return total;
}

void Cart::printOrder(std::ostream &out) const {
    out << "****************************************" << std::endl;
    out << "\t\t\t\tReceipt" << std::endl << std::endl;
    out << "Items:" << std::endl;

    for (auto &&item : m_items) {
        out << item.getID() << " ";
    }

    out << std::endl << std::endl << "Free Items:" << std::endl;

    int numFreebies = 1;

    for (auto &&pair : m_promoDB) {
        if (promoApplies(pair.second, numFreebies)) {

            for (auto &&freebie : pair.second.getFreebies()) {
                out << freebie.first << "x" << freebie.second * numFreebies << " ";
            }

        }
    }

    out << std::endl << std::endl << "Total: " << total() << std::endl << std::endl;
    out << "****************************************" << std::endl << std::endl;

}

bool Cart::promoApplies(Promotion const &promo, int & numFreebies) const {

    for (auto &&rule : promo.getRules()) {
        auto it = m_quantities.find(rule.first);
        if (it != m_quantities.end()) {
            if (it->second < rule.second) {
                return false;
            } else if (it->second != 0 && rule.second != 0) numFreebies = it->second / rule.second;
        } else {
            return false;
        }
    }


    return true;
}

bool Cart::promoApplies(Promotion const &promo) const {

    for (auto &&rule : promo.getRules()) {
        auto it = m_quantities.find(rule.first);
        if (it != m_quantities.end()) {
            if (it->second < rule.second) {
                return false;
            }
        } else {
            return false;
        }
    }


    return true;
}


