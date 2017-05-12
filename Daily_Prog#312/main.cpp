#include <iostream>
#include <vector>
#include <fstream>

// Function Prototypes
bool init_inputs(int const & argc, char *argv[], std::vector<int> & inputs);
// END Function Prototypes

// MAIN
int main(int argc, char *argv[]) {
    std::vector<int> inputs;
    if(!init_inputs(argc, argv, inputs)) return EXIT_FAILURE;

    return EXIT_SUCCESS;
} // END MAIN

bool init_inputs(int const & argc, char *argv[], std::vector<int> & inputs) {
    if (argc > 2) {
        std::cerr << "Too many command line arguments provided -- expected 1" << std::endl;
        return false;
    }

    std::ifstream fin(argv[1]);
    if (!fin) {
        std::cerr << "Error opening " << argv[1] << " , terminating program" << std::endl;
        return false;
    }

    // read in file
    for (int i = 0; fin >> inputs[i]; ++i);
    return true;
}