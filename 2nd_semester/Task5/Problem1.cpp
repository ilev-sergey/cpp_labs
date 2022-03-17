#include <iostream>
#include <iomanip>
#include <regex>

#include <Windows.h> 

bool is_currency(const std::string& string)
{
    std::regex pattern(R"(\d*([.,]\d{1,2})?)");
    return regex_match(string, pattern);
}

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    auto input_locale = std::locale("de_DE.UTF-8");
    auto output_locale = std::locale("ru_RU.UTF-8");
    const double eur_to_rub_rate = 121.03;

    std::cin.imbue(input_locale);
    std::cout.imbue(output_locale);

    std::string value;

    std::cout << std::use_facet < std::moneypunct <char, true> >(std::locale(input_locale)).curr_symbol() <<
        " to " << std::use_facet < std::moneypunct <char, true> >(std::locale(output_locale)).curr_symbol() << 
        " converter\n\n";

    std::cout << "Enter amount of " << 
        std::use_facet < std::moneypunct <char, true> >(std::locale(input_locale)).curr_symbol() << ":\n";
    std::cin >> value;
    while (!is_currency(value))
    {
        std::cout << "Wrong format, please re-enter:\n";
        std::cin >> value;
    }
    std::cout << "\n";

    std::cout << "Amount of " <<
        std::use_facet < std::moneypunct <char, true> >(std::locale(output_locale)).curr_symbol() << ":\n";
    std::cout << std::showbase << std::put_money(std::stold(value) * eur_to_rub_rate * 100) << std::endl;
   
    return EXIT_SUCCESS;
}