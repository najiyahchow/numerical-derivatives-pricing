#ifndef BINOMIAL_HPP
#define BINOMIAL_HPP

double binomial_european_call(
    double spot,
    double strike,
    double rate,
    double volatility,
    double maturity,
    int steps
);

double binomial_american_put(
    double spot,
    double strike,
    double rate,
    double volatility,
    double maturity,
    int steps
);

#endif

