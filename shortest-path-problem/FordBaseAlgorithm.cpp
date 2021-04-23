#include "FordBaseAlgorithm.h"

const float FordBaseAlgorithm::Nan = FLT_MIN;
const int FordBaseAlgorithm::NULL_PARENT = -1;

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

	float result = m_DistanceFromSrc[i_Target];
	if (result == Nan) {
		std::string msg = "No path from " + std::to_string(m_SrcVertex) + " to " + std::to_string(i_Target);
		throw std::exception(msg.c_str());
	}
    
    return result;
}

std::string FordBaseAlgorithm::GetWeightOfShortestPathToTargetAsString(int i_Target) const {
	std::string result = "";
	
	try {
		result = std::to_string(GetWeightOfShortestPathToTarget(i_Target));
	}
	catch (const std::runtime_error& error) {
		throw;
	}
	catch (const std::exception& error) {
		result = error.what();
	}

	return result;
}
