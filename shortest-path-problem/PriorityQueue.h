#pragma once

struct Pair {
    int m_Key, m_Data;
};

class PriorityQueue {

public:
    PriorityQueue() = default;
    virtual ~PriorityQueue() = default;
    
	virtual void Build(/*arry of something*/) = 0;
	virtual Pair DeleteMin() = 0;
	virtual bool IsEmpty() = 0;
	virtual void DecreaseKey(int i_Place, int i_NewKey) = 0;

};

