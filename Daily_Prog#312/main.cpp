#include <iostream>
#include <vector>
#include <fstream>

// Function Prototypes
bool init_inputs(int const & argc, char *argv[], std::vector<long long> & inputs);
std::string compute_next_largest(long long const &input);
// END Function Prototypes

// MAIN
int main(int argc, char *argv[]) {
    std::vector<long long> inputs;
    if(!init_inputs(argc, argv, inputs)) return EXIT_FAILURE;

    if (inputs.size() != 0) {
        // TODO: input file present, evaluate given values and then ask for input
    }

    // TODO: ask for user input

    return EXIT_SUCCESS;
} // END MAIN

bool init_inputs(int const & argc, char *argv[], std::vector<long long> & inputs) {
    if (argc > 2) {
        std::cerr << "Too many command line arguments provided -- expected 1" << std::endl;
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
        if (inputs[i] < 0) {
            std::cerr << "Error! One or more input values were negative, program terminated." << std::endl;
            return false;
        }

        if ((double) inputs[i] / INT64_MAX  >= 0.85) {
            std::cout << "\aWarning! Input integer is very large, possibly resulting in overflow.\n"
                    << "Results may be inaccurate." << std::endl;
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
std::string compute_next_largest(long long const &input) {

}
