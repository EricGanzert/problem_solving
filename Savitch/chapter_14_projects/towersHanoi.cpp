#include <towersHanoi.hpp>
#include <iostream>
#include <iomanip>
using namespace std;
using namespace eric_stack_string;

Stack post1;
Stack post2;
Stack post3;

int capacity;

void towers_of_hanoi(int num_disks)
{
	capacity = num_disks;
	
	init_hanoi_posts();
	display_hanoi_towers();
	 
	transfer_disks(post1, post3, capacity-1);
	display_hanoi_towers();
	
	post2.push(post1.pop());
	
	display_hanoi_towers();
	
	transfer_disks(post3, post2, capacity-1);
	display_hanoi_towers();
}

void transfer_disks(Stack& post_a, Stack& post_b, int transfer_num)
{
	if (transfer_num < 1)
	{
		return;
	}
	else
	{
		post_b.push(post_a.pop());
		transfer_disks(post_a, post_b, transfer_num-1);
	}
}

void init_hanoi_posts()
{
	int index = 1;
	while (index <= capacity)
	{
		post1.push(to_string(index));
		index++;
	}
}

void display_hanoi_towers()
{
	Stack temp1(post1);
	int blanks1 = capacity - temp1.size();
	
	Stack temp2(post2);
	int blanks2 = capacity - temp2.size();
	
	Stack temp3(post3);
	int blanks3 = capacity - temp3.size();
	
	for (int i=0; i<capacity; i++)
	{
		if (blanks1 > 0)
		{
			cout << setw(5) << right << " ";
			blanks1--;
		}
		else
		{
			cout << setw(5) << right << temp1.pop();
		}
		
		if (blanks2 > 0)
		{
			cout << setw(5) << right << " ";
			blanks2--;
		}
		else
		{
			cout << setw(5) << right << temp2.pop();
		}
		
		if (blanks3 > 0)
		{
			cout << setw(5) << right << " ";
			blanks3--;
		}
		else
		{
			cout << setw(5) << right << temp3.pop();
		}
		cout << "\n";
	}
	
	cout << right << setw(5) << "_"
		<< right << setw(5) << "_"
		<< right << setw(5) << "_" << "\n\n";
}
