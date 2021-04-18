#pragma once
#include "List.h"

/*
	A struct to represent a directed edge in a graph.
	Each edge consists of source and destination vertices and its weight.
*/
struct Edge {
	int m_Src, m_Dest, m_Weight;
};

/*
	An abstract class representing a directed graph
 */
class Graph {
protected:
    int m_NumOfVertices;
    
    // check if the vertex number is valid with respect to the num of vertices in the graph
    bool isValidVertex(int i_VertexNum) const { return i_VertexNum > 0 && i_VertexNum <= m_NumOfVertices; }
	// A special value to represent an undefined edge.
	static const int EMPTY = -1;

public:
    Graph(int i_NumOfVertices) { m_NumOfVertices = i_NumOfVertices; }
	virtual ~Graph() = default;
    
	virtual void MakeEmptyGraph(int i_NumOfVertices) = 0;

	/*
		Input: Two vertices (source and destination).
		Output: True if there is an edge in the graph from source to destination. Otherwise false.
	*/
	virtual bool IsAdjacent(int i_Src, int i_Dest) const = 0;

	/*
		Input: A vertex.
		Output: An adjacency list describes the set of neighbors of a particular vertex in the graph.
	*/
	virtual mySTL::List<Edge> GetAdjList(int i_Src) const = 0;

	/*
		Input: None.
		Output: A list of all the edges in the graph.
	*/
    virtual mySTL::List<Edge> GetEdgeList() const = 0;


    virtual void AddEdge(const Edge& i_Edge) { AddEdge(i_Edge.m_Src, i_Edge.m_Dest, i_Edge.m_Weight); }
	virtual void AddEdge(int i_Src, int i_Dest, int i_Weight) = 0;
	virtual void RemoveEdge(int i_Src, int i_Dest) = 0;
	virtual int getNumOfVertices() const = 0;
	virtual void PrintGraph() const = 0;
    virtual std::string GetGraphType() const = 0;
    int GetNumOfVertices() const { return m_NumOfVertices; }
};

