#ifndef STRINGSET_H
#define STRINGSET_H

#include <vector>
#include <string>
#include <iostream>

class StringSet {
public:
	StringSet();
	StringSet(const std::string array[], int len);
	StringSet(const StringSet& copy);
	~StringSet();
	
	void add(std::string new_item);
	std::string remove(int index);
	int num_strings() const;
	void clear_set();
	
	friend std::ostream& operator <<(std::ostream& outs, const StringSet& the_set);
	friend StringSet operator +(const StringSet& left, const StringSet& right);
	friend StringSet operator *(const StringSet& left, const StringSet& right);
	
private:
	std::vector<std::string> strings;
};

#endif //STRINGSET_H
