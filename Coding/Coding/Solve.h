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

	// 'p' is a regex that can contain ? and *. Does 'p' exists in the string 's'?
	bool PatternMatching(char s[], char p[])
	{
		if (!(*s) && !(*p))
			return true;
		if (!(*s) && *p)
		{
			if (*p == '*' || *p == '?')
			{
				return true;
			}
			return false;
		}

		if (*p == '*')
		{
			return PatternMatching(s+1, p) || PatternMatching(s, p+1);
		}
		else if (*p == '?')
		{
			return PatternMatching(s+1, p+1) || PatternMatching(s, p+1);
		}
		else if (*p)
		{
			if (*p != *s)
				return false;
			return PatternMatching(s+1, p+1);
		}
	}

	void ReplaceSpaceWithOtherCharsInPlace(char str[])
	{
		char* x = str;
		int len = 0;
		int spaces = 0;
		while (*x)
		{
			if (*x == ' ')
				spaces++;
			len++;
			x++;
		}

		int newlen = (len - spaces) + (3 * spaces);
		x = str;
		x[newlen] = '\0';

		len--;
		newlen--;

		while (len >= 0)
		{
			if (x[len] != ' ')
			{
				x[newlen--] = x[len--];
			}
			else
			{
				x[newlen--] = '0';
				x[newlen--] = '2';
				x[newlen--] = '%';
				len--;
			}
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

		{
			char str[100];
			str[0] = 'a';
			str[1] = 'b';
			str[2] = ' ';
			str[3] = 'c';
			str[4] = ' ';
			str[5] = '\0';
			ReplaceSpaceWithOtherCharsInPlace(str);
			printf("");
		}

		{
			char str[] = "korea";
			bool result = PatternMatching(str, "korea");
			result = PatternMatching(str, "*");
			result = PatternMatching(str, "*a");
			result = PatternMatching(str, "*a*");
			result = PatternMatching(str, "k*a");
			result = PatternMatching(str, "?orea");
			result = PatternMatching(str, "?korea");
			result = PatternMatching(str, "korea?");
			result = PatternMatching(str, "kore?");
			result = PatternMatching(str, "??re?");

			result = PatternMatching(str, "koreb");
			result = PatternMatching(str, "k?oe");
			result = PatternMatching(str, "d");
		}

		Stack s;
		PrintAllWords(root, &s);
		printf("");
	}
}
