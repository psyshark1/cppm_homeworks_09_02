#include <iostream>
#include"Fraction.h"

int main()
{
	std::system("chcp 1251");

	Fraction* f1 = nullptr;
	Fraction* f2 = nullptr;

	try
	{
		int a; int b;
		std::cout << "Введите числитель дроби 1: ";
		std::cin >> a;
		std::cout << "Введите знаменатель дроби 1: ";
		std::cin >> b;
		f1 = new Fraction(a, b);

		std::cout << "Введите числитель дроби 2: ";
		std::cin >> a;
		std::cout << "Введите знаменатель дроби 2: ";
		std::cin >> b;
		f2 = new Fraction(a, b);
	}
	catch (const NullArg& ex)
	{
		std::cout << ex.what() << '\n';
		std::system("pause");
		return 66;
	}

	std::cout << *f1 << " + " << *f2 << " = " << *f1 + *f2 << '\n';
	std::cout << *f1 << " - " << *f2 << " = " << *f1 - *f2 << '\n';
	std::cout << *f1 << " * " << *f2 << " = " << *f1 * *f2 << '\n';
	std::cout << *f1 << " / " << *f2 << " = " << *f1 / *f2 << '\n';
	std::cout << "++" << *f1 << " * " << *f2 << " = ";
	std::cout << ++ *f1 * *f2 << '\n';
	std::cout << "Значение дроби 1 = " << *f1 << '\n';
	std::cout  << *f1 << "--" << " * " << *f2 << " = ";
	std::cout << (*f1)-- * *f2 << '\n';
	std::cout << "Значение дроби 1 = " << *f1 << '\n';
	std::system("pause");
	return 0;
}

std::ostream& operator<<(std::ostream& l, Fraction r)
{
	return l << r.print();
}