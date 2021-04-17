#pragma once
#include "FordBaseAlgorithm.h"
#include "PriorityQueue.h"

class Dijkstra : public FordBaseAlgorithm
{
private:
	PriorityQueue& m_PriorityQueue;

	virtual void Relax(int i_Src, int i_Dest, int i_Weight) override;
public:
	Dijkstra(PriorityQueue& i_PriorityQueue);
	virtual ~Dijkstra() = default;

	virtual std::string GetAlgorithmName() const override;
	virtual void Process(const Graph& i_Grpah, int i_SrcVertex) override;
};

