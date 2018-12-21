#ifndef PERMUTATIONS_H
#define PERMUTATIONS_H
#include <vector>

std::vector<std::vector<int> > get_permutations(int n);

std::vector<std::vector<int> > add_permutation(std::vector<std::vector<int> > perms, int n);

void display_permutations(std::vector<std::vector<int> > permutations);

#endif //PERMUTATIONS_H
