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

	void InsertAfterHead(CLLNode* node) 
	{
		if (m_head == nullptr)
		{
			m_head = node;
			m_head->next = node;
		}
		else if (m_head->next == m_head)
		{
			m_head->next = node;
			node->next = m_head;
		}
		else if (m_head != m_head)
		{
			CLLNode* afterHead = m_head->next;
			m_head->next = node;
			node->next = afterHead;
		}
	}
	void InsertBeforeHead(CLLNode* node) 
	{
		if (m_head == nullptr)
		{
			m_head = node;
			m_head->next = node;
		}
		else if (m_head->next == m_head)
		{
			m_head->next = node;
			node->next = m_head;
		}
		else if(m_head != m_head)
		{
			CLLNode* beforeHead = m_head->next;
			while (beforeHead->next == m_head)
			{
				beforeHead = beforeHead->next;
			}
			beforeHead->next = node;
			node->next = m_head;

		}
	}
	void InsertNewHead(CLLNode* node)
	{
		if (m_head == nullptr)
		{
			m_head = node;
			m_head->next = node;
		}
		else if (m_head->next == m_head)
		{
			m_head->next = node;
			node->next = m_head;
			m_head = node;
		}
		else if (m_head != m_head)
		{
			CLLNode* beforeHead = m_head->next;
			while (beforeHead->next == m_head)
			{
				beforeHead = beforeHead->next;
			}
			beforeHead->next = node;
			node->next = m_head;
			m_head = node;

		}
	}
	void InsertAfterTarget(CLLNode* target, CLLNode* node) 
	{
		if (target->next == target)
		{
			m_head->next = node;
			node->next = m_head;
		}
		else
		{
			CLLNode* afterTarget = target->next;
			target->next = node;
			node->next = afterTarget;
		}
	}
	void InsertBeforeTarget(CLLNode* target, CLLNode* node) 
	{
		if (target->next == target)
		{
			m_head->next = node;
			node->next = m_head;
		}
		{
			CLLNode* beforeTarget = m_head;
			while (beforeTarget->next != target)
			{
				beforeTarget = beforeTarget->next;
			}

			beforeTarget->next = node;
			node->next = target;
		}
	}

	CLLNode* RemoveAfterHead()
	{
		if (m_head == nullptr) { return nullptr; }
		if (m_head->next == m_head)
		{
			CLLNode* temp = m_head;
			m_head = nullptr;
			temp->next = nullptr;
			return temp;
		}
		else
		{
			CLLNode* afterHead = m_head->next;
			CLLNode* afterAfterHead = afterHead->next;
			if (afterAfterHead == m_head)
			{
				m_head->next = m_head;
				afterHead->next = nullptr;
				return afterHead;
			}
			else
			{
				m_head->next = afterAfterHead;
				afterHead->next = nullptr;
				return afterHead;
			}
		}
	}
	CLLNode* RemoveBeforeHead()
	{
		if (m_head->next == m_head)
		{
			CLLNode* temp = m_head;
			m_head = nullptr;
			temp->next = nullptr;
			return temp;
		}
		else
		{
			CLLNode* afterHead = m_head;
			CLLNode* afterAfterHead = afterHead->next;
			if (afterAfterHead == m_head)
			{
				m_head->next = m_head;
				afterHead->next = nullptr;
				return afterHead;
			}
			else
			{
				while (afterAfterHead->next != m_head)
				{
					afterHead = afterHead->next;
					afterAfterHead = afterAfterHead->next;
				}
				afterHead->next = m_head;
				afterAfterHead->next = nullptr;
				return afterAfterHead;
			}
		}
	}
	CLLNode* RemoveAfterTarget(CLLNode* target)
	{
		if (m_head->next == m_head)
		{
			CLLNode* temp = m_head;
			m_head = nullptr;
			temp->next = nullptr;
			return temp;
		}
		else
		{
			CLLNode* afterTarget = target;
			CLLNode* afterAfterTarget = afterTarget->next;
			if (afterAfterTarget == target)
			{
				m_head->next = m_head;
				afterTarget->next = nullptr;
				return afterTarget;
			}
			else
			{
				target->next = afterAfterTarget;
				afterTarget->next = nullptr;
				return afterTarget;

			}
		}
	}
	CLLNode* RemoveBeforeTarget(CLLNode* target)
	{
		if (m_head->next == m_head)
		{
			CLLNode* temp = m_head;
			m_head = nullptr;
			temp->next = nullptr;
			return temp;
		}
		else
		{
			CLLNode* afterTarget = target;
			CLLNode* afterAfterTarget = afterTarget->next;
			if (afterAfterTarget == target)
			{
				m_head->next = m_head;
				afterTarget->next = nullptr;
				return afterTarget;
			}
			else
			{
				while (afterAfterTarget->next != target)
				{
					afterTarget = afterTarget->next;
					afterAfterTarget = afterAfterTarget->next;
				}
				afterTarget->next = target;
				afterAfterTarget->next = nullptr;
				return afterAfterTarget;

			}
		}
	}

	void Traverse()
	{
		printf("CLL content");
		CLLNode* temp = m_head;
		while (temp->next != m_head)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
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
	cll.InsertAfterHead(&node4);
	cll.InsertAfterHead(&node6);
	cll.InsertBeforeTarget(&node6, &node5);
	cll.InsertBeforeHead(&node7);
	cll.Traverse();


}