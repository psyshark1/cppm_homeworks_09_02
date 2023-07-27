#include"Fraction.h"
#include"Exception.h"

Fraction::Fraction(int numerator, int denominator)
{	
	if (!numerator || !denominator) { throw NullArg("Numerator or denominator not be null!"); }
	numerator_ = numerator;
	denominator_ = denominator;
	shorten();
}
Fraction::~Fraction()
{
}
bool Fraction::operator==(Fraction& fr)
{
	if (numerator_ == fr.numerator_ && denominator_ == fr.numerator_) return true;
	return ((numerator_ * fr.denominator_) == (fr.numerator_ * denominator_));
}
bool Fraction::operator!=(Fraction& fr)
{
	return ((numerator_ * fr.denominator_) != (fr.numerator_ * denominator_));
}
bool Fraction::operator<(Fraction& fr)
{
	if (denominator_ == fr.denominator_)
	{
		return (numerator_ > fr.numerator_);
	}
	if (numerator_ == fr.numerator_)
	{
		return (denominator_ > fr.denominator_);
	}
	return ((numerator_ * fr.denominator_) < (fr.numerator_ * denominator_));
}
bool Fraction::operator>(Fraction& fr)
{
	if (denominator_ == fr.denominator_)
	{
		return (numerator_ > fr.numerator_);
	}
	if (numerator_ == fr.numerator_)
	{
		return (denominator_ > fr.denominator_);
	}
	return ((numerator_ * fr.denominator_) > (fr.numerator_ * denominator_));
}
bool Fraction::operator<=(Fraction& fr)
{
	if (denominator_ == fr.denominator_)
	{
		return (numerator_ > fr.numerator_);
	}
	if (numerator_ == fr.numerator_)
	{
		return (denominator_ > fr.denominator_);
	}
	return ((numerator_ * fr.denominator_) <= (fr.numerator_ * denominator_));
}
bool Fraction::operator>=(Fraction& fr)
{
	if (denominator_ == fr.denominator_)
	{
		return (numerator_ > fr.numerator_);
	}
	if (numerator_ == fr.numerator_)
	{
		return (denominator_ > fr.denominator_);
	}
	return ((numerator_ * fr.denominator_) >= (fr.numerator_ * denominator_));
}

Fraction Fraction::operator+(Fraction& fr)
{
	return Fraction((numerator_ * fr.denominator_) + (fr.numerator_ * denominator_), denominator_ * fr.denominator_);
}

Fraction Fraction::operator-(Fraction& fr)
{
	return Fraction((numerator_ * fr.denominator_) - (fr.numerator_ * denominator_), denominator_ * fr.denominator_);
}

Fraction Fraction::operator*(Fraction& fr)
{
	return Fraction((numerator_ * fr.numerator_), (denominator_ * fr.denominator_));
}

Fraction Fraction::operator/(Fraction& fr)
{
	return Fraction((numerator_ * fr.denominator_), (denominator_ * fr.numerator_));
}

Fraction& Fraction::operator++()
{
	numerator_ = numerator_ + denominator_;
	return *this;
}

Fraction Fraction::operator++(int)
{
	Fraction tmp = *this;
	++(*this);
	return tmp;
}

Fraction& Fraction::operator--()
{
	numerator_ = numerator_ - denominator_;
	return *this;
}

Fraction Fraction::operator--(int)
{
	Fraction tmp = *this;
	--(*this);
	return tmp;
}

void Fraction::shorten()
{
	if (numerator_ > denominator_)
	{
		if (!(numerator_ % denominator_) && abs(denominator_) != 1)
		{
			numerator_ = numerator_ / denominator_;
			denominator_ = 1;
			return;
		}
		int nod = NOD(std::abs(numerator_), std::abs(denominator_));
		if (nod == 1) { return; }
		numerator_ = numerator_ / nod;
		denominator_ = denominator_ / nod;
		return;

	}
	else if (numerator_ < denominator_)
	{
		if (!(denominator_ % numerator_) && abs(numerator_) != 1)
		{
			denominator_ = denominator_ / numerator_;
			numerator_ = 1;
			return;
		}
		int nod = NOD(std::abs(numerator_), std::abs(denominator_));
		if (nod == 1) { return; }
		numerator_ = numerator_ / nod;
		denominator_ = denominator_ / nod;
		return;
	}
	denominator_ = 1;
	numerator_ = 1;
	return;
}
int Fraction::NOD(int a, int b) {
	if (a < b) {
		std::swap(a, b);
	}
	while (a % b) {
		a = a % b;
		std::swap(a, b);
	}
	return b;
}
std::string Fraction::print()
{
	return std::to_string(numerator_) + "/" + std::to_string(denominator_);
}