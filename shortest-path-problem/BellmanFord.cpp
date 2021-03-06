#include "BellmanFord.h"

BellmanFord::~BellmanFord() {
}

void BellmanFord::Process(const Graph& i_Grpah, int i_SrcVertex) {
    m_NumOfVertices = i_Grpah.GetNumOfVertices();
	m_SrcVertex = i_SrcVertex;

    Init(m_SrcVertex);
    mySTL::List<Edge> edgeList = i_Grpah.GetEdgeList();
    
    for (int i = 1; i < m_NumOfVertices; i++) {
        for (const auto& edge : edgeList) {
            Relax(edge.m_Src, edge.m_Dest, edge.m_Weight);
        }
    }
    
    for (const auto& edge : edgeList) {
        if (m_DistanceFromSrc[edge.m_Src] != Nan) { // check if there is path to source
            if (m_DistanceFromSrc[edge.m_Dest] > m_DistanceFromSrc[edge.m_Src] + edge.m_Weight) {
                throw std::runtime_error("Negative cycle!");
            }
        }
    }
}

void BellmanFord::Relax(int i_Src, int i_Dest, float i_Weight) {
    
    if (m_DistanceFromSrc[i_Src] != Nan)
    {
        if (m_DistanceFromSrc[i_Dest] == Nan || m_DistanceFromSrc[i_Dest] > m_DistanceFromSrc[i_Src] + i_Weight) {
            m_DistanceFromSrc[i_Dest] = m_DistanceFromSrc[i_Src] + i_Weight;
            m_Parent[i_Dest] = i_Src;
        }
    }
}

std::string BellmanFord::GetAlgorithmName() const {
    return "Bellman Ford";
}
