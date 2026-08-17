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

double binomial_american_put(
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
        (std::exp(rate * dt) - down)
        / (up - down);

    std::vector<double> option_values(
        steps + 1
    );

    // Payoff at maturity
    for (int i = 0; i <= steps; ++i)
    {
        double terminal_spot =
            spot
            * std::pow(up, steps - i)
            * std::pow(down, i);

        option_values[i] = std::max(
            strike - terminal_spot,
            0.0
        );
    }

    // Work backwards through the tree
    for (int step = steps - 1; step >= 0; --step)
    {
        for (int i = 0; i <= step; ++i)
        {
            double current_spot =
                spot
                * std::pow(up, step - i)
                * std::pow(down, i);

            double continuation_value =
                discount
                * (
                    probability * option_values[i]
                    + (1.0 - probability)
                    * option_values[i + 1]
                );

            double exercise_value =
                std::max(
                    strike - current_spot,
                    0.0
                );

            option_values[i] = std::max(
                continuation_value,
                exercise_value
            );
        }
    }

    return option_values[0];
}