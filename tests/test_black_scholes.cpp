#include "black_scholes.hpp"

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

    std::cout << "Black-Scholes call price: "
              << call_price
              << std::endl;

    return 0;
}