#include <iostream>
#include <string>
#include <random>
#include <iomanip>

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/random_access_index.hpp>

using namespace boost::multi_index;

struct Person
{
	std::string surname;
	std::string name;
	std::string phone_number;
};

std::string get_name(std::mt19937& rng)
{
	const size_t shortest_length{ 3 };
	const size_t longest_length{ 10 };

	std::uniform_int_distribution<size_t> letter_dist('a', 'z');
	std::uniform_int_distribution<size_t> length_dist(shortest_length, longest_length);

	auto length{ length_dist(rng) };
	std::string string;

	for (auto i = 0U; i < length; ++i)
	{
		char letter{ static_cast<char>(letter_dist(rng)) };
		string += letter;
	}
	string[0] = toupper(string[0]);

	return string;
}

std::string get_phone_number(std::mt19937& rng)
{
	std::uniform_int_distribution<size_t> digit_dist('0', '9');

	std::string phone_number{ "+7" };
	const size_t length{ 12 };

	while (phone_number.size() != length)
	{
		char digit{ static_cast<char>(digit_dist(rng)) };
		phone_number += digit;
	}

	return phone_number;
}

using people_multi_index = multi_index_container <
	Person, indexed_by <

	ordered_non_unique <
	member < Person, std::string, &Person::surname > >,

	random_access <>,

	hashed_non_unique <
	member < Person, std::string, &Person::name > >

	> 
>;

int main(int argc, char** argv)
{
	std::random_device rd;  // create random device engine
	std::mt19937 rng(rd()); // initialize Mersennes' twister using rd to generate the seed

	people_multi_index people;
	const size_t person_count{ 10 };

	for (auto i = 0U; i < person_count; ++i)
	{
		people.insert(Person{ get_name(rng), get_name(rng), get_phone_number(rng) });
	}


	std::cout << "Sorted by surname:\n\n";
	std::cout << std::setw(11) << "Surname" << std::setw(12) << "Name" <<
		std::setw(14) << "Phone number" << "\n";
	std::cout << "=====================================\n";

	auto& ordered_surname_index = people.get<0>();
	auto begin = ordered_surname_index.begin();
	auto end = ordered_surname_index.end();
	for (; begin != end; ++begin)
	{
		std::cout << std::setw(11) << begin->surname << std::setw(12) << begin->name <<
			std::setw(14) << begin->phone_number << "\n";
	}
	std::cout << "\n";


	std::cout << "Random access:\n";

	const auto& random_access_index = people.get < 1 >();
	auto first = random_access_index[0];
	std::cout << std::setw(11) << first.surname << std::setw(12) << first.name <<
		std::setw(14) << first.phone_number << "\n\n";


	std::cout << "Fast access by name:\n";
	const auto& hashed_name_index = people.get < 2 >();

	auto person = hashed_name_index.find(first.name);
	std::cout << std::setw(11) << (*person).surname << std::setw(12) << (*person).name <<
		std::setw(14) << (*person).phone_number << "\n\n";

	return EXIT_SUCCESS;
}