#include <iostream>
#include <vector>
#include <fstream>

// Function Prototypes
bool init_inputs(int const & argc, char *argv[], std::vector<long long> & inputs);
// END Function Prototypes

// MAIN
int main(int argc, char *argv[]) {
    std::vector<long long> inputs;
    if(!init_inputs(argc, argv, inputs)) return EXIT_FAILURE;

    return EXIT_SUCCESS;
} // END MAIN

bool init_inputs(int const & argc, char *argv[], std::vector<long long> & inputs) {
    if (argc > 2) {
        std::cerr << "Too many command line arguments provided -- expected 1" << std::endl;
        return false;
    }

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