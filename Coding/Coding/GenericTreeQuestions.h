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

	void FindHeightFromTreeArrayInfoRecursive(int * p, int len, int num, int level, int* maxLevel)
	{
		if (level > *maxLevel)
			*maxLevel = level;
		for (int i = 0; i < len; i++)
		{
			if (p[i] == num)
				FindHeightFromTreeArrayInfoRecursive(p, len, i, level + 1, maxLevel);
		}
	}

	int FindHeightFromTreeArrayInfoIterative(int* p, int len)
	{
		int maxLevel = 0;
		for (int i = 0; i < len; i++)
		{
			int level = 0;
			int x = p[i];
			while (x != -1)
			{
				x = p[x];
				level++;
			}
			if (level > maxLevel)
				maxLevel = level;
		}

		return maxLevel;
	}

	int FindHeightFromTreeArrayInfoIterativeWithHash(int* p, int len)
	{
		int maxLevel = 0;
		HashTable::HashTable hash;

		for (int i = 0; i < len; i++)
		{
			int level = 0;
			int x = p[i];
			while (x != -1)
			{
				void* value = hash.get(x);
				if (value)
				{
					level = (unsigned long long)value;
					x = -1;
				}
				else
				{
					x = p[x];
				}

				level++;
			}

			if (level > maxLevel)
				maxLevel = level;

			hash.insert(i, (void*)level);
		}

		return maxLevel;
	}

	void AreTreesIsomorphic(Node* n1, Node* n2, bool* isIsomorphic)
	{
		if (!n1 && !n2)
			return;
		if (!n1 && n2 || n1 && !n2)
		{
			*isIsomorphic = false;
			return;
		}
		AreTreesIsomorphic(n1->child, n2->child, isIsomorphic);
		AreTreesIsomorphic(n1->sibling, n2->sibling, isIsomorphic);
	}

	void AreTreesMirror(Node* n1, Node* n2, bool* isMirror)
	{
		if (!n1 && !n2) { return; }
		if (!n1 && n2 || n1 && !n2)
		{
			*isMirror = false;
			return;
		}
		AreTreesMirror(n1->child, n2->sibling, isMirror);
		AreTreesMirror(n1->sibling, n2->child, isMirror);
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
		Node* root = CreateNode(0, 0, 0); // let's assume you know where the root node is at
		CreateGenericTreeFromArrayInfo(treeAsArray, sizeof(treeAsArray) / sizeof(treeAsArray[0]), root);
		DFS(root, 0, &treeLevel);

		
		FindHeightFromTreeArrayInfoRecursive(treeAsArray, sizeof(treeAsArray) / sizeof(treeAsArray[0]), -1, 0, &treeLevel);
		treeLevel -= 1; // since the above function assumes root is height of 1

		treeLevel= FindHeightFromTreeArrayInfoIterative(treeAsArray, sizeof(treeAsArray) / sizeof(treeAsArray[0]));

		treeLevel = FindHeightFromTreeArrayInfoIterativeWithHash(treeAsArray, sizeof(treeAsArray) / sizeof(treeAsArray[0]));

		bool isIsomorphic = true;

		Node* isomorphicRoot = CreateNode(0, 0, 0); // let's assume you know where the root node is at
		CreateGenericTreeFromArrayInfo(treeAsArray, sizeof(treeAsArray) / sizeof(treeAsArray[0]), isomorphicRoot);
		AreTreesIsomorphic(root, isomorphicRoot, &isIsomorphic);

		{
			Node* n3 = CreateNode(3, 0, 0);
			Node* n5 = CreateNode(5, 0, 0);
			Node* n4 = CreateNode(4, 0, n5);
			Node* n2 = CreateNode(2, n4, n3);
			Node* n1 = CreateNode(1, n2, 0);


			Node* m2 = CreateNode(2, 0, 0);
			Node* m5 = CreateNode(5, 0, 0);
			Node* m4 = CreateNode(4, m5, 0);
			Node* m3 = CreateNode(3, m2, m4);
			Node* m1 = CreateNode(1, 0, m3);

			bool isMirror = true;
			AreTreesMirror(n1, m1, &isMirror);
		}

		printf("");

	}
}
