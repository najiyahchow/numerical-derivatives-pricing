#ifndef MONTE_CARLO_HPP
#define MONTE_CARLO_HPP

struct MonteCarloResult
{
    double price;
    double standard_error;
};

MonteCarloResult monte_carlo_european_call(
    double spot,
    double strike,
    double rate,
    double volatility,
    double maturity,
    int simulations
);

#endif