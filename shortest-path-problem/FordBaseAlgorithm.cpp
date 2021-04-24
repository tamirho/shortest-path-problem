#include "FordBaseAlgorithm.h"

const float FordBaseAlgorithm::Nan = -1;
const int FordBaseAlgorithm::NULL_PARENT = -2;

FordBaseAlgorithm::FordBaseAlgorithm() : m_DistanceFromSrc(nullptr), m_Parent(nullptr), m_NumOfVertices(0), m_SrcVertex(0) {
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
    m_DistanceFromSrc = new float[m_NumOfVertices + 1];
    m_Parent = new int[m_NumOfVertices + 1];
    
    for (int i = 0; i < m_NumOfVertices + 1; i++) {
        m_DistanceFromSrc[i] = Nan;
        m_Parent[i] = NULL_PARENT;
    }
    
    m_DistanceFromSrc[i_SrcVertex] = 0;
}

float FordBaseAlgorithm::GetWeightOfShortestPathToTarget(int i_Target) const {
    if (m_DistanceFromSrc == nullptr) {
        throw std::runtime_error("Error: can't calculate weight before using Process method!");
    }
	else if (i_Target <= 0 || i_Target > m_NumOfVertices) {
		throw std::invalid_argument("Error: Invalid target vertex");
	}

    return m_DistanceFromSrc[i_Target];
}

std::string FordBaseAlgorithm::GetWeightOfShortestPathToTargetAsString(int i_Target) const {
	std::string result = "";
    float weight = GetWeightOfShortestPathToTarget(i_Target);
    
    if (weight == Nan) {
        result = "No path from " + std::to_string(m_SrcVertex) + " to " + std::to_string(i_Target);
    }
    else {
        result = std::to_string(weight);
    }

	return result;
}
