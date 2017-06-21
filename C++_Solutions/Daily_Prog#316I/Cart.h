//
// Created by Tanner on 5/24/2017.
//

#ifndef DAILY_PROG_316I_CART_H
#define DAILY_PROG_316I_CART_H

#include "PromoDB.h"
#include "ToursDB.h"

class Cart {
public:

    Cart(PromoDB const &promoDB, ToursDB const &tourDB);

    bool addTour(std::string const &tour_id);

    unsigned int total() const;

    void printOrder(std::ostream &out) const;

private:
    std::vector<Tour> m_items;

    /**
     * Map object where the key is a Tour id and the value is the quantity of that tour present in the cart
     */
    std::map<std::string, unsigned int> m_quantities;

    PromoDB m_promoDB;

    ToursDB m_tourDB;

    bool promoApplies(Promotion const &promo, int & numFreebies) const;

    bool promoApplies(Promotion const &promo) const;
};


#endif //DAILY_PROG_316I_CART_H
