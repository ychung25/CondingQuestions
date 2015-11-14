#pragma once
#include <cstdio>
#include "Trees.h"
#include "Stack.h"
#include "Queue.h"

namespace GenericTreeQuestions
{
	struct Node
	{
		int data;
		Node* child;
		Node* sibling;
	};

	Node* CreateNode(int data, Node* child, Node* sibling)
	{
		Node* n = new Node();
		n->data = data;
		n->child = child;
		n->sibling = sibling;
		return n;
	}

	void DFS(Node* n)
	{
		if (!n) { return; }
		//preorder
		DFS(n->child);
		//postorder
		DFS(n->sibling);
	}

	void BFS(Queue* q, int* level)
	{
		if (q->Size() == 0) { return; }

		Node* n = (Node*)q->Deqeue();

		if (n == 0)
		{
			*level = *level + 1;
			if (q->Size() > 0)
				q->Enqueue(0);
		}
		else
		{
			printf("%d ", n->data);
			Node* child = n->child;
			while (child)
			{
				q->Enqueue(child);
				child = child->sibling;
			}
		}

		BFS(q, level);
	}

	void DoGenericTreeQuestions()
	{
		Node* n11 = CreateNode(11, 0, 0);
		Node* n10 = CreateNode(10, 0, n11);
		Node* n9 = CreateNode(9, 0, n10);
		Node* n8 = CreateNode(8, n9, 0);
		Node* n4 = CreateNode(4, n8, 0);
		Node* n7 = CreateNode(7, 0, 0);
		Node* n3 = CreateNode(3, n7, n4);
		Node* n6 = CreateNode(6, 0, 0);
		Node* n5 = CreateNode(5, 0, n6);
		Node* n2 = CreateNode(2, n5, n3);
		Node* n1 = CreateNode(1, n2, 0);

		DFS(n1);

		printf("\n---Generic tree BFS---\n");
		Queue BFSQueue;
		int BFSLevel = 0;
		BFSQueue.Enqueue(n1);
		BFSQueue.Enqueue(0);
		BFS(&BFSQueue, &BFSLevel);

		printf("");
	}
}
