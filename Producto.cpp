#include "Producto.h"
#include "HashMap.h"
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

// void Producto::agregarProducto(HashMap* &productos, vector<int> idProductos)
// {
//     cout<<"Lista de productos en bodega: "<<endl;
//     Producto* aux;
//     for(int id : idProductos)
//     {
//         aux = productos->get(id);
//         cout<<"ID: "<<id<<"| Nombre: "<< aux->getProducto()<<"| Stock: " <<aux->getCantidadProducto()<<endl; 
//     }
//     return;
// }

Producto* Producto::productoRandom()
{
    return nullptr;
}

string Producto::getProducto()
{
    return this->producto;
}

int Producto::getIdProducto()
{
    return this->idProducto;
}

int Producto::getCantidadProducto()
{
    return this->cantidadProducto;
}


