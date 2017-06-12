//
// Created by Tanner on 6/1/2017.
//

#ifndef DAILY_PROG_316I_UTILS_H
#define DAILY_PROG_316I_UTILS_H

#include <string>
#include <vector>

class Utils {
public:

    /**
     * Adapted from stack overflow: https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
     *
     * Parses a string based on a provided delimiter, and returns a vector containing the parsed tokens
     *
     * @param s is the string to be parsed
     * @param delim is the delimiter by which %s will be parsed
     * @return a vector containing the parsed tokens, minus the delimiter
     */
    static std::vector<std::string> parseString(std::string s, std::string const &delim, int const expected_tokens);

    /**
     * A less secure overload of the parseString method that does not require expected tokens
     *
     * @param s is the string to be parsed
     * @param delim is the delimiter by which %s will be parsed
     * @return
     */
    static std::vector<std::string> parseString(std::string s, std::string const &delim);

private:
    Utils() {}

};


#endif //DAILY_PROG_316I_UTILS_H
