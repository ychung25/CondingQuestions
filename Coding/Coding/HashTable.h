#pragma once
#include <cstdio>

namespace HashTable
{
	struct KeyValuePair
	{
		unsigned long long  key;
		void* value;
	};
	struct Node
	{
		KeyValuePair* data;
		Node* prev;
		Node* next;
	};

	class HashTable
	{
	public:
		HashTable() : arraySize(10)
		{
			array = new Node*[arraySize]();
		}
		~HashTable()
		{
			Node* current = array[0];
			while (current)
			{
				Node* temp = current->next;
				delete current->data;
				delete current;
				current = temp;
			}
		}

		void insert(unsigned long long key, void* value)
		{
			KeyValuePair* keyValuePair = new KeyValuePair();
			keyValuePair->key = key;
			keyValuePair->value = value;

			Node* node = new Node();
			node->data = keyValuePair;
			node->next = nullptr;
			node->prev = nullptr;

			int hashPosition = key % arraySize;
			Node* head = array[hashPosition];

			if (head)
			{
				Node* current = head;
				while (current->next != nullptr)
				{
					current = current->next;
				}
				
				current->next = node;
				node->prev = current;
			}
			else
			{
				array[hashPosition] = node;
			}

		}

		void* remove(unsigned long long  key)
		{
			int hashPosition = key % arraySize;
			Node* head = array[hashPosition];

			Node* current = head;
			while (current)
			{
				KeyValuePair* keyValuePair = current->data;
				if (keyValuePair->key == key)
				{
					void* value = keyValuePair->value;

					Node* prev = current->prev;
					Node* next = current->next;
					if (prev)
					{
						prev->next = next;
					}
					if (next)
					{
						next->prev = prev;
					}

					if (current = head)
					{
						array[hashPosition] = next;
					}

					delete current->data;
					delete current;
					return value;
				}
				current = current->next;
			}

			return nullptr;
		}

		void* get(unsigned long long  key)
		{
			int hashPosition = key % arraySize;
			Node* head = array[hashPosition];

			Node* current = head;
			while (current)
			{
				KeyValuePair* keyValuePair = current->data;
				if (keyValuePair->key == key)
				{
					return keyValuePair->value;
				}
				current = current->next;
			}

			return nullptr;
		}

		void print()
		{
			printf("---Content of Hash Table---\n");
			for (int i = 0; i < arraySize; i++)
			{
				Node* head = array[i];
				if (head)
				{
					KeyValuePair* keyValuePair = head->data;
					printf("Key: [%d] \n", keyValuePair->key);
				}
				while (head)
				{
					KeyValuePair* keyValuePair = head->data;
					printf("    value: [%d] \n", (unsigned long long)keyValuePair->value);
					head = head->next;
				}
			}
		}
	private:
		int arraySize;
		Node** array;
	};
}