#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include <iostream>

class Polynomial {
public:
	Polynomial();
	Polynomial(const Polynomial& copy);
	Polynomial(int max_exp);
	Polynomial(std::vector<double> coefs);
	~Polynomial();
	
	double evaluate(double input_value);
	double get_coefficient(int index) const;
	void set_coefficient(int index, double new_coef);
	
	Polynomial& operator =(const Polynomial& right);
	friend std::ostream& operator <<(std::ostream& out_stream, const Polynomial& right);
	
	friend Polynomial operator +(const Polynomial& left, const Polynomial& right);
	friend Polynomial operator +(const Polynomial& left, double constant);
	friend Polynomial operator +(double constant, const Polynomial& right);
	
	friend Polynomial operator -(const Polynomial& left, const Polynomial& right);
	friend Polynomial operator -(const Polynomial& left, double constant);
	friend Polynomial operator -(double constant, const Polynomial& right);	
	
	friend Polynomial operator *(const Polynomial& left, const Polynomial& right);
	friend Polynomial operator *(const Polynomial& left, double constant);
	friend Polynomial operator *(double constant, const Polynomial& right);	
	
private:
	double* value;
	int max_exp;
};

#endif //POLYNOMIAL_H
