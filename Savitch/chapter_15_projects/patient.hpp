#ifndef PATIENT_H
#define PATIENT_H
#include <person.hpp>
#include <doctor.hpp>

class Patient : public Person
{
public: 
	Patient();
	Patient(std::string the_name, employee_eric::Doctor the_physician);
	Patient(const Patient& copy);
	Patient& operator =(const Patient& right);
	
	void set_physician(employee_eric::Doctor new_doc);
	employee_eric::Doctor get_physician();
private: 
	employee_eric::Doctor physician; 
};

#endif //PATIENT_H
