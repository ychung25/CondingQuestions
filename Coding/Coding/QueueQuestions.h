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
			MyQueue() : h(0), t(0){}
			bool Enqueue(int item)
			{
				int next = (t + 1) % 4;
				if (next == h)
				{
					return false; // queue is full you can't enqueue
				}
				else
				{
					data[t] = item;
					t = next;
				}
				return true;
			}
			int Dequeue(int* item)
			{
				if (h == t)
				{
					return false; // queue is empty you can't dequeue
				}
				else
				{
					*item = data[h];
					h = (h + 1) % 4;
					return true;
				}
			}

		private:
			int h;
			int t;
			int data[4];
		};

		MyQueue queue;
		int x = 0;
		bool result = queue.Dequeue(&x);
		result = queue.Enqueue(1);
		result = queue.Enqueue(2);
		result = queue.Enqueue(3);
		result = queue.Enqueue(4); // you shoudn't be able to queue this.
		result = queue.Dequeue(&x);
		result = queue.Dequeue(&x);
		result = queue.Enqueue(5);
		result = queue.Enqueue(6);
		result = queue.Dequeue(&x);
		result = queue.Dequeue(&x);
		result = queue.Dequeue(&x);
		result = queue.Dequeue(&x);  // queue should be empty

		printf("");

	}

	void DoQueueQuestions()
	{
		QueueMadeFromTwoStacks();
		QueueMadeFromArray();
	}
}
