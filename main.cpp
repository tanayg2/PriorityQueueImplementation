#include "heap.h"
#include "element.h"
#include "util.h"
#include <iostream>
#include "stdio.h"

using namespace std;

//Prints the contents of the heap
void printHeap(Heap* heap) {
    cout << "Capacity = " << heap->getCapacity() << endl;
    cout << "Size = " << heap->getSize() << endl;
    heap->print();
}
//Returns a new heap with capacity n
Heap initialize(int capacity) {
    if (capacity < 0) {
        cout << "Error: invalid heap capacity\n";
    } else {
        return Heap(capacity);
    }
}

//Initializes a heap based on an array, builds it into maxheap
void buildHeap(Heap* heap, Element* A, int size) {
    *heap = Heap(A, size, size);
    heap->buildMaxHeap();
}
//Inserts an element into the heap, prints the heap if flag is 2
void insert(Heap* heap, int flag, int key) {
		//Error handling
    if (!heap->initialized) {
        cout << "Error: heap not initialized\n";
        return;
    }
    if (flag != 1 && flag != 2) {
        cout << "Error: invalid flag value\n";
				return;
    }

    if (flag == 2) {
        cout << "Before insert operation:\n";
        printHeap(heap);
    }

		//Actual function
    heap->push(Element(key));

    if (flag == 2) {
        cout << "After insert operation:\n";
        printHeap(heap);
    }
}
//Deletes the maximum of element of the heap, prints contents before and after if flag is 2
Element deleteMax(Heap* heap, int flag) {
    //Error handling
    if (heap->getSize() == 0) {
	cout << "Error: heap empty" << endl;
	return NULL;
    }
    if (!heap->initialized) {
        cout << "Error: heap not initialized\n";
        return NULL;
    }
    if (flag != 1 && flag != 2) {
        cout << "Error: invalid flag value\n";
        return NULL;
    }

    if (flag == 2) {
        cout << "Before delete max operation:\n";
        printHeap(heap);
    }

		//Actual function
    Element deleted = heap->pop();

    if (flag == 2) {
        cout << "After delete max operation:\n";
        printHeap(heap);
    }
    cout << "Deleted max = " << deleted.getKey() << endl;
    return deleted;
}
//Increases the key at the specified index
void increaseKey(Heap* heap, int flag, int index, int value) {
    //Translate from heap index to array index
    index = index-1;

    //Error handling
    if (!heap->initialized) {
        cout << "Error: heap not initialized\n";
        return;
    }
    if (flag != 1 && flag != 2) {
        cout << "Error: invalid flag value\n";
        return;
    }
    if (index < 0 || index >= heap->getSize()) {
        cout << "Error: invalid index\n";
        return;
    }
    if (heap->getElement(index).getKey() >= value) {
        cout << "Error: new key is smaller than current key\n";
        return;
    }

    if (flag == 2) {
        cout << "Before increase key operation:\n";
        printHeap(heap);
    }

		//Changes the element value and calls the floatUp function to make sure heap functionality is maintained
    heap->setElement(index, value);
    heap->floatUp(index);

    if (flag == 2) {
        cout << "After increase key operation:\n";
        printHeap(heap);
    }
}

void printMenu() {
		char printString[] = "\nThis program implements the concept of priority queues. Here are possible program inputs:"
		"\nS:\t\t\t\tStop program"
		"\nC <heapSize>:\t\t\tCreate an empty heap"
		"\nR:\t\t\t\tCreate a max heap from text file (label file \"input.txt\", make sure to initialize heap first)"
		"\nW:\t\t\t\tPrint heap contents"
		"\nI <flag> <value>:\t\tInsert element of value <value> into heap. <flag> = 2 for wordy output, <flag> = 1 for no output"
		"\nD <flag>:\t\t\tDelete element with max value from heap. <flag> = 2 for wordy output, <flag> = 1 for no output"
		"\nK <flag> <index> <value>:\tIncrease element at <index> to <value> and float up, if key value is less than <value>. <flag> = 2 for wordy output, <flag> = 1 for no output\n";
		printf(printString);
}

int main() {

    char c;
    int index, value, flag;
    Heap heap = NULL;
    heap.initialized = false;
		printMenu();
    while(1){
        c = Util::nextCommand(&index, &value, &flag);
        switch (c) {
            //Case S, program stops
            case 's':
            case 'S': {
                printf("COMMAND: %c\n", c);
                exit(0);
            }
                //Case C, program creates an empty heap and exits
            case 'c':
            case 'C': {
                printf("COMMAND: %c %d\n", c, value);
                heap = initialize(value);
                break;
            }
                //Case R, program creates max heap from text file
            case 'r':
            case 'R': {
								cout << "COMMAND: " << c << endl;
								if (heap.initialized) {
									Util::load("input.txt", &heap);
									heap.buildMaxHeap();
								} else {
									cout << "Error: heap not initialized" << endl;
								}
								break;
            }
            //Case W, program prints the heap and then the heap's capacity
            case 'w':
            case 'W': {
                printf("COMMAND: %c\n", c);
								if (heap.initialized) {
	                	printHeap(&heap);
								} else {
										cout << "Error: heap not initialized" << endl;
                }
								break;
            }
                //Case I, program inserts element with key k into heap
            case 'i':
            case 'I': {
                printf("COMMAND: %c %d %d\n", c, flag, value);
                insert(&heap, flag, value);
                break;
            }
                //Case D, program deletes max element and prints the max
            case 'd':
            case 'D': {
                printf("COMMAND: %c %d\n", c, flag);
								if (heap.initialized) {
                	Element max = deleteMax(&heap, flag);
								} else {
									cout << "Error: heap not initialized" << endl;
								}
                break;
            }
                //Case K, program increases key of element at i to v
            case 'k':
            case 'K': {
                printf("COMMAND: %c %d %d %d\n", c, flag, index, value);
                increaseKey(&heap, flag, index, value);
                break;
            }
            default: break;
        }
    }
}
