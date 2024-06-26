#pragma once
#include <iostream>
#include <vector>
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
        void setCantidadProducto(int);
        bool verificarIdProducto(int&, vector<int>);
        int agregarProducto(vector<int>, int&);
        Producto* productoRandom();
        string getProducto();
        int getIdProducto();
        int getCantidadProducto();
        int getPrecioProducto();
        void actualizarProductos(string);
        string informacionProducto();
};