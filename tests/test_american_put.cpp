#include "binomial.hpp"
#include "black_scholes.hpp"

#include <iostream>

int main()
{
    double spot = 100.0;
    double strike = 100.0;
    double rate = 0.05;
    double volatility = 0.20;
    double maturity = 1.0;
    int steps = 500;

    double american_put = binomial_american_put(
        spot,
        strike,
        rate,
        volatility,
        maturity,
        steps
    );

    double european_put = black_scholes_put(
        spot,
        strike,
        rate,
        volatility,
        maturity
    );

    double early_exercise_premium =
        american_put - european_put;

    std::cout
        << "American put price: "
        << american_put
        << std::endl;

    std::cout
        << "European put price: "
        << european_put
        << std::endl;

    std::cout
        << "Early-exercise premium: "
        << early_exercise_premium
        << std::endl;

    return 0;
}