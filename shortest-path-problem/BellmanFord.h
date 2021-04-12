#pragma once
#include "FordBaseAlgorithm.h"

class BellmanFord : public FordBaseAlgorithm {
protected:
    void Init(int i_NumOfVertices, int i_SrcVertex) override;
    void Relax(int i_Src, int i_Dest, int i_Weight) override;
public:
    BellmanFord() = default;
    virtual ~BellmanFord();

    bool Process(const Graph& i_Grpah, int i_SrcVertex) override;
    virtual std::string GetAlgorithmName() const override;

};
