#ifndef BLACK_SCHOLES_HPP
#define BLACK_SCHOLES_HPP

double normal_cdf(double x);

double black_scholes_call(
    double spot,
    double strike,
    double rate,
    double volatility,
    double maturity
);

#endif