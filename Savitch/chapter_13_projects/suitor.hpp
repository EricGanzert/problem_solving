#ifndef SUITOR_H
#define SUITOR_H

#include <list.hpp>

class SuitorSelect {
public:
	SuitorSelect(int num_suitors);
	SuitorSelect(const SuitorSelect& copy);
	~SuitorSelect();
	int select();
		
	friend std::ostream& operator <<(std::ostream& outs, const SuitorSelect& the_object);
		
private:
	void remove(eric_single_linked_list::NodePtr& node);
	eric_single_linked_list::NodePtr head;
	int n;
};

#endif // SUITOR_H
