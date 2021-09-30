#include <iostream>
#include <iomanip>

struct DateAndTime
{
    DateAndTime(unsigned short _day = 1, unsigned short _month = 1, unsigned short _year = 2000,
        unsigned short _hours = 0, unsigned short _minutes = 0, unsigned short _seconds = 0,
        unsigned short _milliseconds = 0) :
        day{ _day }, month{ month }, year{ _year },
        hours{ _hours }, minutes{ _minutes }, seconds{ _seconds }, milliseconds{ _milliseconds } {}

    void printDateAndTime()
    {
        std::cout << "Current time: " << std::endl <<
            std::setfill('0') << std::setw(2) << day << '.' << 
            std::setfill('0') << std::setw(2) << month << '.' << 
            std::setfill('0') << std::setw(4) << year << ' ' << 
            std::setfill('0') << std::setw(2) << hours << ':' << 
            std::setfill('0') << std::setw(2) << minutes << ':' << 
            std::setfill('0') << std::setw(2) << seconds << '.' << 
            std::setfill('0') << std::setw(3) << milliseconds << 
            std::endl;
    }

    void getDateAndTime()
    {
        int input = 0;

        std::cout << "Enter day: " << std::endl;
        std::cin >> input; day = input;

        std::cout << "Enter month: " << std::endl;
        std::cin >> input; month = input;

        std::cout << "Enter year: " << std::endl;
        std::cin >> input; year = input;

        std::cout << "Enter hours: " << std::endl;
        std::cin >> input; hours = input;

        std::cout << "Enter minutes: " << std::endl;
        std::cin >> input; minutes = input;

        std::cout << "Enter seconds: " << std::endl;
        std::cin >> input; seconds = input;

        std::cout << "Enter milliseconds: " << std::endl;
        std::cin >> input; milliseconds = input;
    }

    unsigned short day : 5;
    unsigned short month : 4;
    unsigned short year : 12;
    
    unsigned short hours : 5;
    unsigned short minutes : 6;
    unsigned short seconds : 6;
    unsigned short milliseconds : 10;
};

int main()
{
    DateAndTime par;
    par.getDateAndTime();

    std::cout << std::endl;
    par.printDateAndTime();

    return EXIT_SUCCESS;
}