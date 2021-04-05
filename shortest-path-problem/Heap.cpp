#include "Heap.h"

Heap::Heap(int max) : m_Allocated(true), m_MaxSize(max), m_HeapSize(0), m_Data(new Pair*[max]) {
}

Heap::Heap(Pair** i_InitArray, int i_SizeOfArr) : m_Allocated(false), m_MaxSize(i_SizeOfArr), m_HeapSize(i_SizeOfArr), m_Data(i_InitArray) {
    Build(i_InitArray, i_SizeOfArr);
}

void Heap::Build(Pair** i_InitArray, int i_SizeOfArr) {
    if (m_Allocated) {
        delete[] m_Data;
    }
    
    m_Allocated = false;
    for (int i = i_SizeOfArr / 2 - 1; i >= 0; i--) {
            fixHeap(i);
    }
}

Heap::~Heap() {
	if (m_Allocated) {
		delete[] m_Data;
	}
	m_Data = nullptr;
}

int Heap::Left(int i_Place) {
	return (2 * i_Place + 1);
}

int Heap::Right(int i_Place) {
	return (2 * i_Place + 2);
}

int Heap::Parent(int i_Place) {
	return (i_Place - 1) / 2;
}

void Heap::fixHeap(int i_Place) {

	int min;

	while (true) {
		int left = Left(i_Place);
		int right = Right(i_Place);

		if ((left < m_HeapSize) && (m_Data[left]->m_Key < m_Data[i_Place]->m_Key))
			min = left;
		else min = i_Place;
		if ((right < m_HeapSize) && (m_Data[right]->m_Key < m_Data[min]->m_Key))
			min = right;

		if (min == i_Place)
			break;
		else {
			Pair* temp = m_Data[i_Place];
			m_Data[i_Place] = m_Data[min];
			m_Data[min] = temp;
			i_Place = min;
		}
	}
}

Pair Heap::DeleteMin() {
	if (m_HeapSize < 1)
		throw std::runtime_error("Invalid operation");

	Pair res = *(m_Data[0]);
	m_HeapSize--;
	m_Data[0] = m_Data[m_HeapSize];
	fixHeap(0);
	return res;
}

//bool Heap::insert(Node* newNode) {
//
//	if (m_HeapSize == m_MaxSize)
//		return false;
//
//	int i = m_HeapSize;
//	m_HeapSize++;
//
//	while ((i > 0) && m_Data[Parent(i)]->m_Key > newNode->m_Key) {
//		m_Data[i] = m_Data[Parent(i)];
//		i = Parent(i);
//	}
//
//	m_Data[i] = newNode;
//	return true;
//}
//

