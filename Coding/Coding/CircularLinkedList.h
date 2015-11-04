#pragma once
#include <cstdio>

class CLLNode
{
public:
	CLLNode() : next(nullptr) { }
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
	void InsertAfterTarget(CLLNode* target, CLLNode* node) 
	{
		if (target->next == target)
		{
			m_head->next = node;
			node->next = m_head;
		}
		else
		{

		}
	}
	void InsertBeforeTarget(CLLNode* target, CLLNode* node) {}

	CLLNode* RemoveAfterHead();
	CLLNode* RemoveBeforeHead();
	CLLNode* RemoveAfterTarget(CLLNode* target);
	CLLNode* RemoveBeforeTarget(CLLNode* target);

	bool IsCircular() {}

private:
	CLLNode* m_head;
};