#ifndef STRINGVAR_H
#define STRINGVAR_H

#include <cstdlib>
#include <cstddef>
#include <cstring>

//Uses cstddef and cstdlib
class StringVar
{
public:
	StringVar(int size);
	StringVar();
	StringVar(const char a[]);
	StringVar(const StringVar& string_object);
	~StringVar();
	
	int length() const;
	void input_line(istrem& ins);
	friend ostream& operator <<(ostrem& outs, const StringVar& the_string);
private:
	char *value;
	int max_length();
};

#endif //STRINGVAR_H
