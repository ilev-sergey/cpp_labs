#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <cmath>

using vectorOfPairs = std::vector<std::pair<double, double>>;
using pair = std::pair<double, double>;

class Figure
{
protected:
    std::string m_type;

public:
    virtual ~Figure() = default;
    virtual void printInformation() const;
    virtual double calculateSquare() const = 0;
    virtual double calculatePerimeter() const = 0;
    virtual void printDimensions() const = 0;
    virtual void printVertices() const = 0;
};


class Polygon : public Figure
{
protected:
    vectorOfPairs m_vertices;

public:
    Polygon(const vectorOfPairs&);
    virtual ~Polygon() = default;

    virtual void printVertices() const override;
    virtual void calculateSides() = 0;
};


class Triangle : public Polygon
{
private:
    const int amountOfTriangleDimensions{ 3 };
    std::vector<double> m_sides{ 0, 0, 0 };

public:
    Triangle(const vectorOfPairs&);
    virtual ~Triangle() = default;

    virtual void calculateSides() override;
    virtual double calculatePerimeter() const override;
    virtual double calculateSquare() const override;
    virtual void printDimensions() const override;
};


class Quadrangle : public Polygon
{
private:
    const int amountOfQuadrangleDimensions{ 4 };

public:
    Quadrangle(const vectorOfPairs&);
    virtual ~Quadrangle() = default;
};


class Rectangle : public Quadrangle
{
private:
    double length{ 0 };
    double width{ 0 };

public:
    Rectangle(const vectorOfPairs&);
    virtual ~Rectangle() = default;

    virtual void calculateSides() override;
    virtual double calculatePerimeter() const override;
    virtual double calculateSquare() const override;
    virtual void printDimensions() const override;
};


class Square : public Rectangle
{
private:
    double side{ 0 };

public:
    Square(const vectorOfPairs&);
    virtual ~Square() = default;

    virtual void calculateSides() override;
    virtual void printDimensions() const override;
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
    virtual ~Ellipse() = default;

    virtual void printVertices() const override;
    virtual double calculatePerimeter() const override;
    virtual double calculateSquare() const override;
    virtual void printDimensions() const override;
};


class Circle : public Ellipse
{
private:
    double m_radius{ 0 };

public:
    Circle(const pair&, double = 0);
    virtual ~Circle() = default;

    virtual double calculatePerimeter() const override;
    virtual double calculateSquare() const override;
    virtual void printDimensions() const override;
};

std::ostream& operator<< (std::ostream&, const Figure&);