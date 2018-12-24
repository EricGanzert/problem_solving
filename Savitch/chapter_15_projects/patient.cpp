#include <patient.hpp>
using namespace std;
using namespace employee_eric;

Patient::Patient() : Person()
{
	//empty
}

Patient::Patient(string the_name, employee_eric::Doctor the_physician)
	: Person(the_name), physician(the_physician)
{
	//empty
}

Patient::Patient(const Patient& copy)
	: Person(copy), physician(copy.physician)
{
	//empty
}

Patient& Patient::operator =(const Patient& right)
{
	Person::operator =(right);
	physician = right.physician;
	return *this;
}

void Patient::set_physician(Doctor new_doc)
{
	physician = new_doc;
}

Doctor Patient::get_physician()
{
	return physician;
}
