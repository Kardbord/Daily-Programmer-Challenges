#include <iostream>
#include <cstdlib>
#include <string>
#include <regex>
#include <stack>

// Matches any characters not included in the list
// so any characters that are not '[', ']', '{', '}', '(', ')'
const std::string REGEX_PATTERN = "[^\\[\\]\\{\\}\\(\\)]";

bool stringIsValid(std::string const & input) {
    // Check to see if @input contains any invalid characters
    std::regex e(REGEX_PATTERN);
    if (std::regex_search(input, e)) return false;

    // Check that the characters in @input are in a valid order
    std::stack<char> stack;
    for (const char c : input) {
        switch (c) {
            case '}':
                if (stack.empty() || stack.top() != '{') return false;
                stack.pop();
                break;
            case ')':
                if (stack.empty() || stack.top() != '(') return false;
                stack.pop();
                break;
            case ']':
                if (stack.empty() || stack.top() != '[') return false;
                stack.pop();
                break;
            default:
                stack.push(c);
                break;
        }
    }

    // If stack is empty, all symbols were resolved
    // If stack is not empty, there are unclosed symbols
    return stack.empty();
}

// This program takes a string for a command line argument
// The string should contain only the characters '{' '}' '(' ')' '[' ']'
// The program then determines if the string is 'valid'
// A string is 'valid' if it contains only the designated characters,
// and if the designated characters open and close correctly.
// E.G. "({[]})", "(({}{()})[])" are valid strings
// whereas "())" "{}([)]" "{{}" are not valid
int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "No command line arguments provided.\n"
                  << "Please provide a string containing only the following characters\n"
                  << "'{', '}', '[', ']', '(', ')'"
                  << std::endl;
        return EXIT_FAILURE;
    }

    std::string input(argv[1]);

    if (stringIsValid(input)) {
        std::cout << "Input string is valid" << std::endl;
    } else {
        std::cout << "Input string is invalid" << std::endl;
    }

    return EXIT_SUCCESS;
}
