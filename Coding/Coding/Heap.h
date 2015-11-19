#pragma once

namespace Heap
{
	void HeapifyUp(int index, int data[])
	{
		if (index == 0)
			return;

		int parent = (index - 1) / 2;
		if (parent < 0)
			parent = 0;

		if (data[parent] > data[index])
		{
			int temp = data[parent];
			data[parent] = data[index];
			data[index] = temp;
			HeapifyUp(parent, data);
		}
	}

	void HeapifyDown(int index, int data[], int size)
	{
		int lIndex = 2 * index + 1;
		int rIndex = 2 * index + 2;

		if (lIndex < size && rIndex < size)
		{
			if (data[lIndex] < data[rIndex])
			{
				if (data[index] > data[lIndex])
				{
					int temp = data[index];
					data[index] = data[lIndex];
					data[lIndex] = temp;
					HeapifyDown(lIndex, data, size);
				}
			}
			else
			{
				if (data[index] > data[rIndex])
				{
					int temp = data[index];
					data[index] = data[rIndex];
					data[rIndex] = temp;
					HeapifyDown(rIndex, data, size);
				}
			}
		}
		else if (lIndex < size && data[index] > data[lIndex])
		{
			int temp = data[index];
			data[index] = data[lIndex];
			data[lIndex] = temp;
			HeapifyDown(lIndex, data, size);
		}
	}

	class MinHeap
	{
	public:
		MinHeap()
		{
			ar = new int[1000]();
			size = 0;
		}

		void Insert(int data)
		{
			ar[size] = data;
			HeapifyUp(size, ar);
			size++;
		}

		int GetMin()
		{
			if (size > 0)
			{
				int temp = ar[0];
				ar[0] = ar[size - 1];
				ar[size -1] = temp;
				size--;
				HeapifyDown(0, ar, size);
				return temp;
			}
			return -1; //error
		}

		int PeekMin()
		{
			return ar[0];
		}

		int GetSize()
		{
			return size;
		}

		void Print()
		{
			for (int i = 0; i < size; i++)
			{
				printf("%d ", ar[i]);
			}
		}

	private:

		int* ar;
		int size;
	};
}