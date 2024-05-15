#pragma once 
#include <iostream>
using namespace std;
class Cliente
{
    private:
        string tipoCliente, datoDiferenciador, numeroAtencion;
    public:
        Cliente(string, string, string);
        Cliente* registroClientes(string);
};