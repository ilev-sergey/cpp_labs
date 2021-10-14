#include "Fraction.h"

#include <numeric>

Fraction::Fraction(int numerator, int denominator) :
    m_numerator{ numerator }, m_denominator{ denominator }
{
    while (denominator == 0)
    {
        std::cout << "Incorrect denominator entered, please try again\n";
        std::cin >> denominator;
    }
    m_denominator = denominator;
}

void Fraction::reduceFraction()
{
    int gcd = std::gcd(m_numerator, m_denominator);
    m_numerator /= gcd;
    m_denominator /= gcd;
}

double Fraction::convertToDouble() { return (double)m_numerator / m_denominator; }

void Fraction::setDenominaitor(int a)
{
    if (a != 0)
        m_denominator = a;
}

void Fraction::setNumerator(int a) { m_numerator = a; }

int Fraction::getDenominaitor() const { return m_denominator; }

int Fraction::getNumerator() const { return m_numerator; }

void Fraction::operator+= (const Fraction& fraction)
{
    int lcm{ std::lcm(m_denominator, fraction.m_denominator) };

    int k1{ lcm / fraction.m_denominator };
    int k2{ lcm / fraction.m_denominator };

    m_numerator = k1 * m_numerator + k2 * fraction.m_numerator;
    m_denominator = lcm;

    this->reduceFraction();
}

void Fraction::operator-= (const Fraction& fraction)
{
    int lcm{ std::lcm(m_denominator, fraction.m_denominator) };

    int k1{ lcm / m_denominator };
    int k2{ lcm / fraction.m_denominator };

    m_numerator = k1 * m_numerator - k2 * fraction.m_numerator;
    m_denominator = lcm;

    this->reduceFraction();
}

void Fraction::operator*= (const Fraction& fraction)
{
    m_numerator *= fraction.m_numerator;
    m_denominator *= fraction.m_denominator;

    this->reduceFraction();
}

void Fraction::operator/= (const Fraction& fraction)
{
    m_numerator *= fraction.m_denominator; 
    m_denominator *= fraction.m_numerator;

    this->reduceFraction();
}

Fraction& Fraction::operator++ ()
{
    ++m_numerator;
    this->reduceFraction();
    return *this;
}

Fraction& Fraction::operator-- ()
{
    --m_numerator;
    this->reduceFraction();
    return *this;
}

Fraction Fraction::operator++ (int)
{
    Fraction temp{ m_numerator, m_denominator };
    ++m_numerator;
    this->reduceFraction();
    return temp;
}

Fraction Fraction::operator-- (int)
{
    Fraction temp{ m_numerator, m_denominator };
    --m_numerator;
    this->reduceFraction();
    return temp;
}

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