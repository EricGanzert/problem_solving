#ifndef TEXT_H
#define TEXT_H

#include <stringVar.hpp>

class Text {
public:
	Text();
	Text(int size);
	Text(const char a[]);
	Text(const Text& copy);
	~Text();

	int length() const;
	void input_line(std::istream& ins);
	friend std::ostream& operator <<(std::ostream& outs, const Text& the_text);
	
	Text copy_piece(int index1, int index2);
	StringVar one_string(int index) const;
	void set_string(int index, char new_string[]);
	
	friend bool operator ==(const Text& left, const Text& right);
	friend Text operator +(const Text& left, const Text& right);
	friend std::istream& operator >>(std::istream& ins, Text& right);
	Text& operator =(const Text& second);
	
private:
	StringVar *value;
	int max_length;
};

#endif //TEXT_H
