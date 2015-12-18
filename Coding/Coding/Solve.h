#pragma once
#include "HashTable.h"
#include "Stack.h"
#include "Queue.h"
namespace Solve
{
	struct TernaryNode
	{
		char data;
		bool isEnd;
		TernaryNode* left;
		TernaryNode* mid;
		TernaryNode* right;
	};
	TernaryNode* CreateTernaryNode(char data)
	{
		TernaryNode* n = new TernaryNode();
		n->isEnd = false;
		n->data = data;
		n->left = 0;
		n->mid = 0;
		n->right = 0;
		return n;
	}
	TernaryNode* InsertWord(TernaryNode* n, char* word)
	{
		if (!n)
		{
			n = CreateTernaryNode(*word);
		}

		if (*word == n->data)
		{
			if (*(word + 1) == '\0')
				n->isEnd = true;
			else
				n->mid = InsertWord(n->mid, ++word);
		}
		else if(*word < n->data)
		{
			n->left = InsertWord(n->left, word);
		}
		else if (*word > n->data)
		{
			n->right = InsertWord(n->right, word);
		}

		return n;
	}
	bool WordExists(TernaryNode* n, char* word)
	{
		if (!n)
			return false;
		if (*word == n->data)
		{
			if (*(word + 1) == '\0')
				return n->isEnd;
			else
				return WordExists(n->mid, ++word);
		}
		else if (*word < n->data)
		{
			return WordExists(n->left, word);
		}
		else if (*word > n->data)
		{
			return WordExists(n->right, word);
		}
	}
	void PrintStack(Stack* s)
	{
		printf("\n");
		Stack* temp = new Stack();
		while (s->Size())
		{
			temp->push(s->pop());
		}
		while (temp->Size())
		{
			TernaryNode* n = (TernaryNode*)temp->pop();
			char x = n->data;
			printf("%c", n->data);
			s->push(n);
		}
	}
	void PrintAllWords(TernaryNode* n, Stack* s)
	{
		if (n->isEnd)
		{
			s->push(n);
			PrintStack(s);
			s->pop();
		}
		if (n->left)
		{
			PrintAllWords(n->left, s);
		}
		if (n->mid)
		{
			s->push(n);
			PrintAllWords(n->mid, s);
			s->pop();
		}
		if (n->right)
		{
			PrintAllWords(n->right, s);
		}
	}

	void Solve()
	{
		TernaryNode* root = 0;
		root = InsertWord(root, "car");
		root = InsertWord(root, "ca");
		root = InsertWord(root, "cat");
		root = InsertWord(root, "ass");
		root = InsertWord(root, "cam");
		root = InsertWord(root, "this");
		root = InsertWord(root, "shout");
		root = InsertWord(root, "south");
		root = InsertWord(root, "park");
		root = InsertWord(root, "think");

		bool wordExists = WordExists(root, "car");
		wordExists = WordExists(root, "ass");
		wordExists = WordExists(root, "ca");
		wordExists = WordExists(root, "cap");
		wordExists = WordExists(root, "cam");

		Stack s;
		PrintAllWords(root, &s);
		printf("");
	}
}
