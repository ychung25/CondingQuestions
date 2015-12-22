#pragma once
#include "HashTable.h"
#include "Stack.h"
#include "Queue.h"
namespace Solve
{
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

    int FindMode(int data[], int len)
    {
        if (len < 1)
            return -999;
        HeapSort(data, len);

        int prev = data[0];
        int maxRepeatCount = 0;
        int repeatCount = 0;

        for (int i = 1; i < len; i++)
        {
            if (data[i] == data[i - 1])
            {
                repeatCount++;
                if (++repeatCount > maxRepeatCount)
                {
                    maxRepeatCount = repeatCount;
                    prev = data[i - 1];
                }
            }
            else
            {
                repeatCount = 0;
            }
        }
        return prev;

    }

    bool FindAandBThatMakesUpK(int data[], int len, int k, int* a, int *b)
    {
        HeapSort(data, len);

        int start = 0;
        int end = len-1;
        while (start < end)
        {
            if (data[start] + data[end] == k)
            {
                *a = data[start];
                *b = data[end];
                return true;
            }
            else if (data[start] + data[end] < k)
            {
                start++;
            }
            else if (data[start] + data[end] > k)
            {
                end--;
            }
        }
        return false;
    }
    void FindAandBandCThatMakesupK(int data[], int len, int k)
    {
        HeapSort(data, len);
        for (int i = 0; i < len; i++) 
        {
            int m = k - data[i];
            int a;
            int b;
            if (FindAandBThatMakesUpK(data, len, m, &a, &b))
            {
                printf("(%d,%d,%d)\n", data[i], a, b);
            }
        }
    }

    void MergeTwoSortedArray(int A[], int m, int B[], int n)
    {
        int a = (m - n) - 1;
        int b = n - 1;
        int w = m - 1;
        while (w >= 0)
        {
            if (A[a] > B[b])
                A[w--] = A[a--];
            else
                A[w--] = B[b--];
        }
    }

	void Solve()
	{
        {
            int data[] = { 4,2,2,3,5,4,4,1,3,5,5,2,2 };
            int mode = FindMode(data, sizeof(data) / sizeof(data[0]));
            printf("");
        }


        {
            int data[] = { 4,2,2,3,5,4,4,1,3,5,5,2,2 };
            int mode = FindMode(data, sizeof(data) / sizeof(data[0]));
            printf("");
        }

        {
            int data[] = { 1,3,5,6,7,2,4};
            int a;
            int b;
            if (FindAandBThatMakesUpK(data, sizeof(data) / sizeof(data[0]), 10, &a, &b))
            {
                printf("%d, %d", a, b);
            }
            
            printf("");
        }

        {
            printf("\nFindAandBandCThatMakesupK\n");
            int data[] = {1,4,10,5,7,3,20,45,98,8};
            FindAandBandCThatMakesupK(data, sizeof(data) / sizeof(data[0]), 15);
            printf("");
        }

        {
            int A[] = { 2, 4, 5, 6, 7 , 0, 0 };
            int B[] = { 3, 9 };
            int m = sizeof(A) / sizeof(A[0]);
            int n = sizeof(B) / sizeof(B[0]);
            MergeTwoSortedArray(A, m, B, n);
            printf("");
        }

	}
}
