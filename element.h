#ifndef _ELEMENT_H_
#define _ELEMENT_H_
using namespace std;

class Element {
    private:
        int key;
    
    public:
        //Constructors
        Element();
        Element(int newKey);

        //Accessor Methods
        int getKey();

        //Modifier Methods
        void setKey(int newKey);
};


#endif // _ELEMENT_H_