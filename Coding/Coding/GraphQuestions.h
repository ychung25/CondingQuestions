#pragma once
#include "Queue.h"

namespace GraphQuestions
{
	const int row = 5;
	const int column = 5;

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
	// Application of DFS


	void BFS(int G[], Queue* q, int Visited[])
	{
		int node = (int)q->Deqeue();
		if (Visited[node])
			return;

		printf("Visiting %d\n", node);
		Visited[node] = 1;
		for (int i = 0; i < column; i++)
		{
			if (G[(row*node) + i] && !Visited[i])
			{
				q->Enqueue((void*)i);
			}
		}
		BFS(G, q, Visited);
	}
	// Application of BFS
	void PrintShortestPathFromAToB(int G[], Queue* q, int Visited[], int Prev[], int A, int B)
	{
		int node = (int)q->Deqeue();
		if (node == B)
		{
			int prev = B;
			while (prev != A)
			{
				prev = Prev[node];
				printf("%d -> %d ", node, prev);
				node = prev;
			}
		}

		if (Visited[node])
			return;

		Visited[node] = 1;
		for (int i = 0; i < column; i++)
		{
			if (G[(row*node) + i] && !Visited[i])
			{
				if(Prev[i] == i)
					Prev[i] = node;
				q->Enqueue((void*)i);
			}
		}
		PrintShortestPathFromAToB(G, q, Visited, Prev, A, B);
	}

	void DoGraphQuestions()
	{
		const int row = 5;
		const int column = 5;
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
		DFS(G, 0, Visited);
		printf("");

		Queue q;
		for (int i = 0; i < 5; i++)
		{
			Visited[i] = 0;
		}
		q.Enqueue((void*)0);
		printf("---BFS Traversal of Graph---\n");
		BFS(G, &q, Visited);
		printf("");


		{
			const int row = 5;
			const int column = 5;
			int G[row * column];
			for (int i = 0; i < row * column; i++)
			{
				G[i] = 0;
			}

			G[(row * 0) + 1] = 1;
			G[(row * 0) + 4] = 1;
			G[(row * 0) + 2] = 1;
			G[(row * 1) + 3] = 1;
			G[(row * 2) + 4] = 1;
			G[(row * 3) + 4] = 1;

			int Visited[] = { 0, 0, 0, 0, 0 };
			int Prev[] = { 0, 1, 2, 3, 4};

			Queue q;
			q.Enqueue((void*)0);
			printf("---Shortest path from 0 to 4---\n");
			PrintShortestPathFromAToB(G, &q, Visited, Prev, 0, 4);
			printf("");
		}

		
	}
}