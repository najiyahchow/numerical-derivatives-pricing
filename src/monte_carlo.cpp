#include "monte_carlo.hpp"

#include <algorithm>
#include <cmath>
#include <random>

double monte_carlo_european_call(
    double spot,
    double strike,
    double rate,
    double volatility,
    double maturity,
    int simulations
)
{
    std::mt19937 generator(42);
    std::normal_distribution<double> normal(0.0, 1.0);

    double payoff_sum = 0.0;

    for (int i = 0; i < simulations; ++i)
    {
        double z = normal(generator);

        double terminal_spot =
            spot * std::exp(
                (rate - 0.5 * volatility * volatility) * maturity
                + volatility * std::sqrt(maturity) * z
            );

        double payoff = std::max(
            terminal_spot - strike,
            0.0
        );

        payoff_sum += payoff;
    }

    double average_payoff =
        payoff_sum / simulations;

    return std::exp(-rate * maturity)
        * average_payoff;
}