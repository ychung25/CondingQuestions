#pragma once
#include <memory>

// Creating arrays
void CreateArray()
{
	int stackArray[] = { 1,2 };
	int stackArray2[3];

	// putting () at the end initializes the array with 0s. Very useful.
	int* heapArray = new int[10]();
	delete[] heapArray;
}

// Using arrays
void UseArray()
{
	int stackArray[] = { 1,2 };
	stackArray[1] = 1;
	*(stackArray + 1) = 1;

	int* heapArray = new int[10]();
	int i = 0;
	heapArray[i++] = 10;
	heapArray[i] = 20;
	heapArray[++i] = 30;

	delete[] heapArray;
}

// Getting size of array
void SizeOfArray()
{
	int stackArray[3];
	int* pStackArray = stackArray;

	// This only works on stack declared array and sizeof needs to be used within the same function block
	int sizeOfArrayInByte = sizeof(stackArray);
	int sizeOfElementInByte = sizeof(stackArray[0]);
	int numberOfElementInArray = sizeof(stackArray) / sizeof(stackArray[0]);

	// This returns size of int pointer
	sizeof(pStackArray);
}

// Pointer arithmetic
void PointerArithmetic()
{
	int stackArray[10];

	// stackArray++; <- this doesn't work.
	int* temp = stackArray;
	// Only * declared pointer can do pointer arithmetic.
	temp++; 

	int* pHeapArray = new int[10];
	pHeapArray++;
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

void Alias()
{
	int data = 10;
	int& aliasToData = data;
	aliasToData = 20;
	if (data == 20)
	{
		// yeah the data changed!
	}
}

void StringArray()
{
	// Don't make string like the below two...
	//char explicitString[] = { 's', 't', 'r', 'i', 'n', 'g', '\0' };
	//char* readOnlyString = "string";

	// Do this
	char readWriteString[] = "string";
	// readWriteString++; <- this doesn't work so...
	char* pReadWriteString = readWriteString;
	pReadWriteString++;
}

void RemoveCharFromStringInPlace(char str[], char x)
{
	int read = 0;
	int write = 0;
	while (1)
	{
		if (str[read] == '\0')
		{
			str[write++] = str[read++];
			break;
		}
		else if (str[read] != x)
		{
			str[write++] = str[read++];
		}
		else
		{
			read++;
		}
	}
}

void CommonErrorsUsingString(char str[])
{
	return;

	while (str) // NO! you meant while(*str)
	{
		str++;
	}
	str[1]; // No str points to null terminator now... 
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
	Alias();
	StringArray();
	
	char str[] = "hello from the other side";
	RemoveCharFromStringInPlace(str, 'o');
	printf("\n%s\n", str);

	CommonErrorsUsingString(str);
}
