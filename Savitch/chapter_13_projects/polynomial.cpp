#include <polynomial.hpp>
#include <cstddef>
#include <vector>
#include <string>
#include <math.h>
#include <cctype>
using namespace std;

namespace
{
	bool find(vector<int> array, int item)
	{
		for (vector<int>::iterator iter = array.begin() ; iter != array.end(); iter++)
		{
			if (*iter == item)
			{
				return true;
			}
		}
		return false;
	}
	
	bool get_node(istream& ins, poly_eric::PolyNode& node)
	{
		node.coefficient = 1;
		node.link = NULL;
		char c;
		string coeff_str;
		bool negative = false;
		
		ins >> c;
		if (c == '-')
		{
			//cout << "node is negative\n";
			negative = true;
			ins >> c;
		}
		while (c != 'x' && c != 'X' && c != '\n')
		{
			//cout << c << "\n";
			if (!isdigit(c))
			{
				cout << "coefficient invalid\n";
				return false;
			}
			coeff_str += c;
			ins.get(c);
			if (c == '\n' || c == ' ')
			{
				if (coeff_str.length() != 0)
				{
					node.coefficient = stoi(coeff_str);
					//cout << "coefficient is " << node.coefficient << "\n"; 
					if (negative)
					{
						node.coefficient = -node.coefficient;
					}	
				}
				node.order = 0;
				//cout << "the order is " << node.order << "\n";
				return true;
			}
		}
		if (coeff_str.length() != 0)
		{
			node.coefficient = stoi(coeff_str);
			//cout << "coefficient is " << node.coefficient << "\n"; 
			if (negative)
			{
				node.coefficient = -node.coefficient;
			}	
		}
		char x = c;
		char exp;
		//cout << x << "\n";
		ins.get(exp);
		//cout << exp << "\n";
		
		if ((x != 'x' && x != 'X') || exp != '^')
		{
			return false;
		}
		
		string exp_str;
		ins >> c;
		while (isdigit(c))
		{
			//cout << c << "\n";
			exp_str += c;
			ins.get(c);
		}
		if (exp_str.length() == 0)
		{
			cout << "no exponent found\n";
			return false;
		}
		
		node.order = stoi(exp_str);
		//cout << "exponent is " << node.order << "\n";
		return true;
	}
	
	bool get_sign(istream& ins, int& sign)
	{
		string str;
		char c;
		char space;
		ins.get(c);
		//cout << c << "\n";
		if (c == '+')
		{
			sign = 1;
			//cout << "sign is positive\n";
			ins.get(space);
			//cout << space << "\n";
			return (space == ' ');
		}
		else if (c == '-')
		{
			sign = -1;
			ins.get(space);
			//cout << "sign is negative\n";
			//cout << space << "\n";
			return (space == ' ');
		}
		else
		{
			cout << "Failed to find sign\n";
			return false;
		}
	}
}

namespace poly_eric
{
	Polynomial::Polynomial() : front(NULL)
	{
		//empty
	}
	
	Polynomial::Polynomial(const Polynomial& copy) : front(NULL)
	{
		if (copy.front == NULL)
		{
			return;
		}
		
		front = new PolyNode;
		front->coefficient = copy.front->coefficient;
		front->order = copy.front->order;
		front->link = NULL;
			
		PolyNodePtr iter_copy = copy.front->link;
		PolyNodePtr iter = front;
		
		while(iter_copy != NULL)
		{
			iter->link = new PolyNode;
			iter = iter->link;
			iter->coefficient = iter_copy->coefficient;
			iter->order = iter_copy->order;
			iter_copy = iter_copy->link;
			iter->link = NULL;
		}
	}
	
	Polynomial::Polynomial(int coef, int order)
	{
		front = new PolyNode;
		front->coefficient = coef;
		front->order = order;
		front->link = NULL;
	}
	
	Polynomial::~Polynomial()
	{
		while (front != NULL)
		{
			PolyNodePtr remove = front;
			front = front->link;
			delete remove;
		}
	}
	
