#include <iostream>
#include <list>
#include <iterator>

using namespace std;

void DFSRecursion(int start, bool visited[], list<int>* edges)
{
	visited[start] = true;

	for(list<int>::iterator pointer = edges[start].begin(); pointer != edges[start].end(); pointer++)
	{		
		if(visited[*pointer] == false)
		{
			DFSRecursion(*pointer, visited, edges);
		}
	}
}

int DFS(int start, int end, int numberOfVertices, list<int>* edges)
{
	bool *visited = new bool[numberOfVertices + 1];

	for(int i = 1; i <= numberOfVertices; i++)
	{
		visited[i] = false;
	}

	DFSRecursion(start, visited, edges);

	if(visited[end] == true)
	{
		delete [] visited;
		visited = NULL;
		return 0;
	}
	else
	{
		delete [] visited;
		visited = NULL;
		return 1;
	}
}

int main()
{
	int numberOfVertices, numberOfComparisons, node1, node2, start, end, output1, output2;

	cin >> numberOfVertices >> numberOfComparisons;

	list<int>* edges = new list<int>[numberOfVertices + 1];

	for(int i = 1; i <= numberOfComparisons; i++)
	{
		cin >> node1 >> node2;
		edges[node1].push_back(node2);

	}

	cin >> start >> end;

	output1 = DFS(start, end, numberOfVertices, edges);

	if(output1 == 0)
	{
		cout << "yes" << endl;
	}
	else
	{
		output2 = DFS(end, start, numberOfVertices, edges);

		if(output2 == 0)
		{
			cout << "no" << endl;
		}
		else if(output2 == 1)
		{
			cout << "unknown" << endl;
		}
	}

	delete [] edges;
	edges = NULL;

	return 0;
}