#include <permutations.hpp>
#include <iostream>
using namespace std;

vector<vector<int> > get_permutations(int n)
{
	if (n == 1 || n == 0)
	{
		vector<vector<int> > result;
		vector<int> starter;
		starter.push_back(n);
		result.push_back(starter);
		return result;
	}
	else
	{
		return add_permutation(get_permutations(n-1), n);
	}
}

vector<vector<int> > add_permutation(vector<vector<int> > perms, int n)
{
	vector<vector<int> > result;
	uint8_t i=0;
	while(i<perms.size())
	{
		vector<int> current = perms[i];
		for (uint8_t j=0; j<=current.size(); j++)
		{
			//add to result a vector with n insterted into the jth index
			vector<int> add = current;
			
			add.insert(add.begin()+j, n);
			result.push_back(add);
		}
		i++;
	}
	return result;
}

void display_permutations(vector<vector<int> > permutations)
{
	for (uint8_t i=0; i<permutations.size(); i++)
	{
		cout << "{";
		for (uint8_t j=0; j<permutations[i].size()-1; j++)
		{
			cout << permutations[i][j] << ", ";
		}
		cout << permutations[i][permutations[i].size()-1] << "} ";
	}
	cout << "\n";
}
