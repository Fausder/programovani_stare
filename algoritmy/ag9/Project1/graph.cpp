#include "Graph.h"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

void Graph::insert(int id)
{
	this->vertices.push_back(new Vertex(id));
}


Graph::Vertex* Graph::findVertex(int id)
{
	for (auto vertex : this->vertices)
	{
		if (vertex->id == id)
			return vertex;
	}

	return nullptr;
}



void Graph::insert(int id, vector<int> neighborIds)
{
	Vertex* newVertex = new Vertex(id);
	this->vertices.push_back(newVertex);

	for (auto neighborId : neighborIds)
	{
		Vertex* neighbor = findVertex(neighborId);

		if (neighbor)
		{
			newVertex->neighbors.push_back(neighbor);
			if (newVertex != neighbor)
				neighbor->neighbors.push_back(newVertex);
		}
	}

}

void Graph::bfs(int id)
{
	Vertex* startingVertex = findVertex(id);

	queue<Vertex*> que;

	que.push(startingVertex);
	startingVertex->color = 1;

	while (!que.empty())
	{
		Vertex* currentVertex = que.front();
		que.pop();

		cout << currentVertex->id << endl;
		currentVertex->color = 2;

		for (auto neighbor : currentVertex->neighbors)
		{
			if (neighbor->color == 0)
			{
				que.push(neighbor);
				neighbor->color = 1;
			}
		}
	}
}