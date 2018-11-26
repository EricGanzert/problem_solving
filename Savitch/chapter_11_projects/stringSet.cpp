#include <stringSet.hpp>
#include <string.h>
#include <ctype.h>
#include <math.h>
using namespace std;

StringSet::StringSet() 
{
	//empty
}

StringSet::StringSet(const std::string array[], int len)
{
	for (int i=0; i<len; i++)
	{
		strings.push_back(format_string(array[i]));
	}
}

StringSet::StringSet(const StringSet& copy)
{
	int len = copy.strings.size();
	for (int i=0; i<len; i++)
	{
		strings.push_back(format_string(copy.strings[i]));
	} 
}

StringSet::~StringSet()
{
	//empty
}

void StringSet::add(std::string new_item)
{
	strings.push_back(format_string(new_item));
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

double StringSet::similarity(const StringSet& compare)
{
	StringSet in_common = (*this) * compare;
	double sim = (in_common.num_strings()) / (sqrt(this->num_strings()) * sqrt(compare.num_strings()));
	return  sim;
}

ostream& operator <<(ostream& outs, const StringSet& right)
{
	int len = right.num_strings();
	for (int i=0; i<len; i++)
	{
		outs << right.strings[i] << " ";
	}
	return outs;
}

istream& operator >>(istream& ins, StringSet& right)
{
	right.clear_set();
	string current;
	while(ins >> current)
	{
		right.add(format_string(current));
	}
	return ins;
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

string format_string(const string& raw_string)
{
	int len = raw_string.length();
	string collect = "";
	for (int i=0; i<len; i++)
	{
		char c = raw_string[i];
		if (isalpha(c))
		{
			if (isupper(c))
			{
				collect += tolower(c);
			}
			else
			{
				collect += c;
			}
		}
		else if (isdigit(c))
		{
			collect += c;
		}
	}
	return collect;
}

StringSet get_query_from_user()
{
	StringSet ret;
	string str;
	cout << "Enter your search keywords and press enter : ";
	getline(cin, str, '\n');
	vector<string> all_str = str_split(str, " ");
	for (int i=0; i<all_str.size(); i++)
	{
		ret.add(format_string(all_str[i]));
	}
	return ret;
}

vector<string> str_split(string str, string token)
{
    vector<string> result;
    while(str.size() > 0)
    {
        int index = str.find(token);
        if(index != string::npos)
        {
            result.push_back(str.substr(0,index));
            str = str.substr(index+token.size());
            if (str.size()==0) 
            {
				result.push_back(str);
			}
        }
        else
        {
            result.push_back(str);
            str = "";
        }
    }
    return result;
}
