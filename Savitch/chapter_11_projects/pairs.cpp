#include <pairs.hpp>

ostream& operator <<(ostream& outs, Pairs& second)
{
	outs << "(" << second.f << "," << second.s << ") ";
	return outs;
}

istream& operator >>(istream& ins, Pairs& second)
{
	char left_bracket, comma, right_bracket;
	ins >> left_bracket >> second.f >> comma >> second.s >> right_bracket;
	return ins;
}

Pairs operator +(Pairs& first, Pairs& second)
{
	return Pairs(first.f + second.f, first.s + second.s);
}

Pairs operator *(Pairs& first, Pairs& second)
{
	return Pairs(first.f * second.f, first.s * second.s);
}

Pairs::Pairs() : f(0), s(0)
{
}

Pairs::Pairs(int first) : f(first), s(0)
{
}

Pairs::Pairs(int first, int second) : f(first), s(second)
{
}

