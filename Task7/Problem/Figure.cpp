#include "Figure.h"

void Figure::printInformation() const
{
    std::cout << m_type << "\n\n";

    printVertices();
    printDimensions();

    std::cout << "Perimeter = " << calculatePerimeter() << "\n";
    std::cout << "Square = " << calculateSquare() << "\n\n";
}

Polygon::Polygon(const vectorOfPairs& vertices) : m_vertices{ vertices } {}

void Polygon::printVertices() const
{
    std::cout << "Vertices:\n";

    for (const auto& vertice : m_vertices)
    {
        std::cout << "(" << vertice.first << ", " << vertice.second << ")\n";
    }
    std::cout << "\n";
}

Triangle::Triangle(const vectorOfPairs& vertices) : Polygon(vertices)
{
    m_type = "Triangle";

    if (m_vertices.size() != amountOfTriangleDimensions)
    {
        std::cout << "Incorrect amount of vertices for triangle, please re-enter coordinates:\n";
        m_vertices.clear();
        m_vertices.resize(amountOfTriangleDimensions);
        for (int i = 0; i < amountOfTriangleDimensions; ++i)
        {
            std::cin >> m_vertices[i].first;
            std::cin >> m_vertices[i].second;
        }
    }
    calculateSides();
}

void Triangle::calculateSides()
{
    pair vertice1;
    pair vertice2;

    for (int i = 0; i < m_vertices.size(); ++i)
    {
        vertice1 = m_vertices[i];
        vertice2 = m_vertices[(i + 1) % amountOfTriangleDimensions];
        m_sides[i] = sqrt(pow((vertice1.first - vertice2.first), 2) +
            pow((vertice1.second - vertice2.second), 2));
    }
}

double Triangle::calculatePerimeter() const
{
    double rez = 0;

    for (auto side : m_sides)
    {
        rez += side;
    }
    return rez;
}

double Triangle::calculateSquare() const // based on Heron's formula
{
    double p = calculatePerimeter() / 2;
    double rez = p;

    for (auto side : m_sides)
    {
        rez *= (p - side);
    }
    return sqrt(rez);
}

void Triangle::printDimensions() const
{
    std::cout << "Sides:\n";
    std::string delimiter{ "" };

    for (auto side : m_sides)
    {
        std::cout << delimiter << side;
        delimiter = ", ";
    }
    std::cout << "\n\n";
}

Quadrangle::Quadrangle(const vectorOfPairs& vertices) : Polygon(vertices)
{
    m_type = "Quadrangle";

    if (m_vertices.size() != amountOfQuadrangleDimensions)
    {
        std::cout << "Incorrect amount of vertices for quadrangle, please re-enter coordinates:\n";
        m_vertices.clear();
        m_vertices.resize(amountOfQuadrangleDimensions);
        for (int i = 0; i < amountOfQuadrangleDimensions; ++i)
        {
            std::cin >> m_vertices[i].first;
            std::cin >> m_vertices[i].second;
        }
    }
}

Rectangle::Rectangle(const vectorOfPairs& vertices) : Quadrangle(vertices)
{
    m_type = "Rectangle";
    calculateSides();
}

void Rectangle::calculateSides()
{
    pair vertice1{ m_vertices[0] };
    pair vertice2;
    double currentLength{ 0 };
    double minLength{ 'inf' };
    double maxLength{ 0 };

    for (int i = 1; i < m_vertices.size(); ++i)
    {
        vertice2 = m_vertices[i];
        currentLength = sqrt(pow((vertice1.first - vertice2.first), 2) +
            pow((vertice1.second - vertice2.second), 2));
        minLength = std::min(minLength, currentLength);
        maxLength = std::max(maxLength, currentLength);
    }

    length = sqrt(pow(maxLength, 2) - pow(minLength, 2));
    width = minLength;
}

double Rectangle::calculatePerimeter() const
{
    return 2 * (length + width);
}

double Rectangle::calculateSquare() const
{
    return length * width;
}

void Rectangle::printDimensions() const
{
    std::cout << "Dimesions:\n";
    std::cout << "Length = " << length << "\n";
    std::cout << "Width = " << width << "\n\n";
}

Square::Square(const vectorOfPairs& vertices) : Rectangle(vertices)
{
    m_type = "Square";
    calculateSides();
}

void Square::calculateSides()
{
    pair vertice{ m_vertices[0] };
    pair vertice1{ m_vertices[1] };
    pair vertice2{ m_vertices[2] };

    side = std::min(
        sqrt(pow((vertice1.first - vertice.first), 2) + pow((vertice1.second - vertice.second), 2)),
        sqrt(pow((vertice1.first - vertice.first), 2) + pow((vertice1.second - vertice.second), 2))
    );
}

void Square::printDimensions() const
{
    std::cout << "Side = " << side << "\n\n";
}


Ellipse::Ellipse(const pair& center, double a, double b) : m_center{ center }, m_a{ a }, m_b{ b }
{
    m_type = "Ellipse";
}

void Ellipse::printVertices() const
{
    std::cout << "Center:\n";
    std::cout << "(" << m_center.first << ", " << m_center.second << ")\n";
    std::cout << "\n";
}

double Ellipse::calculatePerimeter() const // approximate value
{
    return 4 * (pi * m_a * m_b + pow((m_a - m_b), 2)) / (m_a + m_b);
}

double Ellipse::calculateSquare() const
{
    return pi * m_a * m_b;
}

void Ellipse::printDimensions() const
{
    std::cout << "Dimensions:\n";
    std::cout << "a = " << m_a << "\n";
    std::cout << "b = " << m_b << "\n";
    std::cout << "\n";
}


Circle::Circle(const pair& center, double radius) : Ellipse{ center, radius, radius }, m_radius{ radius }
{
    m_type = "Circle";
}

double Circle::calculatePerimeter() const
{
    return 2 * pi * m_radius;
}

double Circle::calculateSquare() const
{
    return pi * pow(m_radius, 2);
}

void Circle::printDimensions() const
{
    std::cout << "Radius = " << m_radius << "\n";
    std::cout << "\n";
}

std::ostream& operator<< (std::ostream& out, const Figure& figure)
{
    figure.printInformation();
    return out;
}