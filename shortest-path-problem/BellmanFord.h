#pragma once
#include "Graph.h"

class BellmanFord {
private:
    int* m_DistanceFromSrc;
    int* m_Parent;
    static const int NAN = INT_MIN;
    
    void Init(int i_NumOfVertices, int i_SrcVertex);
    void Relax(int i_Src, int i_Dest, int i_Weight);
public:
    BellmanFord();
    ~BellmanFord();

    bool Process(const Graph& i_Grpah, int i_SrcVertex);
    int GetWeightOfShortestPathToTarget(int i_Target) const { return m_DistanceFromSrc[i_Target]; }
};
