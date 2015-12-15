#pragma once
#include "HashTable.h"
#include "Stack.h"
#include "Queue.h"
namespace Solve
{
	struct Node
	{
		int data;
		Node* left;
		Node* right;
	};
	Node* CreateNode(int data)
	{
		Node* n = new Node();
		n->data = data;
		n->left = 0;
		n->right = 0;
		return n;
	}




	Node* BSTRemove(Node* n, int data)
	{
		if (!n)
			return 0;
		if (data == n->data)
		{
			Node* x = n->left;
			if (!x)
			{
				Node* right = n->right;
				delete n;
				return right;
			}
			else
			{
				if (!x->right)
				{
					n->left = x->left;
				}
				else if (x->right)
				{
					Node* prev = 0;
					while (x->right)
					{
						prev = x;
						x = x->right;
					}
					prev->right = x->left;
				}
				n->data = x->data;
				delete x;
				return n;
			}
		}
		else if (data < n->data)
		{
			n->left = BSTRemove(n->left, data);
		}
		else if (data > n->data)
		{
			n->right = BSTRemove(n->right, data);
		}
		return n;
	}

	void Solve()
	{
		Node* n20 = CreateNode(20);
		Node* n10 = CreateNode(10);
		Node* n30 = CreateNode(30);
		Node* n5 = CreateNode(5);
		Node* n15 = CreateNode(15);
		Node* n7 = CreateNode(7);
		Node* n12 = CreateNode(12);
		Node* n25= CreateNode(25);

		n20->left = n10;
		n20->right = n30;
		n10->left = n5;
		n10->right = n15;
		n5->right = n7;
		n15->left = n12;
		n30->left = n25;


		Node* root = BSTRemove(n20, 1);
		root = BSTRemove(root, 20);
		root = BSTRemove(root, 30);
		root = BSTRemove(root, 10);
		root = BSTRemove(root, 5);
		root = BSTRemove(root, 15);
		root = BSTRemove(root, 7);
		root = BSTRemove(root, 25);

		printf("");
	}
}
