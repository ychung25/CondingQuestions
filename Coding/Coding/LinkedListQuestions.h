#pragma once
#include "Stack.h"
#include "HashTable.h"

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
			hashTable.insert(i, current);
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

	void MergeTwoSortedLinkedListV1(Node* h1, Node* h2, Node** newHead)
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

	void MergeTwoSortedLinkedListV2(Node* h1, Node* h2, Node* newNode, Node** newHead)
	{
		if (!h1)
		{
			if (!newNode)
			{
				*newHead = h2;
			}
			else
			{
				newNode->next = h2;
			}
			return;
		}

		if (!h2)
		{
			if (!newNode)
			{
				*newHead = h1;
			}
			else
			{
				newNode->next = h1;
			}
			return;
		}

		if (h1->data <= h2->data)
		{
			if (!newNode)
			{
				*newHead = h1;
			}
			else
			{
				newNode->next = h1;
			}
			newNode = h1;
			h1 = h1->next;
		}
		else
		{
			if (!newNode)
			{
				*newHead = h2;
			}
			else
			{
				newNode->next = h2;
			}
			newNode = h2;
			h2 = h2->next;
		}

		MergeTwoSortedLinkedListV2(h1, h2, newNode, newHead);
	}

	Node* MergeTwoSortedLinkedListV3(Node* h1, Node* h2)
	{
		if (!h1)
		{
			return h2;
		}
		if (!h2)
		{
			return h1;
		}

		if (h1->data <= h2->data)
		{
			h1->next = MergeTwoSortedLinkedListV3(h1->next, h2);
			return h1;
		}
		else 
		{
			h2->next = MergeTwoSortedLinkedListV3(h1, h2->next);
			return h2;
		}
	}

	void ReverseInPairV1(Node* node, Node** newHead)
	{
		Node* current = node;
		Node* temp = 0;
		Stack stack;
		while (current)
		{
			stack.push(current);
			current = current->next;

			if (!current)
			{
				if (temp)
				{
					temp->next = (Node*)stack.pop();
				}
				else
				{
					*newHead = (Node*)stack.pop();
				}
				return;
			}
			stack.push(current);

			if (current)
			{
				current = current->next;
			}

			Node* a = (Node*)stack.pop();
			Node* b = (Node*)stack.pop();

			a->next = b;
			if(temp)
			{
				temp->next = a;
			}
			else
			{
				*newHead = a;
			}
			temp = b;
			temp->next = 0;
		}
	}

	Node* ReverseInPairV2(Node* node)
	{
		if (!node) { return node; }
		Node* current = node;
		Node* next = current->next;
		if (!next) { return node; }
		Node* nextNext = next->next;

		next->next = current;
		current->next = ReverseInPairV2(nextNext);
		return next;
	}

	void GetTwoCyclesFromOneCycleV1(Node* node, Node** Cycle1, Node** Cycle2)
	{
		if (!node)
		{
			*Cycle1 = 0;
			*Cycle2 = 0;
			return;
		}

		Node* beforeSlow = node;
		Node* slow = node->next;
		if (slow == node)
		{
			*Cycle1 = node;
			*Cycle2 = 0;
			return;
		}

		Node* fast = node->next->next;
		Node* beforeFast = node->next;

		while (fast != node && fast->next != node)
		{
			slow = slow->next;
			beforeSlow = beforeSlow->next;

			fast = fast->next->next;
			beforeFast = beforeFast->next->next;
		}

		if (fast == node)
		{
			*Cycle1 = fast;
			*Cycle2 = slow;
			beforeFast->next = *Cycle2;
			beforeSlow->next = *Cycle1;
		}
		else
		{
			*Cycle1 = fast->next;
			*Cycle2 = slow->next;
			fast->next = *Cycle2;
			slow->next = *Cycle1;
		}
	}

	void GetTwoCyclesFromOneCycleV2(Node* head, Node** C1, Node** C2)
	{
		if (!head) { *C1 = 0; *C2 = 0; return; }
		Node* current = head->next;
		if (head == current)
		{
			*C1 = head;
			*C2 = 0;
			return;
		}
		int length = 1;
		Node* beforeHead = 0;
		while (current != head)
		{
			beforeHead = current;
			current = current->next;
			length++;
		}

		Node* mid = head;
		for (int i = 0; i < (length / 2); i++)
		{
			mid = mid->next;
		}

		Node* midNext = mid->next;
		
		mid->next = head;
		beforeHead->next = midNext;

		*C1 = head;
		*C2 = midNext;
	}

	bool IsItPalindrome(Node* head)
	{
		if (!head) { return true; }
		Node* current = head;
		int length = 0;
		while (current)
		{
			length++;
			current = current->next;
		}

		current = head;
		for (int i = 0; i < (length / 2); i++)
		{
			current = current->next;
		}

		Node* prev = current;
		current = current->next;

		while (current)
		{
			Node* temp = current->next;
			current->next = prev;
			prev = current;
			current = temp;
		}
		
		for (int i = 0; i < length / 2; i++)
		{
			if (head->data != prev->data)
			{
				return false;
			}
			head = head->next;
			prev = prev->next;
		}

		return true;
	}

	Node* ReverseKGroupV1(Node* h, int k)
	{
		if (!h || k <= 1) { return h; }

		int len = k;
		Node* c = h;
		while (c && len > 0)
		{
			len--;
			c = c->next;
		}
		if (len)
			return h;

		c = h;
		Node* pc = 0;
		Node* ac = 0;

		for (int i = 0; i < k; i++)
		{
			ac = c->next;
			c->next = pc;
			pc = c;
			c = ac;
			if (!c)
				break;
		}

		h->next = ReverseKGroupV1(c, k);
		return pc;
	}

	void ReverseKGroupV2(Node* h, int k, Node** newHead)
	{
		if (!h || k <= 0) { *newHead = 0; return; }
		Node* c = h;
		int len = 0;
		while (c)
		{
			len++;
			c = c->next;
		}
		
		c = h;
		Node* ac = 0;
		Node* pc = 0;
		Node* x = 0;
		for (int i = 0; i < (len / k); i++)
		{
			Node* temp = c;
			for (int j = 0; j < k; j++)
			{
				ac = c->next;
				c->next = pc;
				pc = c;
				c = ac;
			}
			if (x)
				x->next = pc;
			if (i == 0)
				*newHead = pc;
			x = temp;
		}

		if (x)
			x->next = c;
		else
			*newHead = h;;
	}

	Node* JosephusCircle(Node* h, int m)
	{
		if (!h || (h == h->next)) { return h; }

		Node* c = h;
		while (1)
		{
			Node* p = 0;
			for (int i = 0; i < m; i++)
			{
				p = c;
				c = c->next;
				if (p == c)
					return c;
			}
			p->next = c->next;
			c->next = 0;
			c = p->next;
		}
	}

	/* Assume that Node has 
	       - 'next' pointer which points to next
		   - 'prev' pointer which points to random node
    */
	void CloneListWithRandomPointerV1(Node* head, Node** newHead)
	{
		HashTable::HashTable hash;
		Node* current = head;
		*newHead = 0;

		while (current)
		{
			Node* copy = new Node();
			if (*newHead == 0)
				*newHead = copy;
			copy->data = current->data;
			copy->next = 0;
			copy->prev = 0;
			hash.insert((unsigned long long)current, copy);
			current = current->next;
		}

		current = head;
		while (current)
		{
			Node* next = (Node*)hash.get((unsigned long long)current->next);
			Node* prev = (Node*)hash.get((unsigned long long)current->prev);
			Node* copy = (Node*)hash.get((unsigned long long)current);

			copy->next = next;
			copy->prev = prev;
			current = current->next;
		}
	}


	/* Assume that Node has
	- 'next' pointer which points to next
	- 'prev' pointer which points to random node
	  This one has O(c) space complexity :-)
	*/
	void CloneListWithRandomPointerV2(Node* head, Node** newHead)
	{
		*newHead = 0;
		if (!head) { return; }

		Node* before = head;
		Node* current = head->next;
		while (before)
		{
			Node* copy = new Node();
			if (!(*newHead))
				*newHead = copy;
			copy->data = before->data;
			before->next = copy;
			copy->next = current;

			before = current;
			if (current)
				current = current->next;
		}

		current = head;
		while (current)
		{
			Node* copy = current->next;
			copy->prev = current->prev->next;
			current = current->next->next;
		}

		before = head;
		current = head->next;
		while (before)
		{
			Node* beforeNext = before->next->next;
			Node* currentNext = 0;
			if (beforeNext)
				currentNext = current->next->next;

			before->next = beforeNext;
			current->next = currentNext;

			before = beforeNext;
			current = currentNext;
		}

	}

	void EvenBeforeOdd(Node* head, Node** newHead)
	{
		*newHead = 0;
		if (!head) { return; }
		
		Node* odd = 0;
		Node* oddHead = 0;
		Node* even = 0;
		Node* evenHead = 0;
		Node* current = head;

		while (current)
		{
			if ((current->data % 2) == 0)
			{
				if (!even)
				{
					even = current;
					evenHead = current;
				}
				else
				{
					even->next = current;
					even = current;
				}
			}
			else
			{
				if (!odd)
				{
					odd = current;
					oddHead = current;
				}
				else
				{
					odd->next = current;
					odd = current;
				}
			}
			
			current = current->next;
		}

		if (odd)
			odd->next = 0;
		if (even)
			even->next = oddHead;

		*newHead = evenHead;
	}

	/* find the last p % k == 0 node 
	   p = current position of elements (assume the first element is p = 1)
	   k = any int > 0 */
	void FindModularNode(Node* head, int k, Node** node)
	{
		*node = 0;
		if (!head || k < 1) { return; }

		int len = 0;
		Node* current = head;
		while (current)
		{
			len++;
			if (len % k == 0)
				*node = current;
			current = current->next;
		}
	}

	/* find n / k  node
	n = # of elements
	k = any int > 0 */
	void FindFractionNode(Node* head, int k, Node** node)
	{
		*node = 0;
		if (!head || k < 1) { return; }

		int len = 0;
		Node* current = head;
		Node* fractionNode = 0;
		
		while (current)
		{
			len++;
			if (((len - 1) / k) < (len / k))
			{
				if (!fractionNode)
				{
					fractionNode = head;
				}
				else
				{
					fractionNode = fractionNode->next;
				}

			}

			current = current->next;
		}

		*node = fractionNode;
	}

	void FindFractionNodeV2(Node* head, int k, Node** node)
	{
		*node = 0;
		if (!head || k < 1) { return; }

		Node* current = head;
		Node* fractionNode = 0;
		int i = 0;
		while (current)
		{
			i++;
			if ((i % k) == 0)
			{
				if (!fractionNode)
					fractionNode = head;
				else
					fractionNode = fractionNode->next;
			}

			current = current->next;
		}

		*node = fractionNode;
	}

	/* find n^(1/2) node
	n = # of elements */
	void FindRootOfNode(Node* head, Node** node)
	{
		*node = 0;
		if (!head) { return; }

		Node* current = head;
		Node* hereNode = 0;
		int len = 0;
		int here = 1;
		while (current)
		{
			len++;
			if (here * here < len)
			{
				here++;
				if (!hereNode)
				{
					hereNode = head;
				}
				else
				{
					hereNode = hereNode->next;
				}

			}
			current = current->next;
		}

		*node = hereNode;
	}

	void FindRootOfNodeV2(Node* head, Node** node)
	{
		*node = 0;
		if (!head) { return; }

		Node* current = head;
		Node* rootOfNode = 0;

		int i = 0;
		int j = 1;
		while (current)
		{
			i++;
			if (j*j == i)
			{
				j++;
				if (!rootOfNode)
					rootOfNode = head;
				else
					rootOfNode = rootOfNode->next;
			}
			current = current->next;
		}

		*node = rootOfNode;
	}

	/* Merge L1 and L1 so that is becomes
	a1, b1, a2, b2, a3, a4 ...  if length of a > b
	a1, b1, a2, b2, b3, b4 ... if lenth of a < b*/
	void MergeWithRule(Node* h1, Node* h2, Node** newHead)
	{
		*newHead = 0;
		if (!h1 && !h2) { return; }
		if (!h1) { *newHead = h2; return; }
		if (!h2) { *newHead = h1; return; }

		Node* a = h1;
		Node* b = h2;
		while (a && b)
		{
			Node* aNext = a->next;
			Node* bNext = b->next;
			
			a->next = b;
			if (aNext)
				b->next = aNext;

			a = aNext;
			b = bNext;
		}

		*newHead = h1;
	}

	/* this is the special version of nth/k fraction node.*/
	float FindMedianInSortedLinkedList(Node* head)
	{ 
		if (!head) { return -1; } // error
		if (!head->next) { return head->data; }

		Node* current = head;
		Node* median = 0;
		int i = 0;
		while (current)
		{
			i++;
			if ((i % 2) == 0)
			{
				if (!median)
					median = head;
				else
					median = median->next;
			}

			current = current->next;
		}

		if (i % 2 == 0)
		{
			return (((median->data + median->next->data) / (float)2));
		}
		else
		{
			median = median->next;
			return median->data;
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
			//MergeTwoSortedLinkedListV1(nodeA1, nodeB1, &mergedList);
			//MergeTwoSortedLinkedListV2(nodeA1, nodeB1, 0, &mergedList);
			Node* temp = MergeTwoSortedLinkedListV3(nodeA1, nodeB1);
		}

		{

			Node* nodeA1 = new Node();
			Node* nodeA2 = new Node();
			Node* nodeA3 = new Node();
			Node* nodeA4 = new Node();
			Node* nodeA5 = new Node();
			nodeA1->data = 1;
			nodeA2->data = 2;
			nodeA3->data = 3;
			nodeA4->data = 4;
			nodeA5->data = 5;
			nodeA1->next = nodeA2;
			nodeA2->next = nodeA3;
			nodeA3->next = nodeA4;
			nodeA4->next = nodeA5;
			nodeA5->next = 0;

			Node* mergedList = 0;
			//ReverseInPairV1(nodeA1, &mergedList);
			mergedList = ReverseInPairV2(nodeA1);
		}

		{
			Node* nodeA1 = new Node();
			Node* nodeA2 = new Node();
			Node* nodeA3 = new Node();
			Node* nodeA4 = new Node();
			Node* nodeA5 = new Node();
			nodeA1->data = 1;
			nodeA2->data = 2;
			nodeA3->data = 3;
			nodeA4->data = 4;
			nodeA5->data = 5;
			nodeA1->next = nodeA2;
			nodeA2->next = nodeA3;
			nodeA3->next = nodeA4;
			nodeA4->next = nodeA5;
			nodeA5->next = nodeA1;

			Node* Cycle1 = 0;
			Node* Cycle2 = 0;
			GetTwoCyclesFromOneCycleV1(nodeA1, &Cycle1, &Cycle2);
			//GetTwoCyclesFromOneCycleV2(nodeA1, &Cycle1, &Cycle2);
		}

		{
			Node* nodeA1 = new Node();
			Node* nodeA2 = new Node();
			Node* nodeA3 = new Node();
			Node* nodeA4 = new Node();
			Node* nodeA5 = new Node();
			nodeA1->data = 1;
			nodeA2->data = 2;
			nodeA3->data = 3;
			nodeA4->data = 2;
			nodeA5->data = 1;
			nodeA1->next = nodeA2;
			nodeA2->next = nodeA3;
			nodeA3->next = nodeA4;
			nodeA4->next = nodeA5;
			nodeA5->next = 0;

			bool result = IsItPalindrome(nodeA1);
		}

		{
			Node* nodeA1 = new Node();
			Node* nodeA2 = new Node();
			Node* nodeA3 = new Node();
			Node* nodeA4 = new Node();
			Node* nodeA5 = new Node();
			nodeA1->data = 1;
			nodeA2->data = 2;
			nodeA3->data = 3;
			nodeA4->data = 4;
			nodeA5->data = 5;
			nodeA1->next = nodeA2;
			nodeA2->next = nodeA3;
			nodeA3->next = nodeA4;
			nodeA4->next = nodeA5;
			nodeA5->next = 0;

			//Node* reversedGroup = ReverseKGroupV1(nodeA1, 5);
			Node* reversedGroup = 0;
			ReverseKGroupV2(nodeA1, 3, &reversedGroup);
			int i = 9;
			i++;
		}

		{
			Node* nodeA1 = new Node();
			Node* nodeA2 = new Node();
			Node* nodeA3 = new Node();
			Node* nodeA4 = new Node();
			Node* nodeA5 = new Node();
			nodeA1->data = 1;
			nodeA2->data = 2;
			nodeA3->data = 3;
			nodeA4->data = 4;
			nodeA5->data = 5;
			nodeA1->next = nodeA2;
			nodeA2->next = nodeA3;
			nodeA3->next = nodeA4;
			nodeA4->next = nodeA5;
			nodeA5->next = nodeA1;

			Node* lastRemainingNode = 0;
			lastRemainingNode = JosephusCircle(nodeA1, 3);
		}

		{
			Node* nodeA1 = new Node();
			Node* nodeA2 = new Node();
			Node* nodeA3 = new Node();
			Node* nodeA4 = new Node();
			Node* nodeA5 = new Node();
			nodeA1->data = 1;
			nodeA2->data = 2;
			nodeA3->data = 3;
			nodeA4->data = 4;
			nodeA5->data = 5;
			nodeA1->next = nodeA2;
			nodeA2->next = nodeA3;
			nodeA3->next = nodeA4;
			nodeA4->next = nodeA5;
			nodeA5->next = 0;

			nodeA1->prev = nodeA3;
			nodeA2->prev = nodeA1;
			nodeA3->prev = nodeA2;
			nodeA4->prev = nodeA5;
			nodeA5->prev = nodeA3;

			Node* newHead = 0;
			//CloneListWithRandomPointerV1(nodeA1, &newHead);
			CloneListWithRandomPointerV2(nodeA1, &newHead);
		}

		{
			Node* nodeA1 = new Node();
			Node* nodeA2 = new Node();
			Node* nodeA3 = new Node();
			Node* nodeA4 = new Node();
			Node* nodeA5 = new Node();
			nodeA1->data = 1;
			nodeA2->data = 2;
			nodeA3->data = 3;
			nodeA4->data = 4;
			nodeA5->data = 5;
			nodeA1->next = nodeA2;
			nodeA2->next = nodeA3;
			nodeA3->next = nodeA4;
			nodeA4->next = nodeA5;
			nodeA5->next = 0;

			Node* newHead = 0;
			EvenBeforeOdd(nodeA1, &newHead);
		}

		{
			Node* nodeA1 = new Node();
			Node* nodeA2 = new Node();
			Node* nodeA3 = new Node();
			Node* nodeA4 = new Node();
			Node* nodeA5 = new Node();
			Node* nodeA6 = new Node();
			Node* nodeA7 = new Node();
			nodeA1->data = 1;
			nodeA2->data = 2;
			nodeA3->data = 3;
			nodeA4->data = 4;
			nodeA5->data = 5;
			nodeA6->data = 6;
			nodeA7->data = 7;
			nodeA1->next = nodeA2;
			nodeA2->next = nodeA3;
			nodeA3->next = nodeA4;
			nodeA4->next = nodeA5;
			nodeA5->next = nodeA6;
			nodeA6->next = nodeA7;
			nodeA7->next = 0;

			Node* newHead = 0;
			FindModularNode(nodeA1, 2, &newHead);

			FindFractionNode(nodeA1, 3, &newHead);

			FindFractionNodeV2(nodeA1, 3, &newHead);

			FindRootOfNodeV2(nodeA1, &newHead);

			FindRootOfNode(nodeA1, &newHead);
		}

		{
			Node* nodeA1 = new Node();
			Node* nodeA2 = new Node();
			nodeA1->data = 1;
			nodeA2->data = 2;
			nodeA1->next = nodeA2;
			nodeA2->next = 0;

			Node* nodeB1 = new Node();
			Node* nodeB2 = new Node();
			Node* nodeB3 = new Node();
			Node* nodeB4 = new Node();
			nodeB1->data = 10;
			nodeB2->data = 20;
			nodeB3->data = 30;
			nodeB4->data = 40;
			nodeB1->next = nodeB2;
			nodeB2->next = nodeB3;
			nodeB3->next = nodeB4;
			nodeB4->next = 0;

			Node* newHead = 0;
			MergeWithRule(nodeA1, nodeB1, &newHead);
		}

		{
			Node* nodeA1 = new Node();
			Node* nodeA2 = new Node();
			Node* nodeA3 = new Node();
			Node* nodeA4 = new Node();
			Node* nodeA5 = new Node();
			nodeA1->data = 1;
			nodeA2->data = 2;
			nodeA3->data = 3;
			nodeA4->data = 4;
			nodeA5->data = 5;
			nodeA1->next = nodeA2;
			nodeA2->next = nodeA3;
			nodeA3->next = nodeA4;
			nodeA4->next = nodeA5;
			nodeA5->next = 0;


			float median = FindMedianInSortedLinkedList(nodeA1);
		}

	}
}