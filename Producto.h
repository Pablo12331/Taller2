#pragma once
#include <iostream>
#include "HashMap.h"
using namespace std;

class Producto
{
    private:
        string categoria, subCategoria, producto;
        int precioProducto, idProducto, cantidadProducto;

    public:
     
        Producto(string, string, string, int, int, int);
        Producto* ingresarProductos(string);
        void setCantidadProducto();
        Producto* agregarProducto();
        Producto* productoRandom();
        HashMap* getBodega();
};