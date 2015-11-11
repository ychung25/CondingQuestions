#pragma once


struct QueueNode
{
	QueueNode* next;
	void* data;
};

class Queue
{
public:
	Queue() : m_head(nullptr), m_tail(nullptr), m_size(0) {}
	~Queue() {}

	void Enqueue(void* data)
	{
		QueueNode* queueNode = new QueueNode();
		queueNode->data = data;
		queueNode->next = nullptr;

		if (m_head == nullptr)
		{
			m_head = queueNode;
			m_tail = queueNode;
		}
		else
		{
			m_tail->next = queueNode;
			m_tail = queueNode;
		}
		m_size++;
	}
	void* Deqeue()
	{
		if (!m_head)
			return 0;

		void* data = m_head->data;
		QueueNode* head = m_head;

		if (m_head == m_tail)
		{
			m_head = nullptr;
			m_tail = nullptr;
		}
		else
		{
			m_head = m_head->next;
		}

		delete head;
		m_size--;

		return data;
	}
	void* Peek()
	{
		if (m_head = 0)
			return 0;
		else
			m_head->data;
	}
	bool IsEmpty()
	{
		if (m_size == 0)
			return true;
		return false;
	}
	int Size()
	{
		return m_size;
	}

private:
	QueueNode* m_head;
	QueueNode* m_tail;
	int m_size;
};
