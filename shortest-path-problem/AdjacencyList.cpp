#include "AdjacencyList.h"

AdjacencyList::AdjacencyList(int i_NumOfVertices) : Graph(i_NumOfVertices), m_AdjList(nullptr) {
    MakeEmptyGraph(i_NumOfVertices);
}

AdjacencyList::AdjacencyList(const AdjacencyList& other) : Graph(other.m_NumOfVertices), m_AdjList(nullptr) {
    *this = other;
}

AdjacencyList::~AdjacencyList() {
    deleteAdjList();
}

const AdjacencyList&  AdjacencyList::operator=(const AdjacencyList& other) {
    if (this != &other) {
        MakeEmptyGraph(other.m_NumOfVertices);
        for (int i = 1; i <= other.m_NumOfVertices; i++) {
            m_AdjList[i] = other.m_AdjList[i];
        }
    }
    
    return *this;
}

void AdjacencyList::MakeEmptyGraph(int i_NumOfVertices) {
    deleteAdjList();
    m_NumOfVertices = i_NumOfVertices;
    m_AdjList = new mySTL::List<Edge>[i_NumOfVertices + 1];
}

bool AdjacencyList::IsAdjacent(int i_Src, int i_Dest) const {
    if (!isValidVertex(i_Src) || !isValidVertex(i_Dest)) {
        throw std::invalid_argument("Invalid vertex number!");
    }
    
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

mySTL::List<Edge> AdjacencyList::GetEdgeList() const {
    mySTL::List<Edge> EdgeList;
    
    for (int i = 1; i <= m_NumOfVertices; i++) {
        for (const auto& edge : m_AdjList[i]) {
            EdgeList.push_back(edge);
        }
    }
    
    return EdgeList;
}


void AdjacencyList::AddEdge(int i_Src, int i_Dest, int i_Weight) {
    
    if (!isValidVertex(i_Src) || !isValidVertex(i_Dest)) {
        throw std::invalid_argument("Invalid vertex number!");
    }
    else if (i_Src == i_Dest) {
        throw std::invalid_argument("A Simple graph cannot contain loop");
    }
    else if (IsAdjacent(i_Src, i_Dest)) {
        throw std::invalid_argument("A Simple graph cannot contain parallel edges");
    }
    
    m_AdjList[i_Src].push_back({ i_Src, i_Dest, i_Weight });
}

void AdjacencyList::RemoveEdge(int i_Src, int i_Dest) {
    if (!IsAdjacent(i_Src, i_Dest)) {
        throw std::invalid_argument("Invalid edge");
    }
    
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

void AdjacencyList::deleteAdjList() {
    delete[] m_AdjList;
    m_AdjList = nullptr;
    m_NumOfVertices = 0;
}

std::string AdjacencyList::GetGraphType() const {
    return "Adjacency";
}
