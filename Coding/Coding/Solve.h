#pragma once
#include "HashTable.h"
#include "Stack.h"
#include "Queue.h"
namespace Solve
{
    struct Node
    {
        int data;
        Node* left;
        Node* right;
        Node* sibling;
    };

    Node* CreateNode(int data)
    {
        Node* n = new Node();
        n->data = data;
        n->left = 0;
        n->right = 0;
        n->sibling = 0;
        return n;
    }

    void PreOrderIterative(Node* n)
    {
        Stack s;
        s.push(n);

        while (s.Size() > 0)
        {
            Node* n = (Node*)s.pop();
            printf("%d ", n->data);
            if (n->right)
                s.push(n->right);
            if (n->left)
                s.push(n->left);
        }
    }

    void InorderIterative(Node* n)
    {
        Stack s;
        while (1)
        {
            if (n)
            {
                s.push(n);
                n = n->left;
            }
            else
            {
                if (s.Size() == 0)
                    break;

                Node* x = (Node*)s.pop();
                printf("%d ", x->data);
                n = x->right;
            }
        }
    }

    void FillSiblings(Queue* q)
    {
        Node* prev = 0;
        while (q->Size() > 0)
        {
            Node* n = (Node*)q->Deqeue();

            if (n)
            {
                if (n->left)
                {
                    if (prev)
                        prev->sibling = n->left;
                    prev = n->left;
                    q->Enqueue(n->left);
                }
                if (n->right)
                {
                    prev->sibling = n->right;
                    prev = n->right;
                    q->Enqueue(n->right);
                }
            }
            else
            {
                if (q->Size() > 0)
                {
                    q->Enqueue(0);
                    prev = 0;
                }
            }
        }
    }

    // Doing this iteratively is super easy
    int FindMax(Node* n, int i)
    {
        int max = n->data;
        if (i > max)
            max = i;

        if (n->left)
        {
            int l = FindMax(n->left, max);
            if (l > max)
                max = l;
        }
        if (n->right)
        {
            int r = FindMax(n->right, max);
            if (r > max)
                max = r;
        }

        return max;
    }
    // Doing this iteratively is super easy
    int FindNumerOfNodes(Node* n)
    {
        if (!n)
            return 0;
        return FindNumerOfNodes(n->left) + FindNumerOfNodes(n->right) + 1;
    }

    void PrintLevelFromBottom(Node* n)
    {
        Queue q;
        q.Enqueue(n);
        q.Enqueue(0);
        Stack s;

        int level = 0;

        while (q.Size() > 0)
        {
            Node* x = (Node*)q.Deqeue();
            s.push(x);
            if (x)
            {
                if (x->left)
                    q.Enqueue(x->left);
                if (x->right)
                    q.Enqueue(x->right);
            }
            else
            {
                if (q.Size() > 0)
                {
                    q.Enqueue(0);
                }
                level++;
            }
        }


        while (s.Size() > 0)
        {
            Node* n = (Node*)s.pop();
            if (n)
            {
                printf("    %d\n", n->data);
            }
            else
            {
                printf("Level %d\n", level);
                level--;
            }
        }
    }


    // Doing this iteratively would be using Queue with level count.
    // bottom two is the same questions really.
    int TreeHeight(Node* n, int level)
    {
        if (!n)
            return 0;

        int max = level;
        int l = TreeHeight(n->left, level + 1);
        if (l > max)
            max = l;
        int r = TreeHeight(n->right, level + 1);
        if (r > max)
            max = r;

        return max;
    }
    int HeightOfDeepestNode(Node* n)
    {
        return TreeHeight(n, 0);
    }
    int LongestPathFromOneLeafNodeToAnotherLeafNode(Node* n, int level)
    {
        if (!n)
            return 0;

        if (level == 0)
        {
            return TreeHeight(n->left, level + 1) + TreeHeight(n->right, level + 1);
        }

        int max = level;
        int l = TreeHeight(n->left, level + 1);
        if (l > max)
            max = l;
        int r = TreeHeight(n->right, level + 1);
        if (r > max)
            max = r;

        return max;
    }

    Node* FindParent(Node* current, Node* parent, int data)
    {
        if (!current)
            return 0;
        if (current->data == data)
            return parent;

        Node* left = FindParent(current->left, current, data);
        if (left)
            return left;
        return FindParent(current->right, current, data);
    }

    Node* LCA(Node* n, int a, int b)
    {
        if (!n)
            return 0;
        Node* l = LCA(n->left, a, b);
        Node* r = LCA(n->right, a, b);
        if (l && r)
            return n;
        if (n->data == a || n->data == b)
            return n;

        if (l)
            return l;
        return r;
    }

    bool SumPathExists(Node* n, int sum)
    {
        if (!n)
            return false;
        sum = sum - n->data;
        if (sum == 0)
            return true;

        return SumPathExists(n->left, sum) || SumPathExists(n->right, sum);
    }

    Node* MakeMirror(Node* n)
    {
        if (!n)
            return 0;

        Node* m = CreateNode(n->data);
        m->left = MakeMirror(n->right);
        m->right = MakeMirror(n->left);
        return m;
    }

    bool IsMirror(Node* a, Node* b)
    {
        if (!a && !b)
            return true;
        if ((!a && b) || (a && !b))
            return false;
        if (a->data != b->data)
            return false;

        return IsMirror(a->left, b->right) || IsMirror(a->right, b->left);
    }

    Node* MakeMirrorInplace(Node* n)
    {
        if (!n)
            return 0;
        Node* left = n->left;
        Node* right = n->right;
        n->left = MakeMirrorInplace(right);
        n->right = MakeMirrorInplace(left);
        return n;
    }

