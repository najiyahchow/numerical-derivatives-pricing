#include "black_scholes.hpp"

#include <cmath>
#include <iostream>

int main()
{
    double spot = 100.0;
    double strike = 100.0;
    double rate = 0.05;
    double volatility = 0.20;
    double maturity = 1.0;

    double call_price = black_scholes_call(
        spot,
        strike,
        rate,
        volatility,
        maturity
    );

    double put_price = black_scholes_put(
        spot,
        strike,
        rate,
        volatility,
        maturity
    );

    std::cout << "Black-Scholes call price: "
              << call_price
              << std::endl;

    std::cout << "Black-Scholes put price: "
              << put_price
              << std::endl;

    double parity_left = call_price - put_price;
    double parity_right =
        spot - strike * std::exp(-rate * maturity);

    std::cout << "Put-call parity difference: "
              << parity_left - parity_right
              << std::endl;

    return 0;
}