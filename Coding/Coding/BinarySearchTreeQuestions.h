#pragma once
#include "Stack.h"
#include "Queue.h"
#include "HashTable.h"

namespace BinarySearchTreeQuestions
{
	struct Node
	{
		int data;
		Node* l;
		Node* r;
	};

	Node* createNode(int data, Node* l, Node* r)
	{
		Node* n = new Node();
		n->data = data;
		n->l = l;
		n->r = r;
		return n;
	}

	int abs(int x)
	{
		if (x < 0)
			return x*-1;
		return x;
	}

	bool FindRecursive(Node* n, int key)
	{
		if (!n)
			return false;

		if (n->data == key)
			return true;

		if (key < n->data)
			FindRecursive(n->l, key);
		else
			FindRecursive(n->r, key);
	}

	bool FindIterative(Node* n, int key)
	{
		while (n)
		{
			if (n->data == key)
				return true;
			if (key < n->data)
				n = n->l;
			else
				n = n->r;
				
		}
	}

	void InsertNode(Node* n, int key)
	{
		Node* p = 0;
		while (n)
		{
			p = n;
			if (key < n->data)
				n = n->l;
			else
				n = n->r;
		}
		
		Node* toInsert = createNode(key, 0, 0);
		if (key < p->data)
			p->l = toInsert;
		else
			p->r = toInsert;
	}

	int FindMax(Node* n)
	{
		int max = 0;
		while (n)
		{
			max = n->data;
			n = n->r;
		}
		return max;
	}

	void DeleteNode(Node* n, int key)
	{
		Node* p = 0;
		while (n)
		{
			if (n->data == key)
			{
				if (n->l && n->r)
				{ 
					int max = FindMax(n->l);
					DeleteNode(n, max);
					n->data = max;
					return;
				}
				else
				{
					Node* temp = 0;
					if (n->l)
						temp = n->l;
					else
						temp = n->r;

					if (p->l == n)
						p->l = temp;
					else
						p->r = temp;
					delete n;
					return;
				}
			}

			p = n;
			if (key < n->data)
				n = n->l;
			else
				n = n->r;
		}
	}

	int findLCD(Node* k, int a, int b)
	{
		if ((a < k->data && k->data < b) ||
			(b < k->data && k->data < a))
		{
			return k->data;
		}

		if (a < k->data)
			findLCD(k->l, a, b);
		else
			findLCD(k->r, a, b);
	}

	// Do inorder and if prev > current, it is not BST
	bool isBST(Node* n, int p)
	{
		if (!n)
			return true;

		bool bLeft = isBST(n->l, n->data);

		if (p > n->data)
			return false;
		p = n->data;

		bool bRight = isBST(n->r, n->data);

		return bLeft && bRight;
	}

	Node* BST2DLL(Node* n)
	{
		if (!n)
			return 0;

		Node* leftTail = BST2DLL(n->l);
		Node* rightTail = BST2DLL(n->r);

		if (!leftTail && !rightTail)
		{
			return n;
		}
		if (leftTail && !rightTail)
		{
			Node* l = n->l;
			l->r = n;
			rightTail = leftTail;
		}
		else if (!leftTail && rightTail)
		{
			Node* r = n->r;
			n->l = r;
			r->r = n;
		}
		else if (leftTail && rightTail)
		{
			Node* r = n->r;
			leftTail->l = r;
			leftTail->r = n;
			r->r = leftTail;
		}

		n->r = rightTail;
		rightTail->l = n;

		return rightTail;
	}

	Node* FindMid(Node* h, Node* t)
	{
		Node* slow = h;
		Node* fast = h;

		while (fast && fast != t && fast->r && fast->r != t)
		{
			fast = fast->r->r;
			if (!fast)
				break;
			slow = slow->r;
		}
		return slow;
	}
	Node* SortedDLL2BST(Node* h, Node* t)
	{
		if (h == t)
		{
			h->l = 0;
			h->r = 0;
			return h;
		}
		Node* mid = FindMid(h, t);

		Node* l = 0;
		if(h != mid)
			l = SortedDLL2BST(h, mid->l);
		Node* r = SortedDLL2BST(mid->r, t);
		mid->l = l;
		mid->r = r;
		return mid;
	}
	Node* SortedDLL2BSTv2(Node* n)
	{
		if (!n)
			return n;

		Node* mid = FindMid(n, 0);

		Node* midR = mid->r;
		Node* midL = mid->l;
		if (midL)
			midL->r = 0;
		if (midR)
			midR->l = 0;

		Node* l = 0;
		if(midL)
			l = SortedDLL2BSTv2(n);
		Node* r = SortedDLL2BSTv2(midR);
		mid->l = l;
		mid->r = r;
		return mid;
	}

	Node* SortedArray2BST(int* ar, int h, int t)
	{
		if (h > t)
			return 0;
		Node* n = createNode(0, 0, 0);
		if (h == t)
		{
			n->data = ar[h];
		}
		else
		{
			int mid = ((t - h) / 2) + h;
			n->data = ar[mid];
			Node* l = SortedArray2BST(ar, h, mid - 1);
			Node* r = SortedArray2BST(ar, mid + 1, t);
			n->l = l;
			n->r = r;
		}

		return n;
	}

