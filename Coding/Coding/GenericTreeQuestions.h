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

	void DFS(Node* n, int level, int* maxLevel)
	{
		if (!n) { return; }

		if (level > *maxLevel)
			*maxLevel = level;

		//preorder
		DFS(n->child, level+1, maxLevel);
		//postorder
		DFS(n->sibling, level, maxLevel);
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

	void CreateGenericTreeFromArrayInfo(int* array, int len, Node* p)
	{
		if (!p) { return; }

		Node* prev = 0;
		for (int i = 0; i < len; i++)
		{
			if (array[i] == p->data)
			{
				Node* n = CreateNode(i, 0, 0);
				if (prev)
					prev->sibling = n;
				else
					p->child = n;
				prev = n;
			}
		}

		CreateGenericTreeFromArrayInfo(array, len, p->child);
		CreateGenericTreeFromArrayInfo(array, len, p->sibling);
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

		int treeLevel = 0;
		DFS(n1, 0, &treeLevel);

		printf("\n---Generic tree BFS---\n");
		Queue BFSQueue;
		int BFSLevel = 0;
		BFSQueue.Enqueue(n1);
		BFSQueue.Enqueue(0);
		BFS(&BFSQueue, &BFSLevel);


		int treeAsArray[] = { -1,0,1,6,6,0,0,2,7 };
		Node* root = CreateNode(0, 0, 0);
		CreateGenericTreeFromArrayInfo(treeAsArray, sizeof(treeAsArray) / sizeof(treeAsArray[0]), root);
		DFS(root, 0, &treeLevel);

		printf("");

	}
}
