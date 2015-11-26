#pragma once
#include "Recursion.h"
namespace SortQuestions
{
	struct Node
	{
		int data;
		Node* next;
		Node* prev;
	};

	Node* FindMidNode(Node *n)
	{
		Node* slow = n;
		Node* fast = n;
		while (1)
		{
			fast = fast->next;
			if (!fast)
				break;
			fast = fast->next;
			if (!fast)
				break;

			slow = slow->next;
		}
		return slow;
	}

	void BubbleSort(int data[], int size)
	{
		for (int i = 1; i < size; i++)
		{
			for (int j = 0; j < size - i; j++)
			{
				if (data[j] > data[j + 1])
				{
					int temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp;
				}
			}
		}
	}
	void BubbleSortLL(Node* n, int size)
	{
		Node* start = n;
		Node* end;
		while (n)
		{
			end = n;
			n = n->next;
		}

		while (start != end)
		{
			n = start;
			while (n != end)
			{
				if (n->next->data < n->data)
				{
					int temp = n->next->data;
					n->next->data = n->data;
					n->data = temp;
				}
				n = n->next;
			}
			end = end->prev;
		}
	}

	void SelectionSort(int data[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			int min = i;
			for (int j = i + 1; j < size; j++)
			{
				if (data[j] < data[min])
				{
					min = j;
				}
			}

			int temp = data[min];
			data[min] = data[i];
			data[i] = temp;
		}
	}
	void SelectionSortLL(Node* n, int size)
	{
		Node* start = n;
		while (start)
		{
			Node* minNode = 0;
			int min = start->data;
			Node* x = start->next;
			while (x)
			{
				if (x->data < min)
				{
					min = x->data;
					minNode = x;
				}
				x = x->next;
			}

			if (minNode)
			{
				int temp = start->data;
				start->data = minNode->data;
				minNode->data = temp;
			}
			
			start = start->next;
		}
	}

	void InsertionSort(int data[], int size)
	{
		for (int i = 1; i < size; i++)
		{
			int k = data[i];
			int j = i;
			while (j > 0 && data[j - 1] > k)
			{
				data[j] = data[j - 1];
				j--;
			}
			data[j] = k;
		}
	}

	void MergeSort(int data[], int l, int r)
	{
		if (l == r)
			return;
		int m = l + ((r - l) / 2);
		MergeSort(data, l, m);
		MergeSort(data, m + 1, r);
		
		int* temp = new int[(r - l)+1]();
		int i = l;
		int j = m + 1;
		int c = 0;
		
		while (i <= m && j <= r)
		{
			if (data[i] <= data[j])
			{
				temp[c] = data[i];
				i++;
			}
			else
			{
				temp[c] = data[j];
				j++;
			}
			c++;
		}
		if (i <= m)
		{
			while (i <= m)
			{
				temp[c] = data[i];
				i++;
				c++;
			}
		}
		if (j <= r)
		{
			while (j <= r)
			{
				temp[c] = data[j];
				j++;
				c++;
			}
		}

		c = 0;
		for (int i = l; i <= r; i++)
		{
			data[i] = temp[c];
			c++;
		}

		delete[] temp;
	}
	Node* MergeSortLL(Node* n)
	{
		if (!n->next)
			return n;

		Node* x = FindMidNode(n);
		Node* y = x->next;
		x->next = 0;
		y->prev = 0;

		Node* l = MergeSortLL(n);
		Node* r = MergeSortLL(y);

		Node* current = 0;
		Node* head = 0;
		while (l && r)
		{
			if (l->data < r->data)
			{
				if (!current)
				{
					current = l;
					if (!head)
						head = l;
				}
				else
				{
					current->next = l;
					l->prev = current;
					current = l;
				}
				l = l->next;

			}
			else
			{
				if (!current)
				{
					current = r;
					if (!head)
						head = r;
				}
				else
				{
					current->next = r;
					r->prev = current;
					current = r;
				}
				r = r->next;
			}
		}
		while (l)
		{
			current->next = l;
			l->prev = current;
			current = l;
			l = l->next;
		}
		while (r)
		{
			current->next = r;
			r->prev = current;
			current = r;
			r = r->next;
		}

		return head;
	}

	void QuickSort(int data[], int l, int r)
	{
		if (l >= r)
		{
			return;
		}

		int p = l + ((r - l) / 2);
		int j = l;
		for (int i = l; i < r; i++)
		{
			if (data[i] < data[p])
			{
				int temp = data[i];
				data[i] = data[j];
				data[j] = temp;
				if (j == p)
				{
					p = i;
				}
			}
			if (data[j] < data[p])
			{
				j++;
			}
		}

		int temp = data[p];
		data[p] = data[j];
		data[j] = temp;

		QuickSort(data, l, p-1);
		QuickSort(data, p + 1, r);
	}

