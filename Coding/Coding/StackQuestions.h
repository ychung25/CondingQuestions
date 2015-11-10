#pragma once
#include "Stack.h"
#include "HashTable.h"

namespace StackQuestions
{
	// An expression can be wrapped with { }, ( ) or [ ].
	// E.g. (A[0]+B[0]){}    <- valid
	//      (A[0] + B[0])){} <- invalid
	bool IsExpressionBalanced(char* expression)
	{
		Stack stack;
		while (*expression)
		{
			if (*expression == '(' ||
				*expression == '{' ||
				*expression == '[')
			{
				stack.push(expression);
			}

			if (*expression == ')')
			{
				if (stack.Size() == 0)
					return false;
				if (((*(char*)(stack.pop())) != '('))
					return false;
			}
			else if (*expression == '}')
			{
				if (stack.Size() == 0)
					return false;
				if (((*(char*)(stack.pop())) != '{'))
					return false;
			}
			else if (*expression == ']')
			{
				if (stack.Size() == 0)
					return false;
				if (((*(char*)(stack.pop())) != '['))
					return false;
			}
		    expression++;
		}

		if (stack.Size() > 0)
		{
			return false;
		}

		return true;
	}

	void GetMininumStackV1()
	{
		class GetMinStack
		{
		public:
			void Push(void *data)
			{
				regularStack.push(data);
				if (regularStack.Size() == 1)
				{
					minStack.push(data);
				}
				else
				{
					if (*((int*)data) < *((int*)minStack.peek()))
					{
						minStack.push(data);
					}
				}
			}
			void* Pop()
			{
				int* data = (int*)regularStack.pop();
				if (*data == *((int*)minStack.peek()))
				{
					minStack.pop();
				}
				return data;
			}

			void* GetMin()
			{
				return minStack.peek();
			}
		private:
			Stack regularStack;
			Stack minStack;
		};

		class GetMinStackV1
		{
		public:
			GetMinStackV1() :min(0) {}

			void Push(void *data)
			{
				regularStack.push(data);
				if (!min)
				{
					min = data;
				}
				else
				{
					if (*((int*)data) < *((int*)min))
					{
						min = data;
					}
				}
			}
			void* Pop()
			{
				void* data = regularStack.pop();
				if (data == min)
				{
					if (regularStack.Size() == 0)
					{
						min = 0;
					}
					else
					{
						Stack tempStack;
						void* tempMin = regularStack.pop();
						while (regularStack.Size() > 0)
						{
							void* tempData = regularStack.pop();
							if (*((int*)tempData) < *((int*)tempMin))
								tempMin = tempData;
							tempStack.push(tempData);
						}
						while (tempStack.Size() > 0)
						{
							regularStack.push(tempStack.pop());
						}
					}
				}
				return data;
			}

			void* GetMin()
			{
				return min;
			}
		private:
			Stack regularStack;
			void* min;
		};

		printf("\n---MinStack values---\n");

		GetMinStack minStack;
		int i1 = 4;
		int i2 = 6;
		int i3 = 2;
		int i4 = 9;
		minStack.Push(&i1);
		printf("Min = %d\n", *((int*)minStack.GetMin())); //4
		minStack.Push(&i2);
		printf("Min = %d\n", *((int*)minStack.GetMin())); //4
		minStack.Push(&i3);
		printf("Min = %d\n", *((int*)minStack.GetMin())); //2
		minStack.Push(&i4);
		printf("Min = %d\n", *((int*)minStack.GetMin())); //2
		minStack.Pop();
		printf("Min = %d\n", *((int*)minStack.GetMin())); //2
		minStack.Pop();
		printf("Min = %d\n", *((int*)minStack.GetMin())); //4
		minStack.Pop();
		printf("Min = %d\n", *((int*)minStack.GetMin())); //4
		minStack.Pop();

		printf("\n-------\n");
		GetMinStack minStack2;
		minStack2.Push(&i1);
		printf("Min = %d\n", *((int*)minStack2.GetMin())); //4
		minStack2.Push(&i2);
		printf("Min = %d\n", *((int*)minStack2.GetMin())); //4
		minStack2.Push(&i3);
		printf("Min = %d\n", *((int*)minStack2.GetMin())); //2
		minStack2.Push(&i4);
		printf("Min = %d\n", *((int*)minStack2.GetMin())); //2
		minStack2.Pop();
		printf("Min = %d\n", *((int*)minStack2.GetMin())); //2
		minStack2.Pop();
		printf("Min = %d\n", *((int*)minStack2.GetMin())); //4
		minStack2.Pop();
		printf("Min = %d\n", *((int*)minStack2.GetMin())); //4
		minStack2.Pop();


	}

	void DoStackQuestions()
	{
		{
			char* expression = "{{{(A)}[0][1]+A*B(1)}";
			bool isBalanced = IsExpressionBalanced(expression);

			expression = "{{(A)}[0][1]+A*B(1)}";
			isBalanced = IsExpressionBalanced(expression);
		}

		{
			GetMininumStackV1();
		}
	}
}
