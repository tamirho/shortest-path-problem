#include "AdjacencyList.h"

AdjacencyList::AdjacencyList(int i_NumOfVertices){
	MakeEmptyGraph(i_NumOfVertices);
}
AdjacencyList::~AdjacencyList() {
	delete[] m_AdjList;
}

void AdjacencyList::MakeEmptyGraph(int i_NumOfVertices) {
	delete[] m_AdjList;
	m_NumOfVertices = i_NumOfVertices;
	m_AdjList = new mySTL::List<Edge>[i_NumOfVertices + 1];
}

bool AdjacencyList::IsAdjacent(int i_Src, int i_Dest) const {
	for (const auto& edge : m_AdjList[i_Src]) {
		if (edge.m_Dest == i_Dest) {
			return true;
		}
	}

	return false;
}

mySTL::List<Edge> AdjacencyList::GetAdjList(int i_Src) const {
	return m_AdjList[i_Src];
}

void AdjacencyList::AddEdge(int i_Src, int i_Dest, int i_Weight) {
	if (i_Weight < 0) {
		throw std::invalid_argument("Invalid weight");
	}
	if (i_Src == i_Dest) {
		throw std::invalid_argument("A Simple graph cannot contain loop");
	}
	if (IsAdjacent(i_Src, i_Dest)) {
		throw std::invalid_argument("A Simple graph cannot contain parallel edges");
	}
	
	m_AdjList[i_Src].push_back({ i_Src, i_Dest, i_Weight });
}

void AdjacencyList::RemoveEdge(int i_Src, int i_Dest) {
	bool found = false;
	auto iter = m_AdjList[i_Src].begin();
	for (; iter != m_AdjList[i_Src].end() && !found; ++iter) {
		if ((*iter).m_Dest == i_Dest) {
			m_AdjList[i_Src].erase(iter);
			found = true;
		}
	}
	if (!found) {
		throw std::invalid_argument("Invalid edge");
	}
}


void AdjacencyList::PrintGraph() const{
	for (int i = 1; i <= m_NumOfVertices; i++)
	{
		std::cout << i << " | ";
		for (const auto& edge : m_AdjList[i]) {
			std::cout << "(" << edge.m_Dest << ", " <<edge.m_Weight << " ) , ";
		}
		std::cout << std::endl;
	}
}