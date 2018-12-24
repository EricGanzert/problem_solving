#include <person.hpp>
using namespace std;

Person::Person() : name("no name yet")
{
	//empty
}

Person::Person(string the_name) : name(the_name)
{
	//empty
}

Person::Person(const Person& copy) : name(copy.name)
{
	//empty
}

string Person::get_name() const
{
	return name;
}

Person& Person::operator =(const Person& right)
{
	name = right.name;
	return *this;
}

istream& operator >>(istream& in_stream, Person& object)
{
	in_stream >> object.name;
	return in_stream;
}

ostream& operator <<(ostream& out_stream, const Person& object)
{
	out_stream << object.name;
	return out_stream;
}
