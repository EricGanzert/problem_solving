#include <movies.h>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <numeric>
#include <vector>

namespace movies_eric
{
	using namespace std;

	void movie_ratings(string filepath) throw(FileNotFound, FormatError)
	{
		ifstream ins;
		ins.open(filepath);
		if (ins.fail())
		{
			throw(FileNotFound());
		}
		int num_ratings = 0;
		string line;
		getline(ins,line);
		if (!line.empty() && line.find_first_not_of("0123456789") == line.npos)
		{
			num_ratings = stoi(line);
		}
		else
		{
			throw(FormatError());
		}
		
		unordered_multimap<string, vector<double> > m;
		
		for (int i=0;i<num_ratings;i++)
		{
			string title;
			getline(ins,title);
			
			string rating_str;
			double rating;
			getline(ins,rating_str);
			if (!rating_str.empty() && rating_str.find_first_not_of(".0123456789") == rating_str.npos)
			{
				rating = stof(rating_str);
			}
			else
			{
				throw(FormatError());
			}		
			
			unordered_multimap<string, vector<double> >::iterator it;
			it = m.find(title);
			if (it != m.end())
			{
				it->second.push_back(rating);
			}
			else
			{
				vector<double> v = {rating};
				m.insert(make_pair(title,v));
			}
		}
		
		unordered_multimap<string,vector<double> >::iterator it;
		for (it=m.begin(); it!=m.end(); ++it)
		{
			int count = it->second.size();
			double avg = accumulate(it->second.begin(), it->second.end(), 0.0) / count;
			cout << it->first << ": " << count << " reviews, average of " 
				<< setprecision(2) << avg << " / 5\n";
			
		}
	}
}