	void HeapifyDown(int data[], int size, int i)
	{
		int l = (2 * i) + 1;
		int r = (2 * i) + 2;
		if (l < size && r < size)
		{
			if (data[l] < data[r])
			{
				if (data[l] < data[i])
				{
					int temp = data[i];
					data[i] = data[l];
					data[l] = temp;
					HeapifyDown(data, size, l);
				}
			}
			else
			{
				if (data[r] < data[i])
				{
					int temp = data[i];
					data[i] = data[r];
					data[r] = temp;
					HeapifyDown(data, size, r);
				}
			}
		}
		else if (l < size)
		{
			if (data[l] < data[i])
			{
				int temp = data[i];
				data[i] = data[l];
				data[l] = temp;
				HeapifyDown(data, size, l);
			}
		}
	}
	void HeapSort(int data[], int size)
	{
		int lastElement = size - 1;
		int firstParent = (lastElement - 1) / 2;
		for (int i = firstParent; i >= 0; i--)
		{
			HeapifyDown(data, size, i);
		}

		for (int i = 0; i < size; i++)
		{
			int temp = data[0];
			data[0] = data[lastElement];
			data[lastElement] = temp;

			HeapifyDown(data, lastElement, 0);
			lastElement--;
		}

		int start = 0;
		int end = size - 1;
		while (start < end)
		{
			int temp = data[start];
			data[start] = data[end];
			data[end] = temp;
			start++;
			end--;
		}
	}

	void BucketSort(int data[], int size, int range)
	{
		int* temp = new int[range+1]();
		for (int i = 0; i < size; i++)
		{
			temp[data[i]]++;
		}

		int x = 0;
		for (int i = 0; i < range+1; i++)
		{
			int count = temp[i];
			while (count)
			{
				data[x] = i;
				x++;
				count--;
			}
		}
	}

	int MostFrequentNumber(int data[], int size)
	{
		HeapSort(data, size);

		int max = 0;
		int frequent = data[0];
		int x = 0;
		for (int i = 1; i < size; i++)
		{
			int datai = data[i];
			int datai1 = data[i - 1];
			if (data[i - 1] == data[i])
			{
				x++;
				if (x > max)
				{
					max = x;
					frequent = data[i - 1];
				}
			}
			else
			{
				x = 0;
			}
		}
		return frequent;
	}

	// Given two sorted arrays A and B (both has the same size). Find a in A and b in B, that sums up to be K.
	void FindAandBThatMakesK(int A[], int B[], int size, int k)
	{
		for (int i = 0; i < size; i++)
		{
			int toFind = k - A[i];
			bool bFound = BinarySearch(0, size - 1, toFind, B);
			if (bFound)
			{
				printf("\n%d in A + %d in B = %d\n", A[i], toFind, k);
			}
		}
	}

	// Given a sorted array B of size n and a sorted array A of size n + x = m,
	// put all elements into the array A and keep it sorted.
	void MergeTwoSortedArray(int A[], int m, int B[], int n)
	{
		int x = m - n - 1;
		int y = n - 1;
		for (int i = m - 1; i >= 0; i--)
		{
			if (A[x] > B[y])
			{
				A[i] = A[x];
				x--;
			}
			else
			{
				A[i] = B[y];
				y--;
			}
		}
	}

	void DoSortQuestions()
	{
		int data[] = { 9, 2, 1, 8, 5, 4, 6, 3, 7, 10 };
		int size = sizeof(data) / sizeof(data[0]);

		//BubbleSort(data, size);
		//SelectionSort(data, size);
		//InsertionSort(data, size);
		//MergeSort(data, 0, size - 1);
		//QuickSort(data, 0, size - 1);
		//HeapSort(data, size);
		BucketSort(data, size, 10);

		Node n1;
		n1.data = 1;
		Node n2;
		n2.data = 2;
		Node n3;
		n3.data = 3;
		Node n4;
		n4.data = 4;
		Node n5;
		n5.data = 5;

		n2.prev = 0;
		n2.next = &n1;
		n1.prev = &n2;
		n1.next = &n3;
		n3.prev = &n1;
		n3.next = &n5;
		n5.prev = &n3;
		n5.next = &n4;
		n4.prev = &n5;
		n4.next = 0;
		//BubbleSortLL(&n2, 5);
		//SelectionSortLL(&n2, 5);
		Node* sorted = MergeSortLL(&n2);

		Node* current = sorted;
		while (current)
		{
			int data = current->data;
			current = current->next;
		}

		{
			int data[] = { 10,10,9,1,2,10,3,1,9,10,4,5,10,5,6,7,9,9,8,10 };
			int size = sizeof(data) / sizeof(data[0]);
			int frequent = MostFrequentNumber(data, size);
			printf("");
		}

		{
			printf("\n");
			int A[] = { 2, 4, 5, 6, 7 };
			int B[] = { 4, 9, 15, 20, 30 };
			int size = sizeof(A) / sizeof(A[0]);
			FindAandBThatMakesK(A, B, size, 37);
		}

		{
			int A[] = { 2, 4, 5, 6, 7 , 0, 0};
			int B[] = { 3, 9 };
			int m = sizeof(A) / sizeof(A[0]);
			int n = sizeof(B) / sizeof(B[0]);
			MergeTwoSortedArray(A, m, B, n);
			printf("");
		}

		printf("");
		
	}
}