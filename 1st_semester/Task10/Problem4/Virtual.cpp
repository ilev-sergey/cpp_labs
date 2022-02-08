#include <iostream>

class Base
{
public:
    virtual ~Base() = default;

    virtual void print() const
    {
        std::cout << "Base\n";
    }
};

class Derived1 : public Base
{
public:
    virtual ~Derived1() = default;

    virtual void print() const override
    {
        std::cout << "Derived1\n";
    }
};

class Derived2 : public Base
{
public:
    virtual ~Derived2() = default;

	virtual void print() const override
	{
		std::cout << "Derived2\n";
	}
};

int main()
{
    Base base;
    base.print();

    Derived1 derived1;
    derived1.print();

	Derived2 derived2;
	derived2.print();
 
    return EXIT_SUCCESS;
}