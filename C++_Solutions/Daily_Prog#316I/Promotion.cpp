//
// Created by Tanner on 5/24/2017.
//

#include "Promotion.h"

Promotion::Promotion(std::string const &tour_id, unsigned int const &amt_req) : m_rules() {
    if (tour_id == "") {
        throw std::invalid_argument("tour_id cannot be an empty string");
    }

    m_rules[tour_id] = amt_req;
}

bool Promotion::addRule(std::string const &tour_id, unsigned int const &amt_req) {
    if (tour_id == "") {
        throw std::invalid_argument("tour_id cannot be an empty string");
    }

    return m_rules.insert(std::make_pair(tour_id, amt_req)).second;
}
