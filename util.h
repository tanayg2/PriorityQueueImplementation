#ifndef _UTIL_H_
#define _UTIL_H_

#include "element.h"
#include "heap.h"
#include <string>
#include <fstream>
using namespace std;

class Util {
    public:
        static void load(string filename, Heap* heap);
        static char nextCommand(int *i, int *v, int *f);

};


#endif //_UTIL_H_
