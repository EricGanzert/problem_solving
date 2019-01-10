#ifndef BOOK_DATABASE_H
#define BOOK_DATABASE_H
#include <string>
#include <vector>

class Book
{
public:
	Book();
	Book(std::string the_author,
		std::string the_date,
		std::string the_title);
	Book(const Book& copy);
	~Book();
	friend bool operator <(const Book& left, const Book& right);
	friend std::ostream& operator <<(std::ostream& outs, const Book& right);
	
public:
	std::string author;
	std::string date;
	std::string title;
};

class BookDatabase
{
public:
	BookDatabase();
	std::vector<Book> lib;
	void main_loop();
	void input_book();
	void print_list();
};

#endif //BOOK_DATABASE_H
