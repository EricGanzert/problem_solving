#ifndef BILLING_H
#define BILLING_H
#include <patient.hpp>
#include <iostream>

class Billing
{
public:
	Billing();
	Billing(Patient the_patient, employee_eric::Doctor the_doctor);
	Billing(const Billing& copy);
	Billing& operator =(const Billing& right);
	
	void set_patient(Patient new_patient);
	Patient get_patient();
	
	void set_doctor(employee_eric::Doctor new_doctor);
	employee_eric::Doctor get_doctor();
	
	void set_amount_due(double new_amount_due);
	double get_amount_due();
	
	void print_bill(std::ostream& out_stream);
	
private:
	Patient patient;
	employee_eric::Doctor doctor;
	double amount_due;
};

#endif //BILLING_H
