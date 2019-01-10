#include <bookDatabase.h>
#include <iostream>
#include <algorithm>
using namespace std;

Book::Book() : author("no author yet"), date("no date yet"), title("no title yet")
{
	//empty
}

Book::Book(std::string the_author,
	std::string the_date,
	std::string the_title)
	: author(the_author), date(the_date), title(the_title)
{
	//empty
}

Book::Book(const Book& copy)
	: author(copy.author), date(copy.date), title(copy.title)
{
	//empty
}

Book::~Book()
{
	//empty
}

bool operator <(const Book& left, const Book& right)
{
	return (left.author < right.author);
}

BookDatabase::BookDatabase()
{
	//empty
}

void BookDatabase::main_loop()
{
	while(1)
	{
		cout << "Select from the following choices:\n1.        Add new book"
			<< "\n2.        Print listing sorted by order\n3.        Quit\n";
		string str;
		getline(cin,str);
		
		if (str.find('1') != string::npos)
		{
			input_book();
		}
		else if (str.find('2') != string::npos)
		{
			print_list();
		}
		else if (str.find('q') != string::npos || str.find('Q') != string::npos)
		{
			break;
		}
	}
}

void BookDatabase::input_book()
{
	Book new_book;
	
	cout << "Enter Author: ";
	getline(cin,new_book.author);
	cout << "Enter Title: ";
	getline(cin,new_book.title);
	cout << "Enter date of publication: ";
	getline(cin,new_book.date);
	
	lib.push_back(new_book);
}

void BookDatabase::print_list()
{
	sort(lib.begin(), lib.end());
	vector<Book>::iterator it;
	for (it=lib.begin(); it!=lib.end(); ++it)
	{
		cout << *it << "\n";
	}
	cout << "\n";
}

ostream& operator <<(ostream& outs, const Book& right)
{
	cout << "Author: " << right.author << "\nTitle: " << right.title
		<< "\nDate of publication: " << right.date << "\n";
		return outs;
}
