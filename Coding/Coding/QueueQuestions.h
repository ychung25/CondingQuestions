#pragma once
#include "Queue.h"
#include "Stack.h"

namespace QueueQuestions
{
	void QueueMadeFromTwoStacks()
	{
		class MyQueue
		{
		public:
			void Enqueue(void* data)
			{
				if (s2.Size() > 0)
				{
					s1.push(s2.pop());
				}

				s1.push(data);
			}

			void* Dequeue()
			{
				while (s1.Size() > 0)
				{
					s2.push(s1.pop());
				}

				return s2.pop();
			}
		private:
			Stack s1;
			Stack s2;
		};


		MyQueue queue;
		queue.Enqueue((void*)1);
		queue.Enqueue((void*)2);
		queue.Enqueue((void*)3);
		queue.Enqueue((void*)4);

		int result = (int)queue.Dequeue();
		result = (int)queue.Dequeue();
		queue.Enqueue((void*)1);
		queue.Enqueue((void*)2);
		result = (int)queue.Dequeue();
		result = (int)queue.Dequeue();
		printf("");
	}

	void QueueMadeFromArray()
	{
		class MyQueue
		{
		public:
			MyQueue(int _size) : h(0), t(0), count(0), size(_size)
			{
				array = new int[size]();
			}
			~MyQueue()
			{
				delete[] array;
			}
			bool Enqueue(int data)
			{
				if (count <= size)
				{
					array[t] = data;
					t = (t + 1) % size;
					count++;
					return true;
				}
				else
				{
					return false; // queue is full
				}
			}
			bool Dequeue(int* data)
			{
				if (count > 0)
				{
					*data = array[h];
					h = (h + 1) % size;
					count--;
					return true;
				}
				else
				{
					return false; // queue is empty
				}
			}

		private:
			int h;
			int t;
			int count;
			int size;
			int* array;
		};

		MyQueue queue(4);
		int x = 0;
		bool result = queue.Dequeue(&x);
		result = queue.Enqueue(1);
		result = queue.Enqueue(2);
		result = queue.Enqueue(3);
		result = queue.Enqueue(4);
		result = queue.Dequeue(&x);
		result = queue.Dequeue(&x);
		result = queue.Enqueue(5);
		result = queue.Enqueue(6);
		result = queue.Dequeue(&x);
		result = queue.Dequeue(&x);
		result = queue.Dequeue(&x);
		result = queue.Dequeue(&x);

		printf("");

	}

	void DoQueueQuestions()
	{
		QueueMadeFromTwoStacks();
		QueueMadeFromArray();
	}
}
