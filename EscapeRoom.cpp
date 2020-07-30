#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <utility>
#include <cmath>

using namespace std;

vector<pair<int, int>> findConnections(int M, int N, int value)
{
	vector<pair<int, int>> points;
	float root = sqrt(value);

	for(int number = 1; number <= root; number++)
	{
		if(value % number == 0)
		{
		    int other = value / number, first = number - 1, second = other - 1;
		    
		    if(number <= M && other <= N)
		    {
		        points.push_back(make_pair(first, second));
		    }
		    if(other <= M && number <= N)
		    {
		        points.push_back(make_pair(second, first));
		    }
		}
	}

	return points;
}

bool BFS(int M, int N, vector<int> maze)
{
	int startingValue = maze[0], finalIndex = M * N;
	unordered_set<int> visitedSet;
	queue<int> queueStructure;
	visitedSet.insert(startingValue);
	queueStructure.push(startingValue);

	while(queueStructure.empty() == false)
	{
		int currentValue = queueStructure.front();
		queueStructure.pop();
		if(finalIndex == currentValue)
		{
			return true;
		}
		
		vector<pair<int, int>> adjacentPoints = findConnections(M, N, currentValue);
		unsigned int adjacentPointsSize = adjacentPoints.size();
		for(unsigned int counter = 0; counter < adjacentPointsSize; counter++)
		{
			pair<int, int> adjacentPoint = adjacentPoints.at(counter);
			int adjacentValue = maze[(adjacentPoint.first * N) + adjacentPoint.second];
			if(visitedSet.find(adjacentValue) == visitedSet.end())
			{
			    if(finalIndex == adjacentValue)
			    {
			        return true;
			    }
				queueStructure.push(adjacentValue);
				visitedSet.insert(adjacentValue);
			}
		}	
	}

	return false;
}

int main()
{
	int M, N, value;
	cin >> M >> N;
	vector<int> maze(M * N, 0);

	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cin >> value;
			maze[(i * N) + j] = value;
		}
	}

	if(BFS(M, N, maze) == true)
	{
		cout << "yes" << endl;
	}
	else
	{
		cout << "no" << endl;
	}
	
	return 0;
}