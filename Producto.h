#include <iostream>

using namespace std;

class Producto
{
    private:
        string categoria, subCategoria, producto;
        int precioProducto, idProducto, cantidadProducto;

    public:
        Producto(string, string, string, int, int);
        Producto* ingresarProductos(string);
        
};