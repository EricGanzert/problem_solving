#ifndef VECTOR_DOUBLE_H
#define VECTOR_DOUBLE_H

#include <fstream>

using namespace std;

enum { VECTOR_DOUBLE_INVALID_INDEX };

class VectorDouble {
public:
	VectorDouble& operator =(const VectorDouble& second);
	friend bool operator ==(const VectorDouble& first, const VectorDouble& second);
	friend ostream& operator <<(ostream& outs, const VectorDouble& output);
	
	VectorDouble();
	VectorDouble(int size_arg);
	VectorDouble(const VectorDouble& copy);
	~VectorDouble();
	
	void push_back(double new_item);
	int capacity();
	int size();
	int reserve();
	void resize(int new_size);
	double value_at(int index);
	void change_value_at(int index, double new_item);
	
private:
	double *dynamic_array;
	int max_count;
	int count;
};

#endif //VECTOR_DOUBLE_H
