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
	bool result = BinarySearch(0, (sizeof(data) / sizeof(data[0])) - 1, find, data);
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

// QuickSort v1, something I figured out! A complex.
void QuickSort1(int start, int end, int data[])
{
	if (start >= end)
	{
		return;
	}

	srand(time(NULL));
	int pivot = (rand() % (end - start + 1)) + start;

	for (int i = start; i <= end;)
	{
		if (pivot < i)
		{
			if (data[i] < data[pivot])
			{
				if (pivot + 1 == i)
				{
					int temp = data[i];
					data[i] = data[pivot];
					data[pivot] = temp;
					
				}
				else
				{
					int temp = data[pivot + 1];
					data[pivot + 1] = data[pivot];
					data[pivot] = data[i];
					data[i] = temp;
				}
				pivot++;
			}
			else
			{
				i++;
			}
		}
		else if (pivot > i)
		{
			if (data[i] > data[pivot])
			{
				if (pivot - 1 == i)
				{
					int temp = data[i];
					data[i] = data[pivot];
					data[pivot] = temp;

				}
				else
				{
					int temp = data[pivot - 1];
					data[pivot - 1] = data[pivot];
					data[pivot] = data[i];
					data[i] = temp;
				}
				pivot--;
			}
			else
			{
				i++;
			}
		}
		else if (pivot == i)
		{
			i++;
		}
	}

	QuickSort1(start, pivot - 1, data);
	QuickSort1(pivot + 1, end, data);
}

// Textbook version of QuickSort
void QuickSort2(int start, int end, int data[])
{
	if (start >= end)
	{
		return;
	}

	srand(time(NULL));
	int pivot = (rand() % (end - start + 1)) + start;

	int g = start;
	for (int i = start; i <= end; i++)
	{
		if (data[i] < data[pivot])
		{
			if (pivot == g)
			{
				pivot = i;
			}

			int temp = data[g];
			data[g] = data[i];
			data[i] = temp;
			g++;
		}
	}

	int temp = data[g];
	data[g] = data[pivot];
	data[pivot] = temp;

	QuickSort2(start, pivot - 1, data);
	QuickSort2(pivot + 1, end, data);
}

void DoQuickSort()
{
	{
		int data[] = { 9,6,50,-23,0,100, -40, 4, 5, 6, 0, -1 ,20, 34, 10, 99 };
		QuickSort1(0, (sizeof(data) / sizeof(data[0])) - 1, data);
	}
	{
		int data[] = { 9,6,50,-23,0,100, -40, 4, 5, 6, 0, -1 ,20, 34, 10, 99 };
		QuickSort2(0, (sizeof(data) / sizeof(data[0])) - 1, data);

		int breakpoint = 10 * 20;
	}
}