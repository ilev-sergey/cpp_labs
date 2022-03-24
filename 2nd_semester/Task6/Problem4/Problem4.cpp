#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>

#include "json.hpp"

using nlohmann::json;

struct Person
{
    std::string name;
    std::string surname;
    size_t age;
    double height;
    std::vector<std::string> phone_numbers;

    friend std::istream& operator>>(std::istream& stream, Person& person);

    json to_json()
    {
        json j_person;
        j_person["Name"] = this->name;
        j_person["Surname"] = this->surname;
        j_person["Age"] = this->age;
        j_person["Height"] = this->height;
        j_person["Phone numbers"] = this->phone_numbers;

        return j_person;
    }
};

std::istream& operator>>(std::istream& stream, Person& person)
{
    stream >> person.name >> person.surname >> person.age >> person.height;
    std::string temp;
    while (stream >> temp)
    {
        person.phone_numbers.push_back(temp);
    }
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const Person& person)
{
    stream << std::setw(10) << std::right << "Name: "    << person.name    << "\n" <<
              std::setw(10) << std::right << "Surname: " << person.surname << "\n" <<
              std::setw(10) << std::right << "Age: "     << person.age     << "\n" <<
              std::setw(10) << std::right << "Height: "  << person.height  << "\n";

    stream << "Phone numbers:\n";
    for (auto &number : person.phone_numbers)
    {
        stream << std::setw(5) << "" << std::right << number << '\n';
    }
    return stream;
}

int main()
{
    std::vector<Person> persons{
        Person { "John", "Doe"   , 24, 180.3, {"+19876543210", "+10123456789"} },
        Person { "Ivan", "Ivanov", 46, 177.8, {"+79876543210", "+70123456789"} }
    };

    //// create custom person
    //Person person;
    //std::cout << "Enter name, surname, age, height, phone numbers: \n(Ctrl + Z to exit)\n";
    //std::cin >> person;
    //persons.push_back(&person);

    // print persons
    for (auto &person : persons)
    {
        std::cout << person << "\n";
    }

    // print persons in JSON format
    for (auto &person : persons)
    {
        std::cout << person.to_json() << "\n";
    }
    std::cout << "\n";

    // create folder
    std::string path = "./Problem4/persons";
    std::filesystem::create_directory(path);

    // check tree
    std::system("tree");

    // create person files
    for (auto& person : persons)
    {
        auto full_path = path + '/' + person.name + ".txt";
        std::fstream fout(full_path, std::ios::out);

        fout << person.to_json();
    }

    return EXIT_SUCCESS;
}