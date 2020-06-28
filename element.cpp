#include "element.h"


Element::Element() {
    key = 0;
}

Element::Element(int newKey) {
    key = newKey;
}

int Element::getKey() {
    return key;
}

void Element::setKey(int newKey) {
    key = newKey;
}