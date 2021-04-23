#include <iostream>
#include "AdjacencyMatrix.h"

const float AdjacencyMatrix::EMPTY = -1;

AdjacencyMatrix::AdjacencyMatrix(int i_NumOfVertices) : Graph(i_NumOfVertices), m_Matrix(nullptr){
    MakeEmptyGraph(i_NumOfVertices);
}

AdjacencyMatrix::~AdjacencyMatrix() {
    deleteMatrix();
}

AdjacencyMatrix::AdjacencyMatrix(const AdjacencyMatrix& other) : Graph(other.m_NumOfVertices), m_Matrix(nullptr){
    *this = other;
}

void AdjacencyMatrix::deleteMatrix() {
    if (m_Matrix) {
        for (int i = 0; i < m_NumOfVertices; i++) {
            delete[] m_Matrix[i];
        }
        delete[] m_Matrix;
        m_NumOfVertices = 0;
    }
    
    m_Matrix = nullptr;
}

void AdjacencyMatrix::MakeEmptyGraph(int i_NumOfVertices) {
    deleteMatrix();
    
    m_NumOfVertices = i_NumOfVertices;
    m_Matrix = new float*[i_NumOfVertices];
    
    for (int i = 0; i < m_NumOfVertices; i++)
    {
        m_Matrix[i] = new float[m_NumOfVertices];
        for (int j = 0; j < m_NumOfVertices; j++)
        {
            m_Matrix[i][j] = AdjacencyMatrix::EMPTY;
        }
    }
}
bool AdjacencyMatrix::IsAdjacent(int i_Src, int i_Dest) const {
    if (!IsValidVertex(i_Src) || !IsValidVertex(i_Dest)) {
        throw std::invalid_argument("Invalid vertex number!");
    }
    
    return m_Matrix[i_Src - 1][i_Dest - 1] != AdjacencyMatrix::EMPTY;
}

mySTL::List<Edge> AdjacencyMatrix::GetAdjList(int i_Src) const {
    mySTL::List<Edge> adjList;
    
    if (!IsValidVertex(i_Src)) {
        throw std::invalid_argument("Invalid vertex number!");
    }
    
    for (int i = 0; i < m_NumOfVertices; i++) {
        if (m_Matrix[i_Src - 1][i] != AdjacencyMatrix::EMPTY) {
            adjList.push_back({ i_Src, i + 1, m_Matrix[i_Src - 1][i] });
        }
    }
    return adjList;
}

mySTL::List<Edge> AdjacencyMatrix::GetEdgeList() const {
    mySTL::List<Edge> EdgeList;
    
    for (int i = 0; i < m_NumOfVertices; i++) {
        for (int j = 0; j< m_NumOfVertices; j++) {
            if (m_Matrix[i][j] != AdjacencyMatrix::EMPTY) {
                EdgeList.push_back({i + 1, j + 1, m_Matrix[i][j]});
            }
        }
    }
    
    return EdgeList;
}


void AdjacencyMatrix::AddEdge(int i_Src, int i_Dest, float i_Weight) {
    
    if (!IsValidVertex(i_Src) || !IsValidVertex(i_Dest)) {
        throw std::invalid_argument("Invalid vertex number!");
    }
    else if (i_Src == i_Dest) {
        throw std::invalid_argument("A Simple graph cannot contain loop");
    }
    else if (IsAdjacent(i_Src, i_Dest)) {
        throw std::invalid_argument("A Simple graph cannot contain parallel edges");
    }
    
    m_Matrix[i_Src - 1][i_Dest - 1] = i_Weight;
}

void AdjacencyMatrix::RemoveEdge(int i_Src, int i_Dest) {
    if (!IsAdjacent(i_Src, i_Dest)) {
        throw std::invalid_argument("Invalid edge");
    }
    m_Matrix[i_Src - 1][i_Dest - 1] = AdjacencyMatrix::EMPTY;
}

void AdjacencyMatrix::PrintGraph() const {
    for (int i = 0; i < m_NumOfVertices; i++)
    {
        std::cout << i + 1 << " | ";
        for (int j = 0; j < m_NumOfVertices; j++) {
            if (m_Matrix[i][j] != AdjacencyMatrix::EMPTY) {
                std::cout << "(" << j + 1 << ", " << m_Matrix[i][j] << " ) , ";
            }
        }
        std::cout << std::endl;
    }
}

const AdjacencyMatrix& AdjacencyMatrix::operator=(const AdjacencyMatrix& other) {
    if (this != &other) {
        MakeEmptyGraph(other.m_NumOfVertices);
        for (int i = 0; i < other.m_NumOfVertices; i++)
        {
            for (int j = 0; j < other.m_NumOfVertices; j++) {
                m_Matrix[i][j] = other.m_Matrix[i][j];
            }
        }
    }
    
    return *this;
}

std::string AdjacencyMatrix::GetGraphType() const {
    return "Matrix";
}
