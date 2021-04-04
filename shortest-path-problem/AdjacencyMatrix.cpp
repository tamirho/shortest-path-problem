#include "AdjacencyMatrix.h"
#include <iostream>

AdjacencyMatrix::AdjacencyMatrix(int i_NumOfVertices){
	MakeEmptyGraph(i_NumOfVertices);
}

AdjacencyMatrix::~AdjacencyMatrix() {
	deleteMatrix();
}

void AdjacencyMatrix::deleteMatrix() {
	if (m_Matrix) {
		for (int i = 0; i < m_NumOfVertices; i++) {
			delete[] m_Matrix[i];
		}
		delete[] m_Matrix;
		m_NumOfVertices = 0;
	}
}

void AdjacencyMatrix::MakeEmptyGraph(int i_NumOfVertices) {
	deleteMatrix();

	m_Matrix = new int*[i_NumOfVertices];
	m_NumOfVertices = i_NumOfVertices;
	for (int i = 0; i < m_NumOfVertices; i++)
	{
		m_Matrix[i] = new int[m_NumOfVertices];
		for (int j = 0; j < m_NumOfVertices; j++)
		{
			m_Matrix[i][j] = Graph::EMPTY;
		}
	}
}
bool AdjacencyMatrix::IsAdjacent(int i_Src, int i_Dest) const {
	return m_Matrix[i_Src - 1][i_Dest - 1] != Graph::EMPTY;
}
mySTL::List<Edge> AdjacencyMatrix::GetAdjList(int i_Src) const {
	mySTL::List<Edge> adjList;
	for (int i = 0; i < m_NumOfVertices; i++) {
		if (m_Matrix[i_Src - 1][i] != Graph::EMPTY) {
			adjList.push_back({ i_Src, i + 1, m_Matrix[i_Src - 1][i] });
		}
	}
	return adjList;
}
void AdjacencyMatrix::AddEdge(int i_Src, int i_Dest, int i_Weight) {
	if (i_Weight < 0) {
		throw std::invalid_argument("Invalid weight");
	}
	if (i_Src == i_Dest) {
		throw std::invalid_argument("A Simple graph cannot contain loop");
	}
	if (IsAdjacent(i_Src, i_Dest)) {
		throw std::invalid_argument("A Simple graph cannot contain parallel edges");
	}

	m_Matrix[i_Src - 1][i_Dest - 1] = i_Weight;
}
void AdjacencyMatrix::RemoveEdge(int i_Src, int i_Dest) {
	if (!IsAdjacent(i_Src, i_Dest)) {
		throw std::invalid_argument("Invalid edge");
	}
	m_Matrix[i_Src - 1][i_Dest - 1] = Graph::EMPTY;
}

void AdjacencyMatrix::PrintGraph() const {
	for (int i = 0; i < m_NumOfVertices; i++)
	{
		std::cout << i + 1 << " | ";
		for (int j = 0; j < m_NumOfVertices; j++) {
			if (m_Matrix[i][j] != Graph::EMPTY) {
				std::cout << "(" << j + 1 << ", " << m_Matrix[i][j] << " ) , ";
			}
		}
		std::cout << std::endl;
	}
}