	int Polynomial::evaluate(int input_value)
	{
		int result = 0;
		PolyNodePtr iter = front;
		
		while (iter != NULL)
		{
			result += iter->coefficient * pow(input_value, iter->order);
			iter = iter->link;
		}
		
		return result;
	}
	
	Polynomial& Polynomial::operator =(const Polynomial& right)
	{
		//first delete all the nodes
		while (front != NULL)
		{
			PolyNodePtr remove = front;
			front = front->link;
			delete remove;
		}
		
		//now head == NULL
		if (right.front == NULL)
		{
			return *this;
		}
		
		front = new PolyNode;
		front->coefficient = right.front->coefficient;
		front->order = right.front->order;
		front->link = NULL;
			
		PolyNodePtr iter_copy = right.front->link;
		PolyNodePtr iter = front;
		
		while(iter_copy != NULL)
		{
			iter->link = new PolyNode;
			iter = iter->link;
			iter->coefficient = iter_copy->coefficient;
			iter->order = iter_copy->order;
			iter_copy = iter_copy->link;
			iter->link = NULL;
		}
		//cout << "done assignment operator: " << *this << "\n";
		return *this;
	}
	
	istream& operator >>(istream& in_stream, Polynomial& right)
	{
		while (right.front != NULL)
		{
			PolyNodePtr temp = right.front;
			right.front = right.front->link;
			delete temp;
		}
		
		PolyNode current_node;
		int sign;
		
		if (get_node(in_stream, current_node))
		{
			right.front = new PolyNode;
			*right.front = current_node;
			right.front->link = NULL;
		}
		else
		{
			cout << "Failed to input Polynomial\n";
			exit(1);			
		}
		
		//cout << "got first term\n";
		PolyNodePtr iter = right.front;
		
		if (!current_node.order == 0)
		{
			while (get_sign(in_stream, sign))
			{
				if (get_node(in_stream, current_node))
				{
					current_node.coefficient = sign*current_node.coefficient;
					iter->link = new PolyNode;
					iter = iter->link;
					*iter = current_node;
					iter->link = NULL;
					if (current_node.order == 0)
					{
						break;
					}
				}
			}
		}
		
		//now we should have all the nodes
		cout << "done input\n";
		
		return in_stream;
	}
	
	ostream& operator <<(ostream& out_stream, const Polynomial& right)
	{
		if (right.front == NULL)
		{
			return out_stream;
		}
		PolyNodePtr iter = right.front;
		
		out_stream << iter->coefficient;
		if (iter->order > 0)
		{ 
			out_stream << "x^" << iter->order;
		}
		
		while(iter->link != NULL)
		{
			iter = iter->link;
			if (iter->coefficient < 0)
				out_stream << " - ";
			else
				out_stream << " + ";
				
			out_stream << abs(iter->coefficient);
			if (iter->order > 0)
			{ 
				out_stream << "x^" << iter->order;
			}
		}
		return out_stream;
	}
	
	void Polynomial::collect_terms()
	{
		//cout << "collecting terms for " << *this << "\n";
		if (front == NULL)
		{
			return;
		}
		vector<int> powers;
		//start by identifying the order of the polynomial,
		//the highest power. And collect all the 
		
		PolyNodePtr iter = front;
		powers.push_back(iter->order);
		iter = iter->link;
		
		while (iter != NULL)
		{
			if (!find(powers, iter->order))
			{
				powers.push_back(iter->order);
			}
			iter = iter->link;
		}
		//now we have all the powers that appear in the polynomial
		
		for (vector<int>::iterator iter = powers.begin(); iter != powers.end(); iter++)
		{
			int current_power = *iter;
			PolyNodePtr temp = front;
			bool power_seen = false;
			PolyNodePtr first_term_with_power;
			int coefficient_collect = 0;
			while (temp != NULL)
			{
				if (temp->order == current_power)
				{
					coefficient_collect += temp->coefficient;
					if (!power_seen)
					{
						first_term_with_power = temp;
						power_seen = true;
					}
					else
					{
						PolyNodePtr before_remove = first_term_with_power;
						while(before_remove->link->order != current_power)
						{
							before_remove = before_remove->link;
						}
						
						PolyNodePtr remove = temp;
						temp = temp->link;
						before_remove->link = remove->link;
						delete remove;
						continue;
					}
				}
				temp = temp->link;
			}
			first_term_with_power->coefficient = coefficient_collect;
		}
		//sort_terms();
	}
	
