#ifndef WORD_READER_H
#define WORD_READER_H
#include <string>

namespace wcount_eric
{
	class WordReader
	{
	public:
		WordReader();
		WordReader(const char* the_filepath);
		
		void set_filepath(std::string new_filepath);
		std::string get_filepath();
		
	private:
		std::string filepath;
	};
} //wcount_eric

#endif //WORD_READER_H
