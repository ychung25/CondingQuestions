#pragma once
#include "Heap.h"

/* ***********************************************************
All Heaps here are MinHeap for the sake of question solving
**************************************************************/
namespace HeapQuestions
{
	void CreateHeapFromArrayInPlace()
	{
		int data[] = { 5,3,2,4,1,7,6 };
		int dataSize = 7;

		for (int i = dataSize - 1; i >= 0; i--)
		{
			Heap::HeapifyUp(i, data);
		}
		printf("");
	}
	void CreateHeapFromArrayInPlacev2()
	{
		int data[] = { 5,3,2,4,1,7,6 };
		int size = 7;
		int lastElementIndex = 7 - 1;
		int firstParent = (lastElementIndex - 1) / 2;
		for (int i = firstParent; i >= 0; i--)
		{
			Heap::HeapifyDown(i, data, size);
		}
		printf("");
	}

	void HeapSortClassic()
	{
		int data[] = { 5,3,2,4,1,7,6 };
		int size = 7;
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
	void HeapSortInPlace()
	{
		int data[] = { 5,3,2,4,1,7,6 };
		int size = 7;

		for (int i = size - 1; i >= 0; i--)
		{
			Heap::HeapifyUp(i, data);
		}

		for (int i = 0; i < size; i++)
		{
			int temp = data[0];
			data[0] = data[size - 1 - i];
			data[size - 1 - i] = temp;
			Heap::HeapifyDown(0, data, size - 1 - i);
		}

		printf("");
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

		CreateHeapFromArrayInPlace();
		CreateHeapFromArrayInPlacev2();

		HeapSortClassic();
		HeapSortInPlace();
	}
}