	void NodeBetweenAB(Node*n, int A, int B)
	{
		if (!n)
			return;
		if (n->data >= A && n->data <= B)
		{
			printf("%d ", n->data);
			NodeBetweenAB(n->l, A, B);
			NodeBetweenAB(n->r, A, B);
		}
	}

	Node* CreateFullBinarySearchTreeofHeightH(int h)
	{
		if (h == 0)
			return 0;

		Node* n = new Node();
        n->l = CreateFullBinarySearchTreeofHeightH(h - 1);
	    n->r = CreateFullBinarySearchTreeofHeightH(h - 1);
		return n;
	}
	// if h is 4 then 2^(h+1)-1 = 31. start = 0 and end 31.
	Node* CreateFullBinarySearchTreeofHeight(int start, int end)
	{
		Node* n = new Node();
		if (start == end)
		{
			n->data = start;
			n->l = 0;
			n->r = 0;
			return n;
		}

		int mid = start + ((end - start) / 2);
		n->data = mid;
		n->l = CreateFullBinarySearchTreeofHeight(start, mid - 1);
		n->r = CreateFullBinarySearchTreeofHeight(mid + 1, end);
		return n;
	}

	int isBSTanAVL(Node* n, bool* BSTanAVL)
	{
		if (!n)
			return 0;

		int lHeight = isBSTanAVL(n->l, BSTanAVL);
		int rHeight = isBSTanAVL(n->r, BSTanAVL);

		int diff = lHeight - rHeight;
		if (diff < 0)
			diff = diff * -1;

		if (diff == 2)
		{
			*BSTanAVL = false;
		}

		int max = lHeight;
		if (rHeight > max)
			max = rHeight;

		return max + 1;
	}

	Node* CreateMinNumberAVLOfHeightH(int h)
	{
		if (h < 0)
			return 0;

		Node* n = new Node();

		n->l = CreateMinNumberAVLOfHeightH(h - 1);
		n->r = CreateMinNumberAVLOfHeightH(h - 2);

		return n;
	}

	// Brute force. (a & b inclusive)
	void CountNumberOfNodesBetweenAandBInBSTv1(Node* n, int a, int b, int* count)
	{
		if (!n)
			return;

		if (a <= n->data && n->data <= b)
		{
			*count = *count + 1;
		}

		CountNumberOfNodesBetweenAandBInBSTv1(n->l, a, b, count);
		CountNumberOfNodesBetweenAandBInBSTv1(n->r, a, b, count);
	}
	// More efficient version.
	int CountNumberOfNodesBetweenAandBInBSTv2(Node* n, int a, int b)
	{
		if (!n)
			return 0;

		int l = 0;
		int r = 0;

		if (a < n->data && n->data < b)
		{
			l = CountNumberOfNodesBetweenAandBInBSTv2(n->l, a, b);
			r = CountNumberOfNodesBetweenAandBInBSTv2(n->r, a, b);
		}
		else if (n->data <= a)
		{
			r = CountNumberOfNodesBetweenAandBInBSTv2(n->r, a, b);
		}
		else if (n->data >= b) 
		{
			l = CountNumberOfNodesBetweenAandBInBSTv2(n->l, a, b);
		}

		if (a <= n->data && n->data <= b)
		{
			return l + r + 1;
		}
		return l + r;
	}
	// (a & b inclusive)
	Node* RemoveNodesThatAreNotWithinRangeOfAandB(Node* n, int a, int b)
	{
		if (!n)
			return 0;
		Node* l = RemoveNodesThatAreNotWithinRangeOfAandB(n->l, a, b);
		Node* r  = RemoveNodesThatAreNotWithinRangeOfAandB(n->r, a, b);

		bool isInRange = (a <= n->data && n->data <= b);
		
		if (isInRange)
		{
			n->l = l;
			n->r = r;
			return n;
		}
		else
		{
			delete n;
			if (l)
				return l;
			return r;
		}


	}

	// Remove all the nodes with only one child from a given tree.
	Node* RemoveHalfNodes(Node* n)
	{
		if (!n)
			return 0;

		n->l = RemoveHalfNodes(n->l);
		n->r = RemoveHalfNodes(n->r);

		if ((n->l && n->r) || (!n->l && !n->r))
			return n;

		Node* l = n->l;
		Node* r = n->r;
		delete n;

		if (l)
			return l;
		return r;
	}

	// if x is 4, the node containing 4 is returned or the one that has the closest value.
	Node* ClosestToX(Node* n, int x)
	{
        if (!n)
            return 0;
        Node* child = 0;
        if (x < n->data)
            child = ClosestToX(n->l, x);
        else if (x > n->data)
            child = ClosestToX(n->r, x);

        if (child)
        {
            if (abs(child->data - x) < abs(n->data - x))
            {
                return child;
            }
        }
        return n;
	}



