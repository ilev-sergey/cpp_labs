#pragma once

#include <iostream>

class Fraction
{
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction(int numerator = 0, int denominator = 1);

    void reduceFraction();

    double convertToDouble();

    void setDenominaitor(int a);
    void setNumerator(int a);
    int getDenominaitor() const;
    int getNumerator() const;

    void operator+= (const Fraction&);
    void operator-= (const Fraction&);
    void operator*= (const Fraction&);
    void operator/= (const Fraction&);

    Fraction& operator++ ();
    Fraction& operator-- ();
    Fraction operator++ (int);
    Fraction operator-- (int);

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

std::ostream& operator<< (std::ostream&, const Fraction&);
std::istream& operator>> (std::istream& in, Fraction& fraction);

Fraction& operator+ (const Fraction& fraction1, const Fraction& fraction2);
Fraction& operator- (const Fraction& fraction1, const Fraction& fraction2);
Fraction& operator* (const Fraction& fraction1, const Fraction& fraction2);
Fraction& operator/ (const Fraction& fraction1, const Fraction& fraction2);

bool operator> (const Fraction& fraction1, const Fraction& fraction2);
bool operator< (const Fraction& fraction1, const Fraction& fraction2);
bool operator>= (const Fraction& fraction1, const Fraction& fraction2);
bool operator<= (const Fraction& fraction1, const Fraction& fraction2);
bool operator== (const Fraction& fraction1, const Fraction& fraction2);
bool operator!= (const Fraction& fraction1, const Fraction& fraction2);