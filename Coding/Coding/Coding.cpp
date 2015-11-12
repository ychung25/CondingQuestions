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

int main()
{
	// [Array and pointer]
	DoArraysAndPointers();

	// [Recursion]
	DoFactorial();
	DoFibonacci();
	DoBinarySearch();
	DoMergeSort();
	DoQuickSort();
	DoPreInPostOrderTraveral();
	DoBreathFirstSearch();
	DoHanoi();
	DoBinaryString();
	DoKString();

	// [Linked List]
	// Becareful with head & tail edge cases
	DoSinglyLinkedList();
	DoDoublyLinkedList();
	DoCircularLinkedList();
	DoXORDoublyLinkedList();

	LinkedListQuestions::DoLinkedListQuestions();

	StackQuestions::DoStackQuestions();

	QueueQuestions::DoQueueQuestions();

	TreeQuestions::DoTreeQuestions();

	return 0;
}

