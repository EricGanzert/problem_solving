#include <billing.hpp>
using namespace employee_eric;
using namespace std;

Billing::Billing() : amount_due(0)
{
	//empty
}

Billing::Billing(Patient the_patient, Doctor the_doctor)
	: patient(the_patient), doctor(the_doctor)
{
	//empty
}

Billing::Billing(const Billing& copy)
	: patient(copy.patient), doctor(copy.doctor), amount_due(copy.amount_due)
{
	//empty
}

Billing& Billing::operator =(const Billing& right)
{
	patient = right.patient;
	doctor = right.doctor;
	amount_due = right.amount_due;
	return *this;
}
	
void Billing::set_patient(Patient new_patient)
{
	patient = new_patient;
}

Patient Billing::get_patient()
{
	return patient;
}
	
void Billing::set_doctor(Doctor new_doctor)
{
	doctor = new_doctor;
}

Doctor Billing::get_doctor()
{
	return doctor;
}

void Billing::set_amount_due(double new_amount_due)
{
	amount_due = new_amount_due;
}

double Billing::get_amount_due()
{
	return amount_due;
}

void Billing::print_bill(ostream& out_stream)
{
	amount_due = doctor.get_visit_fee();
	bool is_primary_physician = (doctor == patient.get_physician());
	if (is_primary_physician)
	{
		amount_due = amount_due - amount_due*0.1;
	}
	
	cout << "\n----------------------------------------------------\n";
	cout << "Patient " << patient.get_name() << " treated by Dr. " << doctor.get_name() << "\n";
	cout << "The fee is " << amount_due << "\n";
	if (is_primary_physician)
	{
		cout << "After 10% discount for primary physician\n"; 	
	}
	cout << "----------------------------------------------------\n";
}
