#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>

class Person
{
public:
	Person();
	Person(std::string the_name);
	Person(const Person& the_object);
	std::string get_name() const;
	Person& operator =(const Person& right);
	
	friend std::istream& operator >>(std::istream& in_stream, Person& object);
	friend std::ostream& operator <<(std::ostream& out_stream, const Person& object);
private:
	std::string name;
};

#endif //PERSON_H
