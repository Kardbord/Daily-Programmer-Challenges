#include <iostream>

int main(int argc, char *argv[]) {
    if (argc > 2) {
        std::cerr << "Too many program arguments provided -- expected 1" << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}