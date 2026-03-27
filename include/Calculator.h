#pragma once
class Calculator
{
public:
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);

    double power(double base, double exponent);
    long long factorial(int n);
    bool isPrime(int n);
};
