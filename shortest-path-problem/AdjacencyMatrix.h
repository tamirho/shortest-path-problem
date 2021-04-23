#pragma once
#include "Graph.h"

/*
 A class that represents a finite graph consisting of neighboring matrix.
 m_Matrix[i][j] = if 'EMPTY' - there is no edge from i to j
 else the weight of the edge from i to j
 */
class AdjacencyMatrix : public Graph
{
private:
    float** m_Matrix;
    void deleteMatrix();

	// A special value to represent an undefined edge.
	static const float EMPTY;
    
public:
    AdjacencyMatrix(int i_NumOfVertices = 0);
    AdjacencyMatrix(const AdjacencyMatrix& other);
    ~AdjacencyMatrix();
    
    const AdjacencyMatrix& operator=(const AdjacencyMatrix& other);
    virtual void MakeEmptyGraph(int i_NumOfVertices = 0) override;
    virtual bool IsAdjacent(int i_Src, int i_Dest) const override;
    virtual mySTL::List<Edge> GetAdjList(int i_Src) const override;
    virtual mySTL::List<Edge> GetEdgeList() const override;
    virtual void AddEdge(int i_Src, int i_Dest, float i_Weight) override;
    virtual void RemoveEdge(int i_Src, int i_Dest) override;
    virtual void PrintGraph() const override;
    virtual std::string GetGraphType() const override;
};

