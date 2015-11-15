#pragma once
#include "Stack.h"
#include "Queue.h"
#include "HashTable.h"

namespace BinarySearchTreeQuestions
{
	struct Node
	{
		int data;
		Node* l;
		Node* r;
	};

	Node* createNode(int data, Node* l, Node* r)
	{
		Node* n = new Node();
		n->data = data;
		n->l = l;
		n->r = r;
		return n;
	}

	bool FindRecursive(Node* n, int key)
	{
		if (!n)
			return false;

		if (n->data == key)
			return true;

		if (key < n->data)
			FindRecursive(n->l, key);
		else
			FindRecursive(n->r, key);
	}

	bool FindIterative(Node* n, int key)
	{
		while (n)
		{
			if (n->data == key)
				return true;
			if (key < n->data)
				n = n->l;
			else
				n = n->r;
				
		}
	}

	void InsertNode(Node* n, int key)
	{
		Node* p = 0;
		while (n)
		{
			p = n;
			if (key < n->data)
				n = n->l;
			else
				n = n->r;
		}
		
		Node* toInsert = createNode(key, 0, 0);
		if (key < p->data)
			p->l = toInsert;
		else
			p->r = toInsert;
	}

	int FindMax(Node* n)
	{
		int max = 0;
		while (n)
		{
			max = n->data;
			n = n->r;
		}
		return max;
	}

	void DeleteNode(Node* n, int key)
	{
		Node* p = 0;
		while (n)
		{
			if (n->data == key)
			{
				if (n->l && n->r)
				{ 
					int max = FindMax(n->l);
					DeleteNode(n, max);
					n->data = max;
					return;
				}
				else
				{
					Node* temp = 0;
					if (n->l)
						temp = n->l;
					else
						temp = n->r;

					if (p->l == n)
						p->l = temp;
					else
						p->r = temp;
					delete n;
					return;
				}
			}

			p = n;
			if (key < n->data)
				n = n->l;
			else
				n = n->r;
		}
	}

	int findLCD(Node* k, int a, int b)
	{
		if ((a < k->data && k->data < b) ||
			(b < k->data && k->data < a))
		{
			return k->data;
		}

		if (a < k->data)
			findLCD(k->l, a, b);
		else
			findLCD(k->r, a, b);
	}

	// Do inorder and if prev > current, it is not BST
	bool isBST(Node* n, int p)
	{
		if (!n)
			return true;

		bool bLeft = isBST(n->l, n->data);

		if (p > n->data)
			return false;
		p = n->data;

		bool bRight = isBST(n->r, n->data);

		return bLeft && bRight;
	}

	Node* BST2DLL(Node* n)
	{
		if (!n)
			return 0;

		Node* leftTail = BST2DLL(n->l);
		Node* rightTail = BST2DLL(n->r);

		if (!leftTail && !rightTail)
		{
			return n;
		}
		if (leftTail && !rightTail)
		{
			Node* l = n->l;
			l->r = n;
			rightTail = leftTail;
		}
		else if (!leftTail && rightTail)
		{
			Node* r = n->r;
			n->l = r;
			r->r = n;
		}
		else if (leftTail && rightTail)
		{
			Node* r = n->r;
			leftTail->l = r;
			leftTail->r = n;
			r->r = leftTail;
		}

		n->r = rightTail;
		rightTail->l = n;

		return rightTail;
	}

	void DoBinarySearchTreeQuestions()
	{
		Node* n2 = createNode(2, 0, 0);
		Node* n5 = createNode(5, n2, 0);
		Node* n17 = createNode(17, 0, 0);
		Node* n16 = createNode(16, 0, n17);
		Node* n15 = createNode(15, n5, n16);
		Node* n40 = createNode(40, 0, 0);
		Node* n35 = createNode(35, 0, n40);
		Node* n25 = createNode(25, 0, 0);
		Node* n30 = createNode(30, n25, n35);
		Node* n20 = createNode(20, n15, n30);

		bool iFind = FindRecursive(n20, 17);
		iFind = FindIterative(n20, 35);
		int iMax = FindMax(n20);

		InsertNode(n20, 1);
		InsertNode(n20, 21);

		DeleteNode(n20, 20);

		int ilcd = findLCD(n20, 21, 40);

		bool bBST = isBST(n20, n20->data);
	

		{
			Node* n2 = createNode(2, 0, 0);
			Node* n5 = createNode(5, n2, 0);
			Node* n17 = createNode(17, 0, 0);
			Node* n16 = createNode(16, 0, n17);
			Node* n15 = createNode(15, n5, n16);
			Node* n40 = createNode(40, 0, 0);
			Node* n35 = createNode(35, 0, n40);
			Node* n25 = createNode(25, 0, 0);
			Node* n30 = createNode(30, n25, n35);
			Node* n20 = createNode(20, n15, n30);

			Node* dll = BST2DLL(n20);
			printf("");
		}
		
		printf("");

	}
}