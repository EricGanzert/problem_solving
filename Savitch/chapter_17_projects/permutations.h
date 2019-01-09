#ifndef PERMUTATIONS_H
#define PERMUTATIONS_H
#include <set.h>
#include <set.cpp>
#include <vector>

namespace set_eric
{
	template<class T>
	Set<std::vector<T> > add_permutation(Set<std::vector<T> > perms, T n)
	{
		Set<vector<T> > result;
		int i=0;
		while(i<perms.num_items())
		{
			vector<T> current = perms.get_item(i);
			for (uint8_t j=0; j<=current.size(); j++)
			{
				//add to result a vector with n inserted into the jth index
				vector<T> add = current;
				
				add.insert(add.begin()+j, n);
				result.add(add);
			}
			i++;
		}
		return result;
	}

	template<class T>
	Set<std::vector<T> > get_permutations(std::vector<T> the_set, int n)
	{
		if (n == 1 || n == 0)
		{
			Set<vector<T> > result;
			vector<T> starter;
			starter.push_back(n);
			result.add(starter);
			return result;
		}
		else
		{
			return add_permutation(get_permutations(the_set, n-1), the_set[n-1]);
		}
	}

	template<class T>
	void display_permutations(Set<std::vector<T> > permutations)
	{
		for (uint8_t i=0; i<permutations.num_items(); i++)
		{
			cout << "{";
			for (uint8_t j=0; j<permutations.get_item(i).size()-1; j++)
			{
				cout << permutations.get_item(i)[j] << ", ";
			}
			cout << permutations.get_item(i)[permutations.get_item(i).size()-1] << "} ";
		}
		cout << "\n";
	}
}

#endif //PERMUTATIONS_H
