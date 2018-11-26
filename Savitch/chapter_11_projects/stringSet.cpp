#include <stringSet.hpp>
#include <string.h>
using namespace std;

//~ class StringSet {
//~ public:
	//~ StringSet();
	//~ StringSet(const std::string array[], int len);
	//~ StringSet(const StringSet& copy);
	//~ ~StringSet();
	
	//~ void add(std::string new_item);
	//~ std::string remove(int index);
	//~ int num_strings();
	//~ void clear_set();
	
	//~ friend std::ostream& operator <<(std::ostream& outs, const StringSet the_set);
	//~ friend StringSet operator +(const StringSet& left, const StringSet& right);
	//~ friend StringSet operator *(const StringSet& left, const StringSet& right);
	
//~ private:
	//~ std

StringSet::StringSet() 
{
	//empty
}

StringSet::StringSet(const std::string array[], int len)
{
	for (int i=0; i<len; i++)
	{
		strings.push_back(array[i]);
	}
}

StringSet::StringSet(const StringSet& copy)
{
	int len = copy.strings.size();
	for (int i=0; i<len; i++)
	{
		strings.push_back(copy.strings[i]);
	} 
}

StringSet::~StringSet()
{
	//empty
}

void StringSet::add(std::string new_item)
{
	strings.push_back(new_item);
}

string StringSet::remove(int index)
{
	string ret = strings[index];
	strings.erase(strings.begin() + index);
	return ret;
}

int StringSet::num_strings() const
{
	return strings.size();
}

void StringSet::clear_set()
{
	strings.clear();
}

ostream& operator <<(ostream& outs, const StringSet& the_set)
{
	int len = the_set.num_strings();
	for (int i=0; i<len; i++)
	{
		outs << the_set.strings[i] << " ";
	}
	return outs;
}

StringSet operator +(const StringSet& left, const StringSet& right)
{
	StringSet ret(left);
	int right_size = right.num_strings();
	for (int i=0; i<right_size; i++)
	{
		ret.add(right.strings[i]);
	}
	return ret;
}

StringSet operator *(const StringSet& left, const StringSet& right)
{
	StringSet ret;
	int left_size = left.num_strings();
	int right_size = right.num_strings();
	for (int i=0; i<left_size; i++)
	{
		for (int j=0; j<right_size; j++)
		{
			if (left.strings[i] == right.strings[j])
			{
				ret.add(left.strings[i]);
			}
		}
	}
	return ret;
}
