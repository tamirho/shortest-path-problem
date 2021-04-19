#pragma once
#include <string>
#include "Graph.h"

/*
 This class is a base for ford algorithems which use relaxion process.
 After using Process method, the class contains:
 m_DistanceFromSrc - the distance of the weighted path to each vertex in the graph, starting from source
 m_Parent - parent array of to lightest path tree,
 where m_Parent[i] is the parent of the i'th vertex in the lightest path to vertex i
 */
class FordBaseAlgorithm {
    
protected:
    static const int Nan = INT_MIN;
    int* m_DistanceFromSrc;
    int* m_Parent;
    int	 m_NumOfVertices;
    
    virtual void Init(int i_SrcVertex);
    virtual void Relax(int i_Src, int i_Dest, int i_Weight) = 0;
    virtual void ClearData();
public:
    FordBaseAlgorithm();
    virtual ~FordBaseAlgorithm();
    
    virtual std::string GetAlgorithmName() const = 0;
    
    /*
     This functions should evaluate the distances to each vertex in the graph and save it in m_DistanceFromSrc,
     using each of the algorithems logic.
     */
    virtual void Process(const Graph& i_Grpah, int i_SrcVertex) = 0;
    
    /*
     This method returns the lightes path from i_Src to i_Target
     Inputs: i_Target - int (represent vertex)
     Output: weight of shortest path - int (where MIN_INT represent that there is no path to target)
     */
    virtual int GetWeightOfShortestPathToTarget(int i_Target) const;
    
};
