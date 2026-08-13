#include "binomial.hpp"
#include "black_scholes.hpp"

#include <cmath>
#include <iostream>

int main()
{
    double spot = 100.0;
    double strike = 100.0;
    double rate = 0.05;
    double volatility = 0.20;
    double maturity = 1.0;

    double benchmark = black_scholes_call(
        spot,
        strike,
        rate,
        volatility,
        maturity
    );

    int steps_list[] = {10, 25, 50, 100, 250, 500, 1000};

    std::cout << "Black-Scholes benchmark: "
              << benchmark << "\n\n";

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

        double absolute_error = std::abs(
            price - benchmark
        );

        std::cout
            << "Steps: " << steps
            << ", Price: " << price
            << ", Absolute error: " << absolute_error
            << std::endl;
    }

    return 0;
}