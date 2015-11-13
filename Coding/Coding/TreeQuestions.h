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

	// Find the node with the max value in binary tree iteratively
	int FindMaxInBinaryTreeIteratively(Node* n)
	{
		Stack s;
		s.push(n);
		int max = 0;
		while (s.Size())
		{
			Node* n = (Node*)s.pop();
			if (n->data > max)
				max = n->data;

			if (n->l)
				s.push(n->l);
			if (n->r)
				s.push(n->r);
		}

		return max;
	}

	// Find the numer of nodes in tree recursively
	int FindTheNumberOfNodesRecursively(Node* n)
	{
		if (n->l == 0 && n->r == 0)
			return 1;
		
		int l = 0;
		int r = 0;
		if (n->l)
			l = FindTheNumberOfNodesRecursively(n->l);
		if (n->r)
			r = FindTheNumberOfNodesRecursively(n->r);

		return l + r + 1;
	}

	// Fine the number of nodes in tree iteratively
	int FindTheNumberOfNodesIteratively(Node* n)
	{
		Queue queue;
		queue.Enqueue(n);
		int i = 0;
		while (queue.Size())
		{
			i++;
			Node* n = (Node*)queue.Deqeue();
			if (n->l)
				queue.Enqueue(n->l);
			if (n->r)
				queue.Enqueue(n->r);
		}

		return i;
	}

	void PrintLevelsFromBottomToTop(Node* n)
	{
		Queue q;
		Stack s;
		q.Enqueue(n);
		while (q.Size())
		{
			Node* n = (Node*)q.Deqeue();
			s.push(n);
			if (n->r)
				q.Enqueue(n->r);
			if (n->l)
				q.Enqueue(n->l);
		}

		printf("\n---PrintLevelsFromBottomToTop--\n");
		while(s.Size() > 0)
		{
			printf("%d ", ((Node*)s.pop())->data);
		}
	}

	int FindTreeLevelIterative(Node* n)
	{
		int l = 0;
		int r = 0;
		if (n->l)
			l = FindTreeLevelIterative(n->l);
		if (n->r)
			r = FindTreeLevelIterative(n->r);

		if (l > r)
			return l + 1;
		return r + 1;
	}

	void FindTreeLevelRecursively(Queue* q, int* height)
	{
		if (q->Size() == 0)
			return;

		Node* n = (Node*)q->Deqeue();
		if (n == 0)
		{
			*height = *height + 1;
			if (q->Size() > 0)
				q->Enqueue(0);
		}
		else
		{
			if (n->l)
				q->Enqueue(n->l);
			if (n->r)
				q->Enqueue(n->r);
		}

		FindTreeLevelRecursively(q, height);

	}

	int MaxSumLevel(Node* n)
	{
		int sum = 0;
		int maxSum = 0;
		int level = 0;
		int maxLevel = 0;
		Queue q;
		q.Enqueue(n);
		q.Enqueue(0);
		while (q.Size())
		{
			Node* n = (Node*)q.Deqeue();
			if (n == 0)
			{
				level++;

				if (sum > maxSum)
				{
					maxSum = sum;
					maxLevel = level;
				}
				sum = 0;

				if (q.Size())
					q.Enqueue(0);
			}
			else
			{
				sum += n->data;
				if (n->l)
					q.Enqueue(n->l);
				if (n->r)
					q.Enqueue(n->r);
			}
		}

		return maxLevel;
	}
 
	// Given a node in a tree, find its parent.
	Node* GetParentNode(Node* n, Node* child)
	{
		if (n->l == child)
			return n;
		if (n->r == child)
			return n;

		Node* l = 0;
		Node* r = 0;
		if (n->l)
			l = GetParentNode(n->l, child);
		if (n->r)
			r = GetParentNode(n->r, child);

		if (l)
			return l;
		if (r)
			return r;

		return 0;
	}

	// Remove a node from a binary tree (not a Binary search tree)
	void RemoveNodeInBinaryTree(Node* root, Node* toDelete)
	{
		Stack s;

		Node* toDeleteTemp = 0;
		s.push(root);
		while (s.Size())
		{
			Node* n = (Node*)s.pop();
			if (n == toDelete)
				toDeleteTemp = toDelete;
			if (n->r)
				s.push(n->r);
			if (n->l)
				s.push(n->l);
		}

		Node* leafNode = 0;
		s.push(root);
		while (s.Size())
		{
			Node* n = (Node*)s.pop();
			if (n->l == 0 && n->r == 0)
				leafNode = n;
			if (n->r)
				s.push(n->r);
			if (n->l)
				s.push(n->l);
		}

		Node* leafNodeParent = GetParentNode(root, leafNode);
		bool isLeftChild = (leafNodeParent->l == leafNode);

		toDeleteTemp->data = leafNode->data;

		if (isLeftChild)
			leafNodeParent->l = 0;
		else
			leafNodeParent->r = 0;

		delete leafNode;
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

	bool IsTreesIdentical(Node* n1, Node* n2)
	{

		if (n1 == 0 && n2 == 0)
			return true;

		if ((n1 == 0 && n2 != 0) ||
			(n2 != 0 && n2 == 0))
		{
			return false;
		}

		if (n1->data != n2->data)
			return false;

		bool bl = IsTreesIdentical(n1->l, n2->l);
		bool br = IsTreesIdentical(n1->r, n2->r);

		return bl && br;
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

	void PathOfSumExists(Node* n, int sum, bool* exists)
	{
		sum = sum - n->data;
		if (sum == 0)
			*exists = true;
		if (n->l)
			PathOfSumExists(n->l, sum, exists);
		if (n->r)
			PathOfSumExists(n->r, sum, exists);
	}

	void CreateMirrorTree(Node* n, Node* m)
	{
		Node* a = 0;
		Node* b = 0;
		if (n->l)
			a = createNode(n->l->data, 0, 0);
		if (n->r)
			b = createNode(n->r->data, 0, 0);

		m->l = b;
		m->r = a;

		if (n->l)
			CreateMirrorTree(n->l, m->r);
		if (n->r)
			CreateMirrorTree(n->r, m->l);
	}

	void AreTwoTreesMirrorOfEachOther(Node* n, Node* m, bool* isMirror)
	{
		if (n == 0 || m == 0)
			return;

		Node* nL = n->l;
		Node* nR = n->r;
		Node* mL = m->l;
		Node* mR = m->r;
		AreTwoTreesMirrorOfEachOther(nL, mR, isMirror);
		AreTwoTreesMirrorOfEachOther(nR, mL, isMirror);

		if ((nL == 0 && mR != 0) ||
			(nR == 0 && mL != 0) ||
			(mL == 0 && nR != 0) ||
			(mR == 0 && nL != 0))
		{
			*isMirror = false;
		}

		if (nL != 0)
		{
			if (nL->data != mR->data)
				*isMirror = false;
		}
		if (nR != 0)
		{
			if (nR->data != mL->data)
				*isMirror = false;
		}

	}

	void MakeMirrorInPlace(Node* n)
	{
		if (n->l)
			MakeMirrorInPlace(n->l);
		if (n->r)
			MakeMirrorInPlace(n->r);

		Node* temp = n->r;
		n->r = n->l;
		n->l = temp;
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

	void PrintAllPathsFromRoot(Node* n, Stack* s)
	{
		if (n == 0)
			return;

		if (n->l == 0 && n->r == 0)
		{
			printf("%d ", n->data);
			Stack s2;
			while (s->Size())
			{
				Node* n = (Node*)s->pop();
				printf("%d ", n->data);
				s2.push(n);
			}
			while (s2.Size())
			{
				s->push(s2.pop());
			}
			printf("\n");
			return;
		}

		s->push(n);
		PrintAllPathsFromRoot(n->l, s);
		PrintAllPathsFromRoot(n->r, s);
		s->pop();
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

		max = FindMaxInBinaryTreeIteratively(n1);

		int numnberOfNodes = FindTheNumberOfNodesRecursively(n1);

		numnberOfNodes = FindTheNumberOfNodesIteratively(n1);

		PrintLevelsFromBottomToTop(n1);

		Node* parentNode = GetParentNode(n1, n7);

		int level = FindTreeLevelIterative(n1);

		level = 0;
		Queue qLevel;
		qLevel.Enqueue(n1);
		qLevel.Enqueue(0);
		FindTreeLevelRecursively(&qLevel, &level);

		int maxSumLevel = MaxSumLevel(n1);

		printf("\n---PrintAllPathsFromRoot---\n");
		Stack sAllPath;
		PrintAllPathsFromRoot(n1, &sAllPath);

		bool pathOfSumExists = false;
		PathOfSumExists(n1, 4, &pathOfSumExists);

		Node* mirror = createNode(n1->data, 0, 0);
		CreateMirrorTree(n1, mirror);

		bool isMirror = true;
		AreTwoTreesMirrorOfEachOther(n1, mirror, &isMirror);
		printf("");

		{

			Node* n6 = createNode(6, 0, 0);
			Node* n7 = createNode(7, 0, 0);
			Node* n4 = createNode(4, n6, 0);
			Node* n5 = createNode(5, 0, n7);
			Node* n9 = createNode(9, 0, 0);
			Node* n2 = createNode(2, n4, n5);
			Node* n3 = createNode(3, 0, n9);
			Node* n1 = createNode(1, n2, n3);

			printf("\n\n---Remove a node---\n\n");
			RemoveNodeInBinaryTree(n1, n5);
			printf("\n\n---PreorderTraversalIterative---\n\n");
			PreorderTraversalIterative(n1);

			printf("\n\n---InorderTraversalIterative---\n\n");
			InorderTraversalIterative(n1);

			printf("\n\n---PostOrderTraversalIterative---\n\n");
			PostOrderTraversalIterative(n1);

			printf("\n\n---BFSIterative---\n\n");
			BFSIterative(n1);
		}

		{
			Node* n6 = createNode(6, 0, 0);
			Node* n7 = createNode(7, 0, 0);
			Node* n4 = createNode(4, n6, 0);
			Node* n5 = createNode(5, 0, n7);
			Node* n9 = createNode(9, 0, 0);
			Node* n2 = createNode(2, n4, n5);
			Node* n3 = createNode(3, 0, n9);
			Node* n1 = createNode(1, n2, n3);

			Node* m6 = createNode(6, 0, 0);
			Node* m7 = createNode(7, 0, 0);
			Node* m4 = createNode(4, m6, 0);
			Node* m5 = createNode(5, 0, m7);
			Node* m9 = createNode(9, 0, 0);
			Node* m2 = createNode(2, m4, m5);
			Node* m3 = createNode(3, 0, m9);
			Node* m1 = createNode(1, m2, m3);

			bool result = IsTreesIdentical(n1, m1);
			printf("");
		}

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

		newTree = CreateTreev3(levelorder, inorder, 0, (sizeof(inorder) / sizeof(inorder[0])) - 1, (sizeof(inorder) / sizeof(inorder[0])));

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

}