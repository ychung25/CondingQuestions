#pragma once
#include <cstdio>

class XORNode
{
public:
	XORNode(int inData) : data(inData), p(nullptr) {}

	int data;
	XORNode* p;
};

class XORDDL
{
public:
	XORDDL() : m_head(nullptr), m_tail(nullptr) {}

	void Insert(XORNode* node)
	{
		if (m_head == nullptr)
		{
			m_head = node;
			m_tail = node;
		}
		else
		{
			if (m_tail->p == nullptr)
			{
				m_tail->p = node;
				node->p = m_tail;
				m_tail = node;
			}
			else
			{
				m_tail->p = (XORNode*)((unsigned long long)(m_tail->p) ^ (unsigned long long)node);
				node->p = m_tail;
				m_tail = node;

			}
		}
	}

	void InsertAfter(XORNode* target, XORNode* node)
	{
		if (target->p == nullptr)
		{
			target->p = node;
			node->p = target;
		}
		else
		{
			XORNode* prev = 0;
			XORNode* current = m_head;
			while (current != target)
			{
				XORNode* temp = current;
				current  = (XORNode*)((unsigned long long)(current->p) ^ (unsigned long long)prev);
				prev = temp;
			}

			XORNode* next = (XORNode*)((unsigned long long)(target->p) ^ (unsigned long long)prev);
			XORNode* nextNext = 0;
			if (next)
			{
				nextNext = (XORNode*)((unsigned long long)(next->p) ^ (unsigned long long)target);
			}

			node->p = (XORNode*)((unsigned long long)target ^ (unsigned long long)next);
			target->p = (XORNode*)((unsigned long long)prev ^ (unsigned long long)node);
			if (next)
			{
				next->p = (XORNode*)((unsigned long long)node ^ (unsigned long long)nextNext);
			}
			
			if (!next)
			{
				m_tail = node;
			}

		}
	}

	void TraverserForward()
	{
		printf("XORDLL traverse forward ");
		if (m_head == nullptr) { return; }
		XORNode* prev = 0;
		XORNode* current = m_head;
		while (current)
		{
			printf("%d, ", current->data);
			XORNode* temp = current;
			current = (XORNode*)((unsigned long long)(current->p) ^ (unsigned long long)prev);
			prev = temp;
		}
		printf("\n");
	}

	void TraverseBackward()
	{
		if (m_tail == nullptr) { return; }

		printf("XORDLL traverse forward ");
		XORNode* prev = 0;
		XORNode* current = m_tail;
		while (current)
		{
			printf("%d, ", current->data);
			XORNode* temp = current;
			current = (XORNode*)((unsigned long long)(current->p) ^ (unsigned long long)prev);
			prev = temp;
		}
		printf("\n");
	}

private:
	XORNode* m_head;
	XORNode* m_tail;
};

void DoXORDoublyLinkedList()
{
	XORNode node1(1);
	XORNode node2(2);
	XORNode node3(3);
	XORNode node4(4);
	XORNode node5(5);
	XORNode node6(6);
	XORNode node7(7);

	XORDDL xordll;
	xordll.Insert(&node1);
	xordll.Insert(&node3);
	xordll.Insert(&node4);
	xordll.Insert(&node6);
	xordll.InsertAfter(&node4, &node5);
	xordll.InsertAfter(&node6, &node7);
	xordll.InsertAfter(&node1, &node2);
	xordll.TraverserForward();
	xordll.TraverseBackward();
}