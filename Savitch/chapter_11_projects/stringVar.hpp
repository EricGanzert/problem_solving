#ifndef STRINGVAR_H
#define STRINGVAR_H

#include <iostream>

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
	void input_line(std::istream& ins);
	friend std::ostream& operator <<(std::ostream& outs, const StringVar& the_string);
	
	StringVar copy_piece(int index1, int index2);
	char one_char(int index) const;
	void set_char(int index, char new_char);
	friend bool operator ==(const StringVar& left, const StringVar& right);
	friend StringVar operator +(const StringVar& left, const StringVar& right);
	friend std::istream& operator >>(std::istream& ins, StringVar& right);
	StringVar& operator =(const StringVar& second);
	
private:
	char *value;
	int max_length;
};

#endif //STRINGVAR_H
