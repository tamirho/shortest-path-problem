#include "Dijkstra.h"

Dijkstra::Dijkstra(PriorityQueue& i_PriorityQueue) : m_PriorityQueue(i_PriorityQueue){
}

void Dijkstra::Process(const Graph& i_Grpah, int i_SrcVertex) {
    m_NumOfVertices = i_Grpah.GetNumOfVertices();
	m_SrcVertex = i_SrcVertex;
    Init(m_SrcVertex);
    
    m_PriorityQueue.Build(m_DistanceFromSrc, m_NumOfVertices);
    
    while (!m_PriorityQueue.IsEmpty())
    {
        int currentVertex = m_PriorityQueue.DeleteMin();
        
        auto currentVertexAdjList = i_Grpah.GetAdjList(currentVertex);
        for (const auto& edge : currentVertexAdjList) {
            Relax(edge.m_Src, edge.m_Dest, edge.m_Weight);
        }
    }
}

void Dijkstra::Relax(int i_Src, int i_Dest, float i_Weight) {
    if (m_DistanceFromSrc[i_Src] != Nan)
    {
        if (m_DistanceFromSrc[i_Dest] == Nan || m_DistanceFromSrc[i_Dest] > m_DistanceFromSrc[i_Src] + i_Weight) {
            m_DistanceFromSrc[i_Dest] = m_DistanceFromSrc[i_Src] + i_Weight;
            m_Parent[i_Dest] = i_Src;
            m_PriorityQueue.DecreaseKey(i_Dest, m_DistanceFromSrc[i_Dest]);
        }
    }
}

std::string Dijkstra::GetAlgorithmName() const {
    return "Dijkstra " + m_PriorityQueue.GetPriorityQueueName();
}


