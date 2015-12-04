#pragma once
#include "Recursion.h"
#include "Trees.h"
namespace SortAndSearchQuestions
{
	struct Node
	{
		int data;
		Node* next;
		Node* prev;
	};

	int abs(int x)
	{
		if (x < 0)
		{
			return x*-1;
		}
		return x;
	}

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

	bool BinarySearch(int data[], int start, int end, int k, int* foundIndex)
	{
		if (start > end)
		{
			return false;
		}

		unsigned int mid = (start + end) / 2;
		if (data[mid] == k)
		{
			if(foundIndex)
				*foundIndex = mid;
			return true;
		}
		else if (data[mid] < k)
		{
			return BinarySearch(data, mid + 1, end, k, foundIndex);
		}
		else
		{
			return BinarySearch(data, start, mid - 1, k, foundIndex);
		}
	}

	// Find the mode.
	int MostFrequentNumber(int data[], int size)
	{
		HeapSort(data, size);

		int max = 0;
		int frequent = data[0];
		int x = 0;
		for (int i = 1; i < size; i++)
		{
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

	// Given one array, find a and b that makes up k (a+b=k).
	void FindAandBThatMakesKInSingleArray(int data[], int size, int k)
	{
		HeapSort(data, size);
		int start = 0;
		int end = size - 1;
		while (start <= end)
		{
			int sum = data[start] + data[end];
			if (sum == k)
			{
				printf("\n found %d + %d = %d\n", data[start], data[end], k);
				return;
			}
			else if (sum < k)
			{
				start++;
			}
			else if (sum > k)
			{
				end--;
			}
		}
	}
	void FindAllPairsThatMakesKInSingleArray(int data[], int size, int k)
	{
		HeapSort(data, size);
		int start = 0;
		int end = size - 1;
		while (start <= end)
		{
			if (data[start] + data[end] > k)
			{
				end--;
			}
			else if (data[start] + data[end] < k)
			{
				start++;
			}
			else if (data[start] + data[end] == k)
			{
				printf("\n(%d,%d)=%d\n", data[start], data[end], k);
				printf("\n(%d,%d)=%d\n", data[end], data[start], k);
				end--;
				start++;
			}
		}
	}

	// Given one array, find a, b and c that make up k. (a+b+c=k).
	void FindAandBandCThatMakesKInSingleArray(int data[], int size, int k)
	{
		HeapSort(data, size);
		for (int i = 0; i < size; i++)
		{
			int start = 0;
			int end = size - 1;
			while (start <= end)
			{
				int sum = data[start] + data[end] + data[i];
				if (sum == k)
				{
					//found. b = data[start] and c = data[end]
					printf("\na=%d, b=%d, c=%d\n k=%d\n", data[i], data[start], data[end], k);
					return;
				}
				else if (sum < k)
				{
					start++;
				}
				else if (sum > k)
				{
					end--;
				}
			}
		}
	}

	// In an array, verify if there are i, j and k such that data[i]^2 + data[j]^2 = data[k]^2
	bool VerifyIJKInSingleArray(int data[], int size)
	{
		HeapSort(data, size);

		for (int i = 0; i < size; i++)
		{
			data[i] = data[i] * data[i];
		}

		for (int i = 0; i < size; i++)
		{
			int start = 0;
			int end = size - 1;
			while (start <= end)
			{
				int sum = data[start] + data[end];
				if (sum == data[i])
				{
					printf("\ndata[i]=%d, data[j]=%d, data[k]=%d\n", data[start], data[end], data[i]);
					return true;
				}
				else if (sum < data[i])
				{
					start++;
				}
				else if (sum > data[i])
				{
					end--;
				}

			}
		}

		return false;
	}

	// Given two sorted arrays A and B (both has the same size). Find a in A and b in B, that sums up to be K.
	void FindAandBThatMakesKInTwoArrays(int A[], int B[], int size, int k)
	{
		for (int i = 0; i < size; i++)
		{
			int toFind = k - A[i];
			bool bFound = BinarySearch(B, 0, size - 1, toFind, 0);
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

	// An array contains negative and positive integers, find the pair that is closest to 0 when added up.
	void ClosestToZero(int data[], int size)
	{
		HeapSort(data, size);
		int start = 0;
		int end = size - 1;

		int startKeep = start;
		int endKeep = end;
		int closest = data[start] + data[end];

		while (start < end)
		{
			int sum = data[start] + data[end];
			if (abs(sum) <= abs(closest))
			{
				startKeep = start;
				endKeep = end;
				closest = sum;
			}
			else
			{
				break;
			}
			if (sum == 0)
			{
				break;
			}
			else if (sum > 0)
			{
				end--;
			}
			else if (sum < 0)
			{
				start++;
			}
		}

		printf("\n %d + %d is closest to 0\n", data[startKeep], data[endKeep]);

	}
	// An array contains negative and positive integers, find a, b and c that are closest to 0 when added up.
	void ClosestToZeroABC(int data[], int size)
	{
		HeapSort(data, size);

		int start = 0;
		int end = size - 1;

		int a = start;
		int b = start;
		int c = end;
		int closest = data[start] + data[end] + data[start];

		for (int i = 0; i < size; i++)
		{
			start = 0;
			end = size - 1;
			while (start <= end)
			{
				int sum = data[start] + data[end] + data[i];
				if (abs(sum) <= abs(closest))
				{
					a = start;
					b = end;
					c = i;
					closest = sum;
				}
				if (sum == 0)
				{
					break;
				}
				else if (sum < 0)
				{
					start++;
				}
				else if (sum > 0)
				{
					end--;
				}
			}
		}

		printf("\n %d + %d + %d = %d\n", data[a], data[b], data[c], data[a] + data[b] + data[c]);
	}

	// Given a sorted array of negative and positive numbers, find the first positive number in O(logn)
	void FindTheFirstPositive(int data[], int start, int end)
	{
		if (start > end)
		{
			return;
		}

		int mid = (start + end) / 2;

		if (data[mid] >= 0)
		{
			if ((mid - 1) >= 0)
			{
				if (data[mid - 1] < 0)
				{
					printf("\n the first positive number %d\n", data[mid]);
				}
			}
			FindTheFirstPositive(data, start, mid - 1);
		}
		else if (data[mid] < 0)
		{
			FindTheFirstPositive(data, mid+1, end);
		}
	}
	// Given an array that as number sorted increasing order and then decreasing order, find the first number that decreases. e.g. 1,2,3,4,3,2,1 = 4. Finding local minima is similar.
	void FindLocalMaxia(int data[], int size, int start, int end)
	{
		if (start > end)
			return;

		int mid = (start + end) / 2;
		if ((mid - 1) >= 0 && (mid + 1) < size)
		{
			if (data[mid] > data[mid + 1] &&
				data[mid] > data[mid - 1])
			{
				printf("\n FindLocalMaxia = %d\n", data[mid]);
			}
			else if (data[mid-1] > data[mid])
			{
				FindLocalMaxia(data, size, start, mid - 1);
			}
			else if (data[mid-1] < data[mid])
			{
				FindLocalMaxia(data, size, mid + 1, end);
			}
		}
		
	}
	// Given a sorted array that has been rotated unknown times, find the rotated pivot. e.g 10,20,4,6,10,11 = 4
	void FindRotatedPivot(int data[], int start, int end, int* pivot)
	{
		if (start > end)
			return;

		int mid = (start + end) / 2;
		if ((mid - 1) >= 0)
		{

			if ((mid - 1) >= 0 && 
				data[mid] < data[mid - 1])
			{
				*pivot = mid;
				return;
			}
			else if (data[mid] < data[end])
			{
				FindRotatedPivot(data, start, mid - 1, pivot);
			}
			else if(data[mid] > data[end])
			{
				FindRotatedPivot(data, mid + 1, end, pivot);
			}
		}
	}
	// THESE ARE AWESOME! Given a sorted array that has been rotated unknown times, find k.
	void FindKInRotatesPrivot(int data[], int size, int start, int end, int pivot, int k)
	{
		bool doPivotCalc = false;
		if (start > end)
		{
			if (start >= pivot && end < pivot)
			{
				doPivotCalc = true;
			}
			else
			{
				return;
			}
		}

		int mid;
		if (doPivotCalc)
		{
			mid = (start + ((size - start + end) / 2)) % size;
		}
		else
		{
			mid = (start + end) / 2;
		}

		if (data[mid] == k)
		{
			printf("\nFindKInRotatesPrivot = %dth index\n", mid);
			return;
		}
		else if (data[mid] < k)
		{
			FindKInRotatesPrivot(data, size, mid + 1, end, pivot, k);
		}
		else if (data[mid] > k)
		{
			FindKInRotatesPrivot(data, size, start, mid - 1, pivot, k);
		}
	}
	void FindKInRotatesPrivotV2(int data[], int size, int k)
	{
		int pivot = -999;
		FindRotatedPivot(data, 0, size - 1, &pivot);

		int foundIndex;
		bool bFound;
		bFound = BinarySearch(data, 0, pivot - 1, k, &foundIndex);
		if (bFound)
			printf("\nFindKInRotatesPrivotV2 = %dth index\n", foundIndex);
		bFound = BinarySearch(data, pivot, size-1, k, &foundIndex);
		if (bFound)
			printf("\nFindKInRotatesPrivotV2 = %dth index\n", foundIndex);

	}
	void FindKInRotatesPrivotV3(int data[], int start, int end, int k)
	{
		if (start > end)
			return;

		int mid = (start + end) / 2;
		if (data[mid] == k)
		{
			printf("\nFindKInRotatesPrivotV3 = %dth index\n", mid);
			return;
		}
		
		if (data[mid] < data[end])
		{
			if (k > data[mid] && k <= data[end])
				FindKInRotatesPrivotV3(data, mid + 1, end, k);
			else
				FindKInRotatesPrivotV3(data, start, mid - 1, k);
		}
		else if (data[start] < data[mid])
		{
			if (k >= data[start] && k < data[mid])
				FindKInRotatesPrivotV3(data, start, mid - 1, k);
			else
				FindKInRotatesPrivotV3(data, mid + 1, end, k);

		}


	}

	// Given a sorted array with duplicates, find the first occurence of k.
	void FindTheFirstOccurenceOfK(int data[], int start, int end, int k)
	{
		if (start > end)
			return;

		int mid = (start + end) / 2;
		if (data[mid] == k)
		{
			if (mid - 1 >= 0)
			{
				if (data[mid - 1] == data[mid])
				{
					FindTheFirstOccurenceOfK(data, start, mid - 1, k);
				}
				else
				{
					printf("\n FindTheFirstOccurenceOfK = %dith index\n", mid);
					return;
				}
			}
			else
			{
				printf("\n FindTheFirstOccurenceOfK = %dith index\n", mid);
				return;
			}
		}
		else if (data[mid] < k)
		{
			FindTheFirstOccurenceOfK(data, mid + 1, end, k);
		}
		else if (data[mid] > k)
		{
			FindTheFirstOccurenceOfK(data, start, mid-1, k);
		}
	}
	// Given a sorted array with duplicates, find the totla number of occurence of k.
	void FindTheNumberOfOccurencesOfK(int data[], int start, int end, int k, int* occurence)
	{
		if (start > end)
			return;

		int mid = (start + end) / 2;
		if (data[mid] == k)
		{
			(*occurence)++;
			int left = mid - 1;
			while (left >= start)
			{
				if (data[left] == data[mid])
				{
					(*occurence)++;
					left = left - 1;
				}
				else
				{
					break;
				}
			}
			int right = mid + 1;
			while (mid <= end)
			{
				if (data[right] == data[mid])
				{
					(*occurence)++;
					right = right + 1;
				}
				else
				{
					break;
				}
			}
		}
		else if (data[mid] > k)
		{
			FindTheNumberOfOccurencesOfK(data, start, mid - 1, k, occurence);
		}
		else if (data[mid] < k)
		{
			FindTheNumberOfOccurencesOfK(data, mid + 1, end, k, occurence);
		}
	}

	// Given an array, find the second smallest element.
	int FindSecondSmallest(int data[], int size)
	{
		int lastElement = size - 1;
		int firstParent = (lastElement - 1) / 2;
		for (int i = firstParent; i >= 0; i--)
		{
			HeapifyDown(data, size, i);
		}

		if (size == 2)
		{
			return data[1];
		}
		else
		{
			int l = data[1];
			int r = data[2];
			if (l < r)
				return l;
			return r;
		}

	}

	// This shows hany property of XOR. Given an array where there is single lonely element and others are pairs, find the lonley one.
	// e.g {3,4,5,5,3,4,2,6,6} = 2
	int FindLonleyOne(int data[], int size)
	{
		int lonely = data[0];
		for (int i = 1; i < size; i++)
		{
			lonely = lonely ^ data[i];
		}
		return lonely;
	}

	// Given an array of even and odd numbers, make array contain even numbers first and then odd numbers.
	void EvenFirstThenOdd(int data[], int size)
	{
		int start = 0;
		int end = size - 1;
		while (start < end)
		{
			while (data[start] % 2 == 0)
			{
				start++;
			}
			while (data[end] % 2 == 1)
			{
				end--;
			}

			if (start < end)
			{
				int temp = data[start];
				data[start] = data[end];
				data[end] = temp;
			}
		}
	}
	// Given an array of 0,1,2 make 0s come first then 1s and then 2s.
	void ZeroOneTwoArray(int data[], int size)
	{
		int l = 0;
		int h = size - 1;
		for (int m = 0; m <= h; m++)
		{
			while (data[h] == 2)
			{
				h--;
			}

			if (m > h)
				break;

			if (data[m] == 2)
			{
				int temp = data[m];
				data[m] = data[h];
				data[h] = temp;
			}

			if (data[m] == 0)
			{
				int temp = data[m];
				data[m] = data[l];
				data[l] = temp;
			}

			if (data[l] == 0)
				l++;
		}
	}

	// Given an array find the max diff of between data[j] - data[i], where j > i.
	// e.g. { 4, 3, 19, 1, 14, 7 }  19-3=16
	int FindMaxDiff(int data[], int size)
	{
		if (size < 2)
			return -1;

		int maxDiff = data[1] - data[0];
		int min = data[0];

		for (int i = 1; i < size; i++)
		{
			int diff = data[i] - min;
			if (diff > maxDiff)
				maxDiff = diff;
			if (data[i] < min)
				min = data[i];
		}

		return maxDiff;
	}
	
	// Given an array like this a1,a2,a3,a4,b1,b2,b3,b4. Make the array 
	// a1,b1,a2,b2,a3,b3,a4,b4.
	void AlternatingOrder(int data[], int size)
	{
		int m = size / 2;
		int i = 1;
		while (m <= size)
		{
			int temp = data[m];
			int x = m;
			while (x > i)
			{
				data[x] = data[x - 1];
				x--;
			}
			data[i] = temp;
			i += 2;
			m++;
		}
	}

	// Given a 2D array where numbers in rows and colums ascend, find k.
	// e.g |1  2  4  5 |
	//     |7  10 12 15|
	//     |19 20 24 26|
	//     |30 32 34 36| 
	// find K=24.
	bool FindKIn2DArrayOfAccendingRowAndColum(int data[], int width, int height, int k)
	{
		for (int y = 0; y < height; y++)
		{
			if (k < data[width - 1 + (y*width)])
			{
				for (int x = 0; x < width; x++)
				{
					if (k == data[x + (y*width)])
					{
						return true;
					}
				}
				return false;
			}
		}
		return false;
	}
	// Given a 2D array, each row is filled with consecutive 0s followed by 1s. Find the row that has max 0s.
	// e.g |1 1 1 0|
	//     |1 1 0 0|
	//     |1 0 0 0|
	//     |1 1 1 0| 
	// row 3.
	int FindRowWithMaxZero(int data[][4], int width, int height)
	{
		int x = width - 1;
		int maxRow = 0;
		for (int y = 0; y < height; y++)
		{
			while (data[y][x] == 0)
			{
				x--;
				maxRow = y;
			}
		}
		return maxRow;
	}


	// The most optimized way to find the kth smallest
	int FindKthSmallestV1(int data[], int size, int kth)
	{
		// O(nlogn)
		HeapSort(data, size);
		for (int i = 0; i < size; i++)
		{
			if (i == kth)
				return data[i];
		}

		return data[size - 1];
	}
	int FindKthSmallestV2(int data[], int size, int kth)
	{
		// O(klogn)
		Heap::MinHeap minHeap(data, size); //O(n)

		int min = minHeap.PeekMin(); 
		for (int i = 0; i <= kth; i++) //O(klogn)
		{
			min = minHeap.GetMin();
		}
		return min;
	}
	int FindKthSmallestV3(int data[], int size, int kth)
	{
		// O(nlogk)
		Trees::AVLTree avlTree;
		for (int i = 0; i <= kth; i++)
		{
			avlTree.Insert(data[i]); //O(klogk)
		}

		for (int i = kth + 1; i < size; i++)
		{
			int max = avlTree.GetMax();
			if (data[i] < max)
			{
				avlTree.Remove(max);
				avlTree.Insert(data[i]);
			}
		}

		return avlTree.GetMax();
	}

	// Find the K nearest neighbours of median
	void FindKNearestFromMedian(int data[], int size, int k)
	{
		printf("\nFindKNearestFromMedian\n");
		HeapSort(data, size);

		int medianLeftIndex = 0;
		int medianRightIndex = 0;
		if (size % 2 == 0)
		{
			medianLeftIndex = (size / 2) - 1;
			medianRightIndex = size / 2;
		}
		else
		{
			medianLeftIndex = size / 2;
			medianRightIndex = size / 2;
		}

		int medianValue = (data[medianLeftIndex] + data[medianRightIndex]) / 2;

		medianLeftIndex--;
		medianRightIndex++;
		while (medianLeftIndex >= 0 && medianRightIndex < size)
		{
			if (k == 0)
				return;
			if (abs(medianValue - data[medianLeftIndex]) < abs(medianValue - data[medianRightIndex]))
			{
				printf("%d ", data[medianLeftIndex]);
				medianLeftIndex--;
			}
			else
			{
				printf("%d ", data[medianRightIndex]);
				medianRightIndex++;
			}

			k--;
		}

	}

	float FindTheMedianFromTwoArrayOfSameSize(int A[], int B[], int size)
	{
		int i = 0;
		int j = 0;
		int m1 = -1;
		int m2 = -1;
		int m1Value = 0;
		int m2Value = 0;
		int c = 0;

		while (m1 == -1 || m2 == -1)
		{
			if (j == size || (i < size && A[i] < B[j]) )
			{
				if (c == size - 1)
				{
					m1 = i;
					m1Value = A[m1];
				}
				if (c == size)
				{
					m2 = i;
					m2Value = A[m2];
				}
				i++;
			}
			else if (i == size || (j < size && A[i] > B[j]))
			{
				if (c == size - 1)
				{
					m1 = j;
					m1Value = B[m1];
				}
				if (c == size)
				{
					m2 = j;
					m2Value = B[m2];
				}
				j++;
			}
			c++;
		}

		return ((float)m1Value + (float)m2Value) / 2.0;
	}

	// Given an array, find a value K that produces the smallest sum of |K-data[1]| + ... + |K-data[n]|
	void FindKThatProducesSmallestDiff(int data[], int size)
	{
		HeapSort(data, size);
		// Median represent center value better than mean, since means is effected easily by extreme values.
		int k = 0;
		if (size % 2 == 0)
		{
			k = (data[size / 2] + data[(size - 1) / 2]) / 2;
		}
		else
		{
			k = data[size / 2];
		}

		return;
	}

	

	void DoSortAndSearchQuestions()
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
			int A[] = { 2, 4, 5, 6, 7, 10, 34, 5, 43 };
			int size = sizeof(A) / sizeof(A[0]);
			FindAandBThatMakesKInSingleArray(A, size, 6);
		}
	
		{
			int A[] = { 2, 4, 5, 7, 3, 10, 8, 11, 13, 1};
			int size = sizeof(A) / sizeof(A[0]);
			FindAllPairsThatMakesKInSingleArray(data, size, 14);
		}

		{
			int A[] = { 2, 4, 5, 6, 7, 10, 34, 5, 43 };
			int size = sizeof(A) / sizeof(A[0]);
			FindAandBandCThatMakesKInSingleArray(A, size, 84);
			printf("");
		}

		{
			printf("\n");
			int A[] = { 2, 4, 5, 6, 7 };
			int B[] = { 4, 9, 15, 20, 30 };
			int size = sizeof(A) / sizeof(A[0]);
			FindAandBThatMakesKInTwoArrays(A, B, size, 37);
		}

		{
			int A[] = { 2, 4, 5, 6, 7 , 0, 0};
			int B[] = { 3, 9 };
			int m = sizeof(A) / sizeof(A[0]);
			int n = sizeof(B) / sizeof(B[0]);
			MergeTwoSortedArray(A, m, B, n);
			printf("");
		}

		{
			int data[] = { -16, -25, -10, 14, 17, 35, -50, 0 };
			int size = sizeof(data) / sizeof(data[0]);
			ClosestToZero(data, size);
		}

		{
			int data[] = { -16, -25, -10, 14, 17, 37, -56, 36 };
			int size = sizeof(data) / sizeof(data[0]);
			ClosestToZeroABC(data, size);
			printf("");
		}
		 
		{
			int data[] = { 16, 5, 25, 3, 10, 14, 2, 17, 35, 50, 4 };
			int size = sizeof(data) / sizeof(data[0]);
			bool bIJKExist = VerifyIJKInSingleArray(data, size);
			printf("");
		}

		{
			int data[] = { -34, -23, -15, 0, 3, 5, 7, 10, 17, 35, 50};
			int size = sizeof(data) / sizeof(data[0]);
			FindTheFirstPositive(data, 0, size - 1);
			printf("");
		}
		{
			int data[] = { 1,2,3,4,3,2,1 };
			int size = sizeof(data) / sizeof(data[0]);
			FindLocalMaxia(data, size, 0, size - 1);
			printf("");
		}
		{
			int data[] = { 3, 4, 5, 6, 8, 12, 13, 1};
			int size = sizeof(data) / sizeof(data[0]);
			int pivot = -999;
			FindRotatedPivot(data, 0, size - 1, &pivot);
			printf("");
		}

		{
			int data[] = { 10,12,15,1,3,4,7,9 };
			int size = sizeof(data) / sizeof(data[0]);
			int pivot = -999;
			FindRotatedPivot(data, 0, size - 1, &pivot);
			FindKInRotatesPrivot(data, size, pivot, pivot - 1, pivot, 12);
			FindKInRotatesPrivotV2(data, size, 12);
			FindKInRotatesPrivotV3(data, 0, size-1, 12);
			printf("");
		}

		{
			int data[] = { 1,2,3,3,4,5,6,7,8,9,10,11,11,12,13,14,15 };
			int size = sizeof(data) / sizeof(data[0]);
			for (int i = 0; i < size; i++)
			{
				int k = data[i];
				FindTheFirstOccurenceOfK(data,0,size-1,k);
			}
		}

		{
			int data[] = { 1,1,2,3,3,3,3,3,3,3,3,4,5,6,7,8,9,10,11,11,11,11,12,13,14,15,15 };
			int size = sizeof(data) / sizeof(data[0]);

			int prev = -1;
			for (int i = 0; i < size; i++)
			{
				int k = data[i];
				if (k != prev)
				{
					prev = k;
					int occurence = 0;
					FindTheNumberOfOccurencesOfK(data, 0, size - 1, k, &occurence);
					printf("");
				}
			}
		}

		{
			int data[] = { 3,5,9,10,23,43 };
			int size = sizeof(data) / sizeof(data[0]);
			int secondSmallest = FindSecondSmallest(data, size);
			printf("");
		}

		{
			int data[] = { 3,4,5,5,3,4,2,6,6 };
			int size = sizeof(data) / sizeof(data[0]);
			int lonely = FindLonleyOne(data, size);
			printf("");
		}

		{
			int twoDimension[4][4] = { { 1,1,1,0 },{ 1,1,0,0 } ,{ 1,0,0,0 } ,{ 1,1,1,0 } };
			int maxRow = FindRowWithMaxZero(twoDimension, 4, 4);
			printf("");
		}

		{
			// e.g |1  2  4  5 |
			//     |7  10 12 15|
			//     |19 20 24 26|
			//     |30 32 34 36| 

			int twoDimension[] = { 1,2,4,5, 7,10,12,15, 19,20,24,16, 30,32,34,36 };
			bool found = FindKIn2DArrayOfAccendingRowAndColum(twoDimension, 4, 4, 21);
			printf("");
		}

		{
			int data[] = { 5,7,2,8,9,12,16,15 };
			int size = sizeof(data) / sizeof(data[0]);
			EvenFirstThenOdd(data, size);
			printf("");
		}

		{
			srand(time(NULL));

			int size = 50;
			for (int i = 0; i < size; i++)
			{
				int* data = new int[size]();
				for (int i = 0; i < size; i++)
				{
					int x = rand() % 3;
					data[i] = x;
				}
				ZeroOneTwoArray(data, size);
				for (int i = 1; i < size; i++)
				{
					if (data[i - 1] > data[i])
					{
						printf("\nsomething is wrong...\n");
					}
				}
			}
		}

		{
			srand(time(NULL));

			int size = 10;
			for (int i = 0; i < size; i++)
			{
				int* data = new int[size]();
				for (int i = 0; i < size; i++)
				{
					int x = rand() % 20;
					data[i] = x;
				}
				printf("\n");
				for (int i = 0; i < size; i++)
				{
					printf("%d ", data[i]);
				}
				int maxDiff = FindMaxDiff(data, size);
				printf("\n   maxaDiff = %d\n", maxDiff);
			}
			printf("");
		}

		{
			int data[] = { 1,2,3,4,5,10,20,30,40,50 };
			int size = sizeof(data) / sizeof(data[0]);
			AlternatingOrder(data, size);
			printf("");
		}

		{
			int data[] = { 0,5,20,4,1,2,9,3,17,15 };
			int size = sizeof(data) / sizeof(data[0]);
			//int result = FindKthSmallestV1(data, size, 3);
			//int result = FindKthSmallestV2(data, size, 5);
			int result = FindKthSmallestV3(data, size, 6);
			printf("");
		}

		{
			int data[] = { 0,5,20,4,1,2,9,3,17,15 };
			int size = sizeof(data) / sizeof(data[0]);
			FindKNearestFromMedian(data, size, 4);
			printf("");
		}

		{
			int A[] = { 2,8,14,15 };
			int B[] = { 4,7,11,13 };
			int size = sizeof(A) / sizeof(A[0]);
			float median = FindTheMedianFromTwoArrayOfSameSize(A, B, size);
			printf("");
		}
		
	}
}