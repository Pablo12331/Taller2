#include "Producto.h"
#include <iostream>

using namespace std;

Producto::Producto(string categoria, string subCategoria, string producto, int precioProducto, int idProducto, int cantidadProducto)
{
    this->categoria = categoria;
    this->subCategoria = subCategoria; 
    this->producto = producto;
    this->precioProducto = precioProducto; 
    this->idProducto = idProducto;
    this->cantidadProducto = cantidadProducto;
}

Producto* Producto::ingresarProductos(string datosProducto)
{
    
}

void Producto::setCantidadProducto()
{

}

Producto* Producto::agregarProducto()
{

}

Producto* Producto::productoRandom()
{
    
}

HashMap* Producto::getBodega()
{
    this->bodega;
}
