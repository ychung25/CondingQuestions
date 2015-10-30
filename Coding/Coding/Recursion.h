#pragma once
#include <cstdlib>
#include <ctime>

// Factorial example
int FactorialLoop(int n)
{
	int result = 1;
	for (int count = 0; count <= n; count++)
	{
		if (count != 0)
		{
			result = result * count;
		};
	}

	return result;
}

int FactorialRecursion(int count)
{
	if (count == 0)
	{
		return 1;
	}
	else
	{
		return FactorialRecursion((count - 1)) * count;
	}
}

void DoFactorial()
{
	int n = 4;
	int loopResult = FactorialLoop(n);

	int recursionResult = FactorialRecursion(n);
}


// Fibonacci example
int Fibonacci(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
	{
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
}

void DoFibonacci()
{
	int n = 12;
	int result = Fibonacci(12);
}


// BinarySearch example
bool BinarySearch(unsigned int start, unsigned int end, int find, const int const data[])
{
	if (data == nullptr || find < data[start] || data[end] < find)
		return false;
	else if (data[start] == data[end])
	{
		if (data[start] == find)
			return true;
		else
			return false;
	}
	else
	{
		unsigned int mid = (start + end) / 2;
		if (data[mid] == find)
			return true;
		else if (data[mid] < find)
			return BinarySearch(mid + 1, end, find, data);
		else
			return BinarySearch(start, mid - 1, find, data);
	}
}

void DoBinarySearch()
{

	int data[] = { 1,3,4,7,8,10,99 };
	int find = 100;
	bool result = BinarySearch(0, (sizeof(data)/sizeof(data[0])) - 1, find, data);
}