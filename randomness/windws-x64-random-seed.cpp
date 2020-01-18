/*
This is a small sample for a working random number generator seed.

Credit to the second response in this post: https://stackoverflow.com/questions/9878965/rand-between-0-and-1

*/

#include <iostream>
#include <random>
#include <chrono>


int main() {

    std::mt19937_64 eng;
    
    // I have no idea, but it does a great job of seeding.
    std::uint64_t t_seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::seed_seq ss{std::uint32_t(t_seed & 0xffffffff), std::uint32_t(t_seed >> 32)};
    
    // Seed our engine.
    eng.seed(ss);
    
    // This example goes from zero (inclusive) to 1 (exclusive). The range can be adjusted to suit your needs.
    std::uniform_real_distribution<double> urd(0, 1);
    
    const int MAX_ITERS = 10;
    int i = 0;
    double randn;
    
    while (i < MAX_ITERS) {
        ++i;
        randn = urd(rng);
        std::cout << "Random number: " << randn << std::endl;
    }
}
