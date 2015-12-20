#pragma once
#include "HashTable.h"
#include "Stack.h"
#include "Queue.h"
namespace Solve
{
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
			//printf("");
		}

	}
}
