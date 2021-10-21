#pragma once

#include <vector>
#include <iostream>

using vectorOfPairs = std::vector<std::pair<double, double>>;
using pair = std::pair<double, double>;

class Figure
{
protected:
    std::string m_type;

public:
    virtual void printInformation();
    virtual double calculateSquare() = 0;
    virtual double calculatePerimeter() = 0;
    virtual void printDimensions() = 0;
    virtual void printVertices() = 0;
};


class Polygon : public Figure
{
protected:
    vectorOfPairs m_vertices;

public:
    Polygon(vectorOfPairs);

    virtual void printVertices();
    virtual void calculateSides() = 0;
};


class Triangle : public Polygon
{
private:
    const int amountOfTriangleDimensions{ 3 };
    std::vector<double> m_sides{ 0, 0, 0 };

public:
    Triangle(const vectorOfPairs&);

    virtual void calculateSides();
    virtual double calculatePerimeter();
    virtual double calculateSquare();
    virtual void printDimensions();
};


class Quadrangle : public Polygon
{
private:
    const int amountOfQuadrangleDimensions{ 4 };

public:
    Quadrangle(const vectorOfPairs&);
};


class Rectangle : public Quadrangle
{
private:
    double length{ 0 };
    double width{ 0 };

public:
    Rectangle(const vectorOfPairs&);

    virtual void calculateSides();
    virtual double calculatePerimeter();
    virtual double calculateSquare();
    virtual void printDimensions();
};


class Square : public Rectangle
{
private:
    double side{ 0 };

public:
    Square(const vectorOfPairs&);

    virtual void calculateSides();
    virtual void printDimensions();
};


class Ellipse : public Figure
{
private:
    double m_a{ 0 };
    double m_b{ 0 };

protected:
    const double pi{ 3.14159265359 };
    pair m_center;

public:
    Ellipse(const pair&, double = 0, double = 0);

    virtual void printVertices();
    virtual double calculatePerimeter();
    virtual double calculateSquare();
    virtual void printDimensions();
};


class Circle : public Ellipse
{
private:
    double m_radius{ 0 };

public:
    Circle(const pair&, double = 0);

    virtual double calculatePerimeter();
    virtual double calculateSquare();
    virtual void printDimensions();
};