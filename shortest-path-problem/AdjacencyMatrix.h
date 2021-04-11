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
    AdjacencyMatrix(const AdjacencyMatrix& other);
	~AdjacencyMatrix();
    
    const AdjacencyMatrix& operator=(const AdjacencyMatrix& other);
	virtual void MakeEmptyGraph(int i_NumOfVertices = 0) override;
	virtual bool IsAdjacent(int i_Src, int i_Dest) const override;
	virtual mySTL::List<Edge> GetAdjList(int i_Src) const override;
    virtual mySTL::List<Edge> GetEdgeList() const override;
	virtual void AddEdge(int i_Src, int i_Dest, int i_Weight) override;
	virtual void RemoveEdge(int i_Src, int i_Dest) override;
	virtual int getNumOfVertices() const override { return m_NumOfVertices; };
	virtual void PrintGraph() const override;
    const std::string GetGraphType() const override;

    
};

