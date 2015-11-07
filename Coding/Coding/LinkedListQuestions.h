#pragma once
#include "Stack.h"

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
	by using two pointer*/
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

	Node* CreateNewReverseLinkedList(Node* head);

	/* Find the nth element from the end of the Single Linked List
	by using twp pointer*/
	Node* FindNthFromEndV5(Node* node, int nth)
	{
		Node* reversedLinkedList = CreateNewReverseLinkedList(node);
		Node* current = reversedLinkedList;
		int i = 0;
		while (current)
		{
			if (i == nth)
			{
				return current;
			}
			current = current->next;
			i++;
		}

		return current;
	}
	

	Node* CreateNewReverseLinkedList(Node* head)
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

	void CreateCyleLinkedList(Node** head)
	{
		Node* node1 = new Node();
		Node* node2 = new Node();
		Node* node3 = new Node();
		Node* node4 = new Node();
		Node* node5 = new Node();
		Node* node6 = new Node();
		Node* node7 = new Node();

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
		node7->next = node3;
		node7->prev = nullptr;

		*head = node1;
	}

	bool DetectCycle(Node* start, Node** cycleStartPoint)
	{
		bool result = false;
		Node* slow = start;
		Node* fast = start;

		while (slow && fast)
		{
			slow = slow->next;
			
			fast = fast->next;
			if (!fast)
			{
				break;
			}
			fast = fast->next;

			if (slow == fast)
			{
				result = true;
				break;
			}
		}

		if (result)
		{
			slow = start;

			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			*cycleStartPoint = slow;
		}

		return result;
	}

	void DeleteLinkedList(Node* head)
	{
		Node* current = head;

		Node* cycleStartPoint = 0;
		bool hasCycle = DetectCycle(head, &cycleStartPoint);

		while (current)
		{
			Node* next = current->next;
			delete current;
			current = next;

			if (next == cycleStartPoint)
			{
				break;
			}
		}
	}

	Node* ReverseLinkedListV1(Node* head)
	{
		Node* current = head;
		Node* temp = 0;

		while (current)
		{
			Node* next = current->next;
			current->next = temp;
			temp = current;
			current = next;

		}

		return temp;
	}

	Node* ReversLinkedListV2(Node* node, Node** newHead)
	{
		if (node)
		{
			Node* prev = ReversLinkedListV2(node->next, newHead);
			if (prev)
			{
				prev->next = node;
			}
			else
			{
				*newHead = node;
			}

			node->next = 0;
		}

		return node;
	}

	/* Two linked list meeting up at some point, find the meeting point.*/
	void FindTheMeetingPointV1(Node* headA, Node* headB, Node** meetingPoint)
	{
		Node* currentA = headA;
		Node* currentB = headB;

		int lengthA = 0;
		int lengthB = 0;

		while (currentA)
		{
			lengthA++;
			currentA = currentA->next;
		}
		while (currentB)
		{
			lengthB++;
			currentB = currentB->next;
		}

		int diff = lengthA - lengthB;
		if (diff < 0)
		{
			diff *= -1;
		}

		currentA = headA;
		currentB = headB;
		if (lengthA > lengthB)
		{
			for (int i = 0; i < diff; i++)
			{
				currentA = currentA->next;
			}
		}
		else
		{
			for (int i = 0; i < diff; i++)
			{
				currentB = currentB->next;
			}
		}

		while (currentA != currentB)
		{
			currentA = currentA->next;
			currentB = currentB->next;
		}

		*meetingPoint =  currentA;
	}

	/* Two linked list meeting up at some point, find the meeting point.*/
	void FindTheMeetingPointV2(Node* headA, Node* headB, Node** meetingPoint)
	{
		Node* currentA = headA;
		Node* currentB = headB;
		Stack stackA;
		Stack stackB;

		while (currentA)
		{
			stackA.push(currentA);
			currentA = currentA->next;
		}

		while (currentB)
		{
			stackB.push(currentB);
			currentB = currentB->next;
		}

		Node* prev = 0;
		currentA = (Node*)stackA.pop();
		currentB = (Node*)stackB.pop();
		while (currentA == currentB)
		{
			prev = currentA;
			currentA = (Node*)stackA.pop();
			currentB = (Node*)stackB.pop();
		}

		*meetingPoint = prev;
	}

	Node* FindMiddleNodeV1(Node* node)
	{
		Node* current = node;
		int length = 0;
		
		while (current)
		{
			length++;
			current = current->next;
		}

		int mid = 0;
		if (length % 2)
		{
			mid = length / 2;
		}
		else
		{
			return nullptr;
		}

		int i = 0;

		current = node;
		while (i < mid)
		{
			current = current->next;
			i++;
		}

		return current;
	}

	Node* FindMiddleNodeV2(Node* node)
	{
		Node* slow = node;
		Node* fast = node;

		while (fast)
		{
			Node* next = fast->next;
			if (!next) { break; }

			fast = next->next;
			slow = slow->next;
		}

		if (fast)
		{
			return slow;
		}
		else
		{
			return nullptr;
		}

	}

	bool IsLinkedListLengthEven(Node* node)
	{
		Node* current = node;
		while (current)
		{
			Node* next = current->next;
			if (!next)
				break;
			current = next->next;
		}
		if (current)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	void MergeTwoSortedLinkedList(Node* h1, Node* h2, Node** newHead)
	{
		Node* newNode = 0;
		while (h1 && h2)
		{
			Node* temp = 0;
			if (h1->data <= h2->data)
			{
				temp = h1;
				h1 = h1->next;
			}
			else
			{
				temp = h2;
				h2 = h2->next;
			}

			if (!newNode)
			{
				*newHead = temp;
			}
			else
			{
				newNode->next = temp;
			}
			newNode = temp;


			Node* tail = h1;
			if (h2)
				tail = h2;

			if (!newNode)
			{
				newNode = tail;
				*newHead = newNode;
			}
			else
			{
				newNode->next = tail;
			}
		}
	}

	void TraverseLinkedList(Node* node)
	{
		while (node)
		{
			printf("%d , ", node->data);
			node = node->next;
		}
	}








	void DoLinkedListQuestions()
	{
		{
			Node* head = 0;
			CreateSampleLinkedList(&head);

			int nth = 3;
			Node* current = head;

			Node* result = FindNthFromEndV1(current, nth);

			int nthTemp = nth;
			result = FindNthFromEndV2(current, &nthTemp);

			result = FindNthFromEndV3(current, nth);

			result = FindNthFromEndV4(current, nth);

			result = FindNthFromEndV5(current, nth);

			DeleteLinkedList(head);
		}

		{
			Node* head = 0;
			CreateSampleLinkedList(&head);

			Node* current = head;

			Node* reversedLinkedList = ReverseLinkedListV1(current);
			TraverseLinkedList(reversedLinkedList);

			Node* newReversedHead;
			ReversLinkedListV2(reversedLinkedList, &newReversedHead);
			TraverseLinkedList(newReversedHead);

			DeleteLinkedList(newReversedHead);
		}

		{
			Node* head = 0;
			CreateSampleLinkedList(&head);

			Node* current = head;

			Node* cycleStartPoint;
			CreateCyleLinkedList(&current);
			bool hasCycle = DetectCycle(current, &cycleStartPoint);
			DeleteLinkedList(current);
		}

		{
			Node* firstHead = 0;
			CreateSampleLinkedList(&firstHead);

			Node* secondHead = 0;
			CreateSampleLinkedList(&secondHead);

			Node* firstLinkedList = firstHead;
			Node* secondLinkedList = secondHead;

			for (int i = 0; i < 3; i++)
			{
				firstLinkedList = firstLinkedList->next;
			}

			while (secondLinkedList->next)
			{
				secondLinkedList = secondLinkedList->next;
			}

			secondLinkedList->next = firstLinkedList;

			Node* meetingPoint = 0;
			FindTheMeetingPointV1(firstHead, secondHead, &meetingPoint);

			meetingPoint = 0;
			FindTheMeetingPointV2(firstHead, secondHead, &meetingPoint);
		}

		{
			Node* firstHead = 0;
			CreateSampleLinkedList(&firstHead);

			Node* current = firstHead;
			Node* midNode = FindMiddleNodeV1(current);

			midNode = 0;
			midNode = FindMiddleNodeV2(current);
			
			DeleteLinkedList(firstHead);
		}

		{
			Node* firstHead = 0;
			CreateSampleLinkedList(&firstHead);


			bool isEven = IsLinkedListLengthEven(firstHead);
		}

		{
			Node* nodeA1 = new Node();
			Node* nodeA2 = new Node();
			Node* nodeA3 = new Node();
			nodeA1->data = 10;
			nodeA2->data = 20;
			nodeA3->data = 30;
			nodeA1->next = nodeA2;
			nodeA2->next = nodeA3;
			nodeA3->next = 0;

			Node* nodeB1 = new Node();
			Node* nodeB2 = new Node();
			nodeB1->data = 5;
			nodeB2->data = 23;
			nodeB1->next = nodeB2;
			nodeB2->next = 0;
			
			Node* mergedList = 0;
			MergeTwoSortedLinkedList(nodeA1, nodeB1, &mergedList);
		}
	}
}