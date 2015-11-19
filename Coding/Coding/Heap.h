#pragma once

namespace Heap
{
	class MinHeap
	{
	public:
		MinHeap()
		{
			ar = new int[1000]();
			lastElement = 0;
		}

		//MinHeap(int data[], int size)
		//{
		//	ar = new int[1000]();
		//	lastElement = 0;
		//	for (int i = 0; i < size; i++)
		//	{
		//		Insert(data[i]);
		//	}
		//}

		MinHeap(int data[], int size) // This is supposed to be more efficient than the above
		{
			ar = new int[1000]();
			lastElement = 0;

			for (lastElement = 0; lastElement < size; lastElement++)
			{
				ar[lastElement] = data[lastElement];
			}

			for (int i = ((lastElement - 1) - 1) / 2; i >= 0; i--)
			{
				HeapifyDown(i);
			}
		}

		void DoHeapSort()
		{

		}

		void Insert(int data)
		{
			ar[lastElement] = data;
			HeapifyUp(lastElement);
			lastElement++;
		}

		int GetMin()
		{
			if (lastElement > 0)
			{
				int temp = ar[0];
				ar[0] = ar[lastElement - 1];
				ar[lastElement] = temp;
				lastElement--;
				HeapifyDown(0);
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
			return lastElement;
		}

		void Print()
		{
			for (int i = 0; i < lastElement; i++)
			{
				printf("%d ", ar[i]);
			}
		}

	private:

		void HeapifyUp(int index)
		{
			if (index == 0)
				return;

			int parent = (index - 1) / 2;
			if (parent < 0)
				parent = 0;

			if (ar[parent] > ar[index])
			{
				int temp = ar[parent];
				ar[parent] = ar[index];
				ar[index] = temp;
			}

			HeapifyUp(parent);
		}

		void HeapifyDown(int index)
		{
			int lIndex = 2 * index + 1;
			int rIndex = 2 * index + 2;

			if (lIndex < lastElement && rIndex < lastElement)
			{
				if (ar[lIndex] < ar[rIndex])
				{
					if (ar[index] > ar[lIndex])
					{
						int temp = ar[index];
						ar[index] = ar[lIndex];
						ar[lIndex] = temp;
						HeapifyDown(lIndex);
					}
				}
				else
				{
					if (ar[index] > ar[rIndex])
					{
						int temp = ar[index];
						ar[index] = ar[rIndex];
						ar[rIndex] = temp;
						HeapifyDown(rIndex);
					}
				}
			}
			else if (lIndex < lastElement && ar[index] > ar[lIndex])
			{
				int temp = ar[index];
				ar[index] = ar[lIndex];
				ar[lIndex] = temp;
				HeapifyDown(lIndex);
			}
		}

		int* ar;
		int lastElement;
	};
}