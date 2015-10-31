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


// Merge Sort
void MergeSort(int start, int end, int data[])
{
	if (start == end || data == nullptr)
		return;
	else
	{
		int length = (end - start) + 1;
		int mid = (start + end) / 2;
		MergeSort(start, mid, data);
		MergeSort(mid + 1, end, data);

		int bufferCount = 0;
		int* buffer = new int[length];
		int leftStart = start;
		int leftEnd = mid;
		int rightStart = mid + 1;
		int rightEnd = end;

		while (leftStart <= leftEnd && rightStart <= rightEnd)
		{
			if (data[leftStart] <= data[rightStart])
			{
				buffer[bufferCount] = data[leftStart];
				leftStart++;
				bufferCount++;
			}
			else
			{
				buffer[bufferCount] = data[rightStart];
				rightStart++;
				bufferCount++;
			}
		}

		if (leftStart > leftEnd)
		{
			for (;bufferCount < length; bufferCount++)
			{
				buffer[bufferCount] = data[rightStart];
				rightStart++;
			}
		}
		else if (rightStart > rightEnd)
		{
			for (;bufferCount < length; bufferCount++)
			{
				buffer[bufferCount] = data[leftStart];
				leftStart++;
			}
		}

		bufferCount = 0;
		for (int i = start; i <= end; i++)
		{
			data[i] = buffer[bufferCount];
			bufferCount++;
		}

		delete[] buffer;
	}
}

void DoMergeSort()
{
	int data[] = { 2, 1 , -3, 99, -20, 43, 89, 50, -5, -13, 1000 };
	MergeSort(0, sizeof(data)/sizeof(data[0])-1, data);
}