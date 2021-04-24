#pragma once
#include "FordBaseAlgorithm.h"

/* Implementation of Bellman-Ford algorithem to find lightest path.
 The algorithem pares N-1 times the graph's edges, and make a 'Relax' improvement */
class BellmanFord : public FordBaseAlgorithm {
protected:
    void Relax(int i_Src, int i_Dest, float i_Weight) override;
public:
    BellmanFord() = default;
    virtual ~BellmanFord();
    
    void Process(const Graph& i_Grpah, int i_SrcVertex) override;
    virtual std::string GetAlgorithmName() const override;
};
