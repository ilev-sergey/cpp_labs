#include "Figure.h"

int main()
{
    vectorOfPairs verticesOfTriangle{ pair{1, 3}, pair{2, 3}, pair{3, 5} };
    Triangle triangle{ verticesOfTriangle };

    vectorOfPairs verticesOfRectangle{ pair{1, 0}, pair{0, 2}, pair{4, 4}, pair{5, 2} };
    Rectangle rectangle{ verticesOfRectangle };

    vectorOfPairs verticesOfSquare{ pair{1, 0}, pair{0, 2}, pair{3, 1}, pair{2, 3} };
    Square square{ verticesOfSquare };

    pair center{ 3, 5 };
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