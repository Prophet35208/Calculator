#include "Calculator.h"
#include <iostream>
#include <string>
#include <limits>

void printMenu()
{
    std::cout << "\nMenu" << std::endl;
    std::cout << "1. Add" << std::endl;
    std::cout << "2. Subtract" << std::endl;
    std::cout << "3. Multiply" << std::endl;
    std::cout << "4. Divide" << std::endl;
    std::cout << "5. Power" << std::endl;
    std::cout << "6. Factorial" << std::endl;
    std::cout << "7. Check Prime" << std::endl;
    std::cout << "8. Exit" << std::endl;
    std::cout << "Choose operation (1-8): ";
}

int main()
{
    Calculator calc;
    int choice;
    double a, b;
    int n;

    std::cout << "Welcome to calculator!" << std::endl;

    while (true)
    {
        printMenu();
        std::cin >> choice;

        if (choice == 8)
        {
            std::cout << "Goodbye!" << std::endl;
            break;
        }

        try
        {
            switch (choice)
            {
            case 1:
                std::cout << "Enter two numbers: ";
                std::cin >> a >> b;
                std::cout << a << " + " << b << " = " << calc.add(a, b) << std::endl;
                break;

            case 2:
                std::cout << "Enter two numbers: ";
                std::cin >> a >> b;
                std::cout << a << " - " << b << " = " << calc.subtract(a, b) << std::endl;
                break;

            case 3:
                std::cout << "Enter two numbers: ";
                std::cin >> a >> b;
                std::cout << a << " * " << b << " = " << calc.multiply(a, b) << std::endl;
                break;

            case 4:
                std::cout << "Enter two numbers: ";
                std::cin >> a >> b;
                std::cout << a << " / " << b << " = " << calc.divide(a, b) << std::endl;
                break;

            case 5:
                std::cout << "Enter base and exponent: ";
                std::cin >> a >> b;
                std::cout << a << "^" << b << " = " << calc.power(a, b) << std::endl;
                break;

            case 6:
                std::cout << "Enter a non-negative integer: ";
                std::cin >> n;
                std::cout << n << "! = " << calc.factorial(n) << std::endl;
                break;

            case 7:
                std::cout << "Enter an integer: ";
                std::cin >> n;
                std::cout << n << (calc.isPrime(n) ? " is prime" : " is not prime") << std::endl;
                break;

            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
            }
        }
        catch (const std::exception &e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }

        // Очистка буфера ввода
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return 0;
}