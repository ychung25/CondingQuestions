#pragma once
#include "Queue.h"
#include "DoublyLinkedList.h"

namespace StringQuestions
{

#include "stdafx.h"

	/* these are applications of tree */
	struct TrieNode
	{
		char data;
		bool isEndOfString;
		TrieNode** children;
	};
	class TrieTree
	{
	public:
		TrieTree()
		{
			rootNode = new TrieNode();
			rootNode->children = new TrieNode*[256]();
		}
		void Insert(char* str)
		{
			TrieNode* currentNode = rootNode;
			while (*str)
			{
				TrieNode** children = currentNode->children;
				TrieNode* child = children[(int)*str];
				if (child)
				{
					currentNode = child;
					str++;
				}
				else
				{
					TrieNode* newChild = new TrieNode();
					newChild->data = *str;
					newChild->children = new TrieNode*[256]();
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
			TrieNode* currentNode = rootNode;
			while (*str)
			{
				TrieNode** children = currentNode->children;
				TrieNode* child = children[(int)*str];
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
		void PrintAllStrings()
		{
			char buffer[1000];

			for (int i = 0; i < 256; i++)
			{
				PrintAllStringsHelper(rootNode->children[i], buffer, 0);
			}
		}
	private:
		void PrintAllStringsHelper(TrieNode* node, char buffer[], int level)
		{
			if (!node)
				return;

			buffer[level] = node->data;
			if (node->isEndOfString)
			{
				buffer[level + 1] = '\0';
				printf("%s\n", buffer);
			}

			for (int i = 0; i < 256; i++)
			{
				PrintAllStringsHelper(node->children[i], buffer, level + 1);
			}
		}
		TrieNode* rootNode;
	};

	/* THIS IS A SPECIAL APPLICATION OF TREE TO REPRESENT A DICTIONARY OF WORDS*/
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
		else if (*word < n->data)
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

	void ReverseString(char str[])
	{
		int len = strlen(str);
		int a = 0;
		int b = len - 1;
		while (a < b)
		{
			int temp = str[a];
			str[a] = str[b];
			str[b] = temp;
			a++;
			b--;
		}
	}

	// "hello hi" -> remove 'h' -> "ello i"
	void RemoveChars(char str[], char x)
	{
		int read = 0;
		int write = 0;
		while (str[read])
		{
			str[write] = str[read];
			if (str[read] == x)
			{
				read++;
			}
			else
			{
				read++;
				write++;
			}
		}
		str[write] = str[read];
	}

	// abcdddce -> abe
	void RemoveDuplicates(char* str)
	{
		if (!str)
			return;
		int x = 0;
		int y = 1;
		while (str[y])
		{
			if (str[x] != str[y])
			{
				str[++x] = str[y++];
			}
			else
			{
				x--;
				y++;
				while (str[y] == str[y - 1])
				{
					y++;
				}
			}
		}
		str[++x] = '\0';
	}

	// Given a string, replace every space char with '%20' in place.
	// Assume the string is big enough for expansion.
	void ReplaceSpaceWithOtherCharsInPlace(char str[])
	{
		int length = 0;
		int numberOfSpaces = 0;
		char* temp = str;
		while (*temp)
		{
			if (*temp == ' ')
				numberOfSpaces++;
			length++;
			temp++;
		}

		int newLength = length + (2 * numberOfSpaces);
		str[newLength] = '\0';

		int w = newLength - 1;
		int r = newLength - 1;

		while (r >= 0)
		{
			if (str[r] == ' ')
			{
				str[w] = '0';
				w--;
				str[w] = '2';
				w--;
				str[w] = '%';
				w--;
			}
			else if (str[r])
			{
				str[w] = str[r];
				w--;
			}
			r--;
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
			return PatternMatching(s + 1, p) || PatternMatching(s, p + 1);
		}
		else if (*p == '?')
		{
			return PatternMatching(s + 1, p + 1) || PatternMatching(s, p + 1);
		}
		else if (*p)
		{
			if (*p != *s)
				return false;
			return PatternMatching(s + 1, p + 1);
		}
	}

	// e.g. flip this man => man this flip
	void FlipString(char s[], int start, int end)
	{
		while (start < end)
		{
			char temp = s[start];
			s[start] = s[end];
			s[end] = temp;
			start++;
			end--;
		}
	}
	void ReverseSetence(char s[], int length)
	{
		FlipString(s, 0, length-1);

		int start = 0;
		int end = 0;

		while (start < length && end < length)
		{
			while (s[end] != ' ' && s[end])
			{
				end++;
			}
			FlipString(s, start, end - 1);
			start = end + 1;
			end = end + 1;
		}
	}

	// e.g abc => abc, acb, bac, bca, cab, cba
	void _PrintAllPermutation(char s[], char p[], bool used[], int len, int depth)
	{
		if (depth == len)
		{
			printf("%s\n", p);
			return;
		}

		for (int i = 0; i < len; i++)
		{
			if (used[i] == false)
			{
				p[depth] = s[i];
				used[i] = true;
				_PrintAllPermutation(s, p, used, len, depth + 1);
				used[i] = false;
			}
		}
	}
	void PrintAllPermutation(char s[])
	{
		int length = 0;
		char* temp = s;
		while (*temp)
		{
			length++;
			temp++;
		}

		char* p = new char[length+1]();
		p[length] = '\0';
		bool* used = new bool[length]();
		for (int i = 0; i < length; i++)
		{
			used[i] = false;
		}

		_PrintAllPermutation(s, p, used, length, 0);
	}

	void _PrintAllCombination(char s[], char p[], int start, int len, int depth)
	{
		if (depth == len)
			return;

		for (int i = start; i < len; i++)
		{
			p[depth] = s[i];
			p[depth + 1] = '\0';
			printf("%s\n", p);
			_PrintAllCombination(s, p, i+1, len, depth+1);
		}
	}
	void PrintAllCombination(char s[])
	{
		int length = 0;
		char* temp = s;
		while (*temp)
		{
			length++;
			temp++;
		}

        char* p = new char[length + 1]();

		_PrintAllCombination(s, p, 0, length, 0);
	}


	// e.g str1 = {A,B} str2 = {C,D} => ABCD, ACDB, ACBD, CDAB, CABD, CADB
	void _PrintIntervening(char A[], int a, char B[], int b, char D[], char depth)
	{
		if (A[a])
		{
			D[depth] = A[a];
			if (depth == 3)
			{
				printf("%s\n", D);
			}
			else if (depth < 3)
			{
				_PrintIntervening(A, a + 1, B, b, D, depth + 1);
				_PrintIntervening(B, b, A, a + 1, D, depth + 1);
			}
		}
	}
	void PrintIntervening(char A[], char B[])
	{
		int length = 0;
		char* temp = A;
		while (*temp)
		{
			temp++;
			length++;
		}

		char* D = new char[(2*length) + 1]();
		D[(2 * length)] = '\0';

		_PrintIntervening(A, 0, B, 0, D, 0);
		_PrintIntervening(B, 0, A, 0, D, 0);
	}

	void DoStringQuestions()
	{
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
			trieTree.PrintAllStrings();
		}

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

		{
			char str[100] = "a bce f g";
			ReplaceSpaceWithOtherCharsInPlace(str);
			printf("");
		}

		{
			char s[] = "abcde";
			char p[] = "?a";
			bool patternMatches = PatternMatching(s, p);
			printf("");
		}

		{
			char s[] = "Never cannot belive what you say";
			int length = sizeof(s) / sizeof(s[0]);
			ReverseSetence(s, length-1);
			printf("");
		}

		{
			char str[] = "abc";
			PrintAllPermutation(str);
			printf("");
		}

		{
			printf("\n----Combination----\n");
			char str[] = "abc";
			PrintAllCombination(str);
			printf("");
		}

		{
			char str[] = "ABCCCCBCDABB";
			RemoveDuplicates(str);
			printf("");
		}

		{
			char str[] = "hello hi";
			RemoveChars(str, 'h');
			printf("");
		}

		{
			char str1[] = "AB";
			char str2[] = "CD";
			PrintIntervening(str1, str2);
			printf("");
		}
	}
}