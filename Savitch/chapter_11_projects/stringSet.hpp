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
	double similarity(const StringSet& compare);
	
	friend std::ostream& operator <<(std::ostream& outs, const StringSet& right);
	friend std::istream& operator >>(std::istream& ins, StringSet& right);
	friend StringSet operator +(const StringSet& left, const StringSet& right);
	friend StringSet operator *(const StringSet& left, const StringSet& right);
	
private:
	std::vector<std::string> strings;
};

//removes punctuation and makes all chars lower case 
std::string format_string(const std::string& raw_string);

//uses std::cin
StringSet get_query_from_user();

std::vector<std::string> str_split(std::string str, std::string token);

#endif //STRINGSET_H
