#include "FordBaseAlgorithm.h"

FordBaseAlgorithm::FordBaseAlgorithm() : m_DistanceFromSrc(nullptr), m_Parent(nullptr), m_NumOfVertices(0) {
}

FordBaseAlgorithm::~FordBaseAlgorithm() {
	ClearData();
}

void FordBaseAlgorithm::ClearData() {
	if (m_DistanceFromSrc) {
		delete[] m_DistanceFromSrc;
		m_DistanceFromSrc = nullptr;
	}

	if (m_Parent) {
		delete[] m_Parent;
		m_Parent = nullptr;
	}
}

void FordBaseAlgorithm::Init(int i_SrcVertex) {
	ClearData();
	m_DistanceFromSrc = new int[m_NumOfVertices + 1];
	m_Parent = new int[m_NumOfVertices + 1];

	for (int i = 0; i < m_NumOfVertices + 1; i++) {
		m_DistanceFromSrc[i] = Nan;
		m_Parent[i] = Nan;
	}

	m_DistanceFromSrc[i_SrcVertex] = 0;
}

