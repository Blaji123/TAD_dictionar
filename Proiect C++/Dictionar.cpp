//
// Created by Blajan David on 3/8/2024.
//
#include "Dictionar.h"
#include <iostream>
#include "IteratorDictionar.h"

//complexitate: Theta(1)
Dictionar::Dictionar() {
    length = 0;
    maxCapacity = 1;
    dictArray = new TElem [1];
}

//complexitate Theta(1)
Dictionar::~Dictionar() {
    delete[] dictArray;
}

// complexitate Theta(n)
void Dictionar::resize() {
    TElem *tempDictArray = new TElem[2 * maxCapacity];
    for (int i=0;i<length;i++)
        tempDictArray[i] = dictArray[i];
    maxCapacity*=2;
    delete[] dictArray;
    dictArray = tempDictArray;
}

// complexitate:
// best case: Elementul exista si este primul din vector : Theta(1)
// worst case: Elementul nu exista in vector: Theta(n)
// average case: Functie se poate de 1,2,...,n ori => T(n) = (3*(n+1))/2 => Theta(n)
// overall: O(n)
TValoare Dictionar::adauga(TCheie c, TValoare v){
    if (length == maxCapacity){
        resize();
    }
    for(int i=0;i<length;i++)
        if (dictArray[i].first == c){
            TValoare oldTValoare = dictArray[i].second;
            dictArray[i].second = v;
            return oldTValoare;
        }
    TElem newPair;
    newPair.first = c;
    newPair.second = v;
    dictArray[length++] = newPair;
    return NULL_TVALOARE;
}



// complexitate
// best case: elementul pe care-l cautam este primul: Theta(1)
// worst case: elementul nu exista in vector: Theta(n)
// average case: T(n) = (n+1)/2 => Theta(n)
// overall: O(n)
TValoare Dictionar::cauta(TCheie c) const{
    for (int i=0;i<length;i++)
        if (dictArray[i].first == c)
            return dictArray[i].second;
    return NULL_TVALOARE;
}

// complexitate: Theta(n)
// daca vrem sa stergem primul element trebuie sa parcurgem tot array-ul pentru a permuta la
// stanga elementele, iar daca elementul nu exista parcurgem tot array-ul prin while
TValoare Dictionar::sterge(TCheie c){
    TValoare oldValue = NULL_TVALOARE;
    int i=0;
    while(i<length && dictArray[i].first!=c)
        i++;
    if (i<length){
        oldValue = dictArray[i].second;
        length--;
        for(int j=i;j<length;j++)
            dictArray[j] = dictArray[j+1];
    }
    return oldValue;
}

// complexitate: Theta(1)
int Dictionar::dim() const {
    return length;
}

// complexitate: Theta(1)
bool Dictionar::vid() const{
    return length==0;
}

/**
 * functie  valoriAB(int a, int b)
 *
 *      dictionat dict_nou;
 *      int nr <- 0;
 *      pentru i<-0,dictArray.length executa
 *          daca dictArray[i].second>= a si dictArray[i].second <=b executa
 *              dict_nou.adauga(nr<-nr+1,dictArray[i].second);
 *          sfDaca
 *      sfPentru
 *      valoriAB <- dict_nou
 * sfFunctie
 *  complexity : Theta(n^2)
 * */
Dictionar Dictionar::valoriAB(int a, int b){
    Dictionar dict_nou;
    int nr = 0;
    for(int i=0;i<length;i++)
        if(dictArray[i].second>=a && dictArray[i].second<=b){
            dict_nou.adauga(nr++, dictArray[i].second);
    }
    return dict_nou;
}

// complexitate: Theta(1)
IteratorDictionar Dictionar::iterator() const {
    return  IteratorDictionar(*this);
}