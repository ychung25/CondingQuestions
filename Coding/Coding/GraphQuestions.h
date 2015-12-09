#pragma once
#include "Queue.h"

namespace GraphQuestions
{
	const int row = 5;
	const int column = 5;

	// You must put the starting node in Queue and mark its Visited as 1.
	void DFS(int G[], int node, int Visited[])
	{
		Visited[node] = 1;
		printf("Visiting %d\n", node);
		for (int i = 0; i < column; i++)
		{
			if (G[(row*node) + i] && !Visited[i])
			{
				DFS(G, i, Visited);
			}
		}
	}

	// You must put the starting node in Queue and mark its distance as 0.
	void BFS(int G[], Queue* q, int Distances[], int Parents[])
	{
		if (q->Size() == 0)
			return;

		int node = (int)q->Deqeue();
		printf("Visiting %d\n", node);

		for (int i = 0; i < column; i++)
		{
			if (G[(row*node) + i] && (Distances[i] == -1))
			{
				Distances[i] = Distances[node] + 1;
				Parents[i] = node;
				q->Enqueue((void*)i);
			}
		}
		BFS(G, q, Distances, Parents);
	}

	void DoGraphQuestions()
	{
		{
			int G[row * column];
			for (int i = 0; i < row * column; i++)
			{
				G[i] = 0;
			}

			G[(row * 0) + 1] = 1;
			G[(row * 0) + 4] = 1;
			G[(row * 1) + 3] = 1;
			G[(row * 2) + 3] = 1;
			G[(row * 2) + 4] = 1;
			G[(row * 3) + 2] = 1;
			G[(row * 4) + 1] = 1;

			int Visited[] = { 0, 0, 0, 0, 0 };

			printf("---DFS Traversal of Graph---\n");
			Visited[0] = 1;
			DFS(G, 0, Visited);
			printf("");
		}
		{
			int G[row * column];
			for (int i = 0; i < row * column; i++)
			{
				G[i] = 0;
			}

			G[(row * 0) + 1] = 1;
			G[(row * 0) + 4] = 1;
			G[(row * 1) + 3] = 1;
			G[(row * 2) + 3] = 1;
			G[(row * 2) + 4] = 1;
			G[(row * 3) + 2] = 1;
			G[(row * 4) + 1] = 1;

			int Parents[] = { 0,0,0,0,0 };
			int Distances[] = { -1,-1,-1,-1,-1 };

			Queue q;
			int startingNode = 0;
			q.Enqueue((void*)startingNode);
			Parents[startingNode] = -1;
			Distances[startingNode] = 0;

			printf("---BFS Traversal of Graph---\n");
			BFS(G, &q, Distances, Parents);
			printf("");
		}
	}
}