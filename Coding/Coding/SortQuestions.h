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

	void QuickSort()
	{

	}

	void DoSortQuestions()
	{
		int data[] = { 9, 2, 1, 8, 5, 4, 6, 3, 7, 10 };
		int size = sizeof(data) / sizeof(data[0]);

		//BubbleSort(data, size);
		//SelectionSort(data, size);
		//InsertionSort(data, size);
		MergeSort(data, 0, size - 1);
		printf("");
		
	}
}