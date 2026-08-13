#include "monte_carlo.hpp"

#include <iostream>

int main()
{
    double spot = 100.0;
    double strike = 100.0;
    double rate = 0.05;
    double volatility = 0.20;
    double maturity = 1.0;

    int simulations = 100000;

    double price = monte_carlo_european_call(
        spot,
        strike,
        rate,
        volatility,
        maturity,
        simulations
    );

    std::cout
        << "Monte Carlo call price: "
        << price
        << std::endl;

    return 0;
}