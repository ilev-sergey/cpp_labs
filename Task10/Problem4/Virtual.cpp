#include <iostream>

class Base
{
public:
    virtual void print()
    {
        std::cout << "Base\n";
    }
};

class Derived1 : public Base
{
public:
    virtual void print()
    {
        std::cout << "Derived1\n";
    }
};

class Derived2 : public Base
{
public:
	virtual void print()
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