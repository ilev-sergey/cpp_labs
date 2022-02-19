#include <functional>
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <random>
#include <vector>

unsigned int RSHash(const char* str, unsigned int length)
{
    unsigned int b = 378551;
    unsigned int a = 63689;
    unsigned int hash = 0;
    unsigned int i = 0;

    for (i = 0; i < length; ++str, ++i)
    {
        hash = hash * a + (*str);
        a = a * b;
    }

    return hash;
}

unsigned int JSHash(const char* str, unsigned int length)
{
    unsigned int hash = 1315423911;
    unsigned int i = 0;

    for (i = 0; i < length; ++str, ++i)
    {
        hash ^= ((hash << 5) + (*str) + (hash >> 2));
    }

    return hash;
}

unsigned int PJWHash(const char* str, unsigned int length)
{
    const unsigned int BitsInUnsignedInt = (unsigned int)(sizeof(unsigned int) * 8);
    const unsigned int ThreeQuarters = (unsigned int)((BitsInUnsignedInt * 3) / 4);
    const unsigned int OneEighth = (unsigned int)(BitsInUnsignedInt / 8);
    const unsigned int HighBits =
        (unsigned int)(0xFFFFFFFF) << (BitsInUnsignedInt - OneEighth);
    unsigned int hash = 0;
    unsigned int test = 0;
    unsigned int i = 0;

    for (i = 0; i < length; ++str, ++i)
    {
        hash = (hash << OneEighth) + (*str);

        if ((test = hash & HighBits) != 0)
        {
            hash = ((hash ^ (test >> ThreeQuarters)) & (~HighBits));
        }
    }

    return hash;
}

unsigned int ELFHash(const char* str, unsigned int length)
{
    unsigned int hash = 0;
    unsigned int x = 0;
    unsigned int i = 0;

    for (i = 0; i < length; ++str, ++i)
    {
        hash = (hash << 4) + (*str);

        if ((x = hash & 0xF0000000L) != 0)
        {
            hash ^= (x >> 24);
        }

        hash &= ~x;
    }

    return hash;
}

unsigned int BKDRHash(const char* str, unsigned int length)
{
    unsigned int seed = 131; /* 31 131 1313 13131 131313 etc.. */
    unsigned int hash = 0;
    unsigned int i = 0;

    for (i = 0; i < length; ++str, ++i)
    {
        hash = (hash * seed) + (*str);
    }

    return hash;
}

unsigned int SDBMHash(const char* str, unsigned int length)
{
    unsigned int hash = 0;
    unsigned int i = 0;

    for (i = 0; i < length; ++str, ++i)
    {
        hash = (*str) + (hash << 6) + (hash << 16) - hash;
    }

    return hash;
}

unsigned int DJBHash(const char* str, unsigned int length)
{
    unsigned int hash = 5381;
    unsigned int i = 0;

    for (i = 0; i < length; ++str, ++i)
    {
        hash = ((hash << 5) + hash) + (*str);
    }

    return hash;
}

unsigned int DEKHash(const char* str, unsigned int length)
{
    unsigned int hash = length;
    unsigned int i = 0;

    for (i = 0; i < length; ++str, ++i)
    {
        hash = ((hash << 5) ^ (hash >> 27)) ^ (*str);
    }

    return hash;
}

unsigned int APHash(const char* str, unsigned int length)
{
    unsigned int hash = 0xAAAAAAAA;
    unsigned int i = 0;

    for (i = 0; i < length; ++str, ++i)
    {
        hash ^= ((i & 1) == 0) ? ((hash << 7) ^ (*str) * (hash >> 3)) :
            (~((hash << 11) + ((*str) ^ (hash >> 5))));
    }

    return hash;
}

std::string get_string(std::mt19937& rng)
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

    return string;
}

int main3(int argc, char** argv)
{
    std::ofstream ofs;
    ofs.open("./Problem3/data.csv", std::ofstream::out | std::ofstream::trunc); // clean up file
    ofs << "RSHash,JSHash,PJWHash,ELFHash,BKDRHash,SDBMHash,DJBHash,DEKHash,APHash\n";
    ofs.close();

    std::vector<std::function<unsigned int(const char*, unsigned int)>> functions{
        RSHash, JSHash, PJWHash, ELFHash, BKDRHash, SDBMHash, DJBHash, DEKHash, APHash };

    std::random_device rd;  // create random device engine
    std::mt19937 rng(rd()); // initialize Mersennes' twister using rd to generate the seed

    const double string_count{ 1e6 };

    std::unordered_set <std::string> strings;
    std::vector < std::unordered_set<size_t> > hash_values(functions.size());

    while (strings.size() != string_count)
    {
        strings.insert(get_string(rng));
    }

    for (auto i = 0U; i < functions.size(); ++i)
    {
        for (const auto& string : strings)
        {
            hash_values[i].insert(functions[i](string.c_str(), string.size()));
        }
    }

    ofs.open("./Problem3/data.csv", std::ios::app);
    for (auto i = 0U; i < functions.size(); ++i)
    {
        ofs << ((i == 0) ? ' ' : ',') << string_count - hash_values[i].size();
    }
    ofs.close();

    return EXIT_SUCCESS;
}