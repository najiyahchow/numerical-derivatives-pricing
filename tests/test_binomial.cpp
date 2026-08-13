#include "binomial.hpp"

#include <iostream>

int main()
{
    double spot = 100.0;
    double strike = 100.0;
    double rate = 0.05;
    double volatility = 0.20;
    double maturity = 1.0;

    int steps_list[] = {10, 25, 50, 100, 250, 500, 1000};

    for (int steps : steps_list)
    {
        double price = binomial_european_call(
            spot,
            strike,
            rate,
            volatility,
            maturity,
            steps
        );

        std::cout
            << "Steps: " << steps
            << ", Price: " << price
            << std::endl;
    }

    return 0;
}