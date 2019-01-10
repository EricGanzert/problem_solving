#include <projectTests.h>
#include <iostream>
#include <sstream>
#include <deque>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <numeric>
#include <math.h>
#include <list>
#include <fstream>
using namespace std;

void sortDeque()
{
	deque<double> dq;
	
	while (dq.size() < 10)
	{
		cout << "enter 10 numbers: ";
		string line;
		getline(cin, line);
		stringstream ss(line);
		while (ss >> line)
		{
			if (!line.empty() && line.find_first_not_of("0123456789") == line.npos)
			{
				cout << line << "\n";
				dq.push_back(stoi(line));
			}
		}
	}
	
	sort(dq.begin(), dq.end());
	deque<double>::iterator it;
	for (it=dq.begin(); it != dq.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << "\n";
}

void sortScores()
{
	vector<pair<double, string> > scores;
	
	while (1)
	{
		string name;
		string str_score;
		double score;
		cout << "Enter Student name : ";
		getline(cin, name);
		while (1)
		{
			cout << "Enter " << name << "'s Score: ";
			cin >> str_score;
			if (!str_score.empty() && str_score.find_first_not_of(".0123456789") == str_score.npos)
			{
				score = stof(str_score);
				break;
			}
		}
		scores.push_back(make_pair(score,name));
		cout << "Another Student(y/n)?: ";
		char c;
		cin >> c;
		cin.ignore(10000,'\n');
		if (c == 'n' || c == 'N')
		{
			break;
		}
	}
	sort(scores.begin(), scores.end());
	
	vector<pair<double,string> >::iterator it;
	for (it = scores.begin(); it != scores.end(); ++it)
	{
		cout << it->second << ": " << it->first << "\n";
	}
}

void primesToN(int n)
{
	if (n<2)
	{
		return;
	}
	vector<int> v(n-1);
	iota(v.begin(), v.end(), 2);
	set<int> s(v.begin(), v.end());

	set<int>::iterator it;
	for (it = s.begin(); *it < sqrt(n); ++it)
	{
		int curr = *it;
		while(curr < n)
		{
			curr += *it;
			set<int>::iterator check;
			check = s.find(curr);
			if (check != s.end())
			{
				s.erase(check);
			}
		}
	}
	
	for (it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " "; 
	}
	cout << "\n";
}

struct StudentInfo
{
	string name;
	int grade;
	StudentInfo(string the_name, int the_grade)
	{
		name = the_name;
		grade = the_grade;
	}
};

bool operator <(const StudentInfo& left, const StudentInfo& right)
{
	return (left.name < right.name);
}

void studentRecords()
{
	list<StudentInfo > scores;
	while (1)
	{
		string name;
		string str_score;
		int score;
		cout << "Enter Student name : ";
		getline(cin, name);
		while (1)
		{
			cout << "Enter " << name << "'s Score: ";
			cin >> str_score;
			if (!str_score.empty() && str_score.find_first_not_of("0123456789") == str_score.npos)
			{
				score = stoi(str_score);
				break;
			}
		}
		struct StudentInfo info(name,score);
		scores.push_back(info);
		cout << "Another Student(y/n)?: ";
		char c;
		cin >> c;
		cin.ignore(10000,'\n');
		if (c == 'n' || c == 'N')
		{
			break;
		}
	}
	
	scores.sort();
	list<StudentInfo>::iterator it;
	double max = scores.begin()->grade;
	double min = scores.begin()->grade;
	double avg = 0;
	for (it = scores.begin(); it != scores.end(); ++it)
	{
		cout << it->name << ": " << it->grade << "\n";
		avg += it->grade;
		if (it->grade < min)
		{
			min = it->grade;
		}
		if (it->grade > max)
		{
			max = it->grade;
		}
	}
	avg = avg/scores.size();
	cout << "Average Score is " << avg << "\nBest Score is " << max << " and worst score is " << min << "\n";
	
	list<StudentInfo> passed, failed;
	
	while (!scores.empty())
	{
		list<StudentInfo>::iterator it = scores.begin();
		if (it->grade < 60)
		{
			failed.push_back(*it);
		}
		else
		{
			passed.push_back(*it);
		}
		scores.erase(scores.begin());
	}
	
	cout << passed.size() << " students passed and " << failed.size() << " students failed\n";
}

void stringset()
{
	string str;
	
	cout << "enter the words for set 1: ";
	getline(cin,str);
	set<string> set1;
	stringstream ss(str);
	while (ss >> str)
	{
		set1.insert(str);
	}
	
	cout << "enter the words for set 2: ";
	getline(cin,str);
	set<string> set2;
	stringstream ss2(str);
	while (ss2 >> str)
	{
		set2.insert(str);
	}
	
	set<string> in_common;
	insert_iterator<set<string> > cIter(in_common, in_common.begin());
	set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), cIter);
	
	cout << "Here are the words that both sets have in common:\n";
	set<string>::iterator it;
	for (it=in_common.begin(); it != in_common.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << "\n";
}

void bookDatabaseTest()
{
	BookDatabase books;
	books.main_loop();
}

void permutations_test()
{
	set<list<int> > p = get_permutations(3);
	display_permutations(p);
}

void movie_ratings_test()
{
	string filepath = "../movies.txt";
	ifstream ins;
	ins.open(filepath);
	if (ins.fail())
	{
		cout << "could not find file\n";
		exit(1);
	}
	int num_ratings = 0;
	string line;
	getline(cin,line);
	if (!line.empty() && line.find_first_not_of("0123456789") == line.npos)
	{
		num_ratings = stoi(line);
	}
	else
	{
		
	}
	
	while (getline(cin,line))
	{
		
	}
}
