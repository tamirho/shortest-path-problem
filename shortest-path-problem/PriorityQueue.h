#pragma once
#include <string>

class PriorityQueue {

protected:
	static const int Nan = INT_MIN;

	struct Pair {
		int m_Key, m_Vertex;
	};

public:
    PriorityQueue() = default;
    virtual ~PriorityQueue() = default;
    
	virtual void Build(int* i_InitArray, int i_NumOfVertices) = 0;
	virtual int DeleteMin() = 0;
	virtual bool IsEmpty() const = 0;
	virtual void DecreaseKey(int i_Vertex, int i_NewKey) = 0;
	virtual std::string GetPriorityQueueName() const = 0;
};

