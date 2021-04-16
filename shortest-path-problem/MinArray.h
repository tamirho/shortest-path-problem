#pragma once
#include "PriorityQueue.h"

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

