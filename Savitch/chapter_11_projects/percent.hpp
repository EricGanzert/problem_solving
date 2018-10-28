#ifndef PERCENT_H
#define PERCENT_H

#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

class Percent
{
public:
	friend bool operator ==(const Percent& first, const Percent& second);
	friend bool operator <(const Percent& first, const Percent& second);
	
	Percent();
	Percent(int percent_value);
	
	friend std::istream& operator >>(std::istream& ins, Percent& second);
	friend std::ostream& operator <<(std::ostream& outs, const Percent& second);
	
	
	friend Percent operator +(const Percent& first, const Percent& second);
	friend Percent operator -(const Percent& first, const Percent& second);
	friend Percent operator *(const Percent& first, int second);
	
private:
	int value;
};

#endif //PERCENT_H
