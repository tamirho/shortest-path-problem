//#include "Heap.h"
//
//Heap::Heap(int max) : _allocated(1), _maxSize(max), _heapSize(0), _data(new Node*[max]) {
//}
//
//Heap::Heap(Node** arr, int size) : _allocated(0), _maxSize(size), _heapSize(size), _data(arr) {
//	for (int i = size / 2 - 1; i >= 0; i--) {
//		fixHeap(i);
//	}
//}
//
//Heap::~Heap() {
//	if (_allocated) {
//		delete[] _data;
//	}
//	_data = nullptr;
//}
//
//int Heap::Left(int node) {
//	return (2 * node + 1);
//}
//
//int Heap::Right(int node) {
//	return (2 * node + 2);
//}
//
//int Heap::Parent(int node) {
//	return (node - 1) / 2;
//}
//
//void Heap::fixHeap(int node) {
//
//	int min;
//
//	while (true) {
//		int left = Left(node);
//		int right = Right(node);
//
//		if ((left < _heapSize) && (_data[left]->getCount() < _data[node]->getCount()))
//			min = left;
//		else min = node;
//		if ((right < _heapSize) && (_data[right]->getCount() < _data[min]->getCount()))
//			min = right;
//
//		if (min == node)
//			break;
//		else {
//			Node* temp = _data[node];
//			_data[node] = _data[min];
//			_data[min] = temp;
//			node = min;
//		}
//	}
//}
//
//Node* Heap::deleteMin() {
//	if (_heapSize < 1)
//		return nullptr;
//
//	Node* res = _data[0];
//	_heapSize--;
//	_data[0] = _data[_heapSize];
//	fixHeap(0);
//	return res;
//}
//
//bool Heap::insert(Node* newNode) {
//
//	if (_heapSize == _maxSize)
//		return false;
//
//	int i = _heapSize;
//	_heapSize++;
//
//	while ((i > 0) && _data[Parent(i)]->getCount() > newNode->getCount()) {
//		_data[i] = _data[Parent(i)];
//		i = Parent(i);
//	}
//
//	_data[i] = newNode;
//	return true;
//}
//
//
