#ifndef INVITATION_LIST_H
#define INVITATION_LIST_H
#include <string>

namespace invitation_eric
{
	class FileNotFound {};

	void get_invites(std::string filepath) throw(FileNotFound);
}
#endif //INVITATION_LIST_H
