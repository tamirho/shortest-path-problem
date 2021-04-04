#include <iostream>
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"

using namespace std;

int main() {
	Graph* graph = new AdjacencyMatrix(5);

	graph->AddEdge(1, 3, 10);
	graph->AddEdge(1, 5, 10);
	graph->AddEdge(5, 2, 20);
	graph->AddEdge(3, 4, 30);
	graph->AddEdge(4, 2, 40);

	graph->PrintGraph();
	graph->RemoveEdge(3, 4);
	graph->PrintGraph();
	std::cout << endl << "==================================" << endl;
	mySTL::List<Edge> lst = graph->GetAdjList(1);
	for (const auto& edge : lst)
	{
		std::cout << edge.m_Dest << endl;
	}

	delete graph;
	return 0;
}