//
// Created by Blajan David on 3/8/2024.
//
#include "IteratorDictionar.h"
#include "Dictionar.h"
#include <exception>

using namespace std;

//complexitate: Theta(1)
IteratorDictionar::IteratorDictionar(const Dictionar& d) : dict(d){
    currInd = 0;
}

//complexitate: Theta(1)
void IteratorDictionar::prim() {
    currInd = 0;
}

//complexitate: Theta(1)
void IteratorDictionar::urmator() {
    if(valid()){
        currInd++;
    }
    else{
        throw std::exception();
    }
}

//complexitate: Theta(1)
TElem IteratorDictionar::element() const{
    if(valid()){
        return dict.dictArray[currInd];
    }else{
        throw std::exception();
    }
}

//complexitate: Theta(1)
bool IteratorDictionar::valid() const {
    return currInd < dict.dim();
}