#include "BellmanFord.h"
using namespace mySTL;


BellmanFord::~BellmanFord() {
    
    if (m_DistanceFromSrc) {
        delete[] m_DistanceFromSrc;
    }
    
    if (m_Parent) {
        delete[] m_Parent;
    }
}

bool BellmanFord::Process(const Graph& i_Grpah, int i_SrcVertex) {
    int numOfVertices = i_Grpah.getNumOfVertices();
    
    Init(numOfVertices, i_SrcVertex);
    List<Edge> edgeList = i_Grpah.GetEdgeList();
    
    for (int i = 1; i < numOfVertices; i++) {
        for (const auto& edge : edgeList) {
            Relax(edge.m_Src, edge.m_Dest, edge.m_Weight);
        }
    }
    
    for (const auto& edge : edgeList) {
        if (m_DistanceFromSrc[edge.m_Dest] > m_DistanceFromSrc[edge.m_Src] + edge.m_Weight) {
            return false;
        }
    }
    
    return true;
}

void BellmanFord::Init(int i_NumOfVertices, int i_SrcVertex) {
    m_DistanceFromSrc = new int(i_NumOfVertices + 1);
    m_Parent = new int(i_NumOfVertices + 1);
    
    for (int i = 0; i < i_NumOfVertices + 1; i++) {
        m_DistanceFromSrc[i] = NAN;
        m_Parent[i] = NAN;
    }
    
    m_DistanceFromSrc[i_SrcVertex] = 0;
}


void BellmanFord::Relax(int i_Src, int i_Dest, int i_Weight) {
    
    if (m_DistanceFromSrc[i_Src] != NAN)
    {
        if (m_DistanceFromSrc[i_Dest] == NAN || m_DistanceFromSrc[i_Dest] > m_DistanceFromSrc[i_Src] + i_Weight) {
            m_DistanceFromSrc[i_Dest] = m_DistanceFromSrc[i_Src] + i_Weight;
            m_Parent[i_Dest] = i_Src;
        }
    }
}

std::string BellmanFord::GetAlgorithmName() const {
    return "Bellman Ford";
}
