//
// Created by Tanner on 5/24/2017.
//

#ifndef DAILY_PROG_316I_TOUR_H
#define DAILY_PROG_316I_TOUR_H

#include <string>

class Tour {
public:
    Tour(std::string const &id, std::string const &name, unsigned int const &price);

    std::string getID() const { return m_id; }

    std::string getName() const { return m_name; }

    unsigned int getPrice() const { return m_price; }

private:
    std::string m_id;

    std::string m_name;

    unsigned int m_price;
};


#endif //DAILY_PROG_316I_TOUR_H
