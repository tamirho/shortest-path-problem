#pragma once
#include "PriorityQueue.h"

/*
This class is an implemention of minimum priority queue using array.
m_Data - array the reprecent a heap's tree.
m_Flags - array of flags, if m_Flags[i] == true, the i'th vertex is in the queue, else not.
*/
class MinArray : public PriorityQueue
{
private:
	Pair* m_Data;
	bool* m_Flags;
	int m_MaxSize;
	int m_QueueSize;

	bool comparePriorityDeleteMin(int i_A, int i_B);

public:
	MinArray();
	~MinArray();

	void Build(int* i_InitArray, int i_NumOfVertices) override;
	bool IsEmpty() const override { return m_QueueSize == 0; }
	void DecreaseKey(int i_Vertex, int i_NewKey) override;
	int DeleteMin() override;
	std::string GetPriorityQueueName() const override;
};

