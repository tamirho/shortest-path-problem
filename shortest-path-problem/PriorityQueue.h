#pragma once
#include <iostream>
#include <string>

/* Interface of priority queue which used to implement Dijkstra's algorithm */
class PriorityQueue {
    
protected:
    /* special value to represent an undefined distance - infinity*/
    static const int Nan = INT_MIN;
    
    struct Pair {
        int m_Key, m_Vertex;
    };
    
public:
    PriorityQueue() = default;
    virtual ~PriorityQueue() = default;
    
    // build PriorityQueue from an array:  key = i_InitArray[i], data = i
    virtual void Build(int* i_InitArray, int i_NumOfVertices) = 0;
    virtual int DeleteMin() = 0;
    virtual bool IsEmpty() const = 0;
    
    /*Decrease key value of vertex in the priority queue and fix the queue*/
    virtual void DecreaseKey(int i_Vertex, int i_NewKey) = 0;
    virtual std::string GetPriorityQueueName() const = 0;
};

