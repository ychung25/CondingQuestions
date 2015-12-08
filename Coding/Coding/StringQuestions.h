#pragma once
#include "Queue.h"
#include "DoublyLinkedList.h"

namespace StringQuestions
{

#include "stdafx.h"

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

	struct TernaryNode
	{
		char data;
		bool isEndOfString;
		TernaryNode* left;
		TernaryNode* mid;
		TernaryNode* right;
	};

	TernaryNode* CreateTernaryNode(char word)
	{
		TernaryNode* node = new TernaryNode();
		node->data = word;
		node->isEndOfString = false;
		node->left = 0;
		node->mid = 0;
		node->right = 0;
		return node;
	}

	class TernaryTree
	{
	public:
		TernaryTree() :root(0) {}

		void Insert(char* word)
		{
			InsertHelper(&root, word);
		}

		bool IsSubString(char* word)
		{
			return IsSubStringHelper(&root, word);
		}

		void PrintAllStrings()
		{
			char buffer[1000];
			PrintAllStrings(root, buffer, 0);
		}

	private:
		void InsertHelper(TernaryNode** node, char* word)
		{
			if (!(*node))
			{
				*node = CreateTernaryNode(*word);
				if (*(word + 1) == '\0')
				{
					(*node)->isEndOfString = true;
					return;
				}
			}

			if (*word < (*node)->data)
			{
				InsertHelper(&(*node)->left, word);
			}
			else if (*word > (*node)->data)
			{
				InsertHelper(&(*node)->right, word);
			}
			else
			{
				InsertHelper(&(*node)->mid, word + 1);
			}
		}

		bool IsSubStringHelper(TernaryNode** node, char* word)
		{
			if (!(*node))
			{
				return false;
			}

			if (*word < (*node)->data)
			{
				return IsSubStringHelper(&(*node)->left, word);
			}
			else if (*word > (*node)->data)
			{
				return IsSubStringHelper(&(*node)->right, word);
			}
			else
			{
				if (*(word + 1) == '\0')
				{
					return (*node)->isEndOfString;
				}
				return IsSubStringHelper(&(*node)->mid, word + 1);
			}
		}

		void PrintAllStrings(TernaryNode* node, char buffer[], int level)
		{
			if (!node)
				return;

			PrintAllStrings(node->left, buffer, level);

			buffer[level] = node->data;
			if (node->isEndOfString)
			{
				buffer[level + 1] = '\0';
				printf("%s\n", buffer);
			}
			PrintAllStrings(node->mid, buffer, level+1);

			PrintAllStrings(node->right, buffer, level);
		}

		TernaryNode* root;
	};

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
		if (!*s)
		{
			return *p ? false : true;
		}
		if (!*p)
		{
			return true;
		}

		if (*p == *s)
		{
			return PatternMatching(++s, ++p);
		}
		else if (*p == '?')
		{
			return PatternMatching(++s, ++p) || PatternMatching(s, ++p);
		}
		else if (*p == '*')
		{
			return PatternMatching(++s, p) || PatternMatching(s, ++p);
		}
		else
		{
			return false;
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
			TernaryTree ternaryTree;
			ternaryTree.Insert("sting");
			ternaryTree.Insert("stink");
			ternaryTree.Insert("pink");
			ternaryTree.Insert("drink");
			ternaryTree.Insert("rock");
			ternaryTree.Insert("solid");

			bool isSubString = ternaryTree.IsSubString("string");
			isSubString = ternaryTree.IsSubString("sti");
			isSubString = ternaryTree.IsSubString("ink");
			isSubString = ternaryTree.IsSubString("rock");
			isSubString = ternaryTree.IsSubString("solid");
			isSubString = ternaryTree.IsSubString("what");

			ternaryTree.PrintAllStrings();
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
	}
}