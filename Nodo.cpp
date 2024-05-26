#include <iostream>
#include "Nodo.h"
#include "Producto.h"

//Constructor de Nodo.
Nodo::Nodo(int key, Producto* value)
{
    this->key = key;
    this->value = value;
    this->next = nullptr;
}





