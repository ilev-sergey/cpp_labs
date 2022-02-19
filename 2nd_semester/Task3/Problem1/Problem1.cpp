#include "../../Clock/Clock.hpp"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <unordered_set>
#include <set>
#include <vector>
#include <algorithm>
#include <random>

void compareSetWithVector(size_t N)
{
    std::random_device rd;                             // create random device engine
    std::mt19937 rng(rd());                            // initialize Mersennes' twister using rd to generate the seed
    std::uniform_int_distribution<int> dist(0, 10e10); // set distribution
    // int example = dist(rng);                        // use rng as a generator

    std::unordered_set<int> unordSet;
    std::set<int> set;
    std::vector<int> vector;
    std::vector<int> storage;

    while (unordSet.size() != N) // generate N unique numbers
    {
        unordSet.insert(dist(rng));
    }

    // print set
    //auto i = 0;
    //for (auto x : unordSet)
    //{
    //    if (i % 10 == 0 && i != 0) { std::cout << "\n"; }
    //    std::cout << std::setw(4) << std::right << x << " ";
    //    ++i;
    //}

    for (auto x : unordSet) // copy to storage
    {
        storage.push_back(x);
    }

    // write N to file
    std::ofstream ofs;
    ofs.open("./Problem1/data.csv", std::ios::app);
    ofs << N << ",";
    ofs.close();

    // insertion test for set
    Clock::start();
    for (auto x : storage)
    {
        set.insert(x);
    }
    Clock::stop();

    // write results to file
    ofs.open("./Problem1/data.csv", std::ios::app);
    ofs << Clock::getDuration().count() << ',';
    ofs.close();

    // insertion test for vector
    Clock::start();
    for (auto x : storage)
    {
        vector.push_back(x);
    }
    std::sort(vector.begin(), vector.end());
    Clock::stop();

    // write results to file
    ofs.open("./Problem1/data.csv", std::ios::app);
    ofs << Clock::getDuration().count() << std::endl;
    ofs.close();
}

int main1()
{
    std::ofstream ofs;
    ofs.open("./Problem1/data.csv", std::ofstream::out | std::ofstream::trunc); // clean up file
    ofs << "N,set,vector\n";
    ofs.close();

    const double lowerBound{ 10e4 };
    const double upperBound{ 10e6 };
    const int numberOfPoints{ 20 };
    const int step = (upperBound - lowerBound) / numberOfPoints;

    for (auto N = lowerBound; N != upperBound; N +=step) // tests for different N
    {
        compareSetWithVector(N);
    }

    return EXIT_SUCCESS;
}