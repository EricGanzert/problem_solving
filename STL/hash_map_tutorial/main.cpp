#include <string.h>
#include <iostream>
#include <sstream>
#include <map>
#include <utility>
#include <unordered_map>
using namespace std;

int main()
{
	//first an STL map
	map<string, int> Employees;
	
	Employees["Neha"] = 5234;
	Employees["Varun"] = 3374;
	
	Employees.insert(pair<string,int>("vikram",1923));
	Employees.insert(map<string,int>::value_type("Johnny",7582));
	Employees.insert(make_pair(string("Peter"),5328));
	
	cout << "Map Size: " << Employees.size() << endl;
	
	for (map<string,int>::iterator it = Employees.begin(); it != Employees.end(); ++it)
	{
		cout << it->first << ": " << it->second << "\n";
	}
	
	map<string,int>::iterator iter = Employees.find("Neha");
	if (iter != Employees.end())
	{
		cout << Employees["Neha"] << "\n";
	}
	
	//unordered map
	unordered_map<int,int> mp;
	
	mp.insert(make_pair(10,20));
	mp.insert(make_pair(4,400));
	mp.insert(make_pair(3,300));
	pair<int, int> p = make_pair(10,900);
	mp.insert(p);	
	
	for (auto it = mp.begin(); it != mp.end(); ++it)
	{
		cout << it->first << ": " << it->second << "\n";
	}
	
	string words = "this is a long test string with many words and some words you may see twice or more but a lot of words will probably be only seen once but no words presetn here will be seen zero times";

	unordered_map<string, int> string_map;
	stringstream ss(words); //to break up by word
	
	string curr;
	while (ss >> curr)
	{
		string_map[curr]++;
	}
	
	unordered_map<string,int>::iterator pt;
	multimap<int,string, greater<int> > mm;
	for (pt = string_map.begin(); pt != string_map.end(); ++pt)
	{
		//cout << pt->first << " : " << pt->second << "\n";
		mm.insert(make_pair(pt->second, pt->first));
	}
	
	multimap<int, string>::iterator mpt;
	for (mpt = mm.begin(); mpt != mm.end(); ++mpt)
	{
		cout << mpt->first << " : " << mpt->second << "\n";
	}
	
	return 0;
}
