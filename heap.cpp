#include "heap.h"
#include "element.h"
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <ostream>

using namespace std;

//Constructors
Heap::Heap(int newCapacity) {
    size = 0;
    capacity = newCapacity;
    heap = new Element[capacity];
    initialized = true;
}
Heap::Heap(Element *newHeap, int newSize, int newCapacity) {
    size = newSize;
    capacity = newCapacity;
    heap = newHeap;
    initialized = true;
}

//Methods
int Heap::getCapacity() {
    return capacity;
}
int Heap::getSize() {
    return size;
}
Element Heap::getElement(int index) {
    return heap[index];
}
//Calculates the index of the parent of the node
int Heap::parent(int n) {
    return int (n / 2);
}
//Sets the value of the element at specified index
bool Heap::setElement(int index, int value) {
    //Makes sure its not an invalid index
    if (index > size-1 || index < 0) {
        return false;
    }
    heap[index] = value;
    return true;
}
bool Heap::push(Element element) {
    //Expand heap if there's no space
    if (size == capacity) {
        //Increase capacity to next power of 2
        capacity = nextPowerOf2(capacity);
        //Initialize new array with this capacity
        Element* newHeap = new Element[capacity];
        //Add elements from old array to this one
        for (int i=0; i<size; i++) {
            newHeap[i] = heap[i];
        }
        //Replace old heap array with the new expanded capacity
        heap = newHeap;
    }
    //Replace the element at index size with the new element
    heap[size] = element;
    //Float value up until it reaches its place
    floatUp(size);
    size++;
    return true;
}
//Returns the max of the heap (stores at first element)
Element Heap::peak() {
    //Error handling if heap is empty
    if (size == 0) {
         return NULL;
    }
    return heap[0];
}
//Pops off the max of the heap (stored at first element of heap)
Element Heap::pop() {
    if (size == 0) {
        return NULL;
    } else {
        //Saves the max and replaces the first element with the last element. Runs maxHeapify on the parent to make it a heap again
        Element max = heap[0];
				heap[0] = heap[size-1];
				size--;
				maxHeapify(0);
        return max;
    }
}
//Runs maxheapify algorithm on the element at the specified index
bool Heap::maxHeapify(int index) {
    int largest;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
		//If Figure out if left child, right child, or parent is larger.
    if (left <= size && heap[left].getKey() > heap[index].getKey()) {
        largest = left;
    } else {
        largest = index;
    }
    if(right <= size && heap[right].getKey() > heap[largest].getKey()) {
        largest = right;
    }
		//Swap those and make sure the subtree under the new largest holds the heap property
    if (largest != index) {
        swap(heap[index], heap[largest]);
        maxHeapify(largest);
    }
}
//Assembles array into maxheap
void Heap::buildMaxHeap() {
    for (int i = int(size+1/2); i >= 0; i--) {
	//cout << "New heap iteration" << endl;
	//print();
        maxHeapify(i);
    }
}
//Floats the specified element until it's in the right position
void Heap::floatUp(int index) {
	//int key = heap[index].getKey();
	int parentIndex = (index - 1)/2;
	//Keep swapping with the parent node until the value either reaches the top or is smaller than its parent
	if (heap[parentIndex].getKey() >= 0) {
		if (heap[index].getKey() > heap[parentIndex].getKey()) {
			swap(heap[index], heap[parentIndex]);
			floatUp(parentIndex);
		}
	}
}
//Prints the just the elements of the heap
void Heap::print() {
    for (int i=0; i<size; i++) {
    printf("%d\n", heap[i].getKey());
    }
}
//Calculates the next power of 2
int Heap::nextPowerOf2(int n) {
    int i=0;
    int power = 0;
    while(power <= n) {
        power = (int) pow(2, i);
        i++;
    }
    return power;
}
