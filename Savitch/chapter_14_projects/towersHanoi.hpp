#ifndef TOWERS_HANOI_H
#define TOWERS_HANOI_H
#include <string>
#include <stackString.hpp>

void towers_of_hanoi(int num_disks);

void transfer_disks(eric_stack_string::Stack& post_a, eric_stack_string::Stack& post_b, int transfer_num);

void init_hanoi_posts();
//places the initial configuration of disks on the posts

void display_hanoi_towers();

#endif //TOWERS_HANOI_H
