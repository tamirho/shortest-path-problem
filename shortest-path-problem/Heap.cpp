#include "Heap.h"

Heap::Heap() : m_MaxSize(0), m_HeapSize(0), m_Data(nullptr), m_Indexes(nullptr){
}

void Heap::Build(int* i_InitArray, int i_NumOfVertices) {
    m_Data = new Pair[i_NumOfVertices];
    m_Indexes = new int[i_NumOfVertices + 1];
    m_HeapSize = m_MaxSize = i_NumOfVertices;
    
    m_Indexes[0] = -1;
    for (int i = 0; i < i_NumOfVertices; i++) { // copy the input arary and init the indexes array
        m_Data[i].m_Vertex = i + 1;
        m_Data[i].m_Key = i_InitArray[i + 1];
        m_Indexes[i + 1] = i;
    }
    
    for (int i = m_HeapSize / 2 - 1; i >= 0; i--) {
        fixHeap(i);
    }
}

Heap::~Heap() {
    if (m_Data != nullptr) {
        delete[] m_Data;
    }
    
    if (m_Indexes != nullptr) {
        delete[] m_Indexes;
    }
    
    m_Data = nullptr;
    m_Indexes = nullptr;
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
    
    while (true) {
        int min;
        int left = Left(i_Place);
        int right = Right(i_Place);
        
        if ((left < m_HeapSize) && compareFixHeapPriority(left,i_Place)) {
            min = left;
        }
        else {
            min = i_Place;
        }
        if ((right < m_HeapSize) && compareFixHeapPriority(right, min)) {
            min = right;
        }
        
        if (min == i_Place)
            break;
        else {
            swap(i_Place, min);
            i_Place = min;
        }
    }
}

bool Heap::compareFixHeapPriority(int i_A, int i_B) const{
    return (m_Data[i_A].m_Key != Nan) && (m_Data[i_A].m_Key < m_Data[i_B].m_Key || m_Data[i_B].m_Key == Nan);
}

int Heap::DeleteMin() {
    if (IsEmpty()) {
        throw std::runtime_error("Invalid operation");
    }
    Pair res = m_Data[0];
    m_HeapSize--;
    m_Data[0] = m_Data[m_HeapSize];
    fixHeap(0);
    return res.m_Vertex;
}


void Heap::DecreaseKey(int i_Vertex, int i_NewKey) {
    if (i_Vertex > m_MaxSize || i_Vertex < 0) {
        throw std::runtime_error("Invalid operation");
    }
    int place = m_Indexes[i_Vertex];
    m_Data[place].m_Key = i_NewKey;
    
    while ((place > 0) && (m_Data[Parent(place)].m_Key == Nan || m_Data[Parent(place)].m_Key > m_Data[place].m_Key))
    {
        swap(place, Parent(place));
        place = Parent(place);
    }
}

std::string Heap::GetPriorityQueueName() const {
    return "heap";
}

void Heap::swap(int i_A, int i_B)
{
    Pair temp = m_Data[i_A];
    m_Data[i_A] = m_Data[i_B];
    m_Data[i_B] = temp;
    m_Indexes[m_Data[i_A].m_Vertex] = i_A;
    m_Indexes[m_Data[i_B].m_Vertex] = i_B;
}
