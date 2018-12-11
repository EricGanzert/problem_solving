#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>

namespace poly_eric
{
	struct PolyNode
	{
		int coefficient;
		int order;
		PolyNode* link;
	};
	typedef PolyNode* PolyNodePtr;
	
	class Polynomial {
	public:
		Polynomial();
		Polynomial(const Polynomial& copy);
		Polynomial(int coef, int order);
		~Polynomial();
		
		int evaluate(int input_value);
		// returns the result of substituting input_value
		// for x in the polynomial and soving it
		
		bool has_node(int coeff, int power);
		// returns true if the polynomial contains a term with the
		// specified coefficient and power
		
		bool has_power(int coeff, int power);
		// returns true if the polynomial contains a term with the
		// specified coefficient and power
		
		Polynomial& operator =(const Polynomial& right);
		friend std::istream& operator >>(std::istream& in_stream, Polynomial& right);
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
		void collect_terms();
		// collects coefficients of terms with the same order
		// for example if the polynomial has 3x^2 and 2x^2 
		// in it then combine them for 5x^2
		PolyNodePtr front;
	};
}

#endif //POLYNOMIAL_H
