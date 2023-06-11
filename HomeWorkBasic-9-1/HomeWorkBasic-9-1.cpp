#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	Fraction(int numerator) {
		numerator_ = numerator;
		denominator_ = 1;
	}

	bool operator==(Fraction f2) {
		Fraction f1(numerator_ * f2.denominator_);
		f2.numerator_ = f2.numerator_ * denominator_;
		if (f1.numerator_ == f2.numerator_) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator!=(Fraction f2) {
		return !(*this == f2);
	}

	bool operator<(Fraction f2) {
		Fraction f1(numerator_ * f2.denominator_);
		f2.numerator_ = f2.numerator_ * denominator_;
		if ((f1.numerator_ < f2.numerator_)) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator>(Fraction f2) {
		return !(*this < f2);
	}

	bool operator<=(Fraction f2) {
		return ((*this < f2) || (*this == f2));
	}

	bool operator>=(Fraction f2) {
		return (!(*this < f2) || (*this == f2));
	}
};

int main()
{
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}
