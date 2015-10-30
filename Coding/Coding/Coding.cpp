// Coding.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int result = 1;
int n = 0;

int forLoop()
{
	for (int count = 0; count <= n; count++)
	{
		if (count != 0)
		{
			result = result * count;
		};
	}

	return result;
}

int recurssion(int count, int var)
{
	if (count == 0)
	{
		return 1;
	}
	else
	{
		return recurssion((count - 1), result) * count;
	}
}


void RecurssionExample()
{
	result = 1;
	n = 4;
	int loopResult = forLoop();

	result = 1;
	n = 4;
	int recursionResult = recurssion(n, result);
}

int main()
{
	RecurssionExample();
    return 0;
}

