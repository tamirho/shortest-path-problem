#pragma once

struct Pair {
    int m_Key, m_Data;
};

class PriorityQueue {

public:
    PriorityQueue() = default;
    virtual ~PriorityQueue() = default;
    
	virtual void Build(Pair** i_InitArray, int i_SizeOfArr) = 0;
	virtual Pair DeleteMin() = 0;
	virtual bool IsEmpty() const = 0;
	virtual void DecreaseKey(int i_Place, int i_NewKey) = 0;
};

