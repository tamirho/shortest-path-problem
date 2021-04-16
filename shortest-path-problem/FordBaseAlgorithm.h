#pragma once
#include <string>
#include "Graph.h"

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
    virtual void Process(const Graph& i_Grpah, int i_SrcVertex) = 0;
    virtual int GetWeightOfShortestPathToTarget(int i_Target) const { return m_DistanceFromSrc[i_Target]; }
    
};
