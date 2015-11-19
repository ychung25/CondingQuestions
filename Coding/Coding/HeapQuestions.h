#pragma once
#include "Heap.h"

/* ***********************************************************
  All Heaps here are MinHeap for the sake of question solving
**************************************************************/
namespace HeapQuestions
{
	void HeapifyUp(int index, int data[])
	{
		if (index == 0)
			return;

		int parentIndex = (index - 1) / 2;
		if (parentIndex < 0)
			parentIndex = 0;

		if (data[parentIndex] > data[index])
		{
			int temp = data[index];
			data[index] = data[parentIndex];
			data[parentIndex] = temp;
		}
	}
	void HeapifyDown(int index, int data[], int size)
	{
		int lIndex = (2 * index) + 1;
		int rIndex = (2 * index) + 2;

		if (lIndex < size && rIndex < size)
		{
			if (data[lIndex] < data[index])
			{
				if (data[lIndex] < data[index])
				{
					int temp = data[index];
					data[lIndex] = data[index];
					data[lIndex] = temp;
					HeapifyDown(lIndex, data, size);
				}
			}
			else
			{
				if (data[rIndex] < data[index])
				{
					int temp = data[index];
					data[rIndex] = data[index];
					data[rIndex] = temp;
					HeapifyDown(rIndex, data, size);
				}
			}
		}
		else if (lIndex < size)
		{
			if (data[lIndex] < data[index])
			{
				int temp = data[index];
				data[lIndex] = data[index];
				data[lIndex] = temp;
				HeapifyDown(lIndex, data, size);
			}
		}
	}

	void CreateHeapFromArrayInPlace()
	{
		int data[] = { 5,3,2,4,1,7,6 };
		int dataSize = 7;
		for (int i = dataSize - 1; i >= 0; i--)
		{
			HeapifyUp(i, data);
		}

		for (int i = 0; i < dataSize; i++)
		{
			HeapifyDown(0, data, dataSize - i);
		}


	}
	void HeapSortClassic()
	{
		int data[] = { 5,3,2,4,1,7,6 };
		int dataSize = 7;
		Heap::MinHeap minHeap;
		for (int i = 0; i < dataSize; i++)
		{
			minHeap.Insert(data[i]);
		}

		for (int i = 0; i < dataSize; i++)
		{
			data[i] = minHeap.GetMin();
		}

		// O(n) space
		// O(nlogn) time
	}

	void HeapSortInPlace()
	{
		int data[] = { 3,4,2,1,5,6,8,7 };
		int dataSize = 8;

		int firstParent = ((dataSize - 1) - 1) / 2;
		for (;firstParent >= 0; firstParent--)
		{

		}
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

		printf("\nminHeap2\n");
		int data[] = { 5,3,2,4,1,7,6 };
		Heap::MinHeap minHeap2(data, 7);
		minHeap2.Print();

		printf("\n");
		while (minHeap2.GetSize())
		{
			printf("%d ", minHeap2.GetMin());
		}


		HeapSortClassic();

	}
}