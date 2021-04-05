#pragma once
#include <iostream>
#include "PriorityQueue.h"

class Heap : public PriorityQueue {
	private:
		Pair** m_Data;
		int m_MaxSize;
		int m_HeapSize;
		bool m_Allocated;
		static int Left(int node);
		static int Right(int node);
		static int Parent(int node);
		void fixHeap(int node);
	public:
		Heap(int max);
		Heap(Pair**, int size);
		~Heap();

        void Build(Pair** i_InitArray, int i_SizeOfArr) override;
        bool IsEmpty() const override { return m_HeapSize == 0; }
        void makeEmpty() { m_HeapSize = 0; }
        void DecreaseKey(int i_Place, int i_NewKey) override;
        Pair DeleteMin() override;

//		Pair* getMin() { return _heapSize ? _data[0] : nullptr; }
//		bool insert(Pair*);

};

