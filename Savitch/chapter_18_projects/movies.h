#ifndef MOVIES_H
#define MOVIES_H
#include <string>

namespace movies_eric
{
	class FileNotFound {};
	class FormatError {};

	void movie_ratings(std::string filepath) throw(FileNotFound, FormatError);	
}

#endif //MOVIES_H
