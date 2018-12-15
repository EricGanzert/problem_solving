#include <computerLab.hpp>
#include <cstddef>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

namespace lab_eric
{
	static const int NUM_LABS = 4;
	static const int LAB_SIZE[4] = {5, 6, 4, 3};
	
	static Lab labs[NUM_LABS];
	static bool initialized = false;
	
	static void init_lab(Lab* the_lab, int id_num, int num_computers)
	{
		if (num_computers < 0)
		{
			cout << "invalid # of computers for lab\n";
			exit(1);
		}
		the_lab->id = id_num;
		the_lab->stations = num_computers;
		
		if (num_computers == 0)
		{
			the_lab->head = NULL;
			return;
		}
		the_lab->head = new LabNode;
		LabNodePtr temp = the_lab->head;
		temp->lab_id = id_num;
		temp->station = 1;
		temp->user_id = 0;
		
		for (int i=2; i <= num_computers; i++)
		{
			temp->link = new LabNode;
			temp = temp->link;
			temp->lab_id = id_num;
			temp->station = i;
			temp->user_id = 0;
		}
		temp->link = NULL;
	}
	
	void init_labs()
	{
		if (!initialized)
		{
			for (int i=0; i<NUM_LABS; i++)
			{
				init_lab(&labs[i], i+1, LAB_SIZE[i]);
			}
			initialized = true;	
		}
	}
	
	void display_labs()
	{
		cout << setw(12) << left << "Lab Number" << "Computer Stations\n";
		for (int i=0; i<NUM_LABS; i++)
		{
			LabNodePtr temp = labs[i].head;
			
			//outputing the lab number
			cout << setw(12) << i+1;
			
			while (temp != NULL)
			{
				//outputing the station number
				cout << temp->station << ": ";
				if (temp->user_id == 0)
				{
					cout << "empty ";
				}
				else
				{
					cout << setw(6) << temp->user_id;
				}
				temp = temp->link;
			}
			cout << "\n";
		}		
	}
	
	bool login(int lab, int station, int user_id)
	{
		bool success = true;
		cout << "logging in lab " << lab << " station "
			<< station << " with user id " << user_id << "\n"; 
		if (lab < 0 || lab > NUM_LABS)
		{
			cout << "invalid lab #\n";
			success = false;
		}
		if (station < 0 || station > LAB_SIZE[lab-1])
		{
			cout << "computer station #\n";
			success = false;
		}
		if (user_id < 0 || lab > 99999)
		{
			cout << "invalid user id # (must be 5 digits)\n";
			success = false;
		}
		
		if (!success)
		{
			return false;
		}
		else
		{
			init_labs();
			LabNodePtr temp = labs[lab-1].head;
			while(temp != NULL)
			{
				if (temp->station == station)
				{
					temp->user_id = user_id;
					return true;
				}
				temp = temp->link;
			}
			cout << "didn't find computer station, problem with init?\n";
			return false;
		}
	}
	
	bool lookup_user(int user_id, LabNodePtr& node_ptr)
	{
		if (!initialized || user_id == 0)
		{
			return false;
		}
		
		for (int i=0; i<NUM_LABS; i++)
		{
			LabNodePtr iter = labs[i].head;
			while(iter != NULL)
			{
				if (iter->user_id == user_id)
				{
					node_ptr = iter;
					return true;
				}
				iter = iter->link;
			}
		}
		return false;
	}
	
	bool logout_user(int user_id)
	{
		LabNodePtr temp = NULL;
		if (lookup_user(user_id, temp))
		{
			temp->user_id = 0;
			return true;
		}
		else
		{
			cout << "user id is not in the system\n";
			return false;
		}
	}
	
	void simulate()
	{
		cout << "Welcome to the computer lab manager simulation\n";
		char c;
		while (1)
		{
			cout << "********************************\n";
			display_labs();
			cout << "'q' to quit\n"
				<< "'1' to simulate a login\n"
				<< "'2' to simulate a log out\n"
				<< "'3' to look up a user id\n"
				<< "Enter selection: ";
			cin >> c;
			cin.ignore(10000, '\n');
			
			if (c == 'q')
			{
				break;
			}
			else if (c == '1')
			{
				int lab_num, computer_num, user_id;
				cout << "Enter lab# station# userID (in format x y zzzzz): ";
				cin >> lab_num >> computer_num >> user_id;
				login(lab_num, computer_num, user_id);
			}
			else if (c == '2')
			{
				int user_id;
				cout << "Enter the user id to log out (in format zzzzz): ";
				cin >> user_id;
				logout_user(user_id);				
			}
			else if (c == '3')
			{
				int user_id;
				cout << "Enter the user id to look up (in format zzzzz): ";
				cin >> user_id;
				LabNodePtr temp = NULL;
				if (lookup_user(user_id, temp))
				{
					cout << "That user is in lab " << temp->lab_id << " at station " << temp->station << "\n";
				}				
			}
		}
	}
}
