#ifndef HEAP_H
#define HEAP_H

#include <string>
#include <sstream>
#include <iostream>

typedef unsigned int uint;
template <class T>
class Heap {
private:
	T 	 *data;
	uint s;
	uint count;

	uint parent(uint) const;
	uint left(uint) const;
	uint right(uint) const;
	void swap(uint, uint);
	void pushDown(uint);

public:
	Heap(uint);
	~Heap();
	void push(T);
	T pop();
    T top();
    bool empty() const;
	bool full() const;
	uint size() const;
	std::string toString() const;

};

// =================================================================
// Constructor. Initializes the maximum size of the heap and creates
// the array.
//
// @param sze, the maximum size of the heap.
// =================================================================
template <class T>
Heap<T>::Heap(uint sz) {
	s = sz;
	data = new T[s];
	count = 0;
}

// =================================================================
// Destructor. Free used dynamic memory.
//
// =================================================================
template <class T>
Heap<T>::~Heap() {
	delete [] data;
	data = NULL;
	s = 0;
	count = 0;
}

// =================================================================
// Returns the position of the parent of an element.
//
// @returns the index of the parent
// =================================================================
template <class T>
uint Heap<T>::parent(uint pos) const {
	return (pos - 1) / 2;
}

// =================================================================
// Returns the position of the left child of an element.
//
// @returns the index of the left child.
// =================================================================
template <class T>
uint Heap<T>::left(uint pos) const {
	return (pos * 2 + 1);
}

// =================================================================
// Returns the position of the right child of an element.
//
// @returns the index of the right child.
// =================================================================
template <class T>
uint Heap<T>::right(uint pos) const {
	return (pos * 2 + 2);
}

// =================================================================
// Swap the content of two locations.
//
// @param i, j, indeces to be swapped.
// =================================================================
template <class T>
void Heap<T>::swap(uint i, uint j) {
	T aux = data[i];
	data[i] = data[j];
	data[j] = aux;
}

// =================================================================
// Place the item in the correct position. Being a min-heap, the
// element must be less than its children. If not, recursively
// perform the pushDown.
//
// @param pos, the current position of the item being inserted.
// =================================================================
template <class T>
void Heap<T>::pushDown(uint pos) {
	
	uint le = left(pos);
    uint ri = right(pos);
    uint min = pos;

    if (le < count && data[le] > data[min]){
        min = le;
    }
    if (ri < count && data[ri] > data[min]){
        min = ri;
    }

    if(min != pos){
        swap(pos, min);
        pushDown(min);
    }
}

// =================================================================
// Add an element to the heap. It is placed, initially, as the
// rightmost blade. Afterwards, it is verified if he is less than
// the father. If that is the case, it is exchanged. This process is
// repeated until the correct position is reached.
//
// @param val, the element to be added.
// @throws Overflow, if the heap is full.
// =================================================================
template <class T>
void Heap<T>::push(T val) {
	uint pos;
	if (full()){
		return;
	}

	pos = count;
	count++;
	while(pos > 0 && val > data[parent(pos)]){
		data[pos]= data[parent(pos)];
		pos = parent(pos);
	}
	data[pos] = val;
    pushDown(count);
	
}

template <class T>
T Heap<T>::pop() {
	if (empty()){
		return 0;
	}

	T aux = data[0];
	data[0] = data[--count]; // data[0] = data[count]; count--;
	pushDown(0);
	return aux;
}

template <class T>
T Heap<T>::top() {
	if (empty()){
		return 0;
	}

	T aux = data[0];
	return aux;
}

// =================================================================
// Returns if the heap is empty or not.
//
// @returns True is the amount of elements is 0 (empty). False,
//					otherwise.
// =================================================================
template <class T>
bool Heap<T>::empty() const {
	return (count == 0);
}

// =================================================================
// Returns if the heap is full or not.
//
// @returns True is the amount of elements is equal to the maximum.
//					False, otherwise.
// =================================================================
template <class T>
bool Heap<T>::full() const {
	return (count == s);
}

// =================================================================
// Returns the number of elements in the heap
//
// @returns the number of elements in the heap.
// =================================================================
template <class T>
uint Heap<T>::size() const {
	return count;
}

// =================================================================
// Return a string representation of the heap.
//
// @returns, a string with the elements of the heap.
// =================================================================
template <class T>
std::string Heap<T>::toString() const {
	std::stringstream aux;

	aux << "[";
	for (uint i = 0; i < count; i++) {
		if (i != 0) {
			aux << " ";
		}
	aux << data[i];
	}
	aux << "]";
	return aux.str();
}

#endif /* HEAP_H */