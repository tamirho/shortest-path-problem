#pragma once

class PriorityQueue 
{

public:
	using Node = int; //#########################################

	void Build(/*arry of something*/);
	Node DeleteMin();
	bool IsEmpty();
	void DecreaseKey(int i_Place, int i_NewKey);

};

