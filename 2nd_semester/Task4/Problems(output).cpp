#include <iostream>
#include <numeric>
#include <vector>
#include <random>
#include <chrono>

int main()
{
    setlocale(LC_ALL, "Russian");
    auto print =
        [](const auto& p) { std::copy(std::begin(p), std::end(p), std::ostream_iterator<int>(std::cout, " "));
                            std::cout << '\n'; };
    // №1
    const size_t size = 10;
    std::vector<int> p1(size);
    std::iota(std::begin(p1), std::end(p1), 1);
    std::cout << "Создайте последовательность П1 целых чисел от 1 до 10:\n";
    std::cout << "p1: "; print(p1);

    // №2
    std::cout << "\nДобавьте еще несколько чисел в конец П1 из сin:\n";
    std::copy(
        std::istream_iterator <int>(std::cin),
        std::istream_iterator <int>(),
        std::back_inserter(p1));
    std::cout << "p1: "; print(p1);

    // №3
    std::shuffle(std::begin(p1), std::end(p1),
        std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count()));
    std::cout << "\nПеремешайте П1 случайным образом:\n";
    std::cout << "p1: "; print(p1);

    // №4
    std::sort(std::begin(p1), std::end(p1));
    auto tail = std::unique(std::begin(p1), std::end(p1));
    p1.erase(tail, p1.end());
    std::cout << "\nУдалите дубликаты из П1:\n";
    std::cout << "p1: "; print(p1);

    // №5
    auto count_odd = std::count_if(std::begin(p1), std::end(p1), [](auto x) { return x % 2 == 1; });
    std::cout << "\nПодсчитайте количество нечетных чисел в П1:\n";
    std::cout << "N = " << count_odd << "\n";

    // №6
    auto [min_element, max_element] = std::minmax_element(std::begin(p1), std::end(p1));
    auto min = *min_element;
    auto max = *max_element;
    std::cout << "\nОпределите минимальное и максимальное значения:\n";
    std::cout << "min = " << min << ", max = " << max << "\n";

    // №7
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
    std::cout << "\nПопробуйте найти хотя бы одно простое число в П1:\n";
    std::cout << *prime_element << "\n";

    // №8
    std::transform(std::begin(p1), std::end(p1), std::begin(p1), [](auto x) { return x * x; });
    std::cout << "\nЗамените все числа в П1 их квадратами:\n";
    std::cout << "p1: "; print(p1);

    // №9
    std::vector<int> p2(size);
    std::generate(std::begin(p2), std::end(p2),
        std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count()));
    std::cout << "\nСоздайте последовательность П2 из N случайных чисел:\n";
    std::cout << "p2: "; print(p2);

    // №10
    auto sum = std::accumulate(std::begin(p2), std::end(p2), 0);
    std::cout << "\nВычислите сумму чисел в П2:\n";
    std::cout << sum << "\n";

    // №11
    const size_t num = 3;
    std::fill(std::begin(p2), std::next(std::begin(p2), num), 1);
    std::cout << "\nЗамените первые несколько чисел в П2 числом 1:\n";
    std::cout << "p2: "; print(p2);

    // №12
    std::vector<int> p3(size);
    std::transform(std::begin(p1), std::end(p1), std::begin(p2),
        std::begin(p3), [](auto x1, auto x2) { return x1 - x2; });
    std::cout << "\nСоздайте последовательность ПЗ как разность П1 и П2:\n";
    std::cout << "p1: "; print(p1);
    std::cout << "p2: "; print(p2);
    std::cout << "p3: "; print(p3);
    
    // №13
    std::replace_if(std::begin(p3), std::end(p3), [](auto x) { return x < 0; }, 0);
    std::cout << "\nЗамените каждый отрицательный элемент в П3 нулем:\n";
    std::cout << "p3: "; print(p3);

    // №14
    std::erase(p3, 0);
    std::cout << "\nУдалите полностью все нулевые элементы из П3:\n";
    std::cout << "p3: "; print(p3);

    // №15
    std::reverse(std::begin(p3), std::end(p3));
    std::cout << "\nИзмените порядок следования элементов в ПЗ на обратный:\n";
    std::cout << "p3: "; print(p3);

    // №16
    std::partial_sort(std::begin(p3), std::next(std::begin(p3), 3), std::end(p3), std::greater());
    std::cout << "\nОпределите быстро топ - 3 наибольших элемента в П3:\n";
    std::cout << "p3: "; print(p3);

    // №17
    std::sort(std::begin(p1), std::end(p1));
    std::sort(std::begin(p2), std::end(p2));
    std::cout << "\nОтсортируйте полностью П1 и П2 по возрастанию:\n";
    std::cout << "p1: "; print(p1);
    std::cout << "p2: "; print(p2);

    // №18
    std::vector<int> p4(std::size(p1) + std::size(p2));
    std::merge(std::begin(p1), std::end(p1), std::begin(p2), std::end(p2), std::begin(p4));
    std::cout << "\nСоздайте последовательность П4 как слияние П1 и П2:\n";
    std::cout << "p4: "; print(p4);

    // №19
    auto [first, last] = std::equal_range(std::begin(p4), std::end(p4), 1);
    auto beginIndex = std::distance(std::begin(p4), first);
    auto endIndex = std::distance(std::begin(p4), last);
    std::cout << "\nОпределите диапазон для упорядоченной вставки числа 1 в П4:\n";
    std::cout << beginIndex << " - " << endIndex << "\n";

    // №20
    std::cout << "\nВыведите все последовательности в cout:\n";
    std::cout << "p1: "; print(p1);
    std::cout << "p2: "; print(p2);
    std::cout << "p3: "; print(p3);
    std::cout << "p4: "; print(p4);

    return EXIT_SUCCESS;
}