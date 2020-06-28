#include "heap.h"
#include "element.h"
#include "util.h"
#include <iostream>
#include <fstream>
#include <string>

void Util::load(string filename, Heap* heap) {
    ifstream filevar;
    filevar.open("HEAPinput.txt");

    //Error handling if heap isn't initialized
    if (heap == NULL) {
        printf("Error: heap not initialized\n");
    } else if(filevar.fail()) {
    //Error handling if file can't be found
        printf("Error: file not found\n");
    } else {
        int index = 0;
        int fileSize;
        int key;
        int capacity;

        //Get size of array from file
        filevar >> fileSize;
        capacity = heap->getCapacity();

        if (fileSize > capacity) {
            printf("Error: array size exceeds heap capacity\n");
        } else {
	    			Element* temp = new Element[capacity+1];
						//stores the array elements from the file into temp array
            while (index < fileSize) {
                filevar >> key;
                temp[index] = Element(key);
                index++;
            }
						//Creates a new heap object with the old capacity but new array
	    			*heap = Heap(temp, fileSize, capacity);
        }

    }
    filevar.close();
}

//Parse command input
char Util::nextCommand(int *index, int *value, int *flag) {
    char c;
    while(1) {
        scanf("%c", &c);
        if (c == ' ' || c == '\t' || c =='\n' || c == 13){
            continue;
        }
        if (c == 'c' || c == 'C') {
            scanf("%d", value);
            break;
        }
        if (c == 'S' || c == 'R' || c == 'W'){
            break;
        }
        if (c == 'I' || c == 'i'){
            scanf("%d", flag);
            scanf("%d", value);
            break;
        }
        if (c == 'D' || c == 'd') {
            scanf("%d", flag);
            break;
        }
        if (c == 'K' || c == 'k') {
            scanf("%d", flag);
            scanf("%d", index);
            scanf("%d", value);
            break;
        }
        printf("Invalid Command\n");
    }
    return c;
}
