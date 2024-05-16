#pragma once
#include <iostream>
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
        Producto* agregarProducto();
        Producto* productoRandom();
        int getIdProducto();
};