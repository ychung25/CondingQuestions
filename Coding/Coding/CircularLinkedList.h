#pragma once
#include <cstdio>

class CLLNode
{
public:
	CLLNode(int inData) : data(inData), next(nullptr) { }
	int data;
	CLLNode* next;
};

class CLL
{
public:
	CLL() : m_head(nullptr) {}

	void InsertNewHead(CLLNode* node)
	{
		if (m_head == nullptr)
		{
			m_head = node;
			m_head->next = m_head;
		}
		else
		{
			InsertBeforeTarget(m_head, node);
			m_head = node;
		}
	}
	void InsertAfterTarget(CLLNode* target, CLLNode* node) 
	{
		if (target->next == target)
		{
			target->next = node;
			node->next = target;
		}
		else
		{
			CLLNode* current = target;
			CLLNode* nextCurrent = target->next;
			current->next = node;
			node->next = nextCurrent;
		}
	}
	void InsertBeforeTarget(CLLNode* target, CLLNode* node) 
	{
		if (target->next == target)
		{
			target->next = node;
			node->next = target;
		}
		else
		{
			CLLNode* current = target;
			CLLNode* nextCurrent = target->next;
			while (nextCurrent->next != target)
			{
				nextCurrent = nextCurrent->next;
			}
			node->next = target;
			nextCurrent->next = node;
		}
	}

	CLLNode* RemoveAfterTarget(CLLNode* target)
	{
		if (target->next == target)
		{
			target->next = nullptr;
			m_head = nullptr;
		}
		else
		{
			CLLNode* current = target;
			CLLNode* nextCurrent = target->next;
			CLLNode* nextNextCurrent = nextCurrent->next;
	
			target->next = nextNextCurrent;
			nextCurrent->next = nullptr;

			if (nextCurrent == m_head)
			{
				m_head = target;
			}

			return nextCurrent;
		}
	}
	CLLNode* RemoveBeforeTarget(CLLNode* target)
	{
		if (target->next == target)
		{
			target->next = nullptr;
			m_head = nullptr;
		}
		else
		{
			CLLNode* current = target;
			CLLNode* nextCurrent = target->next;
			CLLNode* nextNextCurrent = nextCurrent->next;
			while (nextNextCurrent->next != target)
			{
				nextCurrent = nextCurrent->next;
				nextNextCurrent = nextNextCurrent->next;
			}

			nextCurrent->next = target;
			nextNextCurrent->next = nullptr;
			if (nextNextCurrent == m_head)
			{
				m_head = nextCurrent;
			}
			return nextNextCurrent;
		}
	}

	void Traverse()
	{
		printf("DLL content");
		if (m_head == nullptr) { return; }
		CLLNode* current = m_head;
		do
		{
			printf("%d ", current->data);
			current = current->next;
		} while (current != m_head);
		printf("\n");
	}

private:
	CLLNode* m_head;
};

void DoCircularLinkedList()
{
	CLLNode node1(1);
	CLLNode node2(2);
	CLLNode node3(3);
	CLLNode node4(4);
	CLLNode node5(5);
	CLLNode node6(6);
	CLLNode node7(7);

	CLL cll;
	cll.InsertNewHead(&node3);
	cll.InsertNewHead(&node1);
	cll.InsertAfterTarget(&node1, &node2);
	cll.InsertAfterTarget(&node3, &node5);
	cll.InsertBeforeTarget(&node5, &node4);
	cll.InsertAfterTarget(&node5, &node6);
	cll.InsertAfterTarget(&node6, &node7);
	cll.Traverse();


	cll.RemoveAfterTarget(&node1);
	cll.RemoveBeforeTarget(&node1);
	cll.Traverse();
}