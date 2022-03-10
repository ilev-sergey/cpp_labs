#include <iostream>
#include <numeric>
#include <vector>
#include <random>
#include <chrono>

int main()
{
    // ¹1
    const size_t size = 10;
    std::vector<int> p1(size);
    std::iota(std::begin(p1), std::end(p1), 1);

    // ¹2
    std::copy(
        std::istream_iterator <int>(std::cin),
        std::istream_iterator <int>(),
        std::back_inserter(p1));

    // ¹3
    std::shuffle(std::begin(p1), std::end(p1),
        std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count()));

    // ¹4
    std::sort(std::begin(p1), std::end(p1));
    auto tail = std::unique(std::begin(p1), std::end(p1));
    p1.erase(tail, p1.end());

    // ¹5
    auto count_odd = std::count_if(std::begin(p1), std::end(p1), [](auto x) { return x % 2 == 1; });

    // ¹6
    auto [min_element, max_element] = std::minmax_element(std::begin(p1), std::end(p1));
    auto min = *min_element;
    auto max = *max_element;

    // ¹7
    auto isPrime = [](auto x)
    {
        if (x < 2) return false;
        if (x == 2) return true;
        if (x % 2 == 0) return false;
        for (int i = 3; (i * i) <= x; i += 2)
        {
            if (x % i == 0) return false;
        }
        return true;
    };
    auto prime_element = std::find_if(std::begin(p1), std::end(p1), isPrime);

    // ¹8
    std::transform(std::begin(p1), std::end(p1), std::begin(p1), [](auto x) { return x * x; });

    // ¹9
    std::vector<int> p2(size);
    std::generate(std::begin(p2), std::end(p2),
        std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count()));

    // ¹10
    auto sum = std::accumulate(std::begin(p2), std::end(p2), 0);

    // ¹11
    const size_t num = 3;
    std::fill(std::begin(p2), std::next(std::begin(p2), num), 1);

    // ¹12
    std::vector<int> p3(size);
    std::transform(std::begin(p1), std::end(p1), std::begin(p2),
        std::begin(p3), [](auto x1, auto x2) { return x1 - x2; });

    // ¹13
    std::replace_if(std::begin(p3), std::end(p3), [](auto x) { return x < 0; }, 0);

    // ¹14
    std::erase(p3, 0);

    // ¹15
    std::reverse(std::begin(p3), std::end(p3));

    // ¹16
    std::partial_sort(std::begin(p3), std::next(std::begin(p3), 3), std::end(p3), std::greater());

    // ¹17
    std::sort(std::begin(p1), std::end(p1));
    std::sort(std::begin(p2), std::end(p2));

    // ¹18
    std::vector<int> p4(std::size(p1) + std::size(p2));
    std::merge(std::begin(p1), std::end(p1), std::begin(p2), std::end(p2), std::begin(p4));

    // ¹19
    auto [first, last] = std::equal_range(std::begin(p4), std::end(p4), 1);
    auto beginIndex = std::distance(std::begin(p4), first);
    auto endIndex = std::distance(std::begin(p4), last);

    // ¹20
    auto print =
        [](const auto& p) { std::copy(std::begin(p), std::end(p), std::ostream_iterator<int>(std::cout, " "));
                            std::cout << '\n'; };
    print(p1);
    print(p2);
    print(p3);
    print(p4);

    return EXIT_SUCCESS;
}