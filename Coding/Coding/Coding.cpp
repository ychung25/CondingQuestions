// Coding.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Recursion.h"
#include "ArrayAndPointer.h"
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "CircularLinkedList.h"
#include "XORDoublyLinkedList.h"
#include "HashTable.h"

#include "LinkedListQuestions.h"
#include "StackQuestions.h"
#include "QueueQuestions.h"
#include "TreeQuestions.h"
#include "GenericTreeQuestions.h"
#include "BinarySearchTreeQuestions.h"
#include "HeapQuestions.h"
#include "SortAndSearchQuestions.h"

// sdf.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

struct Node
{
    char data;
    bool isEndOfString;
    Node** children;
};

class TrieTree
{
public:
    TrieTree()
    {
        rootNode = new Node();
        rootNode->children = new Node*[256]();
    }
    void Insert(char* str)
    {
        Node* currentNode = rootNode;
        while (*str)
        {
            Node** children = currentNode->children;
            Node* child = children[(int)*str];
            if (child)
            {
                currentNode = child;
                str++;
            }
            else
            {
                Node* newChild = new Node();
                newChild->data = *str;
                newChild->children = new Node*[256]();
                if (*(str + 1) == '\0')
                {
                    newChild->isEndOfString = true;
                }
                else
                {
                    newChild->isEndOfString = false;
                }
                children[(int)*str] = newChild;
                currentNode = newChild;
                str++;
            }

        }
    }
    bool IsSubString(char *str)
    {
        Node* currentNode = rootNode;
        while (*str)
        {
            Node** children = currentNode->children;
            Node* child = children[(int)*str];
            if (child)
            {
                currentNode = child;
                str++;
            }
            else
            {
                return false;
            }
        }

        return currentNode->isEndOfString;
    }
private:
    Node* rootNode;
};

int main()
{
    TrieTree trieTree;
    trieTree.Insert("sting");
    trieTree.Insert("stink");
    trieTree.Insert("pink");
    trieTree.Insert("drink");
    trieTree.Insert("rock");
    trieTree.Insert("solid");

    bool isSubString = trieTree.IsSubString("string");
    isSubString = trieTree.IsSubString("sti");
    isSubString = trieTree.IsSubString("ink");
    isSubString = trieTree.IsSubString("rock");
    isSubString = trieTree.IsSubString("solid");
    isSubString = trieTree.IsSubString("what");
    return 0;
}



int main()
{
	// [Array and pointer]
	DoArraysAndPointers();

	// [Recursion]
	DoRecursionQuestions();

	// [Linked List]
	DoSinglyLinkedList();
	DoDoublyLinkedList();
	DoCircularLinkedList();
	DoXORDoublyLinkedList();

	LinkedListQuestions::DoLinkedListQuestions();

	StackQuestions::DoStackQuestions();

	QueueQuestions::DoQueueQuestions();

	BinaryTreeQuestions::DoBinaryTreeQuestions();

	GenericTreeQuestions::DoGenericTreeQuestions();

	BinarySearchTreeQuestions::DoBinarySearchTreeQuestions();

	HeapQuestions::DoHeapQuestions();

	SortAndSearchQuestions::DoSortAndSearchQuestions();

	return 0;
}

