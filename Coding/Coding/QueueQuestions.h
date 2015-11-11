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
			void Enqueue(int item)
			{

			}
			int Dequeue()
			{

			}

		private:
			int data[100];
		};
	}

	void DoQueueQuestions()
	{
		QueueMadeFromTwoStacks();
	}
}
