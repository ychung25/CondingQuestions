#pragma once

namespace LinkedListQuestions
{
	struct Node
	{
		int data;
		Node* next;
		Node* prev;
	};

	/* Find the nth element from the end of the Single Linked List
	   by traversing the list once to find the length use that information to
	   traverse again and find the nth from the end*/
	Node* FindNthFromEndV1(Node* head, int nth)
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

	/* Find the nth element from the end of the Single Linked List
	by recursively backing out nth time from the end of the list*/
	Node* FindNthFromEndV2(Node* node, int* nth)
	{
		if (!node)
			return 0;
		
		Node* returnedNode = FindNthFromEndV2(node->next, nth);
		if (*nth == 0)
		{
			*nth = *nth - 1;
			return node;
		}

		*nth = *nth - 1;
		return returnedNode;
	}

	/* Find the nth element from the end of the Single Linked List
	by using a hash table*/
	Node* FindNthFromEndV3(Node* node, int nth)
	{
		HashTable::HashTable hashTable;

		int i = 0;
		Node* current = node;
		while (current)
		{
			hashTable.Insert(i, current);
			current = current->next;
			i++;
		}

		int toFind = i - 1 - nth;
		return (Node*)hashTable.get(toFind);
	}

	/* Find the nth element from the end of the Single Linked List
	by using twp pointer*/
	Node* FindNthFromEndV4(Node* node, int nth)
	{
		Node* current = node;
		Node* following = 0;
		int i = 0;

		while (current)
		{
			if (i == nth)
			{
				following = node;
			}
			else
			{
				if (following)
					following = following->next;
			}

			current = current->next;

			i++;
		}

		return following;
	}
	

	Node* ReverseLinkedList(Node* head)
	{
		if (!head) { return 0; }
		Node* current = head;
		Node* next = head->next;
		
		if (!next) { return 0; }

		Node* temp = 0;
		while (next)
		{
			Node* a = 0;
			Node* b = 0;

			a = temp;
			if (!a)
			{
				a = new Node();
				a->next = 0;
				a->prev = 0;
			}

			b = new Node();
			b->next = 0;
			b->prev = 0;

			a->data = current->data;
			b->data = next->data;

			b->next = a;
			temp = b;

			current = current->next;
			next = next->next;
		}

		return temp;
	}


	void CreateSampleLinkedList(Node** head)
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

		*head = node1;
	}

	void DeleteSampleLinkedList(Node* head)
	{

	}

	void DoLinkedListQuestions()
	{
		{
			Node* head = 0;
			CreateSampleLinkedList(&head);

			Node* reversedLL =  ReverseLinkedList(head);

			int nth = 3;

			Node* current = head;
			Node* result = FindNthFromEndV1(current, nth);

			int nthTemp = nth;
			result = FindNthFromEndV2(current, &nthTemp);

			result = FindNthFromEndV3(current, nth);

			result = FindNthFromEndV4(current, nth);


			int stop = 10;

		}
	}
}