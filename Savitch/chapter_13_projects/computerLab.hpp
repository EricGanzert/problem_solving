#ifndef COMPUTER_LAB_H
#define COMPUTER_LAB_H

namespace lab_eric
{
	struct LabNode {
		int lab_id;
		int station;
		int user_id;
		LabNode* link;
	};
	typedef LabNode* LabNodePtr;
	
	struct Lab {
		int id;
		int stations;
		LabNodePtr head;
	};
	
	void init_labs();
	
	void display_labs();
	
	void simulate();
	
	bool login(int lab, int station, int user_id);
	
	bool lookup_user(int user_id);
	
	bool logout_user(int user_id, LabNodePtr& node_ptr);
}

#endif //COMPUTER_LAB_H
