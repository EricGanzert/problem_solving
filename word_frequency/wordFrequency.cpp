#include <wordFrequency.h>
using namespace std;

namespace
{	
	//chop down the argument string into segments that only contain letters
	//each segment gets added to the vector returned
	vector<string> split_by_non_alpha(string str)
	{
		vector<string> result;
		string substr;
		string::iterator it;
		
		//first make sure the whole string is lower case
		for (it=str.begin(); it < str.end(); ++it)
		{
			*it = tolower(*it);
		}
		
		//if the string contains non-alphabet characters we will break it down here
		size_t index=0;
		while ((index=str.find_first_not_of("abcdefghijklmnopqrstuvwxyz")) != string::npos)
		{
			if (index != 0)
			{
				substr = str.substr(0,index);
				result.push_back(substr);
			}
			//cut out the substring we just saved plus the non-alpha character
			str.erase(0,index+1);
		}
		
		//get last remaining substring
		if (str.length() > 0)
		{
			substr = str;
			result.push_back(substr);
		}
		return result;
	}
	
	//custom sorting function for use in get_most_common
	bool sort_descending_by_second(const pair<string,int>& a, 
		const pair<string,int>& b)
	{
		return a.second > b.second;
	}
}

namespace wcount_eric
{
	WordReader::WordReader()
		: filepath("no filepath yet"), total_count(0)
	{
		//empty
	}
	
	
	WordReader::WordReader(std::string the_filepath)
		: filepath(the_filepath)
	{
		//empty
	}
	
	
	void WordReader::set_filepath(string new_filepath)
	{
		filepath = new_filepath; 
		words.clear();
		sorted_by_count.clear();
		total_count = 0;
	}
			
		
	string WordReader::get_filepath() const
	{
		return filepath;
	}
	
	
	void WordReader::load_file() throw(FileError)
	{
		ifstream in_stream(filepath);
		if (in_stream.fail())
		{
			string msg = "Error: Can't connect to file: " + filepath;
			throw FileError(msg);
		}
		
		string word;
		unordered_map<string, int>::iterator it;
		while (in_stream >> word)
		{
			vector<string> segments = split_by_non_alpha(word);
			
			if (segments.empty())
			{
				continue;
			}
			
			total_count += segments.size();
			//add the cleaned up words to our map
			vector<string>::iterator str;
			for (str=segments.begin(); str!=segments.end(); ++str)
			{
				it = words.find(*str);
				
				if (it != words.end())
					it->second++;
				else
					words.insert(make_pair(*str,1));
			}
		}
		in_stream.close();
	}
	
	
	const unordered_map<string,int>& WordReader::get_words() const
	{
		return words;
	}
	
	
	uint64_t WordReader::get_total_count() const
	{
		return total_count;
	}
	
	
	vector<pair<string, int> > WordReader::get_most_common()
	{	
		if (sorted_by_count.empty())
		{
			unordered_map<string,int>::const_iterator it;
			for (it=words.begin(); it!=words.end(); ++it)
			{
				sorted_by_count.push_back(*it);
			}
			sort(sorted_by_count.begin(), sorted_by_count.end(), sort_descending_by_second);
		}
		
		int amount = min(10, static_cast<int>(sorted_by_count.size()));
		vector<pair<string, int> > result(sorted_by_count.begin(), sorted_by_count.begin() + amount);
		return result;
	}
	
	void WordReader::display_most_common()
	{
		vector<pair<string, int> > most_common = get_most_common();
		vector<pair<string, int> >::iterator it;
		for (it=most_common.begin(); it!=most_common.end(); ++it)
		{
			cout << it->first << " - " << it->second << "\n";
		}
	}
}
