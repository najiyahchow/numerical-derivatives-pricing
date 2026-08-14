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

    MonteCarloResult result = monte_carlo_european_call(
        spot,
        strike,
        rate,
        volatility,
        maturity,
        simulations
    );

    double lower =
        result.price - 1.96 * result.standard_error;

    double upper =
        result.price + 1.96 * result.standard_error;

    std::cout
        << "Monte Carlo price: "
        << result.price
        << std::endl;

    std::cout
        << "Standard error: "
        << result.standard_error
        << std::endl;

    std::cout
        << "95% confidence interval: ["
        << lower << ", "
        << upper << "]"
        << std::endl;

    return 0;
}