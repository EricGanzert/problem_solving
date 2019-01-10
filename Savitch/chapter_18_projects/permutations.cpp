#include <permutations.h>
#include <iostream>
using namespace std;

set<list<int> > get_permutations(int n)
{
	if (n == 1 || n == 0)
	{
		set<list<int> > result;
		list<int> starter;
		starter.push_back(n);
		result.insert(starter);
		return result;
	}
	else
	{
		return add_permutation(get_permutations(n-1), n);
	}
}

set<list<int> > add_permutation(set<list<int> > perms, int n)
{
	set<list<int> > result;
	uint8_t i=0;
	
	set<list<int> >::iterator it;
	for (it=perms.begin(); it!=perms.end(); ++it)
	{
		list<int> current = *it;
		for (uint32_t j=0; j<=current.size(); j++)
		{
			//add to result a vector with n insterted into the jth index
			list<int> add = current;
			list<int>::iterator iter = add.begin();
			for (uint32_t i = 0;i<j;i++)
			{
				iter++;
			}
			add.insert(iter, n);
			result.insert(add);
		}
		i++;
	}
	return result;
}

void display_permutations(set<list<int> > permutations)
{
	set<list<int> >::const_iterator i;
	for (i=permutations.begin(); i!=permutations.end(); ++i)
	{
		cout << "{";
		list<int>::const_iterator j;
		for (j=i->begin(); j!=i->end(); j++)
		{
			cout << *j << " ";
		}
		cout << "} ";
	}
	cout << "\n";
}
