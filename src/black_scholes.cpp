#include "black_scholes.hpp"

#include <cmath>

double normal_cdf(double x)
{
    return 0.5 * std::erfc(-x / std::sqrt(2.0));
}

double black_scholes_call(
    double spot,
    double strike,
    double rate,
    double volatility,
    double maturity
)
{
    double d1 =
        (
            std::log(spot / strike)
            + (rate + 0.5 * volatility * volatility) * maturity
        )
        / (volatility * std::sqrt(maturity));

    double d2 =
        d1 - volatility * std::sqrt(maturity);

    return (
        spot * normal_cdf(d1)
        - strike * std::exp(-rate * maturity) * normal_cdf(d2)
    );
}

double black_scholes_put(
    double spot,
    double strike,
    double rate,
    double volatility,
    double maturity
)
{
    double d1 =
        (
            std::log(spot / strike)
            + (rate + 0.5 * volatility * volatility) * maturity
        )
        / (volatility * std::sqrt(maturity));

    double d2 =
        d1 - volatility * std::sqrt(maturity);

    return (
        strike * std::exp(-rate * maturity) * normal_cdf(-d2)
        - spot * normal_cdf(-d1)
    );
}