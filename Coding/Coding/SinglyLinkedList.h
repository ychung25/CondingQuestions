#pragma once
#include <cstdio>

class SLLNode
{
public:
	SLLNode() : data(0), next(nullptr) {}
	SLLNode(int inData) : data(inData), next(nullptr) {}
	int data;
	SLLNode* next;
};

class SLL
{
public:
	SLL() : m_head(nullptr) {}
	~SLL() {}

	void InsertAtEnd(SLLNode* node) 
	{
		if (m_head == nullptr) { m_head = node; return; }

		SLLNode* temp;
		temp = m_head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = node;
	}
	void InsertAtBeginning(SLLNode* node) 
	{
		if (m_head == nullptr) { m_head = node; return; }

		node->next = m_head;
		m_head = node;
	}
	void InsertAfter(SLLNode* middleNode, SLLNode* node)
	{
		if (middleNode->next == nullptr)
		{
			middleNode->next = node;
		}
		else
		{
			SLLNode* temp = middleNode->next;
			middleNode->next = node;
			node->next = temp;
		}
	}

	void InsertBefore(SLLNode* middleNode, SLLNode* node)
	{
		if (middleNode == m_head)
		{
			InsertAtBeginning(node);
		}
		else
		{
			SLLNode* before = m_head;
			SLLNode* current = m_head->next;
			while (current->next != nullptr)
			{
				if (middleNode == current)
					break;
				before = before->next;
				current = current->next;
			}
			
			before->next = node;
			node->next = middleNode;
		}
	}

	SLLNode* RemoveAtEnd()
	{
		if (m_head == nullptr) { return nullptr; }

		SLLNode* before = m_head;
		SLLNode* current = m_head->next;

		if (current == nullptr)
		{
			before->next = nullptr;
			m_head = current;
			return before;
		}

		while (current->next != nullptr)
		{
			before = before->next;
			current = current->next;
		}

		before->next = current->next;
		current->next = nullptr;
		return current;
	}
	SLLNode* RemoveAtBeginning() 
	{
		if (m_head == nullptr) { return nullptr; }

		SLLNode* temp = m_head;
		m_head = m_head->next;
		temp->next = nullptr;
		return temp;
	}
	SLLNode* RemoveAfter(SLLNode* middleNode)
	{
		if (middleNode->next == nullptr) { return nullptr; }

		SLLNode* after = middleNode->next;
		middleNode->next = after->next;
		after->next = nullptr;
		return after;
	}
	SLLNode* RemoveBefore(SLLNode* middleNode)
	{
		if (m_head == middleNode) { return nullptr; }

		SLLNode* first = m_head;
		SLLNode* second = m_head->next;
		SLLNode* third = second->next;

		if (third == nullptr)
		{
			return RemoveAtBeginning();
		}
		else
		{
			while (third->next != nullptr)
			{
				if (third == middleNode)
					break;

				first = first->next;
				second = second->next;
				third = third->next;
			}

			first->next = third;
			second->next = nullptr;
			return second;
		}
	}

	void Traverse()
	{
		printf("SLL content");
		SLLNode* temp = m_head;
		while (temp != nullptr)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}

private:
	SLLNode* m_head;
};

void DoSinglyLinkedList()
{
	SLLNode node1(1);
	SLLNode node2(2);
	SLLNode node3(3);
	SLLNode node4(4);
	SLLNode node5(5);
	SLLNode node6(6);
	SLLNode node7(7);

	SLL sll;
	sll.InsertAtBeginning(&node2);
	sll.InsertAtBeginning(&node1);
	sll.InsertAtEnd(&node5);
	sll.InsertAfter(&node2, &node3);
	sll.InsertBefore(&node5, &node4);
	sll.InsertAtEnd(&node6);
	sll.InsertAfter(&node6, &node7);
	
	sll.RemoveAtBeginning();
	sll.RemoveAtEnd();
	sll.RemoveBefore(&node4);
	sll.RemoveAfter(&node4);

	sll.Traverse();
}