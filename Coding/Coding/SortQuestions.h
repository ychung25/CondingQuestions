#pragma once
namespace SortQuestions
{
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

		printf("");
		
	}
}