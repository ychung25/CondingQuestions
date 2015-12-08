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
	}
}