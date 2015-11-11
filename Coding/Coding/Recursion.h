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

struct Node
{
	Node* left;
	Node* right;
	int data;
};

void CreateSampleBinaryTree(Node** rootNode)
{
	Node* node1 = new Node();
	node1->left = nullptr;
	node1->right = nullptr;
	node1->data = 1;
	*rootNode = node1;

	Node* node2 = new Node();
	node2->left = nullptr;
	node2->right = nullptr;
	node2->data = 2;
	node1->left = node2;

	Node* node3 = new Node();
	node3->left = nullptr;
	node3->right = nullptr;
	node3->data = 3;
	node1->right = node3;

	Node* node4 = new Node();
	node4->left = nullptr;
	node4->right = nullptr;
	node4->data = 4;
	node2->left = node4;

	Node* node5 = new Node();
	node5->left = nullptr;
	node5->right = nullptr;
	node5->data = 5;
	node2->right = node5;

	Node* node6 = new Node();
	node6->left = nullptr;
	node6->right = nullptr;
	node6->data = 6;
	node3->left = node6;

	Node* node7 = new Node();
	node7->left = nullptr;
	node7->right = nullptr;
	node7->data = 7;
	node3->right = node7;
}

void TreeTraversal(Node* node)
{
	if (node == nullptr)
		return;

	//std::wcout << node->data; // PreOrder
	TreeTraversal(node->left);
	//std::wcout << node->data; // InOrder
	TreeTraversal(node->right);
	//std::wcout << node->data; // PostOrder
}

void DoPreInPostOrderTraveral()
{
	Node* rootNode;
	CreateSampleBinaryTree(&rootNode);
	TreeTraversal(rootNode);
}

void BreathFirstSearch(Queue* queue)
{
	if (queue->IsEmpty())
		return;

	Node* node;
	node = (Node*)queue->Deqeue();

	std::wcout << node->data;

	if (node->left != nullptr)
		queue->Enqueue(node->left);
	if (node->right != nullptr)
		queue->Enqueue(node->right);

	BreathFirstSearch(queue);
}

void DoBreathFirstSearch()
{
	Node* rootNode;
	CreateSampleBinaryTree(&rootNode);

	Queue* queue = new Queue();
	queue->Enqueue(rootNode);
	BreathFirstSearch(queue);
	delete queue;
}

//class HanoiBar
//{
//public:
//	HanoiBar() : size(0) {}
//	~HanoiBar() {}
//
//	void push(int disk)
//	{
//		array[size] = disk;
//		size++;
//	}
//
//	int pop()
//	{
//		size--;
//		return array[size];
//	}
//
//	int peek()
//	{
//		size--;
//		int data = array[size];
//		size++;
//		return data;
//	}
//
//	bool IsCompleted()
//	{
//		bool toReturn = true;
//		if (size == 3)
//		{
//			for (int i = 0; i < size - 1; i++)
//			{
//				if (array[i] < array[i + 1])
//				{
//					toReturn = false;
//				}
//			}
//		}
//		else
//		{
//			toReturn =  false;
//		}
//		
//		return toReturn;
//	}
//
//	HanoiBar& operator= (const HanoiBar& other)
//	{
//		if (this != &other)
//		{
//			size = other.size;
//			for (int i = 0; i < 3; i++)
//			{
//				array[i] = other.array[i];
//			}
//		}
//		return *this;
//	}
//
//	int array[3];
//	int size;
//};

//bool g_done = false;
//
//void Hanoi(HanoiBar bars[], int from, int to)
//{
//	if (g_done)
//		return;
//	int disk = bars[from].pop();
//	bars[to].push(disk);
//
//	{
//		HanoiBar b0 = bars[0];
//		HanoiBar b1 = bars[1];
//		HanoiBar b2 = bars[2];
//
//		std::wcout << "\n\n";
//
//		std::wcout << "\n bar1:";
//		for (int i = 0; i < bars[0].size; i++)
//		{
//			std::wcout << bars[0].array[i];
//			std::wcout << ", ";
//		}
//
//		std::wcout << "\n bar2:";
//		for (int i = 0; i < bars[1].size; i++)
//		{
//			std::wcout << bars[1].array[i];
//			std::wcout << ", ";
//		}
//
//		std::wcout << "\n bar3:";
//		for (int i = 0; i < bars[2].size; i++)
//		{
//			std::wcout << bars[2].array[i];
//			std::wcout << ", ";
//		}
//	}
//
//	if (bars[to].IsCompleted())
//	{
//		g_done = true;
//		return;
//	}
//	
//	for (int i = 0; i < 3; i++)
//	{
//		if (i != to)
//		{
//			for (int j = 0; j < 3; j++)
//			{
//				if (i != j)
//				{
//					if (bars[i].size > 0)
//					{
//						if (bars[j].size == 0)
//						{
//							HanoiBar barsCopy[3];
//							barsCopy[0] = bars[0];
//							barsCopy[1] = bars[1];
//							barsCopy[2] = bars[2];
//							Hanoi(barsCopy, i, j);
//						}
//						else if (bars[i].peek() < bars[j].peek())
//						{
//							HanoiBar barsCopy[3];
//							barsCopy[0] = bars[0];
//							barsCopy[1] = bars[1];
//							barsCopy[2] = bars[2];
//							Hanoi(barsCopy, i, j);
//						}
//					}
//				}
//			}
//		}
//	}
//}
//
//void DoHanoi()
//{
//	HanoiBar bars[3];
//	bars[0].push(3);
//	bars[0].push(2);
//	bars[0].push(1);
//
//	std::wcout << "\n-------tower of hanoi answer------\n";
//	Hanoi(bars, 0, 1);
//	Hanoi(bars, 0, 2);
//}

//void moveDisks(int n, char origin, char destination, char buffer) {
//
//	if (n <= 0) return;
//
//	//Move top n - 1 disks from origin to buffer
//	moveDisks(n - 1, origin, buffer, destination);
//
//	//Move nth disk (the bottom disk) from origin to destination
//	std::wcout << "Moving ";
//	std::wcout << n;
//	std::wcout << "th from '";
//	std::wcout << origin;
//	std::wcout << "' to '";
//	std::wcout << destination;
//	std::wcout << "'\n";
//
//	//Move top n - 1 disks from buffer to destination
//	moveDisks(n - 1, buffer, destination, origin);
//}
//
//// This is the textbook version.
//void DoHanoi2()
//{
//	std::wcout << "\n\nTower of Hanoi\n";
//	int diskNumber = 3;
//	char peg1 = 'A';
//	char peg2 = 'B';
//	char peg3 = 'C';
//
//	moveDisks(diskNumber, peg1, peg2, peg3);
//}

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