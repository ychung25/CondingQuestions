#pragma once
#include <cstdio>
#include "Trees.h"
#include "Stack.h"
#include "Queue.h"

namespace TreeQuestions
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

	// This is also DFS iterative version.
	void PreorderTraversalIterative(Node* r)
	{
		Stack s;
		s.push(r);
		while (s.Size())
		{
			Node* n = (Node*)s.pop();
			printf("%d", n->data);
			if(n->r)
				s.push(n->r);
			if(n->l)
			s.push(n->l);
		}
	}

	void InorderTraversalIterative(Node* r)
	{
		Stack s;
		while (1)
		{
			if (r)
			{
				s.push(r);
				r = r->l;
			}
			else
			{
				if (s.Size() == 0)
					break;

				Node* n = (Node*)s.pop();
				printf("%d,", n->data);
				r = n->r;
			}
		}
	}

	void PostOrderTraversalIterative(Node* n)
	{
		Node* poppedChild = 0;
		Stack s;
		while (1)
		{
			if (s.Size() > 0 && n == s.peek())
			{
				if (n->r && n->r != poppedChild)
				{
					n = n->r;
				}
				else
				{
					poppedChild = (Node*)s.pop();
					printf("%d,", poppedChild->data);
					if (s.Size() == 0)
					{
						break;
					}
					n = (Node*)s.peek();
					
				}
			}
			else if (n == 0)
			{
				n = (Node*)s.peek();
			}
			else if (n)
			{
				s.push(n);
				n = n->l;
			}
		}
	}

	void BFSIterative(Node* n)
	{
		Queue queue;
		queue.Enqueue(n);
		
		while (queue.Size() > 0)
		{
			Node* node = (Node*)queue.Deqeue();
			printf("%d ", node->data);
			if (node->l)
				queue.Enqueue(node->l);
			if (node->r)
				queue.Enqueue(node->r);
		}
	}

	void FillNextSibling(Node* n)
	{
		Queue queue;
		queue.Enqueue(n);
		queue.Enqueue(0);
		Node* prev = 0;
		while (queue.Size() > 0)
		{
			Node* current = (Node*)queue.Deqeue();
			if (current == 0)
			{
				//prev->nextSibling = 0;
				prev = 0;
				if (queue.Size() > 0)
					queue.Enqueue(0);
			}

			if (prev == 0)
			{
				prev = current;
			}
			else
			{
				//prev->nextSibling = current;
				prev = current;
			}

			if (n->l)
				queue.Enqueue(n->l);
			if (n->r)
				queue.Enqueue(n->r);
			
		}

	}

	// This only works if binary tree always have either no child or two children.
	void FillNextSiblingV2(Node* n)
	{
		if (n->l)
		{
			//n->l->nextSibling = n->r;
		}
		if (n->r)
		{
			//if (n->nextSibling)
			{
				//n->r->nextSibling = n->nextSibling->l;
			}
		}

		if (n->l)
			FillNextSiblingV2(n->l);
		if (n->r)
			FillNextSiblingV2(n->r);
	}


	// Find the node with the max value in binary tree recursively
	int FindMaxInBinaryTreeRecursively(Node* n)
	{
		int max = n->data;
		if (n->l)
		{
int maxL = FindMaxInBinaryTreeRecursively(n->l);
max = maxL;
		}
		if (n->r)
		{
			int maxR = FindMaxInBinaryTreeRecursively(n->r);
			max = maxR;
		}
		return max;
	}

	Node* LCA(Node* n, Node* x, Node* y)
	{
		if (!n)
			return n;
		if (n == x || n == y)
			return n;

		Node* l = LCA(n->l, x, y);
		Node* r = LCA(n->r, x, y);

		if (l && r)
			return n;

		if (l)
			return l;

		return r;
	}

	// Given inorder traversal and preorder traversal, create a treee
	Node* CreateTree(int* preorder, int* inorder, int start, int end, int* index)
	{
		if (start > end)
			return 0;
		Node* n = new Node();
		n->data = preorder[*index];

		int mid;
		for (int i = start; i <= end; i++)
		{
			if (inorder[i] == preorder[*index])
			{
				mid = i;
				break;
			}
		}
		*index = (*index) + 1;

		Node* l = CreateTree(preorder, inorder, start, mid - 1, index);
		Node* r = CreateTree(preorder, inorder, mid + 1, end, index);
		n->l = l;
		n->r = r;
		return n;
	}

	// Given inorder traversal and postorder traversal, create a tree.
	Node* CreateTreev2(int* postorder, int* inorder, int start, int end, int* index)
	{
		if (start > end) { return 0; }
		Node* n = new Node();
		n->data = postorder[*index];

		int mid = 0;
		for (int i = start; i <= end; i++)
		{
			if (inorder[i] == postorder[*index])
			{
				mid = i;
				break;
			}
		}
		*index = *index - 1;

		Node* r = CreateTreev2(postorder, inorder, mid + 1, end, index);
		Node* l = CreateTreev2(postorder, inorder, start, mid - 1, index);
		n->r = r;
		n->l = l;
		return n;
	}

	// Given inorder traversal and levelorder traversal, creete a tree
	Node* CreateTreev3(int* levelorder, int* inorder, int start, int end, int len)
	{
		if (start > end)
			return 0;
		Node* n = new Node();
		n->data = *levelorder;

		int mid = 0;
		for (int i = start; i <= end; i++)
		{
			if (inorder[i] == *levelorder)
			{
				mid = i;
				break;
			}
		}

		int* levelorderL = 0;
		int* levelorderR = 0;
		int levelorderLLength = ((mid - 1) - start) + 1;
		int levelorderRLength = (end - (mid + 1)) + 1;
		if (levelorderLLength > 0)
		{
			levelorderL = new int[levelorderLLength]();
		}
		if (levelorderRLength > 0)
		{
			levelorderR = new int[levelorderRLength]();
		}

		int* levelorderLTemp = levelorderL;
		int* levelorderRTemp = levelorderR;
		for (int i = 1; i < len; i++)
		{
			for (int j = start; j <= mid - 1; j++)
			{
				if (levelorder[i] == inorder[j])
				{
					*levelorderLTemp = inorder[j];
					levelorderLTemp++;
				}
			}
			for (int j = mid+1; j <= end; j++)
			{
				if (levelorder[i] == inorder[j])
				{
					*levelorderRTemp = inorder[j];
					levelorderRTemp++;
				}
			}
		}

		Node* l = CreateTreev3(levelorderL, inorder, start, mid - 1, levelorderLLength);
		Node* r = CreateTreev3(levelorderR, inorder, mid+1, end, levelorderRLength);
		n->l = l;
		n->r = r;

		if (levelorderL)
			delete[] levelorderL;
		if (levelorderR)
			delete[] levelorderR;

		return n;

	}

	bool PrintfPathToX(Node* n, int x)
	{
		if (x == n->data)
		{
			printf("%d", n->data);
			return true;
		}

		bool bl = false;
		bool br = false;

		if (n->l)
			bl = PrintfPathToX(n->l, x);
		if (n->r)
			br = PrintfPathToX(n->r, x);

		if (bl | br)
			printf("%d", n->data);
		return (bl | br);
	}

	void ZigZagTraverse(Node* n)
	{
		Stack* s1 = new Stack();
		s1->push(n);
		Stack* s2 = new Stack();
		bool pushLeftFirst = true;

		while (1)
		{
			if (s1->Size() == 0 && s2->Size() == 0)
				break;

			if (s1->Size() == 0)
			{
				Stack* temp;
				temp = s1;
				s1 = s2;
				s2 = temp;
				pushLeftFirst = !pushLeftFirst;
			}

			Node* n = (Node*)s1->pop();
			printf("%d ", n->data);

			if (pushLeftFirst)
			{
				if (n->l)
					s2->push(n->l);
				if (n->r)
					s2->push(n->r);
			}
			else
			{
				if (n->r)
					s2->push(n->r);
				if (n->l)
					s2->push(n->l);
			}
		}
	}

	Node* CreateTreeWithILPreorder(int* preorder, int* index)
	{
		Node* n = new Node();
		n->data = preorder[*index];
		n->l = 0;
		n->r = 0;
		*index = *index + 1;

		if (n->data == 0)
			return n;

		Node* l = CreateTreeWithILPreorder(preorder, index);
		Node* r = CreateTreeWithILPreorder(preorder, index);
		n->l = l;
		n->r = r;
		return n;
	}
	
	void DoTreeQuestions()
	{
		Node* n6 = createNode(6, 0, 0);
		Node* n7 = createNode(7, 0, 0);
		Node* n4 = createNode(4, n6, 0);
		Node* n5 = createNode(5, 0, n7);
		Node* n9 = createNode(9, 0, 0);
		Node* n2 = createNode(2, n4, n5);
		Node* n3 = createNode(3, 0, n9);
		Node* n1 = createNode(1, n2, n3);

		printf("\n\n---PreorderTraversalIterative---\n\n");
		PreorderTraversalIterative(n1);

		printf("\n\n---InorderTraversalIterative---\n\n");
		InorderTraversalIterative(n1);

		printf("\n\n---PostOrderTraversalIterative---\n\n");
		PostOrderTraversalIterative(n1);

		printf("\n\n---BFSIterative---\n\n");
		BFSIterative(n1);

		int max = FindMaxInBinaryTreeRecursively(n1);

		Node* lca = LCA(n1, n6, n7);

		int index = 0;
		int inorder[] = { 4,2,6,5,1,7,3 };
		int preorder[] = { 1,2,4,5,6,3,7 };
		int postorder[] = { 4,6,5,2,7,3,1 };
		int levelorder[] = { 1,2,3,4,5,7,6 };
		Node* newTree = CreateTree(preorder, inorder, 0, (sizeof(inorder) / sizeof(inorder[0])) - 1, &index);

		printf("\nnew tree1\n");
		PreorderTraversalIterative(newTree);
		InorderTraversalIterative(newTree);
		PostOrderTraversalIterative(newTree);

		index = (sizeof(inorder) / sizeof(inorder[0])) - 1;
		newTree = CreateTreev2(postorder, inorder, 0, (sizeof(inorder) / sizeof(inorder[0])) - 1, &index);

		printf("\nnew tree2\n");
		PreorderTraversalIterative(newTree);
		InorderTraversalIterative(newTree);
		PostOrderTraversalIterative(newTree);

		newTree = CreateTreev3(levelorder, inorder, 0, (sizeof(inorder) / sizeof(inorder[0]))-1, (sizeof(inorder) / sizeof(inorder[0])));

		printf("\nnew tree3\n");
		PreorderTraversalIterative(newTree);
		InorderTraversalIterative(newTree);
		PostOrderTraversalIterative(newTree);

		printf("\n---PrintfPathToX---\n");
		PrintfPathToX(n1, 9);

		printf("\n---ZigZagTraverse---\n");
		ZigZagTraverse(n1);

		{
			int preorder[] = { 1,1,0,0,1,0,1,0,0 };
			printf("\n---CreateTreeWithILPreorder---\n");
			index = 0;
			Node* tree = CreateTreeWithILPreorder(preorder, &index);
		}

}