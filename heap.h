#ifndef HEAP_H
#define HEAP_H
#include "element.h"
#include <stdio.h>

using namespace std;
class Heap {
    private:
        int capacity;
        int size;
        Element* heap;
        int nextPowerOf2(int n);
	int parent(int n);

    public:
        //variables
        bool initialized = false;

        //Constructors
        Heap(int newCapacity);
        Heap(Element* newHeap, int newSize, int newCapacity);

        //Methods
        int getCapacity();
        int getSize();
        Element getElement(int index);
	bool setElement(int index, int value);
        bool push(Element h);
        Element peak();
        Element pop();
        bool maxHeapify(int index);
	void heapify(int index);
        void buildMaxHeap();
	void floatUp(int index);
        void print();
};

#endif //HEAP_H
