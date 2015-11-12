#pragma once
#include <cstdio>
#include "Trees.h"
#include "Stack.h"

namespace TreeQuestions
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

	void PreorderTraversalIterative(Node* r)
	{
		Stack s;
		s.push(r);
		while (s.Size())
		{
			Node* n = (Node*)s.pop();
			printf("%d", n->data);
			if(n->r)
				s.push(n->r);
			if(n->l)
			s.push(n->l);
		}
	}

	void InorderTraversalIterative(Node* r)
	{
		Stack s;
		while (1)
		{
			if (r)
			{
				s.push(r);
				r = r->l;
			}
			else
			{
				if (s.Size() == 0)
					break;

				Node* n = (Node*)s.pop();
				printf("%d,", n->data);
				r = n->r;
			}
		}
	}

	void PostOrderTraversalIterative()
	{

	}

	void DoTreeQuestions()
	{
		Node* n6 = createNode(6, 0, 0);
		Node* n7 = createNode(7, 0, 0);
		Node* n4 = createNode(4, n6, 0);
		Node* n5 = createNode(5, 0, n7);
		Node* n9 = createNode(9, 0, 0);
		Node* n2 = createNode(2, n4, n5);
		Node* n3 = createNode(3, 0, n9);
		Node* n1 = createNode(1, n2, n3);

		printf("\n\n---PreorderTraversalIterative---\n\n");
		PreorderTraversalIterative(n1);

		printf("\n\n---InorderTraversalIterative---\n\n");
		InorderTraversalIterative(n1);

	}
}