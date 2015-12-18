#pragma once
#include "HashTable.h"
#include "Stack.h"
#include "Queue.h"
namespace Solve
{

    void HeapifyUp(int tree[], int currentIndex)
    {
        int parentIndex = (currentIndex - 1) / 2;
        if (parentIndex >= 0)
        {
            if (tree[currentIndex] < tree[parentIndex])
            {
                int temp = tree[currentIndex];
                tree[currentIndex] = tree[parentIndex];
                tree[parentIndex] = temp;
                HeapifyUp(tree, parentIndex);
            }
        }
    }

    void HeapifyDown(int tree[], int currentIndex, int len)
    {
        int leftIndex = (2 * currentIndex) + 1;
        int rightIndex = (2 * currentIndex) + 2;

        int currentValue = tree[currentIndex];
        int leftValue = currentValue;
        int rightValue = currentValue;

        if (leftIndex < len)
            leftValue = tree[leftIndex];
        if (rightIndex < len)
            rightValue = tree[rightIndex];

        if ((leftValue < rightValue) && (leftValue < currentValue))
        {
            int temp = tree[currentIndex];
            tree[currentIndex] = tree[leftIndex];
            tree[leftIndex] = temp;
            HeapifyDown(tree, leftIndex, len);
        }
        if ((rightValue < leftValue) && (rightValue < currentValue))
        {
            int temp = tree[currentIndex];
            tree[currentIndex] = tree[rightIndex];
            tree[rightIndex] = temp;
            HeapifyDown(tree, rightIndex, len);
        }
    }

    void HeapSort(int data[], int len)
    {
        int lastElementIndex = len - 1;
        int x = (lastElementIndex - 1) / 2;
        for (int i = x; i >= 0; i--)
        {
            HeapifyDown(data, i, len);
        }

        for (int i = (len - 1); i >= 0; i--)
        {
            int temp = data[0];
            data[0] = data[i];
            data[i] = temp;
            HeapifyDown(data, 0, i);
        }

        // if heapifydown was maxHeap version, you wouldn't have to do this
        int a = 0;
        int b = len - 1;
        while (a < b)
        {
            int temp = data[a];
            data[a] = data[b];
            data[b] = temp;
            a++;
            b--;
        }
    }

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


	void Solve()
	{
        int data[] = { 91, 23, 1,2,3,4,5,6,0,10,12,32, 7};
        HeapSort(data, sizeof(data) / sizeof(data[0]));

        bool isMinHeap = IsAnArrayMeanHeap(data, sizeof(data) / sizeof(data[0]));

        {
            int data[] = { 7, 3, 10 };
            bool isMinHeap = IsAnArrayMeanHeap(data, sizeof(data) / sizeof(data[0]));
            printf("");
        }

        printf("");
	}
}
