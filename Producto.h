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
        ~Producto();
        Producto* ingresarProductos(string);
        void setCantidadProducto();
        void agregarProducto(HashMap* &productos, vector<int>);
        Producto* productoRandom();
        string getProducto();
        int getIdProducto();
        int getCantidadProducto();
};