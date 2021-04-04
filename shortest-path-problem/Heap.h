#pragma once
#include "PriorityQueue.h"

class Heap : public PriorityQueue
{
	using Node = int; // ##########################################

	private:
		Node** _data;
		int _maxSize;
		int _heapSize;
		int _allocated;
		static int Left(int node);
		static int Right(int node);
		static int Parent(int node);
		void fixHeap(int node);
	public:
		Heap(int max);
		Heap(Node**, int size);
		~Heap();


		Node* getMin() { return _heapSize ? _data[0] : nullptr; }
		Node* deleteMin();
		bool insert(Node*);
		bool isEmpty() const { return _heapSize == 0; }
		void makeEmpty() { _heapSize = 0; }


};

