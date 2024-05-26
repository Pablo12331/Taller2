#include "Producto.h"
#include "HashMap.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

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

//Este método toma una cadena de datos de un producto y la descompone en sus componentes (categoría, subcategoría, nombre del producto, precio, ID y cantidad). Luego, crea un nuevo objeto Producto con estos datos y lo devuelve.
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

//Destructor de la clase Producto.
Producto::~Producto(){}

//Este método actualiza la cantidad de stock del producto sumando la cantidad proporcionada como argumento a la cantidad actual.
void Producto::setCantidadProducto(int stockSuma)
{
    this->cantidadProducto = this->cantidadProducto + stockSuma;
}

//Este método solicita al usuario un ID de producto y verifica si ese ID está presente en la lista de IDs de productos existentes. Si el ID es válido, devuelve true; de lo contrario, solicita al usuario que ingrese un ID válido.
bool Producto::verificarIdProducto(int& idProducto, vector<int> idProductos)
{
    do
    {
        cout<<"\nEscriba el ID del producto(Ejemplo: 9718): ";
        cin>>idProducto;
        for(int id : idProductos)
        {
            if(id == idProducto)
            {
                return true;
            }
        }
        cout<<"\nNo se encontro el ID escrito, por favor verifique el ID que escribio."<<endl;

    }while(true);
}

//Este método solicita al usuario el ID del producto que desea agregar y la cantidad de stock que se añadirá al producto. 
int Producto::agregarProducto(vector<int> idProductos, int& stockSuma)
{
    int idProducto;
    int aux;
    
    if(verificarIdProducto(idProducto, idProductos))
    {
        cout<<"\n¿Cuanto sera la cantidad que se le agregara al stock?(Ejemplo: 10): ";
        cin>>stockSuma;
    }

    return idProducto;
}

//Este método devuelve el nombre del producto.

string Producto::getProducto()
{
    return this->producto;
}

//Este método devuelve el ID del producto.
int Producto::getIdProducto()
{
    return this->idProducto;
}

//Este método devuelve la cantidad de stock del producto.
int Producto::getCantidadProducto()
{
    return this->cantidadProducto;
}

//Este método devuelve el precio del producto.
int Producto::getPrecioProducto()
{
    return this->precioProducto;
}
//Este método devuelve una cadena que contiene toda la información del producto en un formato específico.
string Producto::informacionProducto()
{
    return this->categoria + "," + this->subCategoria + "," + this->producto + "," + to_string(this->precioProducto) +
          "," + to_string(this->idProducto) + "," + to_string(this->cantidadProducto);
}
//Este método actualiza el archivo de texto que almacena la información de los productos. Toma una cadena que representa toda la información de los productos y la escribe en el archivo "Productos.txt", sobrescribiendo su contenido anterior.
void Producto::actualizarProductos(string productos)
{
    ofstream datosProductos("Productos.txt", ios::out);
    datosProductos << productos;
    datosProductos.close();
}