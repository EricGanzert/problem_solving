#ifndef PROJECT_FUNCTIONS_H
#define PROJECT_FUNCTIONS_H

int nth_fibonacci(int n);

int index_of_smallest(const int a[], int start_index, int number_used);
//Precondition: 0 <= start_index < number_used. Referenced array elements have values
//Returns the index i such that a[i] is the smallest of the values
// a[start_index], a[start_index + 1], ..., a[number_used-1]

int search(const int a[], int low_index, int number_used, int target);
//precondition: number_used is <= the declared size of a.
//lower_index is < number_used.
//also a[0] through a[number_used] have values
//returns the first index such that a[index] == target
//otherwise returns -1

int combinations(int n, int r);
//returns the number of possible ways to choose
//r different things from n total

int combinations_iter(int n, int r);

int factorial(int n);
//returns n*(n-1)*(n-2)*...*(1)
//requires n >= 0

int factorial_iter(int n);

void reverse_array(char a[], int low_index, int high_index);
//reverses the order of the elements in the array a in between low and high index

void swap(char a[], int index1, int index2);
//changes the place of the 2 elements in the array specified by the indices

void swap(int a[], int index1, int index2);
//changes the place of the 2 elements in the array specified by the indices

void swap_sort(int a[], int low_index, int num_elements);
//ascending sort recurtsive using swap

#endif //PROJECT_FUNCTIONS_H
