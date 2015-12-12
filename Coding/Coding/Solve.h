#pragma once
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

	Node* InsertFront(Node* h, int data)
	{
		if (!h)
			return 0;
		Node* n = CreateNode(data);
		n->next = h;
		h->prev = n;
		return n;
	}

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

	void Solve()
	{
		Node* h = CreateNode(3);
		Node* t = h;

		h = InsertFront(h, 2);

		t = InsertEnd(t, 5);
		t = InsertEnd(t, 6);

		Node* found = Find(h, 5);
		h = InsertBefore(h, found, 4);
		h = InsertBefore(h, h, 1);
		// 1,2,3,4,5,6

		found = Find(h, 3);
		t = InsertAfter(t, found, 30);
		// 1,2,3,30,4,5,6

		t = InsertAfter(t, t, 7);
		// 1,2,3,30,4,5,6,7

		Remove(&h, &t, 1);
		Remove(&h, &t, 7);
		// 2,3,30,4,5,6
		Remove(&h, &t, 30);
		Remove(&h, &t, 4);
		// 2,3,5,6

		Node* newH;
		Node* newT;
		CopyAll(&newH, &newT, h, t);
		// the new one 2,3,5,6
		DeleteAll(h);

		printf("");

	}
}
