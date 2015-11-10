#pragma once

struct StackNode
{
	StackNode* prev;
	void* data;
};

class Stack
{
public:
	Stack() : m_head(nullptr), m_tail(nullptr), size(0) {}
	~Stack() {}

	void push(void* data)
	{
		StackNode* node = new StackNode();
		node->prev = nullptr;
		node->data = data;

		if (m_head == nullptr)
		{
			m_head = node;
			m_tail = node;
		}
		else
		{
			node->prev = m_tail;
			m_tail = node;
		}
		size++;
	}

	void* pop()
	{
		if (!m_tail) { return nullptr; }

		void* data = m_tail->data;
		if (m_head == m_tail)
		{
			delete m_tail;
			m_head = nullptr;
			m_tail = nullptr;
		}
		else
		{
			StackNode* temp = m_tail;
			m_tail = m_tail->prev;
			delete temp;
		}
		size--;
		return data;
	}

	void* peek()
	{
		if (!m_tail) { return nullptr; }

		void* data = m_tail->data;
		return data;
	}

	int Size()
	{
		return size;
	}

private:
	StackNode* m_head;
	StackNode* m_tail;
	int size;
};
