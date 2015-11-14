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

	void DoGenericTreeQuestions()
	{
	}
}
