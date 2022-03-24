#include <iostream>
#include <fstream>
#include <random>
#include <string>

int main()
{
    const size_t length = 10;
    const size_t number_of_strings = 10;

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<size_t> letter_dist('a', 'z');

    std::fstream file("./Problem2/file.txt", std::ios::out | std::ios::in);  // open to read and write

    // write random strings
    for (auto i = 0U; i < number_of_strings; ++i)
    {
        for (auto k = 0U; k < length; ++k)
        {
            file << static_cast<char>(letter_dist(rng));
        }
        file << '\n';
    }

    file.seekg(std::ios::beg);          // move to beginning of file
    std::cout << file.rdbuf() << "\n";  // print content of file
    file.seekg(std::ios::beg);          // move to beginning of file

    std::string string;
    std::getline(file, string);  // get first line to find out length 

    size_t number = 2; 
    file.seekg(number * (string.length() + 2));  // set position to beginning of number_th string
    std::getline(file, string);                  // get number_th string
    std::cout << string << "\n";

    return EXIT_SUCCESS;
}