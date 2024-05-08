#include <iostream>
#include "Nodo.h"
#include "Bodega.h"
class HashMap
{
    private:
        int tableSize;
        double maxLoadFactor;
        vector<Nodo*> table;
        int hashFunction(int key)
        {
            return key % tableSize;
        }
        void rehash();
    public:
        HashMap(double maxLoadFactor = 0.75);
        void insert(int key, Bodega* value);
        Bodega* get(int key);
        void erase(int key);
        int getNumberOfElements();
};