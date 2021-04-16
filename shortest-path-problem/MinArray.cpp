#include "MinArray.h"
MinArray::MinArray() : m_Data(nullptr), m_Flags(nullptr), m_MaxSize(0), m_QueueSize(0){
}

MinArray::~MinArray() {
	if (m_Data != nullptr) {
		delete[] m_Data;
	}

	if (m_Flags != nullptr) {
		delete[] m_Flags;
	}

	m_Data = nullptr;
	m_Flags = nullptr;
}

void MinArray::Build(int* i_InitArray, int i_NumOfVertices) {
	m_Data = new Pair[i_NumOfVertices + 1];
	m_Flags = new bool[i_NumOfVertices + 1];
	m_MaxSize = i_NumOfVertices + 1;
	m_QueueSize = i_NumOfVertices;

	for (int i = 0; i <= i_NumOfVertices; i++) {
		m_Data[i].m_Vertex = i;
		m_Data[i].m_Key = i_InitArray[i];
		m_Flags[i] = (i != 0);
	}
}

void MinArray::DecreaseKey(int i_Vertex, int i_NewKey) {
	if (i_Vertex > m_MaxSize || i_Vertex < 0 || m_Flags[i_Vertex] == false) {
		throw std::runtime_error("Invalid operation");
	}
	m_Data[i_Vertex].m_Key = i_NewKey;
}

int MinArray::DeleteMin() {
	if (IsEmpty()) {
		throw std::runtime_error("Invalid operation");
	}
	
	int minIndex = 0;
	for (int i = 1; i < m_MaxSize; i++) {
		if (m_Flags[i] == true && (minIndex == 0 || comparePriorityDeleteMin(i, minIndex))) {
			minIndex = i;
		}
	}

	m_Flags[minIndex] = false;
	m_QueueSize--;
	return m_Data[minIndex].m_Vertex;
}

bool MinArray::comparePriorityDeleteMin(int i_A, int i_B) {
	return (m_Data[i_B].m_Key == Nan && m_Data[i_A].m_Key != Nan) ||
		(m_Data[i_A].m_Key != Nan && m_Data[i_A].m_Key < m_Data[i_B].m_Key);
}

std::string MinArray::GetPriorityQueueName() const {
	return "array";
}

