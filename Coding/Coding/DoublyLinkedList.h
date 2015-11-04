#pragma once
#include <cstdio>

class DLLNode
{
public:
	DLLNode(int inData) :data(inData), next(nullptr), prev(nullptr) {}

	int data;
	DLLNode* next;
	DLLNode* prev;
};

class DLL
{
public:
	DLL() : m_head(nullptr), m_tail(nullptr){}

	void InsertAtBeginning(DLLNode* node)
	{
		if (m_head == nullptr)
		{
			m_head = node;
			m_tail = node;
		}
		else
		{
			node->next = m_head;
			m_head->prev = node;
			m_head = node;
		}
	}
	void InsertAtEnd(DLLNode* node)
	{
		if (m_head == nullptr)
		{
			m_head = node;
			m_tail = node;
		}
		else
		{
			m_tail->next = node;
			node->prev = m_tail;
			m_tail = node;
		}
	}
	void InsertBefore(DLLNode* target, DLLNode* node)
	{
		if (m_head == target)
		{
			InsertAtBeginning(node);
		}
		else
		{
			DLLNode* beforeTarget = target->prev;
			beforeTarget->next = node;
			node->prev = beforeTarget;
			target->prev = node;
			node->next = target;
		}
	}
	void InsertAfter(DLLNode* target, DLLNode* node)
	{
		if (m_tail == target)
		{
			InsertAtEnd(node);
		}
		else
		{
			if (target->next == nullptr)
			{
				target->next = node;
				node->prev = target;
				m_tail = node;
			}
			else
			{
				DLLNode* afterTarget = target->next;
				target->next = node;
				node->prev = target;
				afterTarget->prev = node;
				node->next = afterTarget;
			}
		}
	}

	DLLNode* RemoveAtBeginning() 
	{
		if (m_head == nullptr) { return nullptr; }
		
		if (m_head->next == nullptr)
		{
			DLLNode* temp = m_head;
			m_head = nullptr;
			m_tail = nullptr;
			return temp;
		}
		else
		{
			DLLNode* afterBeginning = m_head->next;
			afterBeginning->prev = nullptr;
			m_head->next = nullptr;
			
			DLLNode* temp = m_head;
			m_head = afterBeginning;
			return temp;
		}
	}
	DLLNode* RemoveAtEnd() 
	{
		if (m_tail == nullptr) { return nullptr; }

		if (m_tail->prev == nullptr)
		{
			DLLNode* temp = m_tail;
			m_head = nullptr;
			m_tail = nullptr;
			return temp;
		}
		else
		{
			DLLNode* beforeEnd = m_tail->prev;
			beforeEnd->next = nullptr;
			m_tail->prev = nullptr;

			DLLNode* toReturn = m_tail;
			m_tail = beforeEnd;
			return toReturn;
		}
	}
	DLLNode* RemoveBefore(DLLNode* target) 
	{
		if (target->prev == nullptr)
		{
			return RemoveAtBeginning();
		}
		else
		{
			DLLNode* targetBefore = target->prev;
			DLLNode* targetBeforeBefore = targetBefore->prev;

			if (targetBeforeBefore == nullptr)
			{
				return RemoveAtBeginning();
			}
			else
			{
				targetBeforeBefore->next = target;
				target->prev = targetBeforeBefore;
				targetBefore->prev = nullptr;
				targetBefore->next = nullptr;
				return targetBefore;
			}
		}
	}

	DLLNode* RemoveAfter(DLLNode* target) 
	{
		if (target->next == nullptr)
		{
			return RemoveAtEnd();
		}
		else
		{
			DLLNode* nextTarget = target->next;
			if (nextTarget->next == nullptr)
			{
				nextTarget->prev = nullptr;
				target->next = nullptr;
				m_tail = target;
				return nextTarget;
			}
			else
			{
				DLLNode* nextnextTarget = nextTarget->next;
				target->next = nextnextTarget;
				nextnextTarget->prev = target;
				nextTarget->next = nullptr;
				nextTarget->prev = nullptr;
				return nextTarget;
			}
		}
	}

	void Traverse()
	{
		printf("DLL content");
		DLLNode* temp = m_head;
		while (temp != nullptr)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}

private:
	DLLNode* m_head;
	DLLNode* m_tail;
};


void DoDoublyLinkedList()
{
	DLLNode node1(1);
	DLLNode node2(2);
	DLLNode node3(3);
	DLLNode node4(4);
	DLLNode node5(5);
	DLLNode node6(6);
	DLLNode node7(7);

	DLL dll;
	dll.InsertAtBeginning(&node3);
	dll.InsertAtBeginning(&node2);
	dll.InsertBefore(&node2, &node1);
	dll.InsertAfter(&node3, &node4);
	dll.InsertAtEnd(&node5);
	dll.InsertAtEnd(&node6);
	dll.InsertAtEnd(&node7);

	dll.RemoveAtBeginning();
	dll.RemoveAtEnd();
	dll.RemoveBefore(&node6);
	dll.RemoveAfter(&node2);

	dll.Traverse();
}