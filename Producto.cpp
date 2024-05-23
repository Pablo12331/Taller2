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

void Producto::setCantidadProducto(int stockSuma)
{
    this->cantidadProducto = this->cantidadProducto + stockSuma;
}

int Producto::agregarProducto(vector<int> idProductos, int& stockSuma)
{
    int idProducto;
    int aux;
    
    do
    {
        cout<<"\nEscriba ID del producto al que quiera agregar stock(Ejemplo: 9718): ";
        cin>>idProducto;
        for(int i = 0; i < idProductos.size(); i++)
        {
            aux = idProductos[i];
            if(aux == idProducto)
            {
                cout<<"\n¿Cuanto sera la cantidad que se le agregara al stock?(Ejemplo: 10): ";
                cin>>stockSuma;
                break;
            }
        }
        if(stockSuma == -1){cout<<"\nNo se encontro el ID escrito, por favor verifique el ID que escribio."<<endl;}       
    }while(idProducto != aux);

    return idProducto;
}

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


