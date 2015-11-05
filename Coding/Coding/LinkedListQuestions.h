#pragma once

namespace LinkedListQuestions
{
	struct Node
	{
		int data;
		Node* next;
		Node* prev;
	};

	Node* head = 0;

	/* Find the nth element fromt the end of the Single Linked List */
	Node* FindNthFromEnd(int nth)
	{
		Node* current = head;
		int length = 0;
		while (current)
		{
			current = current->next;
			length++;
		}

		if (length <= nth)
		{
			current = nullptr;
		}
		else
		{
			int count = length - nth - 1;
			current = head;
			for (int i = 0; i < count; i++)
			{
				current = current->next;
			}
		}

		return current;
	}


	void DoLinkedListQuestions()
	{
		{
			Node* node1 = new Node();
			Node* node2 = new Node();
			Node* node3 = new Node();
			Node* node4 = new Node();
			Node* node5 = new Node();
			Node* node6 = new Node();
			Node* node7 = new Node();
			Node* node8 = new Node();

			node1->data = 1;
			node1->next = node2;
			node1->prev = nullptr;

			node2->data = 2;
			node2->next = node3;
			node2->prev = nullptr;

			node3->data = 3;
			node3->next = node4;
			node3->prev = nullptr;

			node4->data = 4;
			node4->next = node5;
			node4->prev = nullptr;

			node5->data = 5;
			node5->next = node6;
			node5->prev = nullptr;

			node6->data = 6;
			node6->next = node7;
			node6->prev = nullptr;

			node7->data = 7;
			node7->next = nullptr;
			node7->prev = nullptr;

			head = node1;
			Node* result = FindNthFromEnd(7);
			head = nullptr;
		}
	}
}