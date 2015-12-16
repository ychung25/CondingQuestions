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

	void PreOrderIterative(Node* n)
	{
		Stack s;
		s.push(n);
		
		while (s.Size() > 0)
		{
			Node* n = (Node*)s.pop();
			printf("%d ", n->data);
			if (n->right)
				s.push(n->right);
			if (n->left)
				s.push(n->left);
		}
	}

	void InorderIterative(Node* n)
	{
		Stack s;
		while (1)
		{
			if (n)
			{
				s.push(n);
				n = n->left;
			}
			else
			{
				if (s.Size() == 0)
					break;

				Node* x = (Node*)s.pop();
				printf("%d ", x->data);
				n = x->right;
			}
		}
	}

	void Solve()
	{
		Node* n1 = CreateNode(1);
		Node* n2 = CreateNode(2);
		Node* n3 = CreateNode(3);
		Node* n4 = CreateNode(4);
		Node* n5 = CreateNode(5);
		Node* n6 = CreateNode(6);
		Node* n7 = CreateNode(7);

		n1->left = n2;
		n1->right = n3;
		n2->left = n4;
		n2->right = n5;
		n1->right = n3;
		n3->right = n6;
		n6->left = n7;

		printf("\n$$$$$$$$$$$$$$$$$$$ SOLVE $$$$$$$$$$$$$$\n");
		//PreOrderIterative(n1);
		InorderIterative(n1);


        printf("");
	}
}
