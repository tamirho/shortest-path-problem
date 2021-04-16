#pragma once
#include "FordBaseAlgorithm.h"

class BellmanFord : public FordBaseAlgorithm {
protected:
    void Relax(int i_Src, int i_Dest, int i_Weight) override;
public:
    BellmanFord() = default;
    virtual ~BellmanFord();

    void Process(const Graph& i_Grpah, int i_SrcVertex) override;
    virtual std::string GetAlgorithmName() const override;

};
