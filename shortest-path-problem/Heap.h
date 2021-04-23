#pragma once
#include <iostream>
#include "PriorityQueue.h"

/*
 This class is an implemention of minimum priority queue using heap.
 m_Data - array the reprecent a heap's tree.
 m_Indexes - array of indexs, where m_Indexes[i] is the index of i'th vertex in the m_Data array.
 */
class Heap : public PriorityQueue {
private:
    Pair* m_Data;
    int* m_Indexes;
    int m_MaxSize;
    int m_HeapSize;
    static int Left(int node);
    static int Right(int node);
    static int Parent(int node);
    void fixHeap(int node);
    
    // swap 2 items in the heap and update the m_Indexes array to the new indexes
    void swap(int i_A, int i_B);
    
    // compare priority of 2 items, with the respect to Nan as a infinity.
    bool compareFixHeapPriority(int i_A, int i_B) const;
public:
    Heap();
    ~Heap();
    
    void Build(float* i_InitArray, int i_NumOfVertices) override;
    bool IsEmpty() const override { return m_HeapSize == 0; }
    void makeEmpty() { m_HeapSize = 0; }
    void DecreaseKey(int i_Vertex, float i_NewKey) override;
    int DeleteMin() override;
    std::string GetPriorityQueueName() const override;
    
};

