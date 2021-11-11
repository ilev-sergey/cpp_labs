#include <iostream>

template<class Derived>
class Base
{
public:
	void print()
	{
		static_cast<Derived*> (this)->printImplementation();
	}
};

class Derived1 : public Base<Derived1>
{
public:
	void printImplementation()
	{
		std::cout << "Derived1\n";
	}
};

class Derived2 : public Base<Derived2>
{
public:
	void printImplementation()
	{
		std::cout << "Derived2\n";
	}
};

int main()
{
	Derived1 derived1;
	derived1.print();

	Derived2 derived2;
	derived2.print();

	return EXIT_SUCCESS;
}