#include "monte_carlo.hpp"

#include <iostream>

int main()
{
    double spot = 100.0;
    double strike = 100.0;
    double rate = 0.05;
    double volatility = 0.20;
    double maturity = 1.0;

    int simulation_counts[] = {
        1000,
        5000,
        10000,
        50000,
        100000,
        500000,
        1000000
    };

    for (int simulations : simulation_counts)
    {
        MonteCarloResult result =
            monte_carlo_european_call(
                spot,
                strike,
                rate,
                volatility,
                maturity,
                simulations
            );

        std::cout
            << "Simulations: " << simulations
            << ", Price: " << result.price
            << ", Standard error: "
            << result.standard_error
            << std::endl;
    }

    return 0;
}