	Polynomial operator +(const Polynomial& left, const Polynomial& right)
	{
		//cout << "adding together " << left << " and " << right << "\n";
		Polynomial result;
		if (left.front == NULL)
		{
			result = right;
			return result;
		}
		else if (right.front == NULL)
		{
			result = left;
			return result;
		}
		else
		{
			result = left;
		}
		//cout << "starting with left half " << result << "\n";
		
		PolyNodePtr temp = result.front;
		while (temp->link != NULL)
		{
			temp = temp->link;
		}
		
		for (PolyNodePtr iter_r = right.front; iter_r != NULL; iter_r = iter_r->link)
		{
			temp->link = new PolyNode;
			temp = temp->link;
			temp->coefficient = iter_r->coefficient;
			temp->order = iter_r->order;					
		}
		temp->link = NULL;
		result.collect_terms();
		//cout << "result of addition: " << result << "\n";
		return result;
	}
	
	Polynomial operator +(const Polynomial& left, double constant)
	{
		Polynomial result(left);
		//is there a power 0 term?
		PolyNodePtr iter = result.front;
		while (iter->link != NULL)
		{
			if (iter->order == 0)
			{
				iter->coefficient += constant;
				return result;
			}
			iter = iter->link;
		}
		//we have to make a new node
		iter->link = new PolyNode;
		iter = iter->link;
		iter->coefficient = constant;
		iter->order = 0;
		iter->link = NULL; 
		
		return result;
	}
	
	Polynomial operator +(double constant, const Polynomial& right)
	{
		return (right + constant);
	}
	
	Polynomial operator -(const Polynomial& left, const Polynomial& right)
	{
		//cout << "adding together " << left << " and " << right << "\n";
		Polynomial result;
		if (left.front == NULL)
		{
			result = -1 * right;
			return result;
		}
		else if (right.front == NULL)
		{
			result = left;
			return result;
		}
		else
		{
			result = left;
			//cout << "starting with left half: " << result << "\n";
		}
		
		PolyNodePtr temp = result.front;
		while (temp->link != NULL)
		{
			temp = temp->link;
		}
		
		for (PolyNodePtr iter_r = right.front; iter_r != NULL; iter_r = iter_r->link)
		{
			temp->link = new PolyNode;
			temp = temp->link;
			temp->coefficient = -1 * iter_r->coefficient;
			temp->order = iter_r->order;					
		}
		temp->link = NULL;
		result.collect_terms();
		//cout << "result of addition: " << result << "\n";
		return result;
	}
	
	Polynomial operator -(const Polynomial& left, double constant)
	{
		return left + (-1 * constant);
	}
	
	Polynomial operator -(double constant, const Polynomial& right)
	{
		Polynomial result = right;
		PolyNodePtr iter = result.front;
		while (iter != NULL)
		{
			iter->coefficient *= -1; 
			iter = iter->link;
		}
		return result + constant;
	}

	Polynomial operator *(const Polynomial& left, const Polynomial& right)
	{
		Polynomial result;
		for (PolyNodePtr iter_l = left.front; iter_l != NULL; iter_l = iter_l->link)
		{
			for (PolyNodePtr iter_r = right.front; iter_r != NULL; iter_r = iter_r->link)
			{
				Polynomial add((iter_l->coefficient * iter_r->coefficient), (iter_l->order + iter_r->order));
				result = result + add;
			}
		}
		return result;
	}
	
	Polynomial operator *(const Polynomial& left, double constant)
	{
		Polynomial result = left;
		PolyNodePtr iter = result.front;
		
		while (iter != NULL)
		{
			iter->coefficient *= constant;
			iter = iter->link;
		}
		return result;
	}
	
	Polynomial operator *(double constant, const Polynomial& right)
	{
		return (right * constant);
	}
}
