#pragma once
#include <iostream>
#include "PriorityQueue.h"

class Heap : public PriorityQueue {
	private:
		Pair* m_Data;
		int* m_Indexes;
		int m_MaxSize;
		int m_HeapSize;
		static int Left(int node);
		static int Right(int node);
		static int Parent(int node);
		void fixHeap(int node);
		void swap(int i_A, int i_B);
		bool compareFixHeapPriority(int i_A, int i_B) const;
	public:
		Heap();
		~Heap();

        void Build(int* i_InitArray, int i_NumOfVertices) override;
        bool IsEmpty() const override { return m_HeapSize == 0; }
        void makeEmpty() { m_HeapSize = 0; }
        void DecreaseKey(int i_Vertex, int i_NewKey) override;
        int DeleteMin() override;
		std::string GetPriorityQueueName() const override;

};

