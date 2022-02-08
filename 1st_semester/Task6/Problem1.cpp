#include <iostream>
#include <vector>

class ClassName
{
private:
    int m_length;
    int* m_array;
    std::vector<int> m_vector;

public:
    ClassName(const std::vector<int>& vector, int length = 0, int* array = nullptr) : // конструктор с переданным вектором
        m_vector{ vector }, m_length{ length }, m_array{ array } {}

    ClassName(int length = 0, int* array = nullptr) : // конструктор без переданного вектора
        m_length{ length }, m_array{ array } {}

    ~ClassName()
    {
        delete[] m_array;
    }

    ClassName(const ClassName& other) : m_length{other.m_length} // конструктор копирования
    {
        m_array = new int[m_length]; // выделяем память под массив

        for (int i = 0; i < m_length; ++i) // поэлементно копируем переданный массив
        {
            m_array[i] = other.m_array[i];
        }

        m_vector = other.m_vector; // копируем переданный вектор
    };

    ClassName(ClassName&& other) : m_length{other.m_length}, m_array{other.m_array} // указатель на массив инициализируется переданным указателем
    {
        other.m_length = 0; // очищаем переданные длину и указатель
        other.m_array = nullptr;
        m_vector = std::move(other.m_vector); // перемещаем переданный vector, он очищается самостоятельно
    }

    ClassName& operator=(const ClassName& other)
    {
        if (this == &other) // проверка на самоприсваивание
        {
            return *this;
        }

        if (m_length) // очищаем память с содержимым массива
        {
            m_length = 0;
            delete[] m_array;
        }

        m_length = other.m_length;

        m_array = new int[m_length]; // выделяем память под массив (теперь для нужного числа элементов)

        for (int i = 0; i < m_length; ++i) // поэлементно копируем переданный массив
        {
            m_array[i] = other.m_array[i];
        }

        m_vector = other.m_vector; // копируем переданный vector

        return *this;
    }

    ClassName& operator=(ClassName&& other) 
    {
        if (this == &other) // проверка на самоприсваивание
        {
            return *this;
        }

        if (m_length) // очищаем память с содержимым массива
        {
            m_length = 0;
            delete[] m_array;
        }

        m_length = other.m_length;

        m_array = new int[m_length]; // выделяем память под массив (теперь для нужного числа элементов)

        for (int i = 0; i < m_length; ++i) // поэлементно копируем переданный массив
        {
            m_array[i] = other.m_array[i];
        }

        other.m_length = 0;
        other.m_array = nullptr;
        m_vector = std::move(other.m_vector); // перемещаем переданный vector, он очищается самостоятельно

        return *this;
    }

    friend std::ostream& operator<< (std::ostream&, const ClassName&);
};

std::ostream& operator<< (std::ostream& out, const ClassName& right)
{
    out << "Length: ";
    out << right.m_length << "\n";

    out << "Array:  ";
    if (right.m_length == 0)
    {
        out << "Empty";
    }
    else
    {
        for (int i = 0; i < right.m_length; ++i)
        {
            out << right.m_array[i] << " ";
        }
    }

    out << "\n";

    out << "Vector: ";
    if (right.m_vector.size() == 0)
    {
        out << "Empty";
    }
    else
    {
        for (int i = 0; i < right.m_vector.size(); ++i)
        {
            out << right.m_vector[i] << " ";
        }
    }

    out << "\n\n";

    return out;
}

int main()
{
    setlocale(LC_ALL, "Russian");

// Конструктор
    std::cout << "Конструктор:\n\n";

    ClassName test1{ std::vector<int>{1, -9}, 2, new int[2]{ 1, 7 } };
    std::cout << test1;

    ClassName test2{ 2, new int[2]{ 1, 7 } };
    std::cout << test2;

    ClassName test3;
    std::cout << test3;

    std::cout << "===================\n\n";

// Констуктор копирования
    std::cout << "Конструктор копирования:\n\n";

    ClassName test4{ test1 };
    std::cout << test4;

    std::cout << "===================\n\n";

// Констуктор перемещения
    std::cout << "Конструктор перемещения:\n\n";

    ClassName test5{ std::move(test1) };
    std::cout << test5;
    std::cout << test1;

    std::cout << "===================\n\n";

    test1 = { std::vector<int>{1, -9}, 2, new int[2]{ 1, 7 } };

// Оператор присваивания копированием
    std::cout << "Оператор присваивания копированием:\n\n";

    ClassName test6;
    test6 = test1;
    std::cout << test6;

    std::cout << "===================\n\n";

// Оператор присваивания перемещением
    std::cout << "Оператор присваивания перемещением:\n\n";

    ClassName test7;
    test7 = std::move(test1);
    std::cout << test7;
    std::cout << test1;

    std::cout << "===================\n\n";

    return EXIT_SUCCESS;
}