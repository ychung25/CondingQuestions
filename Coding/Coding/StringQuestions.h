#pragma once
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
	private:
		TrieNode* rootNode;
	};

	void DoStringQuestions()
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
	}
}