#include <iostream>
#include <chrono>

int main()
{
    using s300 = std::chrono::duration<  // создаём псевдоним для типа, соответствующего интервалу времени
        int, std::ratio<300>>;           // в 300 секунд, тип целочисленный

    using m5 = std::chrono::duration<    // создаём псевдоним для типа, соответствующего интервалу времени,
        int, std::ratio_multiply<        // в 5 минут (равен произведению дробей
        std::ratio<5>,                   // 5/1 и
        std::chrono::minutes::period>>;  // 60/1 (длительность минуты в секундах))

    s300 numberOf300s{ 12 }; // переменная, равная интервалу 300с * 12
    m5 numberOf5m{ 12 };     // переменная, равная интервалу 5м * 24

    std::cout << std::boolalpha << (numberOf300s == numberOf5m) << "\n"; // true

    // неявное преобразование в секунды
    std::cout << std::chrono::seconds(numberOf5m) << "\n\n"; // 3600s

    // неявное преобразование в часы не разрешено
    // std::cout << std::chrono::hours(numberOf5m) << "\n\n";

    // значение переменной
    std::chrono::duration<int, std::chrono::minutes::period> t1 = numberOf5m; // приведение пятиминутного типа к минутам
    std::cout << t1.count() << "\n"; // 60 - количество минут

    // округление в сторону ближайшего целого
    std::cout << std::chrono::round<std::chrono::hours>(numberOf5m) << "\n\n"; // 1h

    // преобразование к float-типу
    using fhours = std::chrono::duration<float, std::chrono::hours::period>;
    fhours hours{ numberOf5m };
    std::cout << hours << "\n"; // 1h

    // засечение времени
    auto start = std::chrono::steady_clock::now(); // auto = std::chrono::time_point<std::chrono::steady_clock>
    // actions
    auto end = std::chrono::steady_clock::now();
    auto elapsed = duration_cast<std::chrono::nanoseconds>(end - start); // 300ns
    std::cout << elapsed << "\n";

    return EXIT_SUCCESS;
}