#pragma once
#include<iostream>
#include<string>
#include"Exception.h"

class Fraction
{
private:
	int numerator_{0};
	int denominator_{ 0 };

	void shorten();
	int NOD(int a, int b);
	std::string print();
public:
	Fraction(int numerator, int denominator);
	~Fraction();
	bool operator==(Fraction& fr);
	bool operator!=(Fraction& fr);
	bool operator<(Fraction& fr);
	bool operator>(Fraction& fr);
	bool operator<=(Fraction& fr);
	bool operator>=(Fraction& fr);
	Fraction operator+(Fraction& fr);
	Fraction operator-(Fraction& fr);
	Fraction operator*(Fraction& fr);
	Fraction operator/(Fraction& fr);
	Fraction& operator++();
	Fraction operator++(int);
	Fraction& operator--();
	Fraction operator--(int);
	friend std::ostream& operator<<(std::ostream& l, Fraction r);
	
};