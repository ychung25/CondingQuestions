#pragma once
#include "HashTable.h"
#include "Stack.h"
namespace Solve
{
	struct Node
	{
		int data;
		Node* prev;
		Node* next;
		Node* random;
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

	void TwoCycles(Node* start, Node** c1, Node** c2)
	{
		*c1 = 0;
		*c2 = 0;
		if (!start)
			return;

		Node* c1start;
		Node* c1end;
		Node* c2start;
		Node* c2end;
		
		c1start = start;
		c2end = start;
		int len = 0;
		while (c2end->next != start)
		{
			len++;
			c2end = c2end->next;
		}

		c1end = start;
		for (int i = 0; i < (len / 2); i++)
		{
			c1end = c1end->next;
		}
		c2start = c1end->next;

		c1end->next = c1start;
		c2end->next = c2start;

		*c1 = c1start;
		*c2 = c2start;
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

	bool Palidrome(Node* h)
	{
		Node* current = h;
		int len = 0;
		while (current)
		{
			len++;
			current = current->next;
		}
		current = h;
		int i = 0;
		Node* prev = 0;
		while (current)
		{
			if (i < (len / 2))
			{
				prev = current;
				current = current->next;
			}
			else
			{
				Node* next = current->next;
				current->next = prev;
				prev = current;
				current = next;
			}
			i++;
		}

		Node* start = h;
		Node* end = prev;
		for (int i = 0; i < (len / 2); i++)
		{
			if (start->data != end->data)
			{
				return false;
			}
			start = start->next;
			end = end->next;
		}
		return true;
	}

	void ReverseGroup(Node* h, int k, Node* x, Node** newHead)
	{
		if (k < 1)
			return;
		if (x)
			x->next = 0;
		int count = k - 1;
		Node* current = h;
		while (count && current)
		{
			count--;
			current = current->next;
		}
		if (!current)
		{
			if (x)
				x->next = h;
			else
				*newHead = h;
			return;
		}

		current = h;
		Node* prev = 0;
		for (int i = 0; i < k; i++)
		{
			Node* next = current->next;
			if (prev)
				current->next = prev;
			prev = current;
			current = next;
		}
		if (x)
			x->next = prev;
		else
			*newHead = prev;

		ReverseGroup(current, k, h, newHead);
	}

	Node* RemoveEveryMth(Node* h, int m)
	{
		if (!h || h == h->next || m < 0)
			return 0;

		int len = 0;
		Node*c = h;
		while (c->next != h)
		{
			len++;
			c = c->next;
		}
		if (m == 0)
			m = len + 1;
		
		c = h;

		while (1)
		{
			for (int i = 0; i < (m - 1); i++)
			{
				c = c->next;
			}
			Node* n = c->next;
			Node* nn = n->next;
			c->next = nn;\

			delete n;
			if (c == nn)
				break;
			c = nn;
		}
		return c;
	}

	Node* Clone(Node* h)
	{
		HashTable::HashTable hash;
		Node* c = h;
		Node* newHead = 0;
		while (c)
		{
			Node* n = new Node();
			n->data = c->data;
			if (!newHead)
				newHead = n;
			hash.insert((unsigned long long)c, n);
			c = c->next;
		}
		
		c = h;
		while (c)
		{
			Node* n = (Node*)hash.get((unsigned long long)c);
			Node* nNext = 0;
			if(c->next)
				nNext = (Node*)hash.get((unsigned long long)c->next);
			Node* nRandom = (Node*)hash.get((unsigned long long)c->random);
			n->next = nNext;
			n->random = nRandom;
			c = c->next;
		}
		return newHead;
	}

	Node* Clone2(Node* h)
	{
		if (!h)
			return 0;

		Node* c = h;
		Node* newHead = 0;
		while (c)
		{
			Node* n = new Node();
			if (!newHead)
				newHead = n;
			n->data = c->data;
			Node* next = c->next;
			c->next = n;
			n->next = next;
			c = next;
		}

		c = h;
		while (c)
		{
			Node* n = c->next;
			Node* r = c->random->next;
			n->random = r;
			c = n->next;
		}

		c = h;
		while (c->next)
		{
			Node* copy = c->next;
			Node* next = copy->next;
			c->next = next;
			c = copy;
		}

		return newHead;
	}

	Node* EvenBeforeOdd(Node* h)
	{
		Node* oH = 0;
		Node* eH = 0;
		Node* o = 0;
		Node* e = 0;
		
		Node* c = h;
		while (c)
		{
			if ((c->data % 2) == 0)
			{
				if (!eH)
					eH = c;
				if (e)
					e->next = c;
				e = c;
			}
			else
			{
				if (!oH)
					oH = c;
				if (o)
					o->next = c;
				o = c;
			}
			c = c->next;
		}

		if (!o || !e)
			return 0;

		o->next = 0;
		e->next = 0;
		e->next = oH;
		return eH;
	}

	Node* LastModNode(Node* h, int k)
	{
		if (k < 1)
			return 0;
		Node* c = h;
		Node* x = 0;
		int i = 1;
		while (c)
		{
			if (i%k == 0)
			{
				x = c;
			}
			c = c->next;
			i++;
		}
		return x;
	}

	Node* ModN(Node* h, int k)
	{
		int i = 1;
		Node* c = h;
		Node* x = 0;
		while (c)
		{
			if (i%k == 0)
			{
				if (x)
					x = x->next;
				else
					x = h;
			}
			i++;
			c = c->next;
		}
		return x;
	}

	Node* RootN(Node* h)
	{
		int n = 1;
		int len = 1;
		Node* x = 0;
		Node* c = h;
		while (c)
		{
			if (n*n == len)
			{
				if (x)
					x = x->next;
				else
					x = h;
				n++;
			}
			c = c->next;
			len++;
		}
		return x;
	}

	Node* MergeWithARule(Node* a, Node* b)
	{
		if (!a)
			return b;
		if (!b)
			return a;

		a->next = MergeWithARule(b, a->next);
		return a;
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

		tail->next = head;

		{
			Node* n1 = CreateNode(1);
			Node* n2 = CreateNode(2);
			Node* n3 = CreateNode(3);
			Node* n4 = CreateNode(4);
			n1->next = n2;
			n2->next = n3;
			n3->next = n4;
			n1->random = n1;
			n2->random = n1;
			n3->random = n1;
			n4->random = n3;

			Node* clone = Clone(n1);
			printf("");

			Node* clone2 = Clone2(n1);
			printf("");

		}

		{
			Node* n1 = CreateNode(1);
			Node* n2 = CreateNode(2);
			Node* n3 = CreateNode(3);
			Node* n4 = CreateNode(4);
			n1->next = n2;
			n2->next = n3;
			n3->next = n4;

			Node* m1 = CreateNode(10);
			Node* m2 = CreateNode(20);
			Node* m3 = CreateNode(30);
			Node* m4 = CreateNode(40);
			m1->next = m2;
			m2->next = m3;
			m3->next = m4;

			Node* merged = MergeWithARule(n1, m1);
			printf("");


		}

		printf("");

	}
}
