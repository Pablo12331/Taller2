#include <iostream>
#include "HashMap.h"
using namespace std;

class Producto
{
    private:
        string categoria, subCategoria, producto;
        int precioProducto, idProducto, cantidadProducto;
        HashMap* bodega();

    public:
        Producto(string, string, string, int, int);
        Producto* ingresarProductos(string);
        void setCantidadProducto();
        Producto* agregarProducto();
        Producto* productoRandom();
        HashMap* getBodega();
};