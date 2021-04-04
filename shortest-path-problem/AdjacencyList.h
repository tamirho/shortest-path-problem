#pragma once
#include "Graph.h"

class AdjacencyList : public Graph
{
private:
	mySTL::List<Edge>*  m_AdjList;
	int m_NumOfVertices;

public:
	AdjacencyList(int i_NumOfVertices = 0);
	~AdjacencyList();

	virtual void MakeEmptyGraph(int i_NumOfVertices = 0);
	virtual bool IsAdjacent(int i_Src, int i_Dest) const;
	virtual mySTL::List<Edge> GetAdjList(int i_Src) const;
	virtual void AddEdge(int i_Src, int i_Dest, int i_Weight);
	virtual void RemoveEdge(int i_Src, int i_Dest);
	virtual int getNumOfVertices() const { return m_NumOfVertices; };
	virtual void PrintGraph() const;
};

