#include <iostream>
#include "Bodega.h"

class Nodo 
{
    public: 
        int key;
        Bodega* value;
        Nodo* next;
        Nodo(int key, Bodega* value);
};