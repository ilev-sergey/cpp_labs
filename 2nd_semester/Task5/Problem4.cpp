#include <iostream>
#include <regex>

int main()
{
    std::string text = "Date (YYYY.MM.DD): 0001.01.00 0000.01.01 0001.00.01 0001.01.01"
        "1999.12.31 2022.03.16 1000.13.01 1000.11.31 1000.02.29 1234.06.06 2099.01.31 2100.01.31"
        "Time (HH:MM:SS): 12:10:01 00:00:00 25:00:00 13:59:58 01:60:00 01:00:60 23:59:59 24:00:00"
    ;

    //std::regex date_pattern(R"((0\d{2}[1-9]|1\d{3}|20\d{2})\.(0[1-9]|1[0-2])\.(0[1-9]|[12]\d|3[01]))"); // all months have 31 days 
    std::regex date_pattern(
        R"((0\d{2}[1-9]|1\d{3}|20\d{2}))" // year
        R"(\.)"

            // 31 day months
            R"((((0[13578]|10|12))"
            R"(\.)"
                R"((0[1-9]|[12]\d|3[01]))"
            R"(|)"

            // 30 day months
            R"((0[4689]|11))"
            R"(\.)"
                R"((0[1-9]|[12]\d|30))"
            R"(|)"

            // Feb
            R"(02\.(0[1-9]|1\d|2[0-8]))))"
    );
    std::regex time_pattern(R"(([01]\d|2[0-3]):[0-5]\d:[0-5]\d)");

    std::sregex_iterator date_begin(text.cbegin(), text.cend(), date_pattern);
    std::sregex_iterator date_end;

    std::cout << "Dates:\n";
    std::for_each(date_begin, date_end, [](const std::smatch& m)
        {
            std::cout << m[0] << std::endl;
        });

    std::sregex_iterator time_begin(text.cbegin(), text.cend(), time_pattern);
    std::sregex_iterator time_end;

    std::cout << "\nTimes:\n";
    std::for_each(time_begin, time_end, [](const std::smatch& m)
        {
            std::cout << m[0] << "" << std::endl;
        });

    return EXIT_SUCCESS;
}