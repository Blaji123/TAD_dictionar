//
// Created by Blajan David on 3/8/2024.
//

#ifndef TAD_DICTIONAR_DICTIONAR_H
#define TAD_DICTIONAR_DICTIONAR_H

#define NULL_TVALOARE -1

typedef int TCheie;
typedef int TValoare;

class IteratorDictionar;

#include <utility>
typedef std::pair<TCheie, TValoare > TElem;

class Dictionar{
    friend class IteratorDictionar;

private:
    /* aici e reprezentarea */
    int length, maxCapacity;
    TElem *dictArray;
    void resize();

public:
    // constructorul implicit al dictionarului
    Dictionar();

    // adauga o pereche (cheie, valoare) in dictionar
    //daca exista deja cheia in dictionar, inlocuieste valoarea asociata cheii si returneaza vechea valoare
    // daca nu exista cheia, adauga perechea si returneaza null: NULL_TVALOARE
    TValoare adauga(TCheie c, TValoare v);

    //cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null: NULL_TVALOARE
    TValoare cauta(TCheie c) const;

    //sterge o cheie si returneaza valoarea asociata (daca exista) sau null: NULL_TVALOARE
    TValoare sterge(TCheie c);

    //returneaza numarul de perechi (cheie, valoare) din dictionar
    int dim() const;

    //verifica daca dictionarul e vid
    bool vid() const;

    Dictionar valoriAB(int a, int b);

    // se returneaza iterator pe dictionar
    IteratorDictionar iterator() const;

    // destructorul dictionarului
    ~Dictionar();
};


#endif //TAD_DICTIONAR_DICTIONAR_H