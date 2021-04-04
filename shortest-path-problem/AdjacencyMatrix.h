#pragma once
#include "Graph.h"

class AdjacencyMatrix : public Graph
{
private:
	int** m_Matrix;
	int m_NumOfVertices;

	void deleteMatrix();

public:
	AdjacencyMatrix(int i_NumOfVertices = 0);
	~AdjacencyMatrix();

	virtual void MakeEmptyGraph(int i_NumOfVertices = 0);
	virtual bool IsAdjacent(int i_Src, int i_Dest) const;
	virtual mySTL::List<Edge> GetAdjList(int i_Src) const;					 // TODO: implemntation
	virtual void AddEdge(int i_Src, int i_Dest, int i_Weight);
	virtual void RemoveEdge(int i_Src, int i_Dest);
	virtual int getNumOfVertices() const { return m_NumOfVertices; };
	virtual void PrintGraph() const;
};

