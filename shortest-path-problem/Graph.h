#pragma once
#include <fstream>
#include "List.h"

struct Edge {
	int m_Src, m_Dest, m_Weight;
};

class Graph {
public:
	Graph() = default;
	virtual ~Graph() = default;
    
	virtual void MakeEmptyGraph(int i_NumOfVertices) = 0;
	virtual bool IsAdjacent(int i_Src, int i_Dest) const = 0;
	virtual mySTL::List<Edge> GetAdjList(int i_Src) const = 0;
	virtual void AddEdge(int i_Src, int i_Dest, int i_Weight) = 0;
	virtual void RemoveEdge(int i_Src, int i_Dest) = 0;
	virtual int getNumOfVertices() const = 0;
	virtual void PrintGraph() const = 0;

	static const int EMPTY = -1;
};

