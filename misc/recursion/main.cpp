#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

int fibonacci_slow(int n)
{
	cout << ".";
	if (n==1 || n==0)
	{
		return 1;
	}
	return fibonacci_slow(n-1) + fibonacci_slow(n-2);
}

typedef unordered_map<int, int> Map;

int fib(int n, Map& m)
{
	cout << ".";
	if (n==1 || n==0)
	{
		return 1;
	}
	else
	{
		int n1, n2;
		if (m.find(n-1) != m.end())
		{
			n1 = m[n-1];
		}
		else
		{
			n1 = fib(n-1,m);
			m.insert(make_pair(n-1,n1));
		}
		if (m.find(n-2) != m.end())
		{
			n2 = m[n-2];
		}
		else
		{
			n2 = fib(n-2,m);
			m.insert(make_pair(n-2,n2));
		}
		return n1 + n2;
	}	
}

int fibonacci_fast(int n)
{
	Map m;
	return fib(n,m);
}

int fibonacci_iter(int n)
{
	if (n==1 || n==0)
	{
		return 1;
	}
	int current=2;
	int result=2;
	int result_prev = 1;
	while(current < n)
	{
		cout << ".";
		int sum = result + result_prev;
		result_prev = result;
		result = sum;
		current++;
	}
	return result;
}

int main()
{
	int n=7;
	int result;
	cout << "Inefficient Fibonacci\n";
	result = fibonacci_slow(n);
	cout << "\n";
	cout << "result is " << result << "\n\n";
	
	cout << "efficient Fibonacci\n";
	result = fibonacci_fast(n);
	cout << "\n";
	cout << "result is " << result << "\n\n";
	
	cout << "iterative Fibonacci\n";
	result = fibonacci_iter(n);
	cout << "\n";
	cout << "result is " << result << "\n\n";
	return 0;
}
