#pragma once
#include <memory>

void DontDoThis(int n, int data[])
{
	// int data[n]; <-the size must be constant value.
	// sizeof(data); <-this return the size of a pointer in byte not the size of an array.

}

// Creating arrays
void CreateArray()
{
	int stackArray[] = { 1,2 };
	int stackArray2[3];

	int* heapArray = new int[10];
	delete[] heapArray;

	int* heapArray2 = (int*)malloc(3 * sizeof(int));
	free(heapArray2);

	int n = 10;
	int data[10];
	DontDoThis(n, data);
}

// Using arrays
void UseArray()
{
	int data;

	int stackArray[] = { 1,2 };
	data = stackArray[0];
	data = *(stackArray + 1);

	int* heapArray = new int[10];
	data = heapArray[2];
	data = *(heapArray + 3);
	delete[] heapArray;

	int* heapArray2 = (int*)malloc(2 * sizeof(int));
	heapArray2[0] = 1;
	heapArray2[1] = 2;
	free(heapArray2);
}

// Getting size of array
void SizeOfArray()
{
	int stackArray[3];
	int* pStackArray = stackArray;

	int* heapArray = new int[3];
	delete[] heapArray;

	int* heapArray2 = (int*)malloc(3 * sizeof(int));
	free(heapArray2);

	int ArrayLength = sizeof(stackArray) / sizeof(stackArray[0]);

	// these all return the size of pointer because they are now pointer type.
	sizeof(pStackArray);
	sizeof(heapArray);
	sizeof(heapArray2);
}

// Pointer arithmetic
void PointerArithmetic()
{
	int stackArray[10];
	int* pHeapArray = new int[10];

	int distance;
    distance = (stackArray + 8) - (stackArray + 2);
	distance = (pHeapArray + 8) - (pHeapArray + 2);
}

// In and Out Array
void InArray(int* inArray, int length)
{
	for (int i = 0; i < length; i++)
	{
		inArray[i];
	}
}

void OutArray(int** outArray)
{
	int* pArray = new int[10];
	*outArray = pArray;
}

void InAndOutArray()
{
	int inData[] = { 1,2,3,4 };
	InArray(inData, sizeof(inData) / sizeof(inData[0]));

	int* outData;
	OutArray(&outData);
}

// 2DArray
void TwoDimensionArray()
{
	int TwoDimensionData[3][4];
	int OneDimensionData[12];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			TwoDimensionData[i][j];
			OneDimensionData[(i*3)+j];
		}
	}
}

// Array of Arrays
void ArrayOfArrays()
{
	int* arrayOfArrays[2];
	int array1[] = { 10,20 };
	int array2[] = { 100, 200 };
	arrayOfArrays[0] = array1;
	arrayOfArrays[1] = array2;

	int data = *(*(arrayOfArrays + 1) + 1); // should be 200;
}

void DoArraysAndPointers()
{
	CreateArray();
	UseArray();
	SizeOfArray();
	PointerArithmetic();
	InAndOutArray();
	TwoDimensionArray();
	ArrayOfArrays();
}
