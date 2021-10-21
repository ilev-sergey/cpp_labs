#include <iostream>
#include <utility>
#include <vector>

#include "Figure.h"

using vectorOfPairs = std::vector<std::pair<double, double>>;
using pair = std::pair<double, double>;

class Figure
{
protected:
    std::string m_type;
public:
    virtual double calculateSquare() = 0;
    virtual double calculatePerimeter() = 0;
    virtual void printInformation()
    {
        std::cout << m_type << "\n\n";

        printVertices();

        printDimensions();

        std::cout << "Perimeter = " << calculatePerimeter() << "\n";
        std::cout << "Square = " << calculateSquare() << "\n\n";
    }
    virtual void printDimensions() = 0;
    virtual void printVertices() = 0;
};

class Polygon : public Figure
{
protected:
    vectorOfPairs m_vertices;

public:
    virtual void calculateSides() = 0;

    Polygon(vectorOfPairs vertices) : m_vertices{ vertices } {}

    virtual void printVertices()
    {
        std::cout << "Vertices:\n";
        for (const auto& vertice : m_vertices)
        {
            std::cout << "(" << vertice.first << ", " << vertice.second << ")\n";
        }
        std::cout << "\n";
    }
};

class Triangle : public Polygon
{
private:
    const int amountOfTriangleDimensions = 3;
    std::vector<double> m_sides{ 0, 0, 0 };
public:
    Triangle(const vectorOfPairs& vertices) : Polygon(vertices)
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

    virtual void calculateSides()
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

    virtual double calculatePerimeter()
    {
        double rez = 0;
        for (auto side : m_sides)
        {
            rez += side;
        }
        return rez;
    }

    virtual double calculateSquare()
    {
        double p = calculatePerimeter() / 2;
        double rez = p;
        for (auto side : m_sides)
        {
            rez *= (p - side);
        }
        return sqrt(rez);
    }

    virtual void printDimensions()
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
};

class Quadrangle : public Polygon
{
private:
    const int amountOfQuadrangleDimensions = 4;
public:
    Quadrangle(const vectorOfPairs& vertices) : Polygon(vertices)
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
};

class Rectangle : public Quadrangle
{
private:
    double length{ 0 };
    double width{ 0 };
public:
    Rectangle(const vectorOfPairs& vertices) : Quadrangle(vertices)
    {
        m_type = "Rectangle";
        calculateSides();
    }

    virtual void calculateSides()
    {
        pair vertice1{ m_vertices[0] };
        pair vertice2;
        double currentLength{ 0 };
        double minLength{ 'inf' };
        double maxLength{ 0 };

        for (int i = 1; i < m_vertices.size(); ++i)
        {
            vertice2 = m_vertices[i];
            currentLength = sqrt(pow((vertice1.first - vertice2.first), 2) + pow((vertice1.second - vertice2.second), 2));
            minLength = std::min(minLength, currentLength);
            maxLength = std::max(maxLength, currentLength);
        }

        length = sqrt(pow(maxLength, 2) - pow(minLength, 2));
        width = minLength;
    }

    virtual double calculatePerimeter()
    {
        return 2 * (length + width);
    }

    virtual double calculateSquare()
    {
        return length * width;
    }

    virtual void printDimensions()
    {
        std::cout << "Dimesions:\n";
        std::cout << "Length = " << length << "\n";
        std::cout << "Width = " << width << "\n\n";
    }
};

class Square : public Rectangle
{
private:
    double side{ 0 };
public:
    Square(const vectorOfPairs& vertices) : Rectangle(vertices)
    {
        m_type = "Square";
        calculateSides();
    }

    virtual void calculateSides()
    {
        pair vertice{ m_vertices[0] };
        pair vertice1{ m_vertices[1] };
        pair vertice2{ m_vertices[2] };

        side = std::min(
            sqrt(pow((vertice1.first - vertice.first), 2) + pow((vertice1.second - vertice.second), 2)),
            sqrt(pow((vertice1.first - vertice.first), 2) + pow((vertice1.second - vertice.second), 2))
        );
    }

    virtual void printDimensions()
    {
        std::cout << "Side = " << side << "\n\n";
    }
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
    Ellipse(const pair& center, double a, double b) :
        m_center{ center }, m_a{ a }, m_b{ b }
    {
        m_type = "Ellipse";
    }

    virtual void printVertices()
    {
        std::cout << "Center:\n";
        std::cout << "(" << m_center.first << ", " << m_center.second << ")\n";
        std::cout << "\n";
    }

    virtual double calculatePerimeter()
    {
        return 4 * (pi * m_a * m_b + pow((m_a - m_b), 2)) / (m_a + m_b);
    }

    virtual double calculateSquare()
    {
        return pi * m_a * m_b;
    }

    virtual void printDimensions()
    {
        std::cout << "Dimensions:\n";
        std::cout << "a = " << m_a << "\n";
        std::cout << "b = " << m_b << "\n";
        std::cout << "\n";
    }
};

class Circle : public Ellipse
{
private:
    double m_radius;

public:
    Circle(const pair& center, double radius) :
        Ellipse{ center, radius, radius }, m_radius{ radius }
    {
        m_type = "Circle";
    }

    virtual double calculatePerimeter()
    {
        return 2 * pi * m_radius;
    }

    virtual double calculateSquare()
    {
        return pi * pow(m_radius, 2);
    }

    virtual void printDimensions()
    {
        std::cout << "Radius = " << m_radius << "\n";
        std::cout << "\n";
    }
};

int main()
{
    vectorOfPairs verticesOfTriangle{ pair(1, 3), pair(2, 3), pair(3, 5) };
    Triangle triangle{ verticesOfTriangle };

    vectorOfPairs verticesOfRectangle{ pair(1, 0), pair(0, 2), pair(4, 4), pair(5, 2) };
    Rectangle rectangle{ verticesOfRectangle };

    vectorOfPairs verticesOfSquare{ pair(1, 0), pair(0, 2), pair(3, 1), pair(2, 3) };
    Square square{ verticesOfSquare };

    std::pair < double, double > center{ pair(3, 5) };
    Ellipse ellipse{ center, 10, 1 };

    Circle circle{ center, 10 };

    std::vector<Figure*> figures{ &triangle, &rectangle, &square, &ellipse, &circle };

    for (auto figure : figures)
    {
        figure->printInformation();
        std::cout << "=====================\n\n";
    }

    return EXIT_SUCCESS;
}