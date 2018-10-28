#ifndef PAIRS_H
#define PAIRS_H

#include <iostream>
#include <fstream>

using namespace std;

class Pairs
{
public:
	Pairs();
	Pairs(int first);
	Pairs(int first, int second);
	
	friend std::ostream& operator <<(std::ostream& outs, Pairs& second);
	friend std::istream& operator >>(std::istream& ins, Pairs& second);
	
	friend Pairs operator +(Pairs& first, Pairs& second);
	friend Pairs operator *(Pairs& first, Pairs& second);
private:
	int f;
	int s;
};

#endif //PAIRS_H 
