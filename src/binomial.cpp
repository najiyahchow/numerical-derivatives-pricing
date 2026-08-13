#include "binomial.hpp"

#include <algorithm>
#include <cmath>
#include <vector>

double binomial_european_call(
    double spot,
    double strike,
    double rate,
    double volatility,
    double maturity,
    int steps
)
{
    double dt = maturity / steps;

    double up = std::exp(
        volatility * std::sqrt(dt)
    );

    double down = 1.0 / up;

    double discount = std::exp(-rate * dt);

    double probability =
        (
            std::exp(rate * dt) - down
        )
        / (up - down);

    std::vector<double> option_values(
        steps + 1
    );

    for (int i = 0; i <= steps; ++i)
    {
        double terminal_spot =
            spot
            * std::pow(up, steps - i)
            * std::pow(down, i);

        option_values[i] = std::max(
            terminal_spot - strike,
            0.0
        );
    }

    for (int step = steps - 1; step >= 0; --step)
    {
        for (int i = 0; i <= step; ++i)
        {
            option_values[i] =
                discount
                * (
                    probability * option_values[i]
                    + (1.0 - probability)
                    * option_values[i + 1]
                );
        }
    }

    return option_values[0];
}