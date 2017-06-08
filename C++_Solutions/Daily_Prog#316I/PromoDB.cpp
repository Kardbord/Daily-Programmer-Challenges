//
// Created by Tanner on 6/1/2017.
//

#include <iostream>
#include "PromoDB.h"
#include "Utils.h"

/**
 *
 * @param toursDB is a ToursDB object. It is used to build a set of valid tour IDs that Promotions can apply to.
 * @param freebies are any free Tours to be applied to am entire cart regardless of any rules
 * @param discount is the discount to be applied to an entire cart regardless of any rules
 */
PromoDB::PromoDB(ToursDB const &toursDB, std::vector<std::pair<std::string, unsigned int>> freebies,
                 unsigned int discount) {
    std::vector<std::string> validTourKeys;

    for (auto &&tour : toursDB) {
        validTourKeys.push_back(tour.first);
    }

    Promotion promo("ALL");
    this->insert(std::make_pair(promo.getID(), promo));
    for (int i = 0; i < validTourKeys.size(); ++i) {
        this->at("ALL").addRule(validTourKeys[i], 0, freebies);
        if (discount != 0) {
            this->at("ALL").addRule(validTourKeys[i], 0, discount);
        }
    }
}

/**
 *
 * @param toursDB is a ToursDB object. It is used to build a set of valid tour IDs that Promotions can apply to.
 * @param fin is the input file through which promotions will be created and added to the PromoDB
 *
 * The input file must be formatted as follows:
 *     - One Promotion per line
 *     - Each line follows the format:
 * <number of tour_ids (keys) to expect> <promo_id> <appropriate # of tour id's> <appropriate # of amt_req values to go with the tour_ids>
 */
PromoDB::PromoDB(ToursDB const &toursDB, std::ifstream &fin, std::vector<std::pair<std::string, unsigned int>> freebies,
                 unsigned int discount) : PromoDB(toursDB, freebies, discount) {
    std::string line = "";
    std::string delimiter = " ";

    unsigned int numKeys;
    std::string promo_id;
    std::vector<std::string> tour_ids;
    std::vector<unsigned int> amts_req;

    // Create Promotions and add them to PromoDB line by line
    while (!fin.eof()) {
        tour_ids.clear();
        amts_req.clear();

        // parse inputs
        fin >> numKeys;
        fin >> promo_id;
        // TODO: unsure if I need to use fin.ignore somewhere around here or not... will find out after testing
        std::getline(fin, line);

        if (promo_id == "ALL") {
            std::cerr << "\aWarning! database key 'ALL' is reserved for PromoDB use. This promotion will be discarded."
                      << std::endl;
        } else {

            std::vector<std::string> tokens;

            try {
                // passing numKeys * 2 as expected_tokens arg because per line we have (numKeys) tour_ids and (numKeys) amts_req
                tokens = Utils::parseString(line, delimiter, numKeys * 2);
            } catch (std::invalid_argument e) {
                throw std::invalid_argument("Input file is not formatted correctly");
            }

            for (int i = 0; i < numKeys * 2; ++i) {
                if (i < numKeys) {
                    tour_ids.push_back(tokens[i]);
                } else {
                    amts_req.push_back(std::stoul(tokens[i]));
                }
            }
            // done parsing inputs


            for (int i = 0; i < numKeys; ++i) {
                if (i == 0) {
                    Promotion promo(promo_id, tour_ids[i], amts_req[i]);
                    this->insert(std::make_pair(promo.getID(), promo));
                } else {
                    this->at(promo_id).addRule(tour_ids[i], amts_req[i]);
                }
            }
        }
    }
}


