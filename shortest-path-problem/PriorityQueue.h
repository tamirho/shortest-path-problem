#pragma once
#include <iostream>
#include <string>

/* Interface of priority queue which used to implement Dijkstra's algorithm */
class PriorityQueue {
    
protected:
    /* special value to represent an undefined distance - infinity*/
    static const float Nan;
    
    struct Pair {
		float m_Key;
		int m_Vertex;
    };
    
public:
    PriorityQueue() = default;
    virtual ~PriorityQueue() = default;
    
    // build PriorityQueue from an array:  key = i_InitArray[i], data = i
    virtual void Build(float* i_InitArray, int i_NumOfVertices) = 0;
    virtual int DeleteMin() = 0;
    virtual bool IsEmpty() const = 0;
    
    /*Decrease key value of vertex in the priority queue and fix the queue*/
    virtual void DecreaseKey(int i_Vertex, float i_NewKey) = 0;
    virtual std::string GetPriorityQueueName() const = 0;
};

