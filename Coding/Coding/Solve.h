#pragma once
#include "HashTable.h"
#include "Stack.h"
#include "Queue.h"
namespace Solve
{
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

	struct Node
	{
		int data;
		Node* next;
	};
	Node* CreateNode(int data)
	{
		Node* n = new Node();
		n->data = data;
		n->next = 0;
		return n;
	}
	Node* FindMid(Node* n)
	{
		Node* slow = n;
		Node* fast = n;
		while (fast)
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
	void BububleShort(int data[], int len)
	{
		for (int j = len - 1; j > 0; j--)
		{
			for (int i = 0; i < j; i++)
			{
				if (data[i] > data[i + 1])
				{
					int temp = data[i];
					data[i] = data[i + 1];
					data[i + 1] = temp;
				}
			}
		}
	}

	void SelectionSort(int data[], int len)
	{
		for (int i = 0; i < len; i++)
		{
			for (int j = i + 1; j < len; j++)
			{
				if (data[j] < data[i])
				{
					int temp = data[i];
					data[i] = data[j];
					data[j] = temp;
				}
			}
		}
	}

	void InsertionSort(int data[], int len)
	{
		for (int i = 0; i < len; i++)
		{
			int temp = data[i];
			int j = i - 1;
			while (j >= 0 && data[j] > temp)
			{
				data[j + 1] = data[j];
				j--;
			}
			data[j + 1] = temp;
		}
	}

	void QuickSort(int data[], int start, int end)
	{
		if (start >= end)
			return;
		
		int pivot = (start + end) / 2;
		int pivotValue = data[pivot];
		int j = start;

		for (int i = start; i <= end; i++)
		{
			if (data[j] < pivotValue)
			{
				j++;
			}
			if (data[i] < pivotValue && i > j)
			{
				if (pivot == j)
				{
					pivot = i;
				}

				int temp = data[i];
				data[i] = data[j];
				data[j] = temp;
				j++;
			}
		}
		int temp = data[pivot];
		data[pivot] = data[j];
		data[j] = temp;
		pivot = j;

		QuickSort(data, start, pivot - 1);
		QuickSort(data, pivot + 1, end);
	}

	void Merge(int data[], int start, int end)
	{
		if (start >= end)
			return;

		int mid = (start + end) / 2;
		int* buffer = new int[(end - start) + 1]();
		int i = start;
		int j = mid + 1;
		int k = 0;
		while (i <= mid && j <= end)
		{
			if (data[i] < data[j])
			{
				buffer[k++] = data[i++];
			}
			else
			{
				buffer[k++] = data[j++];
			}
		}
		while (i <= mid)
		{
			buffer[k++] = data[i++];
		}
		while (j <= end)
		{
			buffer[k++] = data[j++];
		}

		k = 0;
		for (int i = start; i <= end; i++)
		{
			data[i] = buffer[k++];
		}
		delete[] buffer;
	}
	void MergeSort(int data[], int start, int end)
	{
		if (start >= end)
			return;

		int mid = (start + end) / 2;
		MergeSort(data, start, mid);
		MergeSort(data, mid + 1, end);
		Merge(data, start, end);
	}

	void BucketSort(int data[], int len, int range)
	{
		int* bucket = new int[range]();
		for (int i = 0; i < len; i++)
		{
			bucket[data[i]]++;
		}

		int j = 0;
		for (int i = 0; i < range; i++)
		{
			int count = bucket[i];
			while (count)
			{
				data[j++] = i;
				count--;
			}
		}
	}

	bool BinarySearch(int data[], int start, int end, int k)
	{
		if (start > end)
			return false;

		int mid = (start + end) / 2;
		if (k == data[mid])
		{
			return true;
		}
		else if (k < data[mid])
		{
			return BinarySearch(data, start, mid - 1, k);
		}
		else
		{
			return BinarySearch(data, mid+1, end, k);
		}
	}

	Node* Merge(Node* l, Node* r)
	{
		Node* current = 0;
		Node* newHead = 0;
		while (l && r)
		{
			if (l->data < r->data)
			{
				if (!newHead)
					newHead = l;
				else
					current->next = l;
				current = l;
				l = l->next;
			}
			else
			{
				if (!newHead)
					newHead = r;
				else
					current->next = r;
				current = r;
				r = r->next;
			}
		}
		if (l)
			current->next = l;
		if (r)
			current->next = r;
		return newHead;
	}
	Node* MergeSort(Node* n)
	{
		if (!n)
			return 0;
		if (!n->next)
			return n;
		Node* mid = FindMid(n);
		Node* l = n;
		Node* r = mid->next;
		mid->next = 0;
		l = MergeSort(l);
		r = MergeSort(r);
		return Merge(l, r);
	}

	int abs(int x)
	{
		if (x < 0)
			return x*-1;
		return x;
	}
	void FindClosestToK(int data[], int len, int k, int *a, int* b)
	{
		HeapSort(data, len);

		int start = 0;
		int end = len - 1;
		*a = data[start];
		*b = data[end];
		int diff = data[start] + data[end];
		while (start <= end)
		{
			if (abs(k - (data[start] + data[end])) < abs(k-diff))
			{
				diff = data[start] + data[end];
				*a = data[start];
				*b = data[end];
			}

			if (data[start] + data[end] == k)
			{
				break;
			}
			else if (data[start] + data[end] > k)
			{
				end--;
			}
			else if (data[start] + data[end] < k)
			{
				start++;
			}
		}
	}
	void FindClosestToKABC(int data[], int len, int k)
	{
		HeapSort(data, len);
		int x, y, z;
		int diff = -1;
		for (int i = 0; i < len; i++)
		{
			int a, b;
			int c = data[i];
			int m = k - c;
			FindClosestToK(data, len, m, &a, &b);
			if((abs(k-(a + b + c)) < diff) || diff < 0)
			{
				diff = abs(k - (a + b + c));
				x = a;
				y = b;
				z = c;
			}
		}
		printf("(%d, %d, %d)", x, y, z);
	}

	int FindFirstPositive(int data[], int start, int end)
	{
		if (start > end)
			return -1;
		int mid = (start + end) / 2;
		if (data[mid] >= 0)
		{
			if (mid == 0 || data[mid - 1] < 0)
			{
				return data[mid];
			}
		}

		if (data[mid] > 0)
		{
			return FindFirstPositive(data, start, mid - 1);
		}
		else
		{
			return FindFirstPositive(data, mid + 1, end);
		}

	}

	int FindPivot(int data[], int start, int end)
	{
		if (start > end)
			return -999;
		int mid = (start + end) / 2;
		if (mid == 0)
			return data[mid];

		if (data[mid - 1] > data[mid])
			return data[mid];

		if (data[end] < data[mid])
			return FindPivot(data, mid + 1, end);
		else
			return FindPivot(data, start, mid - 1);
	}

	void FindKInRotated(int data[], int start, int end, int k)
	{
		if (start > end)
		{
			printf("didn't find %d\n", k);
			return;
		}

		int mid = (start + end) / 2;
		if (data[mid] == k)
		{
			printf("%d\n", k);
			return;
		}

		if (data[mid] < data[end])
		{
			if (k >= data[mid] && k <= data[end])
				FindKInRotated(data, mid + 1, end, k);
			else
				FindKInRotated(data, start, mid - 1, k);
		}
		else
		{
			if(k <= data[mid] && k >= data[start])
				FindKInRotated(data, start, mid - 1, k);
			else
				FindKInRotated(data, mid + 1, end, k);
		}
		
	}

	void FindTheFirstOccurenceOfK(int data[], int start, int end, int k)
	{
		if (start > end)
			return;

		int mid = (start + end) / 2;
		if (data[mid] == k)
		{
			if (mid == 0 || (data[mid - 1] != data[mid]))
			{
				printf("\nfirst %d found at the index [%d]\n", k, mid);
			}
		}

		if (k <= data[mid])
		{
			FindTheFirstOccurenceOfK(data, start, mid - 1, k);
		}
		else if (k > data[mid])
		{
			FindTheFirstOccurenceOfK(data, mid+1, end, k);
		}
	}

	void FindTheOccurencesOfK(int data[], int start, int end, int k)
	{
		if (start > end)
			return;

		int mid = (start + end) / 2;
		if (data[mid] == k)
		{
			int left = mid - 1;
			int right = mid + 1;
			int count = 1;
			while (left >= 0 && data[left] == k)
			{
				left--;
				count++;
			}
			while (right <= end && data[right] == k)
			{
				right++;
				count++;
			}
			printf("\nThere are %d k\n", count);

		}

		if (k < data[mid])
		{
			FindTheOccurencesOfK(data, start, mid - 1, k);
		}
		else if (k > data[mid])
		{
			FindTheOccurencesOfK(data, mid + 1, end, k);
		}
	}

	void EvenBeforeOdd(int data[], int len)
	{
		int r = 0;
		int w = 0;
		while (r < len)
		{
			if ((data[r] % 2) == 0 && (data[w] % 2) == 1 && r > w)
			{
				int temp = data[r];
				data[r] = data[w];
				data[w] = temp;
			}
			if ((data[w] % 2) == 0)
				w++;
			r++;
		}
	}

	void ZeroOneTwoArray(int data[], int len)
	{
		{
			int r = 0;
			int w = 0;
			while (r < len)
			{
				if (data[r] == 0 && data[w] != 0)
				{
					int temp = data[r];
					data[r] = data[w];
					data[w] = temp;
				}
				if (data[w] == 0)
					w++;
				r++;
			}
		}
		{
			int r = 0;
			int w = 0;
			while (r < len)
			{
				if (data[r] != 2 && data[w] == 2)
				{
					int temp = data[r];
					data[r] = data[w];
					data[w] = temp;
				}
				if (data[w] != 2)
					w++;
				r++;
			}
		}

	}

	void FindMaxDiff(int data[], int len)
	{
		if (len < 2)
			return;

		int maxDiff = data[1] - data[0];
		int min = data[0];

		for (int i = 1; i < len; i++)
		{
			if (data[i] - min > maxDiff)
				maxDiff = data[i] - min;
			if (data[i] < min)
				min = data[i];
		}

		printf("\n maxdiff = %d\n", maxDiff);
	}

	void Alternate(int data[], int len)
	{
		if (len < 2)
			return;
		int a = 1;
		for (int i = (len / 2); i < len; i++)
		{
			int temp = data[i];
			int x = i;
			while (x != a)
			{
				data[x] = data[x - 1];
				x--;
			}
			data[x] = temp;
			a = a + 2;
		}
	}

	void Solve()
	{
		{
			int data[] = { 4,3,5,6,9,1,10,41,34 };
			BububleShort(data, sizeof(data) / sizeof(data[0]));
			printf("");
		}

		{
			int data[] = { 4,3,5,6,9,1,10,41,34 };
			SelectionSort(data, sizeof(data) / sizeof(data[0]));
			printf("");
		}

		{
			int data[] = { 4,3,5,6,9,1,10,41,34 };
			InsertionSort(data, sizeof(data) / sizeof(data[0]));
			printf("");
		}


		{
			int data[] = { 4,3,5,6,9,1,10,41,34 };
			int end = (sizeof(data) / sizeof(data[0])) - 1;
			QuickSort(data, 0, end);
			printf("");
		}

		{
			int data[] = { 4,3,5,6,9,1,10,41,34 };
			int end = (sizeof(data) / sizeof(data[0])) - 1;
			MergeSort(data, 0, end);
			printf("");
		}

		{
			int data[] = { 4,3,10,5,6,9,1,4,10,41,34,10,10 };
			BucketSort(data, sizeof(data) / sizeof(data[0]), 50);
			printf("");
		}

		{
			int data[] = { 4,3,5,6,9,1,10,41,34 };
			int end = (sizeof(data) / sizeof(data[0])) - 1;
			bool found = BinarySearch(data, 0, end, 11);
			found = BinarySearch(data, 0, end, 8);
			found = BinarySearch(data, 0, end, 41);
			found = BinarySearch(data, 0, end, 10);
			printf("");
		}

		{
			Node* n1 = CreateNode(1);
			Node* n2 = CreateNode(2);
			Node* n3 = CreateNode(3);
			Node* n4 = CreateNode(4);
			Node* n5 = CreateNode(5);

			n5->next = n4;
			n4->next = n3;
			n3->next = n2;
			n2->next = n1;

			Node* sorted = MergeSort(n5);
			printf("");

		}

		{
			int data[] = { -16, -25, -10, 14, 17, 35, -50, 0 };
			int size = sizeof(data) / sizeof(data[0]);
			int a;
			int b;
			FindClosestToK(data, size, 10, &a, &b);

			printf("(%d,%d)\n", a, b);
			printf("");
		}


		{
			int data[] = { -16, -25, -10, 14, 17, 37, -56, 36 };
			int size = sizeof(data) / sizeof(data[0]);
			FindClosestToKABC(data, size, 0);
			printf("");
		}

		{
			int data[] = { -34, -23, -15, 3, 5, 7, 10, 17, 35, 50 };
			int size = sizeof(data) / sizeof(data[0]);
			int z = FindFirstPositive(data, 0, size - 1);
			printf("");
		}

		{
			int data[] = { 14, 15, 16, 17, 19, 3, 4, 5, 6, 8, 12, 13};
			int size = sizeof(data) / sizeof(data[0]);
			int pivot = FindPivot(data, 0, size - 1);
			printf("");
		}


		{
			int data[] = { 14, 15, 16, 17, 19, 3, 4, 5, 6, 8, 12, 13 };
			int size = sizeof(data) / sizeof(data[0]);
			FindKInRotated(data, 0, size - 1, 15);
			FindKInRotated(data, 0, size - 1, 44);
			printf("");
		}

		{
			int data[] = { 1,1,2,2,2,3,4,4,4,5,5,6,6,6,7 };
			int size = sizeof(data) / sizeof(data[0]);
			FindTheFirstOccurenceOfK(data, 0, size - 1, 1);
			FindTheFirstOccurenceOfK(data, 0, size - 1, 2);
			FindTheFirstOccurenceOfK(data, 0, size - 1, 3);
			FindTheFirstOccurenceOfK(data, 0, size - 1, 4);
			FindTheFirstOccurenceOfK(data, 0, size - 1, 7);

			FindTheOccurencesOfK(data, 0, size - 1, 1);
			FindTheOccurencesOfK(data, 0, size - 1, 2);
			FindTheOccurencesOfK(data, 0, size - 1, 7);
			printf("");
		}

		{
			int data[] = { 1,2,4,6,7,8,9,11,14,15 };

			EvenBeforeOdd(data, sizeof(data) / sizeof(data[0]));
			printf("");
		}

		{
			int data[] = { 0,0,1,2,1,2,0,1,2,0 };
			ZeroOneTwoArray(data, sizeof(data) / sizeof(data[0]));
			printf("");
		}

		{
			int data[] = { 4,3,19,1,14,7 };
			FindMaxDiff(data, sizeof(data) / sizeof(data[0]));
			printf("");
		}

		{
			{
				int data[] = { 1,2,3,4,5,10,20,30,40,50 };
				int size = sizeof(data) / sizeof(data[0]);
				Alternate(data, size);
				printf("");
			}
		}
	}
}
