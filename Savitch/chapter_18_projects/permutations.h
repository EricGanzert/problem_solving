#ifndef PERMUTATIONS_H
#define PERMUTATIONS_H
#include <set>
#include <list>

std::set<std::list<int> > get_permutations(int n);

std::set<std::list<int> > add_permutation(std::set<std::list<int> > perms, int n);

void display_permutations(std::set<std::list<int> > permutations);

#endif //PERMUTATIONS_H
