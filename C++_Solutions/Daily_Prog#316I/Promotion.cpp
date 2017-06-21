//
// Created by Tanner on 5/24/2017.
//

#include "Promotion.h"

Promotion::Promotion(std::string const &promo_id)
        : m_rules(), m_promo_id(promo_id), m_discount(0), m_discount_per_item(0), m_freebies() {

    if (promo_id == "" || m_promo_id == "") {
        throw std::invalid_argument("promo_id cannot be an empty string");
    }
}

bool Promotion::addRule(std::string const &tour_id, unsigned int const &amt_req, unsigned int const &discount,
                        bool const discountIsPerItem) {
    if (tour_id == "") {
        throw std::invalid_argument("tour_id cannot be an empty string");
    }

    if (discount == 0) {
        throw std::invalid_argument("discount must be greater than 0");
    }

    if (m_rules.insert(std::make_pair(tour_id, amt_req)).second) {
        if (discountIsPerItem) {
            m_discount_per_item = discount;
        } else m_discount += discount;
        return true;
    } else return false;
}

bool Promotion::addRule(std::string const &tour_id, unsigned int const &amt_req,
                        std::vector<std::pair<std::string, unsigned int>> const &freebies) {
    if (tour_id == "") {
        throw std::invalid_argument("tour_id cannot be an empty string");
    }

    if (freebies.empty()) {
        throw std::invalid_argument("'freebies' vector cannot be empty");
    }

    if (m_rules.insert(std::make_pair(tour_id, amt_req)).second) {
        for (auto &&pair : freebies) {
            m_freebies.push_back(pair);
        }
        return true;
    } else return false;
}

void Promotion::updateDiscount(unsigned int const &newDiscount) {
    m_discount = newDiscount;
}

void Promotion::modifyDiscount(int const &modAmt) {
    if (modAmt < 0 && std::abs(modAmt) > m_discount) {
        m_discount = 0;
    } else m_discount += modAmt;
}

void Promotion::updateDiscountPerItem(unsigned int const &newDiscount) {
    m_discount_per_item = newDiscount;
}

void Promotion::modifyDiscountPerItem(int const &modAmt) {
    if (modAmt < 0 && std::abs(modAmt) > m_discount_per_item) {
        m_discount_per_item = 0;
    } else m_discount_per_item += modAmt;
}
