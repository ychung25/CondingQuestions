#pragma once
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Stack.h"
#include "Queue.h"

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
	bool result = BinarySearch(0, (sizeof(data) / sizeof(data[0])) - 1, find, data);
}

void Hanoi(int n, char origin, char destination, char buffer)
{
	if (n == 0) { return; }

	Hanoi(n - 1, origin, buffer, destination);
	printf("Moving %dth disk from Peg%c to Peg%c\n", n, origin, destination);
	Hanoi(n - 1, buffer, destination, origin);
}

void DoHanoi()
{
	printf("\nTower Of Hanoi Solution\n");

	Hanoi(3, 'A', 'C', 'B');
}

void KString(int n, char string[], int k, char charSet[])
{
	if (n == 0)
	{
		printf("%s\n", string);
		return;
	}

	for (int i = 0; i < k; i++)
	{
		string[n - 1] = charSet[i];
		KString(n - 1, string, k, charSet);
	}
}

void DoKString()
{
	char string[4];
	string[3] = '\0';
	char charSet[] = { 'A','B','C', 'D' };
	KString(3, string, 4, charSet);
}

void BinaryString(int n, char string[])
{
	if (n == 0)
	{
		printf("%s\n", string);
		return;
	}

	string[n - 1] = '0';
	BinaryString(n - 1, string);
	string[n - 1] = '1';
	BinaryString(n - 1, string);
}

void DoBinaryString()
{
	printf("---- Binary Strings---\n");
	char string[5];
	string[4] = '\0';
	BinaryString(4, string);
}

void DoRecursionQuestions()
{
	DoFactorial();
	DoFibonacci();
	DoBinarySearch();
	DoHanoi();
	DoBinaryString();
	DoKString();
}