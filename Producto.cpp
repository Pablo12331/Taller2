#include "Producto.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

Producto::Producto(string categoria, string subCategoria, string producto, 
                int precioProducto, int idProducto, int cantidadProducto)
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
    string categoria, subCategoria, producto, precioProducto, idProducto, cantidadProducto;

    stringstream datosSeparar(datosProducto);

    getline(datosSeparar, categoria, ',');
    getline(datosSeparar, subCategoria, ',');
    getline(datosSeparar, producto, ',');
    getline(datosSeparar, precioProducto, ',');
    getline(datosSeparar, idProducto, ',');
    getline(datosSeparar, cantidadProducto, ',');

    Producto* productoIngresar = new Producto(categoria, subCategoria, producto, stoi(precioProducto), stoi(idProducto), stoi(cantidadProducto));
    return productoIngresar;
}

Producto::~Producto(){}

void Producto::setCantidadProducto()
{
    cout<<this->cantidadProducto<<endl;
}

void Producto::agregarProducto(HashMap* &productos)
{
    
    return;
}

Producto* Producto::productoRandom()
{
    return nullptr;
}

int Producto::getIdProducto()
{
    return this->idProducto;
}
