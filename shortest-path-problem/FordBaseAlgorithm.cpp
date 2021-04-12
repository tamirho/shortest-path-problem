#include "FordBaseAlgorithm.h"

FordBaseAlgorithm::FordBaseAlgorithm() : m_DistanceFromSrc(nullptr), m_Parent(nullptr) {
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
