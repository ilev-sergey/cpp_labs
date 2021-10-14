// #include "Fraction.h"

#include <iostream>
#include <numeric>

class Fraction
{
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction(int numerator = 0, int denominator = 1) :
        m_numerator{ numerator }, m_denominator{ denominator }
    {
        while (denominator == 0)
        {
            std::cout << "Incorrect denominator entered, please try again\n";
            std::cin >> denominator;
        }
        m_denominator = denominator;
    }

    void reduceFraction()
    {
        int gcd = std::gcd(m_numerator, m_denominator);
        m_numerator /= gcd;
        m_denominator /= gcd;
    }

    double convertToDouble() { return (double)m_numerator / m_denominator; }

    void setDenominaitor(int a)
    {
        if (a != 0)
            m_denominator = a;
    }

    void setNumerator(int a) { m_numerator = a; }

    int getDenominaitor() const { return m_denominator; }

    int getNumerator() const { return m_numerator; }

    friend std::ostream& operator<< (std::ostream&, const Fraction&);
    friend std::istream& operator>> (std::istream&, Fraction&);

    friend Fraction& operator+ (const Fraction&, const Fraction&);
    friend Fraction& operator- (const Fraction&, const Fraction&);
    friend Fraction& operator* (const Fraction&, const Fraction&);
    friend Fraction& operator/ (const Fraction&, const Fraction&);

    friend bool operator> (const Fraction&, const Fraction&);
    friend bool operator< (const Fraction&, const Fraction&);
    friend bool operator>= (const Fraction&, const Fraction&);
    friend bool operator<= (const Fraction&, const Fraction&);
    friend bool operator== (const Fraction&, const Fraction&);
    friend bool operator!= (const Fraction&, const Fraction&);
};

std::ostream& operator<< (std::ostream& out, const Fraction& fraction)
{
    out << fraction.m_numerator << "/" << fraction.m_denominator << "\n";
    return out;
}

std::istream& operator>> (std::istream& in, Fraction& fraction)
{
    in >> fraction.m_numerator >> fraction.m_denominator;
    return in;
}

Fraction& operator+ (const Fraction& fraction1, const Fraction& fraction2)
{
    Fraction result;

    int lcm{ std::lcm(fraction1.m_denominator, fraction2.m_denominator) };

    int k1{ lcm / fraction1.m_denominator };
    int k2{ lcm / fraction2.m_denominator };

    result.m_numerator = k1 * fraction1.m_numerator + k2 * fraction2.m_numerator;
    result.m_denominator = lcm;

    result.reduceFraction();

    return result;
}

Fraction& operator- (const Fraction& fraction1, const Fraction& fraction2)
{
    Fraction result;

    int lcm{ std::lcm(fraction1.m_denominator, fraction2.m_denominator) };

    int k1{ lcm / fraction1.m_denominator };
    int k2{ lcm / fraction2.m_denominator };

    result.m_numerator = k1 * fraction1.m_numerator - k2 * fraction2.m_numerator;
    result.m_denominator = lcm;

    result.reduceFraction();

    return result;
}

Fraction& operator* (const Fraction& fraction1, const Fraction& fraction2)
{
    Fraction result{ fraction1.m_numerator * fraction2.m_numerator,
        fraction1.m_denominator * fraction2.m_denominator };

    result.reduceFraction();

    return result;
}

Fraction& operator/ (const Fraction& fraction1, const Fraction& fraction2)
{
    Fraction result{ fraction1.m_numerator * fraction2.m_denominator,
    fraction1.m_denominator * fraction2.m_numerator };

    result.reduceFraction();

    return result;
}

bool operator> (const Fraction& fraction1, const Fraction& fraction2)
{
    int lcm{ std::lcm(fraction1.m_denominator, fraction2.m_denominator) };

    int k1{ lcm / fraction1.m_denominator };
    int k2{ lcm / fraction2.m_denominator };

    int difference = k1 * fraction1.m_numerator - k2 * fraction2.m_numerator;
    return (difference > 0);
}

bool operator< (const Fraction& fraction1, const Fraction& fraction2)
{
    int lcm{ std::lcm(fraction1.m_denominator, fraction2.m_denominator) };

    int k1{ lcm / fraction1.m_denominator };
    int k2{ lcm / fraction2.m_denominator };

    int difference = k1 * fraction1.m_numerator - k2 * fraction2.m_numerator;
    return (difference < 0);
}

bool operator>= (const Fraction& fraction1, const Fraction& fraction2)
{
    int lcm{ std::lcm(fraction1.m_denominator, fraction2.m_denominator) };

    int k1{ lcm / fraction1.m_denominator };
    int k2{ lcm / fraction2.m_denominator };

    int difference = k1 * fraction1.m_numerator - k2 * fraction2.m_numerator;
    return (difference >= 0);
}

bool operator<= (const Fraction& fraction1, const Fraction& fraction2)
{
    int lcm{ std::lcm(fraction1.m_denominator, fraction2.m_denominator) };

    int k1{ lcm / fraction1.m_denominator };
    int k2{ lcm / fraction2.m_denominator };

    int difference = k1 * fraction1.m_numerator - k2 * fraction2.m_numerator;
    return (difference <= 0);
}

bool operator== (const Fraction& fraction1, const Fraction& fraction2)
{
    int lcm{ std::lcm(fraction1.m_denominator, fraction2.m_denominator) };

    int k1{ lcm / fraction1.m_denominator };
    int k2{ lcm / fraction2.m_denominator };

    int difference = k1 * fraction1.m_numerator - k2 * fraction2.m_numerator;
    return (difference == 0);
}

bool operator!= (const Fraction& fraction1, const Fraction& fraction2)
{
    int lcm{ std::lcm(fraction1.m_denominator, fraction2.m_denominator) };

    int k1{ lcm / fraction1.m_denominator };
    int k2{ lcm / fraction2.m_denominator };

    int difference = k1 * fraction1.m_numerator - k2 * fraction2.m_numerator;
    return (difference != 0);
}


int main()
{
    Fraction a{ 2, 5 };
    Fraction b{ 3, 8 };
    std::cout << a << b << "\n";

    std::cout << "Sum = " << a + b << "Diff = " << a - b << "Mult = " << a * b <<
        "Div = " << a / b;
    std::cout << "Double b = " << b.convertToDouble() << "\n\n";
    std::cout << "a compare b\n";
    std::cout << ">, <, =, >=, <=, !=\n";
    std::cout << (a > b) << (a < b) << (a == b) << (a >= b) << (a <= b) << (a != b);

    return EXIT_SUCCESS;
}


