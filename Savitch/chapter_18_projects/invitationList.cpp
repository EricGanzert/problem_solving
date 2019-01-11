#include <invitationList.h>
#include <iostream>
#include <fstream>
#include <set>
using namespace std;

namespace invitation_eric
{
	void get_invites(std::string filepath) throw(FileNotFound)
	{
		ifstream ins;
		ins.open(filepath);
		if (ins.fail())
		{
			throw(FileNotFound());
		}
		
		set<string> s;
		string line;
		while(getline(ins,line))
		{
			s.insert(line);
		}
		
		set<string>::iterator it;
		for (it=s.begin(); it!=s.end(); ++it)
		{
			cout << *it << "\n";
		}
	}
}
