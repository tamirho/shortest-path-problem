#pragma once
#include "Graph.h"


/*
	A class that represents a finite graph consisting of neighboring lists.
	Each list describes the set of neighbors of a particular vertex.
*/
class AdjacencyList : public Graph
{

private:
	mySTL::List<Edge>*  m_AdjList;
	int m_NumOfVertices;

    void deleteAdjList();

public:
	AdjacencyList(int i_NumOfVertices = 0);
    AdjacencyList(const AdjacencyList& other);
	~AdjacencyList();

    const AdjacencyList& operator=(const AdjacencyList& other);
	virtual void MakeEmptyGraph(int i_NumOfVertices = 0) override;
	virtual bool IsAdjacent(int i_Src, int i_Dest) const override;
	virtual mySTL::List<Edge> GetAdjList(int i_Src) const override;
    virtual mySTL::List<Edge> GetEdgeList() const override;
	virtual void AddEdge(int i_Src, int i_Dest, int i_Weight) override;
	virtual void RemoveEdge(int i_Src, int i_Dest) override;
	virtual int getNumOfVertices() const override { return m_NumOfVertices; };
	virtual void PrintGraph() const override;
    virtual std::string GetGraphType() const override;

};