	void DoBinarySearchTreeQuestions()
	{
		Node* n2 = createNode(2, 0, 0);
		Node* n5 = createNode(5, n2, 0);
		Node* n17 = createNode(17, 0, 0);
		Node* n16 = createNode(16, 0, n17);
		Node* n15 = createNode(15, n5, n16);
		Node* n40 = createNode(40, 0, 0);
		Node* n35 = createNode(35, 0, n40);
		Node* n25 = createNode(25, 0, 0);
		Node* n30 = createNode(30, n25, n35);
		Node* n20 = createNode(20, n15, n30);

		bool iFind = FindRecursive(n20, 17);
		iFind = FindIterative(n20, 35);
		int iMax = FindMax(n20);

		InsertNode(n20, 1);
		InsertNode(n20, 21);

		DeleteNode(n20, 20);

		int ilcd = findLCD(n20, 21, 40);

		bool bBST = isBST(n20, n20->data);

		printf("\n---NodeBetweenAB---\n");
		NodeBetweenAB(n20, 5, 50);
	

		{
			Node* n2 = createNode(2, 0, 0);
			Node* n5 = createNode(5, n2, 0);
			Node* n17 = createNode(17, 0, 0);
			Node* n16 = createNode(16, 0, n17);
			Node* n15 = createNode(15, n5, n16);
			Node* n40 = createNode(40, 0, 0);
			Node* n35 = createNode(35, 0, n40);
			Node* n25 = createNode(25, 0, 0);
			Node* n30 = createNode(30, n25, n35);
			Node* n20 = createNode(20, n15, n30);

			Node* dll = BST2DLL(n20);
		}

		{
			Node* n1 = createNode(1, 0, 0);
			Node* n2 = createNode(2, 0, 0);
			Node* n3 = createNode(3, 0, 0);
			Node* n4 = createNode(4, 0, 0);
			Node* n5 = createNode(5, 0, 0);
			Node* n6 = createNode(6, 0, 0);
			Node* n7 = createNode(7, 0, 0);
			Node* n8 = createNode(8, 0, 0);
			Node* n9 = createNode(9, 0, 0);

			n1->l = 0;
			n1->r = n2;
			n2->l = n1;
			n2->r = n3;
			n3->l = n2;
			n3->r = n4;
			n4->l = n3;
			n4->r = n5;
			n5->l = n4;
			n5->r = n6;
			n6->l = n5;
			n6->r = n7;
			n7->l = n6;
			n7->r = n8;
			n8->l = n7;
			n8->r = n9;
			n9->l = n8;
			n9->r = 0;

			//Node* bst = SortedDLL2BST(n1, n9); //Only enable one of them to see the result.
			Node* bst = SortedDLL2BSTv2(n1);
		}



		{
			int ar[] = {1,2,3,4,5,6,7,8,9};
			Node* bst = SortedArray2BST(ar, 0, 8);
		}

		
		{
			int count = 1;
			Node* fullBST = CreateFullBinarySearchTreeofHeightH(4);

			Node* node7 = ClosestToX(fullBST, 7);

			Node* fullBST2 = CreateFullBinarySearchTreeofHeight(1, 31);

			Node* current = fullBST2;
			while (current->r)
			{
				current = current->r;
			}

			Node* temp1 = createNode(100, 0, 0);
			Node* temp2 = createNode(200, 0, 0);
			temp1->r = temp2;
			current->r = temp1;

			bool BSTanAVL = true;
			isBSTanAVL(fullBST2, &BSTanAVL);

			Node* minAVL = CreateMinNumberAVLOfHeightH(3);

			int num = CountNumberOfNodesBetweenAandBInBSTv2(fullBST, 3, 10);

			num = 0;
			CountNumberOfNodesBetweenAandBInBSTv1(fullBST, 3, 10, &num);

			printf("");
		}


		{
			Node* n10 = createNode(10, 0, 0);
			Node* n5 = createNode(5, 0, 0);
			Node* n3 = createNode(3, 0, 0);
			Node* n7 = createNode(7, 0, 0);
			Node* n8 = createNode(8, 0, 0);
			Node* n20 = createNode(20, 0, 0);
			Node* n15 = createNode(15, 0, 0);
			Node* n25 = createNode(25, 0, 0);
			Node* n30 = createNode(30, 0, 0);

			n10->l = n5;
			n5->l = n3;
			n5->r = n7;
			n7->r = n8;
			n10->r = n20;
			n20->l = n15;
			n20->r = n25;
			n25->r = n30;

			Node* removedNodes = RemoveHalfNodes(n10);
			printf("");
		}

		{
			Node* n16 = createNode(16, 0, 0);
			Node* n5 = createNode(5, 0, 0);
			Node* n15 = createNode(15, 0, n16);
			Node* n10 = createNode(10, n5, n15);
			Node* n25 = createNode(25, 0, 0);
			Node* n35 = createNode(35, 0, 0);
			Node* n30 = createNode(30, n25, n35);
			Node* n20 = createNode(20, n10, n30);

			Node * smallTree = RemoveNodesThatAreNotWithinRangeOfAandB(n20, 15, 25);
			printf("");
		}

	}
}