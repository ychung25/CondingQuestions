#pragma once
#include "Stack.h"
namespace Solve
{
	struct Node
	{
		int data;
		Node* prev;
		Node* next;
	};

	Node* CreateNode(int data)
	{
		Node* n = new Node();
		n->data = data;
		n->prev = 0;
		n->next = 0;
		return n;
	}

	// Returns head
	Node* InsertFront(Node* h, int data)
	{
		if (!h)
			return 0;
		Node* n = CreateNode(data);
		n->next = h;
		h->prev = n;
		return n;
	}

	// Returns tail
	Node* InsertEnd(Node* t, int data)
	{
		if (!t)
			return 0;
		Node* n = CreateNode(data);
		t->next = n;
		n->prev = t;
		return n;
	}

	Node* Find(Node* n,int  data)
	{
		while (n)
		{
			if (n->data == data)
				return n;
			n = n->next;
		}
		return 0;
	}

	// Resturns head
	Node* InsertBefore(Node* h, Node* x, int data)
	{
		if (!h || !x)
			return 0;
		Node* prev = x->prev;
		Node* n = CreateNode(data);
		x->prev = n;
		n->next = x;

		n->prev = prev;
		if (prev)
		{
			prev->next = n;
			return h;
		}
		else
		{
			return n;
		}
	}
	
	// Returns tail
	Node* InsertAfter(Node* t, Node* x, int data)
	{
		if (!t || !x)
			return 0;
		Node* next = x->next;
		Node* n = CreateNode(data);
		x->next = n;
		n->prev = x;
		n->next = next;
		if (next)
		{
			next->prev = n;
			return t;
		}
		{
			return n;
		}
	}

	void Remove(Node** h, Node** t, int data)
	{
		if (!h || !*h || !t || !*t)
			return;

		Node* c = *h;
		while (c)
		{
			if (c->data == data)
				break;
			c = c->next;
		}

		Node* prev = c->prev;
		Node* next = c->next;
		delete c;

		if (prev)
			prev->next = next;
		else
			*h = next;

		if (next)
			next->prev = prev;
		else
			*t = prev;
	}

	void CopyAll(Node** newH, Node** newT, Node* h, Node* t)
	{
		if (!h || !t || !newH || !newT)
			return;
		Node* prev = 0;
		Node* current = h;
		while (current)
		{
			Node* n = CreateNode(current->data);
			if (prev)
			{
				prev->next = n;
				n->prev = prev;
			}
			else
			{
				*newH = n;
			}
			prev = n;
			current = current->next;
		}

		*newT = prev;
	}
	
	void DeleteAll(Node* h)
	{
		if (!h)
			return;
		Node* current = h;
		while(current)
		{
			Node* next = current->next;
			delete current;
			current = next;
		}
	}

	bool IsIsCyclic(Node* h)
	{
		Node* slow = h;
		Node* fast = h;

		while (fast)
		{
			slow = slow->next;
			fast = fast->next;
			if (!fast)
				return false;
			fast = fast->next;

			if (slow == fast)
				return true;
		}

		return false;
	}

	Node* FindSplitPoint(Node *h)
	{
		Node* slow = h;
		Node* fast = h;

		Node* a = h;
		Node* b = 0;

		while (fast)
		{
			slow = slow->next;
			fast = fast->next;
			if (!fast)
				break;
			fast = fast->next;

			if (slow == fast)
			{
				b = fast;
				break;
			}
		}

		if (b)
		{
			while (a != b)
			{
				a = a->next;
				b = b->next;
			}
		}

		return b;
	}

	Node* FindNthFromEnd(Node* h, int nth)
	{
		if (!h)
			return 0;
		Node* a = h;
		Node* b = 0;
		int i = -1;
		while (a)
		{
			a = a->next;
			i++;
			if (i == nth)
			{
				b = h;
			}
			else
			{
				if (b)
					b = b->next;
			}
			
		}
		return b;
	}



	Node* MeetingPoint(Node* a, Node* b)
	{
		Stack s1;
		Stack s2;
		while (a)
		{
			s1.push(a);
			a = a->next;
		}
		while (b)
		{
			s2.push(b);
			b = b->next;
		}

		Node* x;
		Node* y;
		while (s1.Size() && s2.Size())
		{
			if (((Node*)s1.peek())->data == ((Node*)s2.peek())->data)
			{
				x = (Node*)s1.pop();
				y = (Node*)s2.pop();
			}
			else
			{
				break;
			}
		}
		return x;
	}

	bool IsLenEven(Node* h)
	{
		while (h)
		{
			h = h->next;
			if (!h)
				return false;
			h = h->next;
		}
		return true;
	}

	Node* Merge(Node* a, Node* b)
	{
		if (!a)
			return b;
		if (!b)
			return a;
		if (a->data < b->data)
		{
			a->next = Merge(a->next, b);
			return a;
		}
		else
		{
			b->next = Merge(a, b->next);
			return b;
		}
	}


	Node* Reverse(Node* a)
	{
		if (!a)
			return 0;
		Node* b = a->next;
		if (!b)
			return a;

		Node* c = b->next;
		Node* x = Reverse(c);

		a->next = x;
		b->next = a;
		return b;
	}

	void Solve()
	{
		Node* head = CreateNode(1);
		Node* tail = head;

		tail = InsertEnd(tail, 2);
		tail = InsertEnd(tail, 3);
		tail = InsertEnd(tail, 4);
		tail = InsertEnd(tail, 5);
		tail = InsertEnd(tail, 6);
		tail = InsertEnd(tail, 7);



		Node* newHead = Reverse(head);]\





		printf("");

	}
}
