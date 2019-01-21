#ifndef WORD_READER_H
#define WORD_READER_H
#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>

namespace wcount_eric
{
	class FileError 
	{
	public:
		FileError(std::string str) : message(str) {}
		std::string get_message() {return message;}
	private:
		std::string message;
	};
	
	class WordReader
	{
	public:
		WordReader();
		WordReader(std::string the_filepath);
		
		//sets the filepath member variable but does not check whether the file exists
		//that check happens during the load_file method
		//also resets the unordered_map and total_count for when we want to evaluate another file
		void set_filepath(std::string new_filepath);
		
		//returns the current filepath
		std::string get_filepath();
		
		//connects a file input stream to the given filepath 
		//and reads the contents into our unordered_map.
		//Also stores the total number of words seen in total_count
		void load_file() throw(FileError);
		
		//returns a constant reference to the unordered_map
		const std::unordered_map<std::string,int>& get_words();
		
		//returns the total number of words in the file loaded
		uint64_t get_total_count();
		
		//returns the 10 most common words and their count
		//will return less than 10 if there were less than 10 words in the file
		std::vector<std::pair<std::string, int> > get_most_common();
		
		//uses get_most_common and prints the results to the terminal
		void display_most_common();
		
	private:
		std::string filepath;
		
		uint64_t total_count;
		
		std::unordered_map<std::string, int> words;
		
		std::vector<std::pair<std::string, int> > sorted_by_count;
	};
} //wcount_eric

#endif //WORD_READER_H
