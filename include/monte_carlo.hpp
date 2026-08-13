#ifndef MONTE_CARLO_HPP
#define MONTE_CARLO_HPP

double monte_carlo_european_call(
    double spot,
    double strike,
    double rate,
    double volatility,
    double maturity,
    int simulations
);

#endif