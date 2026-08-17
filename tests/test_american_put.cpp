#include "binomial.hpp"
#include "black_scholes.hpp"

#include <iostream>

int main()
{
    double strike = 100.0;
    double rate = 0.05;
    double volatility = 0.20;
    double maturity = 1.0;
    int steps = 500;

    double spot_values[] = {
        70.0,
        80.0,
        90.0,
        100.0,
        110.0,
        120.0,
        130.0
    };

    for (double spot : spot_values)
    {
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

        double premium =
            american_put - european_put;

        std::cout
            << "Spot: " << spot
            << ", American: " << american_put
            << ", European: " << european_put
            << ", Premium: " << premium
            << std::endl;
    }

    return 0;
}