#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

// Function Prototypes
bool init_inputs(int const &argc, char *argv[], std::vector<std::string> &inputs);
std::string compute_next_largest(std::string const &input);
void swap(std::string &container, int const &index1, int const &index2);
bool validateInput(std::string const &input);
// END Function Prototypes

// MAIN
int main(int argc, char *argv[]) {
    std::vector<std::string> inputs;
    if (!init_inputs(argc, argv, inputs)) return EXIT_FAILURE;

    if (inputs.size() != 0) {
        // TODO: input file present, evaluate given values and then ask for input
    }

    // TODO: ask for user input

    return EXIT_SUCCESS;
} // END MAIN

bool init_inputs(int const &argc, char *argv[], std::vector<std::string> &inputs) {
    if (argc > 2) {
        std::cerr << "Too many command line arguments provided -- expected 0 or 1" << std::endl;
        return false;
    }

    // if no cmd line args provided
    if (argc < 2) return true;

    // if input file provided
    std::ifstream fin(argv[1]);
    if (!fin) {
        std::cerr << "Error opening " << argv[1] << ", program terminated" << std::endl;
        return false;
    }

    // read in file
    for (int i = 0; fin >> inputs[i]; ++i) {
        if (!validateInput(inputs[i])) {
            return false;
        }
    }
    return true;
}

/**
 * Computes the next largest number using only the digits available
 *
 * @param input
 * @return next largest number using only the digits contained in 'input'
 */
std::string compute_next_largest(std::string const &input) {
    std::string nextLargest = input;

    /*
     * Yes, I know this is confusing, but it's cool dang it.
     * The for loop contains an anonymous struct so I can initialize variables of multiple types for use in the loop
     * See http://stackoverflow.com/questions/11255684/why-c-does-not-support-multiple-initializers-in-for-loop
     */
    for (struct { int index; bool swapped; } loopVars = {(int) nextLargest.size() - 1, false};
         !loopVars.swapped; --loopVars.index) {

        for (int j = 1; !loopVars.swapped && j <= loopVars.index; ++j) {
            if (nextLargest[loopVars.index] != '0') {
                if (nextLargest[loopVars.index] > nextLargest[loopVars.index - j]) {
                    swap(nextLargest, loopVars.index, loopVars.index - j);
                    loopVars.swapped = true;
                }
            }
        }
    }

    return nextLargest;
}

void swap(std::string &container, int const &index1, int const &index2) {
    auto temp = container[index1];
    container[index1] = container[index2];
    container[index2] = temp;
}

bool validateInput(std::string const &input) {
    double d_input = std::stod(input);

    if (d_input < 0) {
        std::cerr << "Error! One negative input value present, program terminated." << std::endl;
        return false;
    }

    if (d_input != std::floor(d_input)) {
        std::cerr << "Error! Non-whole number input present, program terminated" << std::endl;
        return false;
    }

    if (d_input / INT64_MAX >= 0.85) {
        std::cout << "\aWarning! Input integer is very large, possibly resulting in overflow.\n"
                  << "Results may be inaccurate." << std::endl;
    }

    return true;
}
