#pragma once
#include "Heap.h"

/* ***********************************************************
All Heaps here are MinHeap for the sake of question solving
**************************************************************/
namespace HeapQuestions
{

	void ConvertArrayIntoHeap(int data[], int size)
	{
		int lastElementIndex = size - 1;
		int firstParent = (lastElementIndex - 1) / 2;

		// 0th - firstParent-th are internal nodes
		// firstParent-th + 1 to end are leaves

		for (int i = firstParent; i >= 0; i--)
		{
			Heap::HeapifyDown(i, data, size);
		}
		printf("");
	}

	void HeapSortClassic(int data[], int size)
	{
		Heap::MinHeap minHeap;
		for (int i = 0; i < size; i++)
		{
			minHeap.Insert(data[i]);
		}

		for (int i = 0; i < size; i++)
		{
			data[i] = minHeap.GetMin();
		}

		printf("");

		// O(n) space
		// O(nlogn) time
	}
	void HeapSortInPlace(int data[], int size)
	{
		ConvertArrayIntoHeap(data, size);

		for (int i = 0; i < size; i++)
		{
			int temp = data[0];
			data[0] = data[size - 1 - i];
			data[size - 1 - i] = temp;
			Heap::HeapifyDown(0, data, size - 1 - i);
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

		printf("");
	}

	// does given array represent heap?
    bool IsAnArrayMeanHeap(int data[], int len)
    {
        for (int i = (len - 1); i >= 0; i--)
        {
            int parentIndex = (i - 2) / 2;
            if (parentIndex >= 0)
            {
                if (data[parentIndex] > data[i])
                    return false;
            }
        }

        return true;
    }

	int FindMaxInMinHeap(int data[], int size)
	{
		int max = 0;
		int lastElement = size - 1;
		int firstParentIndex = (lastElement - 1) / 2;
		for (int i = firstParentIndex + 1; i < size; i++)
		{
			if (data[i] > max)
				max = data[i];
		}

		return max;
	}


	void DoHeapQuestions()
	{
		Heap::MinHeap minHeap;
		minHeap.Insert(5);
		minHeap.Insert(3);
		minHeap.Insert(2);
		minHeap.Insert(4);
		minHeap.Insert(1);
		minHeap.Insert(7);
		minHeap.Insert(6);

		printf("\n\n---nminHeap---\n\n");
		minHeap.Print();

		printf("\n");
		while (minHeap.GetSize())
		{
			printf("%d ", minHeap.GetMin());
		}

		{
			int data[] = { 999, 1, 65, 2 ,3, 78, 4, 5, 6, 88, 7, 8, 9, 10, 45, 11, 12, 13, 34, 14, 15, 16 };
			int size = sizeof(data) / sizeof(data[0]);

            bool isHeap = IsAnArrayMeanHeap(data, size);

			ConvertArrayIntoHeap(data, size);

            isHeap = IsAnArrayMeanHeap(data, size);
			printf("");
		}

		{
			int data[] = { 999, 1, 65, 2 ,3, 78, 4, 5, 6, 88, 7, 8, 9, 10, 45, 11, 12, 13, 34, 14, 15, 16 };
			int size = sizeof(data) / sizeof(data[0]);
            bool isHeap = IsAnArrayMeanHeap(data, size);
			HeapSortClassic(data, size);
            isHeap = IsAnArrayMeanHeap(data, size);
			printf("");
		}

		{
			int data[] = { 999, 1, 65, 2 ,3, 78, 4, 5, 6, 88, 7, 8, 9, 10, 45, 11, 12, 13, 34, 14, 15, 16 };
			int size = sizeof(data) / sizeof(data[0]);
			HeapSortInPlace(data, size); // it is sorted decending. so yo might want to do inplace flip

			printf("");
		}

		{
			int data[] = { 999, 1, 65, 2 ,3, 78, 4, 5, 6, 88, 7, 8, 9, 10, 45, 11, 12, 13, 34, 14, 15, 16 };
			int size = sizeof(data) / sizeof(data[0]);
			ConvertArrayIntoHeap(data, size);
			int max = FindMaxInMinHeap(data, size);

			max = FindMaxInMinHeap(0, 0);

			int data2[] = { 1 };
			int size2 = sizeof(data2) / sizeof(data2[0]);
			max = FindMaxInMinHeap(data2, size2);

			printf("");
		}

		{
			int data[] = { 999, 1, 65, 2 ,3, 78, 4, 5, 6, 88, 7, 8, 9, 10, 45, 11, 12, 13, 34, 14, 15, 16 };
			int size = sizeof(data) / sizeof(data[0]);
			Heap::MaxHeap maxHeap;

			for (int i = 0; i < size; i++)
			{
				maxHeap.Insert(data[i]);
			}

			int max = maxHeap.GetMax();
			max = maxHeap.GetMax();
			printf("");
		}

		{
			int data[] = { 1, 5 , 7, 12, 13, 4, 3, 6, 14, 15 };
			int size = sizeof(data) / sizeof(data[0]);
			Heap::MedianHeap medianHeap;

			for (int i = 0; i < size; i++)
			{
				medianHeap.Insert(data[i]);
				int datum = data[i];
				float median = medianHeap.PeekMedian();
				printf("");
			}
		}
	}
}