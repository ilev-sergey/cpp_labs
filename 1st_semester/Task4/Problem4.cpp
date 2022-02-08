#include <iostream>

enum class Months
{
    JANUARY,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};

int getNumberOfDays(Months a)
{
    switch (a)
    {
    case (Months::JANUARY):
    case (Months::MARCH):
    case (Months::MAY):
    case (Months::JULY):
    case (Months::AUGUST):
    case (Months::OCTOBER):
    case (Months::DECEMBER):
        return 31;
    case (Months::APRIL):
    case (Months::JUNE):
    case (Months::SEPTEMBER):
    case (Months::NOVEMBER):
        return 30;
    case (Months::FEBRUARY):
        return 28;
    default:
        return -1;
    }
}

int main()
{
    using namespace std;

    cout << "Enter the month number: ";
    int numOfMonth;
    cin >> numOfMonth;
    --numOfMonth; // because enum starts from 0

    Months month = static_cast<Months>(numOfMonth);

    int numberOfDays = getNumberOfDays(month);
    cout << "Number of days: " << numberOfDays;
    
    return EXIT_SUCCESS;
}