#pragma once
#include "Stack.h"
#include "HashTable.h"

namespace StackQuestions
{
	int stringLength(char* str)
	{
		int i = 0;
		while (*str)
		{
			i++;
			str++;
		}
		return i;
	}

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

	void GetMininumStack()
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

	// You can also solve it with by converting it to LL. Space O(c), Time (n)
	// This implementation uses stack so Space O(n), Time O(n)
	bool IsItPalindrome(char* string, int len)
	{
		int mid = len / 2;

		Stack stack;
		for (int i = 0; i < mid; i++)
		{
			stack.push(string);
			string++;
		}

		if (len % 2)
		{
			string++;
		}

		while (stack.Size() > 0)
		{
			char* x = (char*)stack.pop();
			if (*x != *string)
				return false;
			string++;
		}

		if (*string)
			return false;

		return true;
	}
	 
	// This is FUCKING AWESOME!!!!! Use only on stack to reverse stack.
	void FlipIt(Stack* s, void* toInsert)
	{
		if (s->Size() == 0)
		{
			s->push(toInsert);
		}
		else
		{
			void* data = s->pop();
			FlipIt(s, toInsert);
			s->push(data);
		}
	}
	void ReverseIt(Stack* s)
	{
		if (s->Size() == 0)
			return;
		
		void* data = s->pop();
		ReverseIt(s);
		FlipIt(s, data);
	}

	// You can also do the same to build a stack using two queues
	void QueueUsingTwoStacks()
	{
		class Queue
		{
		public:
			void push(void* data)
			{
				if (s2.Size() > 0)
				{
					s1.push(s2.pop());
				}
				s1.push(data);

			}
			void* pop()
			{
				void* data = 0;
				while (s1.Size() > 0)
				{
					s2.push(s1.pop());
				}
				
				data = s2.pop();
				return data;

			}
		private:
			Stack s1;
			Stack s2;
		};

		int i1 = 9;
		int i2 = 3;
		int i3 = 4;
		Queue queue;
		queue.push(&i1);
		queue.push(&i2);
		queue.push(&i3);

		int* data = (int*)queue.pop(); //9
		data = (int*)queue.pop(); //3

		queue.push(&i3);
		queue.push(&i2);
	    data = (int*)queue.pop(); //4
		data = (int*)queue.pop(); //4
	}

	// p - push
	// x - pop
	// pxpx  valid
	// pxx   invalid
	// pppxx valid
	bool IsValidPushPopOpeartions(char* pushesAndPops, int len)
	{
		int pushCount = 0;
		int popCount = 0;

		for (int i = 0; i < len; i++)
		{
			if (*pushesAndPops == 'p')
				pushCount++;
			if (*pushesAndPops == 'x')
			{
				popCount++;
				if (popCount > pushCount)
				{
					return false;
				}
			}

			pushesAndPops++;
		}

		return true;
	}

	void FindLargestRectInHistogram()
	{
		int histogram[] = { 1,2,2,6,5,1 };
		int len = sizeof(histogram) / sizeof(histogram[0]);

		int max = 0;
		int rangeStart = 0;
		int rangeEnd = 0;
		int maxRangeStart = 0;
		int maxRangeEnd = 0;

		for (int i = 0; i < len; i++)
		{
			int begin = i;
			int end = i;

			int curentValue = histogram[i];
			int rangeStart = i;
			int rangeEnd = i;

			while (begin >= 0 || end < len)
			{
				begin = begin - 1; 
				end = end + 1;

				if (begin >= 0)
				{
					if (histogram[begin] >= histogram[i])
					{
						curentValue += histogram[i];
						rangeStart = begin;
					}
					else
					{
						begin = -1;
					}
				}

				if (end < len)
				{
					if (histogram[end] >= histogram[i])
					{
						curentValue += histogram[i];
						rangeEnd = end;
					}
					else
					{
						end = len;
					}
				}
			}
			if (curentValue > max)
			{
				max = curentValue;
				maxRangeStart = rangeStart;
				maxRangeEnd = rangeEnd;
			}
		}
	}

	// replace adjacent duplicates using stack
	void RemoveAdjacentDuplicates(char* string, int len)
	{
		Stack stack;
		for (int i = 0; i < len; i++)
		{
			char c = *string;
			void* data = stack.peek();
			if (data)
			{
				char cStack = *(char*)data;
				if (c == cStack)
				{
					stack.pop();
				}
				else
				{
					stack.push(string);
				}

			}
			else
			{
				stack.push(string);
			}

			string++;
		}

		printf("\nRemoveAdjacentDuplicates-----\n");
		Stack temp;
		while (stack.Size() > 0)
		{
			temp.push(stack.pop());
		}
		while (temp.Size() > 0)
		{
			printf("%c", *((char*)temp.pop()));
		}
		printf("\n\n");
	}

	void RemoveAdjacentDuplicatesV2(char* string, int len)
	{
		int currentIndex = 0;
		int prevIndex = 0;

		while (currentIndex < len)
		{
			if (currentIndex != prevIndex && string[currentIndex] == string[prevIndex])
			{
				string[currentIndex] = '\0';
				string[prevIndex] = '\0';

				if (prevIndex > 0)
				{
					prevIndex--;
				}
				else
				{
					prevIndex = currentIndex + 1;
				}
				
				currentIndex++;

			}
			else
			{
				prevIndex = currentIndex;
				currentIndex++;
			}
		}

		printf("\n---RemoveAdjacentDuplicatesV2---\n");
		for (int i = 0; i < len; i++)
		{
			if(string[i] != '\0')
				printf("%c", string[i]);
		}
		printf("\n\n");
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
			GetMininumStack();
		}

		{
			bool result = IsItPalindrome("abccbaa", 6);
		}

		{
			Stack stack;
			char c1 = 'c';
			char c2 = 'b';
			char c3 = 'a';
			stack.push(&c1);
			stack.push(&c2);
			stack.push(&c3);

			ReverseIt(&stack);

			char* c = (char*)stack.pop();
			char* b = (char*)stack.pop();
			char* a = (char*)stack.pop();
		}

		{
			QueueUsingTwoStacks();
		}

		{
			char* string = "pxpxpxppxxppxpxxppx";
			bool result = IsValidPushPopOpeartions(string, stringLength(string));
		}

		{
			FindLargestRectInHistogram();
		}

		{
			char str[] = "mississippi";
			RemoveAdjacentDuplicates(str, stringLength(str));
			char str2[] = "mississippiabc";
			RemoveAdjacentDuplicatesV2(str2, stringLength(str2));

			int size = sizeof(str2) / sizeof(str2[0]);
			printf("");
		}
	}
}
