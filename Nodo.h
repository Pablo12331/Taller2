#include <iostream>
#include "Producto.h"

class Nodo 
{
    public: 
        int key;
        Producto* value;
        Nodo* next;
        Nodo(int key, Producto* value);
};