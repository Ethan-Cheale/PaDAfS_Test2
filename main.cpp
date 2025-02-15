#include <iostream>
#include <string>
#include "system.h"


/**
 * @brief Entry point of the program.
 *
 * This function initializes the program and manages execution.
 */
int main(int argc, char* argv[]) {
    // number of disks
    int N = std::stof(argv[1]);
    double maxDisplacement  = std::stof(argv[2]);
    double dt = std::stof(argv[3]);
    double X = std::stof(argv[4]);
    double Y = std::stof(argv[5]);

    // initialise the system
    System system(N, maxDisplacement, dt, X, Y, 1234);

    // total number of iterations
    int iterations = N*500;

    for (int i = 0; i < iterations; ++i) {
        // move one disk
        system.step();
        // save a configuration
        system.save("confs/conf"+std::to_string(i));
    }
    return 0;
}