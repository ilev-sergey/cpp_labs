#include <iostream>

class MyClass;          // класс, к экземплярам которого требуется получить доступ
class AccessProvider;   // промежуточный класс, который обеспечивает предоставление доступа
void function(MyClass&); // функция, которая должна получить ограниченный доступ к MyClass


class MyClass
{
private:
    int m_x;
    int m_y;

public:
    MyClass(int x = 0, int y = 0) : m_x{ x }, m_y{ y } {}
    friend AccessProvider;
};

class AccessProvider
{
private:
    MyClass _object;
    AccessProvider(MyClass& object) : _object{ object } {};

    int getX() const
    {
        return _object.m_x;
    }

    friend void function(MyClass&);
};

void function(MyClass& object)
{
    AccessProvider provider(object);                // создаём экземпляр класса-провайдера
                                                    // с данными экземпляра object
    std::cout << "x = " << provider.getX() << '\n'; // функция может получать значение поля "x"
}

int main()
{
    std::cout << "Enter x, y:\n";
    int x;
    std::cin >> x;
    int y;
    std::cin >> y;

    MyClass object{ x, y }; // создаём экземпляр класса, с которым мы работаем
    function(object);       // передаём экземпляр в функцию
}

// function имеет ограниченный доступ к полю "x" экземпляра класса MyClass:
// может получить значение, но не изменить его.
// При этом function не имеет доступа к остальным полям ("y").
// 
// При необходимости добавления функций необходимо создать свой класс-провайдер для каждой функции,
// в котором необходимо объявить функцию другом и определить необходимые геттеры/сеттеры для данных,
// к которым требуется доступ.