    bool PrintPathToX(Node *n, int x)
    {
        if (!n)
            return false;
        if (n->data == x)
        {
            printf("%d ", n->data);
            return true;
        }

        bool left = PrintPathToX(n->left, x);
        bool right = PrintPathToX(n->right, x);
        if (left || right)
            printf("%d ", n->data);
        return left || right;
    }

    void PrintStack(Stack* s)
    {
        printf("\nStack content-\n");
        Stack* s2 = new Stack();
        while (s->Size() > 0)
        {
            Node* n = (Node*)s->pop();
            printf("%d ", n->data);
            s2->push(n);
        }

        while (s2->Size())
        {
            s->push(s2->pop());
        }

        delete s2;
        printf("\n");


    }

    void PrintAllPath(Node *n, Stack* s)
    {
        s->push(n);
        if (n->left)
            PrintAllPath(n->left, s);
        if (n->right)
            PrintAllPath(n->right, s);
        if (!n->left && !n->right)
            PrintStack(s);
        s->pop();
    }

    void ZigZag(Node* n)
    {
        Stack* s1 = new Stack();
        Stack* s2 = new Stack();
        bool opposite = true;
        s1->push(n);

        while (s1->Size() > 0)
        {
            Node* x = (Node*)s1->pop();
            if (x)
            {
                printf("%d ", x->data);
                if (opposite)
                {
                    s2->push(x->left);
                    s2->push(x->right);
                }
                else
                {
                    s2->push(x->right);
                    s2->push(x->left);
                }
            }
            if (s1->Size() == 0)
            {
                opposite = !opposite;
                Stack* temp = s1;
                s1 = s2;
                s2 = temp;
            }
        }

        delete s1;
        delete s2;
    }

    Node* FullTree(int h)
    {
        if (h < 0)
            return 0;
        Node* n = CreateNode(0);
        n->left = FullTree(h - 1);
        n->right = FullTree(h - 1);
        return n;
    }

    Node* MinAVLTree(int h)
    {
        if (h < 0)
            return 0;
        Node* n = CreateNode(0);
        n->left = MinAVLTree(h - 1);
        n->right = MinAVLTree(h - 2);
        return 0;
    }

    Node* RemoveNodesThatAreNotWithinRangeOfAandB(Node* n, int a, int b)
    {
        if (!n)
            return 0;
        Node* left = RemoveNodesThatAreNotWithinRangeOfAandB(n->left, a, b);
        Node* right = RemoveNodesThatAreNotWithinRangeOfAandB(n->right, a, b);
        if (a <= n->data && n->data <= b)
        {
            n->left = left;
            n->right = right;
            return n;
        }
        else
        {
            delete n;
            if (left)
                return left;
            return right;
        }

    }

    Node* RemoveNodesWithOnlyOneChild(Node* n)
    {
        if (!n)
            return 0;
        Node* l = RemoveNodesWithOnlyOneChild(n->left);
        Node* r = RemoveNodesWithOnlyOneChild(n->right);
        if (!l && r)
        {
            delete n;
            return r;
        }
        if (l && !r)
        {
            delete n;
            return l;
        }

        n->left = l;
        n->right = r;
        return n;
    }

	void Solve()
	{
		Node* n1 = CreateNode(1);
		Node* n2 = CreateNode(2);
		Node* n3 = CreateNode(3);
		Node* n4 = CreateNode(4);
		Node* n5 = CreateNode(5);
		Node* n6 = CreateNode(6);
		Node* n7 = CreateNode(7);
        Node* n8 = CreateNode(8);
        Node* n9 = CreateNode(9);

        n1->left = n2;
        n1->right = n3;
        n2->left = n4;
        n3->right = n5;
        n4->left = n6;
        n4->right = n7;
        n5->right = n8;
        n7->left = n9;

        Queue q;
        q.Enqueue(n1);
        q.Enqueue(0);
        FillSiblings(&q);

        int max = FindMax(n1, n1->data);

        int numberOfNode = FindNumerOfNodes(n1);

        PrintLevelFromBottom(n1);

        int height = TreeHeight(n1, 0);
        int longestPath = LongestPathFromOneLeafNodeToAnotherLeafNode(n1, 0);

        Node* parent = FindParent(n1, 0, 7);

        Node* lca = LCA(n1, 6, 9);
        lca = LCA(n1, 9, 8);
        lca = LCA(n1, 3, 8);
        lca = LCA(n1, 4, 4);

        bool sumpath = SumPathExists(n1, 7);

        Node* m1 = MakeMirror(n1);
        bool mirror = IsMirror(n1, m1);

        Node* inplaceMirror = MakeMirrorInplace(n1);

        PrintPathToX(inplaceMirror, 5);

        Stack s;
        PrintAllPath(inplaceMirror, &s);

        printf("--zigzag\n---");
        ZigZag(inplaceMirror);

        Node* fullTree = FullTree(2);

        {
            Node* n1 = CreateNode(1);
            Node* n2 = CreateNode(2);
            Node* n3 = CreateNode(3);
            Node* n4 = CreateNode(4);
            Node* n5 = CreateNode(5);
            Node* n6 = CreateNode(6);
            Node* n7 = CreateNode(7);
            Node* n8 = CreateNode(8);
            Node* n9 = CreateNode(9);

            n7->left = n4;
            n7->right = n8;
            n8->right = n9;
            n4->left = n2;
            n2->left = n1;
            n2->right = n3;
            n4->right = n5;
            n5->right = n6;



            //Node* removed = RemoveNodesThatAreNotWithinRangeOfAandB(n7, 5, 8);
            Node* removed = RemoveNodesWithOnlyOneChild(n7);
            printf("");
        }

        printf("");
	}
}
