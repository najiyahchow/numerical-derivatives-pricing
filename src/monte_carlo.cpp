#include "monte_carlo.hpp"

#include <algorithm>
#include <cmath>
#include <random>

MonteCarloResult monte_carlo_european_call(
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
    double payoff_squared_sum = 0.0;

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
        payoff_squared_sum += payoff * payoff;
    }

    double mean_payoff =
        payoff_sum / simulations;

    double payoff_variance =
        (
            payoff_squared_sum
            - simulations * mean_payoff * mean_payoff
        )
        / (simulations - 1);

    double discount =
        std::exp(-rate * maturity);

    double price =
        discount * mean_payoff;

    double standard_error =
        discount
        * std::sqrt(payoff_variance / simulations);

    return {price, standard_error};
}