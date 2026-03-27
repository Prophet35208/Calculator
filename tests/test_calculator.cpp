#include <gtest/gtest.h>
#include "Calculator.h"

class CalculatorTest : public ::testing::Test
{
protected:
    Calculator calc;
};

// ����� ��� ��������
TEST_F(CalculatorTest, AddPositiveNumbers)
{
    EXPECT_DOUBLE_EQ(calc.add(2, 3), 5);
    EXPECT_DOUBLE_EQ(calc.add(10, 20), 30);
}

TEST_F(CalculatorTest, AddNegativeNumbers)
{
    EXPECT_DOUBLE_EQ(calc.add(-2, -3), -5);
    EXPECT_DOUBLE_EQ(calc.add(-10, 5), -5);
}

TEST_F(CalculatorTest, AddZero)
{
    EXPECT_DOUBLE_EQ(calc.add(5, 0), 5);
    EXPECT_DOUBLE_EQ(calc.add(0, 5), 5);
    EXPECT_DOUBLE_EQ(calc.add(0, 0), 0);
}

// ����� ��� ���������
TEST_F(CalculatorTest, SubtractPositiveNumbers)
{
    EXPECT_DOUBLE_EQ(calc.subtract(5, 3), 2);
    EXPECT_DOUBLE_EQ(calc.subtract(10, 4), 6);
}

TEST_F(CalculatorTest, SubtractNegativeNumbers)
{
    EXPECT_DOUBLE_EQ(calc.subtract(-5, -3), -2);
    EXPECT_DOUBLE_EQ(calc.subtract(5, -3), 8);
}

// ����� ��� ���������
TEST_F(CalculatorTest, MultiplyPositiveNumbers)
{
    EXPECT_DOUBLE_EQ(calc.multiply(2, 3), 6);
    EXPECT_DOUBLE_EQ(calc.multiply(4, 5), 20);
}

TEST_F(CalculatorTest, MultiplyByZero)
{
    EXPECT_DOUBLE_EQ(calc.multiply(5, 0), 0);
    EXPECT_DOUBLE_EQ(calc.multiply(0, 5), 0);
}

TEST_F(CalculatorTest, MultiplyNegativeNumbers)
{
    EXPECT_DOUBLE_EQ(calc.multiply(-2, 3), -6);
    EXPECT_DOUBLE_EQ(calc.multiply(-2, -3), 6);
}

// ����� ��� �������
TEST_F(CalculatorTest, DividePositiveNumbers)
{
    EXPECT_DOUBLE_EQ(calc.divide(6, 2), 3);
    EXPECT_DOUBLE_EQ(calc.divide(10, 4), 2.5);
}

TEST_F(CalculatorTest, DivideByZero)
{
    EXPECT_THROW(calc.divide(5, 0), std::invalid_argument);
}

TEST_F(CalculatorTest, DivideNegativeNumbers)
{
    EXPECT_DOUBLE_EQ(calc.divide(-6, 2), -3);
    EXPECT_DOUBLE_EQ(calc.divide(-6, -2), 3);
}

// ����� ��� ���������� � �������
TEST_F(CalculatorTest, PowerPositiveExponent)
{
    EXPECT_DOUBLE_EQ(calc.power(2, 3), 8);
    EXPECT_DOUBLE_EQ(calc.power(5, 2), 25);
}

TEST_F(CalculatorTest, PowerZeroExponent)
{
    EXPECT_DOUBLE_EQ(calc.power(5, 0), 1);
    EXPECT_DOUBLE_EQ(calc.power(0, 0), 1);
}

TEST_F(CalculatorTest, PowerNegativeExponent)
{
    EXPECT_DOUBLE_EQ(calc.power(2, -1), 0.5);
    EXPECT_DOUBLE_EQ(calc.power(4, -2), 0.0625);
}

// ����� ��� ����������
TEST_F(CalculatorTest, FactorialOfZero)
{
    EXPECT_EQ(calc.factorial(0), 1);
}

TEST_F(CalculatorTest, FactorialOfOne)
{
    EXPECT_EQ(calc.factorial(1), 1);
}

TEST_F(CalculatorTest, FactorialOfPositiveNumber)
{
    EXPECT_EQ(calc.factorial(5), 120);
    EXPECT_EQ(calc.factorial(7), 5040);
}

TEST_F(CalculatorTest, FactorialOfNegativeNumber)
{
    EXPECT_THROW(calc.factorial(-1), std::invalid_argument);
}

// ����� ��� �������� ������� �����
TEST_F(CalculatorTest, PrimeNumbers)
{
    EXPECT_TRUE(calc.isPrime(2));
    EXPECT_TRUE(calc.isPrime(3));
    EXPECT_TRUE(calc.isPrime(5));
    EXPECT_TRUE(calc.isPrime(7));
    EXPECT_TRUE(calc.isPrime(11));
    EXPECT_TRUE(calc.isPrime(13));
}

TEST_F(CalculatorTest, NotPrimeNumbers)
{
    EXPECT_FALSE(calc.isPrime(1));
    EXPECT_FALSE(calc.isPrime(4));
    EXPECT_FALSE(calc.isPrime(6));
    EXPECT_FALSE(calc.isPrime(8));
    EXPECT_FALSE(calc.isPrime(9));
    EXPECT_FALSE(calc.isPrime(10));
}

TEST_F(CalculatorTest, PrimeNumbersLarge)
{
    EXPECT_TRUE(calc.isPrime(97));
    EXPECT_TRUE(calc.isPrime(101));
}