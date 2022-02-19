#include <functional>
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <random>

// http://www.boost.org/doc/libs/1_35_0/doc/html/hash/combine.html

template < typename T >
void hash_combine(std::size_t& seed, const T& value) noexcept
{
    seed ^= std::hash < T >()(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

template < typename T >
void hash_value(std::size_t& seed, const T& value) noexcept
{
    hash_combine(seed, value);
}

template < typename T, typename ... Types >
void hash_value(std::size_t& seed, const T& value, const Types & ... args) noexcept
{
    hash_combine(seed, value);
    hash_value(seed, args...);
}

template < typename ... Types >
std::size_t hash_value(const Types & ... args) noexcept
{
    std::size_t seed = 0;
    hash_value(seed, args...);
    return seed;
}

class Customer
{
private:
    friend struct Customer_Hash;
    friend struct Customer_Equal;

public:
    explicit Customer(const std::string& name, const std::size_t mark) :
        m_name(name), m_mark(mark)
    {}

    ~Customer() noexcept = default;

public:
    friend std::ostream& operator << (std::ostream& stream, const Customer& customer)
    {
        return (stream << customer.m_name << "," << customer.m_mark);
    }

private:
    std::string m_name;
    std::size_t m_mark;
};

struct Customer_Hash
{
    std::size_t operator() (const Customer& customer) const noexcept
    {
        return hash_value(customer.m_name, customer.m_mark);
    }
};

struct Customer_Equal
{
    bool operator() (const Customer& lhs, const Customer& rhs) const noexcept
    {
        return (lhs.m_name == rhs.m_name);
    }
};

Customer create_customer(std::mt19937& rng)
{
    const size_t lowest_mark{ 1 };
    const size_t highest_mark{ 100 };
    const size_t shortest_name{ 3 };
    const size_t longest_name{ 10 };

    std::uniform_int_distribution<size_t> mark_dist(lowest_mark, highest_mark);
    std::uniform_int_distribution<size_t> letter_dist('a', 'z');
    std::uniform_int_distribution<size_t> size_dist(shortest_name, longest_name);

    auto mark{ mark_dist(rng) };
    auto size{ size_dist(rng) };
    std::string name;

    for (auto i = 0U; i < size; ++i)
    {
        char letter{ static_cast<char>(letter_dist(rng)) };
        name += letter;
    }

    return Customer{ name, mark };
}

void collision_counter(size_t customer_count)
{
    std::random_device rd;  // create random device engine
    std::mt19937 rng(rd()); // initialize Mersennes' twister using rd to generate the seed

    std::unordered_set < Customer, Customer_Hash, Customer_Equal > customers;
    std::unordered_set <size_t> hash_values;

    while (customers.size() != customer_count)
    {
        customers.insert(create_customer(rng));
    }

    for (const auto& customer : customers)
    {
        hash_values.insert(Customer_Hash()(customer));
    }

    std::ofstream ofs;
    ofs.open("./Problem2/data.csv", std::ios::app);
    ofs << customer_count << "," << customer_count - hash_values.size() << '\n';
    ofs.close();
}

int main2(int argc, char** argv)
{
    std::ofstream ofs;
    ofs.open("./Problem2/data.csv", std::ofstream::out | std::ofstream::trunc); // clean up file
    ofs << "customers,collisions\n";
    ofs.close();

    const double lower_bound{ 1e4 };
    const double upper_bound{ 5e6 };
    const int point_count{ 30 };
    const int step = (upper_bound - lower_bound) / point_count;

    for (auto count = lower_bound; count < upper_bound; count += step) // tests for different customer_counts
    {
        collision_counter(count);
    }

    return EXIT_SUCCESS;
}